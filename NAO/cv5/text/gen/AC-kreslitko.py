import pandas as pd
import matplotlib.pyplot as plt
import os

# Načtení dat ze souboru
file_path = './gen/simAC.txt'

# Změň na cestu k souboru
data = []

# Otevření souboru a čtení řádek po řádku
with open(file_path, 'r', encoding='latin1') as file:
    lines = file.readlines()[1:]  # Skipping the header
    for line in lines:
        parts = line.strip().split('\t')
        if len(parts) == 2:
            try:
                freq = float(parts[0])
                values = parts[1].strip('()').split(',')
                db = float(values[0].replace('dB', '').strip())
                faz = float(values[1].replace('d', '').strip())
                data.append((freq, db, faz))
            except ValueError:
                continue  # Skip lines with invalid data

# Konverze dat do pandas DataFrame
df = pd.DataFrame(data, columns=['Frequency', 'Gain(dB)', 'Faze'])

# Předpokládejme, že closest_to_zero_gain je řádek s frekvencí blízkou 0 dB a df.iloc[0] pro bod u 0 Hz
closest_to_zero_gain = df.iloc[(df['Gain(dB)'] - 0).abs().argmin()]

# amplitudová rezerva
closest_to_180_drift = df.iloc[(df['Faze'] - -180).abs().argmin()]

# Výpočet hodnoty pro pokles o 3 dB
max_gain = df['Gain(dB)'].max()
gain_3dB = max_gain - 3

# Najít frekvenci, kde nastává pokles o 3 dB
frequency_3dB = df[df['Gain(dB)'] <= gain_3dB].iloc[0]

# Kód pro vykreslení grafu
fig, ax1 = plt.subplots(figsize=(10, 6))

# První graf na první ose Y (Gain(dB))
ax1.plot(df['Frequency'], df['Gain(dB)'], color='green', linewidth=2)
ax1.set_xlabel('f (Hz)', fontsize=20)
ax1.set_ylabel('A (dB)', fontsize=20, color='green')
ax1.tick_params(axis='y')
ax1.set_xscale('log')

# Vytvoření druhé osy Y sdílející osu X
ax2 = ax1.twinx()

# Druhý graf na druhé ose Y (Faze)
ax2.plot(df['Frequency'], df['Faze'], color='blue', linewidth=2)
ax2.set_ylabel('Faze', fontsize=20, color='blue')

# Přidání bodu pro frekvenci blízkou 0 dB
ax1.scatter(closest_to_zero_gain['Frequency'], closest_to_zero_gain['Gain(dB)'], color='red')
ax2.scatter(closest_to_zero_gain["Frequency"], closest_to_zero_gain["Faze"], color='red')
label_red = f'{(closest_to_zero_gain["Frequency"]/1000000):.1f}MHz, {closest_to_zero_gain["Gain(dB)"]:.2f}dB, {closest_to_zero_gain["Faze"]:.0f}°'
ax1.text(2000, closest_to_zero_gain['Gain(dB)']+3,
         label_red, fontsize=20, color='red')

# Přidání bodu pro pokles o 3 dB
ax1.scatter(frequency_3dB['Frequency'], gain_3dB, color='green')  # Oranžový bod pro 3 dB
label_3dB = f'{(frequency_3dB['Frequency']):.0f}Hz, {gain_3dB:.2f}dB, {frequency_3dB["Faze"]:.0f}°'
ax1.text(frequency_3dB['Frequency']+1000, gain_3dB-1, label_3dB, fontsize=20, color='green')

# Přidání bodu pro zisk při 0 Hz
gain_at_zero_frequency = df.iloc[0]
ax1.scatter(df.iloc[0]['Frequency'], gain_at_zero_frequency['Gain(dB)'], color='blue')
label_green = f'{df.iloc[0]["Frequency"]:.0f}Hz, {gain_at_zero_frequency['Gain(dB)']:.2f}dB, {gain_at_zero_frequency["Faze"]:.0f}°'
ax1.text(df.iloc[0]['Frequency']*0.5, gain_at_zero_frequency['Gain(dB)']-9,
         label_green, fontsize=20, color='blue')

# Přidání bodu pro frekvenci blízkou 0 dB
ax1.scatter(closest_to_180_drift['Frequency'], closest_to_180_drift['Gain(dB)'], color='orange')
ax2.scatter(closest_to_180_drift["Frequency"], closest_to_180_drift["Faze"], color='orange')
label_red = f'{(closest_to_180_drift["Frequency"]/1000000):.1f}MHz, {closest_to_180_drift["Gain(dB)"]:.2f}dB, {closest_to_180_drift["Faze"]:.0f}°'
ax1.text(3500, closest_to_180_drift['Gain(dB)']-1,
         label_red, fontsize=20, color='orange')

# Nastavení velikosti písma pro čísla os (tick labels)
ax1.tick_params(axis='x', labelsize=20)  # Změna velikosti písma pro čísla na ose X
ax1.tick_params(axis='y', labelsize=20)  # Změna velikosti písma pro čísla na ose Y

# Přidání mřížky a legendy
ax1.grid(True, which='both', ls='--')

# Zobrazení grafu
plt.show()
