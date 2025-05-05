import pandas as pd
import matplotlib.pyplot as plt

# Load the data from the file
file_path = './gen/simDC.txt'
data = pd.read_csv(file_path, sep="\t")

# Check the first few rows of the data
data.head()

# Plotting the graph
plt.figure(figsize=(10, 6))
plt.plot(data['vin'], data['V(n001)'], label='$U_{IN}$', color='b', linestyle='--', marker='')
plt.plot(data['vin'], data['V(out)'], label='$U_{OUT}$', color='r', linestyle='-', marker='')

# Adding labels and title
plt.xlabel('$U_{IN}$', fontsize = 20)
plt.ylabel('$U_{OUT}$', fontsize = 20)
plt.legend()
plt.legend(fontsize=20) 

# Nastavení velikosti písma pro čísla os (tick labels)
plt.tick_params(axis='x', labelsize=20)  # Změna velikosti písma pro čísla na ose X
plt.tick_params(axis='y', labelsize=20)  # Změna velikosti písma pro čísla na ose Y

plt.scatter(1.8, 1.749, color='red',  marker='x')
label_red = f'1.749 V'
plt.text(1.65, 1.55, label_red, fontsize=20, color='red')

plt.scatter(0, 0, color='green',  marker='x')
label_red = f'0 V'
plt.text(-0.05, 0.1, label_red, fontsize=20, color='green')


# Show the plot
plt.grid(True)
plt.show()




plt.plot(data['vin'], data['V(out)']-data['V(n001)'], label='$U_{IN}$', color='g', linestyle='-', marker='')

# Adding labels and title
plt.xlabel('$U_{IN}$', fontsize = 20)
plt.ylabel('$U_{OUT}$', fontsize = 20)

# Nastavení velikosti písma pro čísla os (tick labels)
plt.tick_params(axis='x', labelsize=20)  # Změna velikosti písma pro čísla na ose X
plt.tick_params(axis='y', labelsize=20)  # Změna velikosti písma pro čísla na ose Y

# Show the plot
plt.grid(True)
plt.show()
