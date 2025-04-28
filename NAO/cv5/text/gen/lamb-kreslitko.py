import numpy as np
import matplotlib.pyplot as plt


# Load data from the uploaded file
file_path_N = "gen/N-lambda.txt"
file_path_P = "gen/P-lambda.txt"

# Read data, skipping the first row (header)
data_N = np.loadtxt(file_path_N, skiprows=1, usecols=(0, 1))  # Use only the second and third columns
data_P = np.loadtxt(file_path_P, skiprows=1, usecols=(0, 1))  # Use only the second and third columns

# Extract U_SB and U_TH values
U_SB_N = data_N[:, 0] / 50
U_TH_N = data_N[:, 1] 

U_SB_P = data_P[:, 0] / 50
U_TH_P = data_P[:, 1] 

# Plot the graph
plt.rcParams.update({'font.size': 20})

plt.figure(figsize=(10, 6), dpi=200)
plt.plot(U_SB_N, U_TH_N, color='blue', linewidth=2.5, marker='', markersize=4, label = "NMOS")
plt.plot(U_SB_P, U_TH_P, color='red', linewidth=2.5, marker='', markersize=4, label = "PMOS")
plt.xlabel("Delka kanálu $L [\mu m]$")
plt.ylabel("Modulované délky kanálu $\lambda$")
plt.grid(True, linestyle='--', alpha=0.7)
plt.legend()
plt.show()
