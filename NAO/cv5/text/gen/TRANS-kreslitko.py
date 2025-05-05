import numpy as np
import matplotlib.pyplot as plt

# Funkce pro načtení dat ze souboru
def extract_data_from_file(file_path):
    data = []
    with open(file_path, 'r') as file:
        for line in file:
            # Přeskočíme řádky, které neobsahují čísla nebo začínají textem
            if line.startswith("time") or not line.strip():  # Přeskočíme řádky obsahující "time"
                continue
            parts = line.split("\t")
            if len(parts) > 1:
                try:
                    time = float(parts[0])  # První hodnota je čas
                    voltage = float(parts[1])  # Napětí
                    data.append((time, voltage))
                except ValueError:
                    continue  # Pokud není možné převést hodnotu, přeskočíme tento řádek
    return np.array(data)

# Cesta k souboru
file_path = './gen/simTrans.txt'  # Opravená cesta k souboru

# Extrahování dat
data = extract_data_from_file(file_path)
time = data[:, 0]
voltages = data[:, 1]

# Určení bodů 10% a 90% napětí
max_voltage = np.max(voltages)
min_voltage = np.min(voltages)

v_10 = min_voltage + 0.1 * (max_voltage - min_voltage)
v_90 = min_voltage + 0.9 * (max_voltage - min_voltage)

# Funkce pro hledání bodu na určité hodnotě napětí na vzestupné nebo sestupné hraně
def find_transition_point(voltage_array, voltage_value, ascending=True):
    if ascending:
        for i in range(1, len(voltage_array)):
            if voltage_array[i-1] < voltage_value <= voltage_array[i]:
                return i
    else:
        for i in range(1, len(voltage_array)):
            if voltage_array[i-1] > voltage_value >= voltage_array[i]:
                return i
    return -1  # Pokud není nalezen, vrátí -1

# Najdeme indexy bodů odpovídajících 10% a 90% napětí na vzestupné a sestupné hraně
rising_10_idx = find_transition_point(voltages, v_10, ascending=True)
falling_10_idx = find_transition_point(voltages, v_10, ascending=False)

rising_90_idx = find_transition_point(voltages, v_90, ascending=True)
falling_90_idx = find_transition_point(voltages, v_90, ascending=False)

# Funkce pro inženýrský zápis s prefixy
def to_engineering_notation(value):
    prefixes = {1e3: 'k', 1e6: 'M', 1e9: 'G', 1e-3: 'm', 1e-6: 'u', 1e-9: 'n', 1e-12: 'p'}
    exponent = int(np.floor(np.log10(abs(value)) / 3) * 3)
    value_in_eng = value / 10**exponent
    prefix = prefixes.get(10**exponent, '')
    return f'{value_in_eng:.3f}{prefix}'

# Vykreslení grafu s normální osou X
plt.figure(figsize=(10, 6))
plt.plot(time, voltages, color='b')

# Označení bodů 10% a 90% na vzestupné a sestupné hraně
plt.scatter(time[rising_10_idx], voltages[rising_10_idx], color='r', zorder=5)
plt.scatter(time[falling_10_idx], voltages[falling_10_idx], color='orange', zorder=5)

plt.scatter(time[rising_90_idx], voltages[rising_90_idx], color='g', zorder=5)
plt.scatter(time[falling_90_idx], voltages[falling_90_idx], color='purple', zorder=5)

# Přidání souřadnic k bodům v inženýrském zápisu s prefixy
plt.text(time[rising_10_idx]*1.12, voltages[rising_10_idx], f'{to_engineering_notation(time[rising_10_idx])}s, {to_engineering_notation(voltages[rising_10_idx])}V', color='r', fontsize=15, verticalalignment='bottom')
plt.text(time[falling_10_idx]*1.02, voltages[falling_10_idx], f'{to_engineering_notation(time[falling_10_idx])}s, {to_engineering_notation(voltages[falling_10_idx])}V', color='orange', fontsize=15, verticalalignment='bottom')

plt.text(time[rising_90_idx]*1.1, voltages[rising_90_idx], f'{to_engineering_notation(time[rising_90_idx])}s, {to_engineering_notation(voltages[rising_90_idx])}V', color='g', fontsize=15, verticalalignment='bottom')
plt.text(time[falling_90_idx]*1.02, voltages[falling_90_idx], f'{to_engineering_notation(time[falling_90_idx])}s, {to_engineering_notation(voltages[falling_90_idx])}V', color='purple', fontsize=15, verticalalignment='bottom')

# Nastavení osy X a Y
plt.xlabel('t (us)')
plt.ylabel('U (V)')

# Zobrazení mřížky
plt.grid(True, which='both', axis='both', linestyle='--', linewidth=0.5)

# Zobrazení grafu bez legendy
plt.tight_layout()
plt.show()
