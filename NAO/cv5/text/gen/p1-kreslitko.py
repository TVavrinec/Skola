import numpy as np
import matplotlib.pyplot as plt

# Load data from the file
file_path = "gen/P1-mos.txt"
data = np.loadtxt(file_path, skiprows=1)  # Skip the header row

# Extract voltage (Vgs) and current (Is(M2))
vgs = data[:, 0] * 1e3  # Convert to mV
is_m2 = data[:, 1] * 1e6  # Convert to µA

# Define cursor positions based on provided values
cursor1_x = 651.75616  # in mV
cursor1_y = 9.0021129  # in µA
cursor2_x = 679.20872  # in mV
cursor2_y = 11.011331  # in µA

# Compute difference and slope
diff_x = cursor2_x - cursor1_x
diff_y = cursor2_y - cursor1_y
slope = diff_y / diff_x

# Annotation position for the difference table
annotation_x = 420  # in mV
annotation_y = 9  # in µA

# Plot the graph
plt.rcParams.update({'font.size': 20})

plt.figure(figsize=(10, 6), dpi=200)
plt.plot(vgs, is_m2, color='green', linewidth=2.5)
plt.xlabel("Vgs (mV)")
plt.ylabel("Is (µA)")
plt.grid(True, linestyle='--', alpha=0.7)

# Plot cursor positions
plt.scatter([cursor1_x, cursor2_x], [cursor1_y, cursor2_y], color='red', marker='o')
plt.axhline(y=cursor1_y, color='gray', linestyle='--', alpha=0.7)
plt.axhline(y=cursor2_y, color='gray', linestyle='--', alpha=0.7)
plt.axvline(x=cursor1_x, color='gray', linestyle='--', alpha=0.7)
plt.axvline(x=cursor2_x, color='gray', linestyle='--', alpha=0.7)

# Adjust annotation positions
offset_x_left = -100  # Move text to the left
offset_y = -4  # Slightly move text up

cursor1_text_x = cursor1_x + offset_x_left
cursor1_text_y = cursor1_y + offset_y
cursor2_text_x = cursor2_x + offset_x_left
cursor2_text_y = cursor2_y - offset_y

# Draw leader lines
plt.plot([cursor1_x, cursor1_text_x], [cursor1_y, cursor1_text_y], color='black', linestyle='--', linewidth=1)
plt.plot([cursor2_x, cursor2_text_x], [cursor2_y, cursor2_text_y], color='black', linestyle='--', linewidth=1)

# Place annotations
plt.text(cursor1_text_x, cursor1_text_y, f"Cursor 1\n({cursor1_x:.2f}mV, {cursor1_y:.2f}µA)", 
         fontsize=18, color='red', bbox=dict(facecolor='white', alpha=0.7), ha='right')
plt.text(cursor2_text_x, cursor2_text_y, f"Cursor 2\n({cursor2_x:.2f}mV, {cursor2_y:.2f}µA)", 
         fontsize=18, color='red', bbox=dict(facecolor='white', alpha=0.7), ha='right')
plt.text(annotation_x, annotation_y, 
         f"ΔVgs={diff_x:.2f}mV\nΔIs={diff_y:.2f}µA\ngm={slope:.4f}mS",
         fontsize=18, color='blue', bbox=dict(facecolor='white', alpha=0.7), ha='center')

plt.legend()
plt.show()
