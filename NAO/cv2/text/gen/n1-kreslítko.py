import numpy as np
import matplotlib.pyplot as plt

# Load data from the file
file_path = "gen/N1-mos.txt"  # Uprav cestu, pokud je soubor jinde
data = np.loadtxt(file_path, skiprows=1)  # Skip header

# Extract voltage (Vgs) and current (Id)
vgs = data[:, 0] * 1e3  # Convert to mV
id_m1 = data[:, 1] * 1e6  # Convert to µA

# Define cursor positions
cursor1_x = 540.16173  # in mV
cursor1_y = 11.024494  # in µA
cursor2_x = 525.60647  # in mV
cursor2_y = 8.974674  # in µA

# Compute difference and slope
diff_x = cursor2_x - cursor1_x
diff_y = cursor2_y - cursor1_y
slope = diff_y / diff_x

# === POZICE TABULEK ===
offset_x_left = -110  # Posun tabulek doleva (větší číslo víc doleva)
offset_y = 4  # Posun tabulek nahoru/dolů

cursor1_text_x = cursor1_x + offset_x_left
cursor1_text_y = cursor1_y + offset_y
cursor2_text_x = cursor2_x + offset_x_left
cursor2_text_y = cursor2_y - offset_y

# Pozice hlavní tabulky (posun dolů/doleva)
annotation_x = cursor1_x - 180  # Menší hodnota více doleva
annotation_y = cursor1_y - 2   # Menší hodnota více dolů

# === KRESLENÍ GRAFU ===
plt.rcParams.update({'font.size': 20})

plt.figure(figsize=(10, 6), dpi=200)
plt.plot(vgs, id_m1, color='green', linewidth=2.5)
plt.xlabel("Vgs (mV)")
plt.ylabel("Id (µA)")
plt.grid(True, linestyle='--', alpha=0.7)

# Plot cursor positions
plt.scatter([cursor1_x, cursor2_x], [cursor1_y, cursor2_y], color='red', marker='o')
plt.axhline(y=cursor1_y, color='gray', linestyle='--', alpha=0.7)
plt.axhline(y=cursor2_y, color='gray', linestyle='--', alpha=0.7)
plt.axvline(x=cursor1_x, color='gray', linestyle='--', alpha=0.7)
plt.axvline(x=cursor2_x, color='gray', linestyle='--', alpha=0.7)

# Draw leader lines
plt.plot([cursor1_x, cursor1_text_x], [cursor1_y, cursor1_text_y], color='black', linestyle='--', linewidth=1)
plt.plot([cursor2_x, cursor2_text_x], [cursor2_y, cursor2_text_y], color='black', linestyle='--', linewidth=1)

# Place annotations
plt.text(cursor1_text_x, cursor1_text_y, f"Cursor 1\n({cursor1_x:.2f}mV, {cursor1_y:.2f}µA)", 
         fontsize=18, color='red', bbox=dict(facecolor='white', alpha=0.7), ha='right')
plt.text(cursor2_text_x, cursor2_text_y, f"Cursor 2\n({cursor2_x:.2f}mV, {cursor2_y:.2f}µA)", 
         fontsize=18, color='red', bbox=dict(facecolor='white', alpha=0.7), ha='right')
plt.text(annotation_x, annotation_y, 
         f"ΔVgs={diff_x:.2f}mV\nΔId={diff_y:.2f}µA\ngm={(slope):.4f}mS",
         fontsize=18, color='blue', bbox=dict(facecolor='white', alpha=0.7), ha='center')

plt.legend()
plt.show()
