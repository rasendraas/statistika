# MENEMUKAN OUTLIERS DARI DATASET "weather_data.csv"

import numpy as np
import pandas as pd

lokasi_file = "/content/spotify_weather_data.csv"
df = pd.read_csv(lokasi_file)
df.head(5)

data = df.iloc[:, 5].values

# Hitung nilai Q1 dan Q3
Q1 = np.quantile(df['Popularity'], 0.25)
Q3 = np.quantile(df['Popularity'], 0.75)

# Hitung IQR
IQR = Q3 - Q1

print('Kuartil 1 = ', Q1)
print('Kuartil 3 = ', Q3)
print('IQR = ', IQR)

min_IQR = Q1 - 1.5 * IQR
max_IQR = Q3 + 1.5 * IQR

# Nilai maksimum dan minimum
print("")
print("Nilai Maksimum dan Minimum :")
nilai_min = np.min(data)
nilai_max = np.max(data)

print('Nilai minimum data = ', nilai_min)
print('Nilai maksimum data = ', nilai_max)

low_out = []
high_out = []

for i in data:
    if (i < min_IQR):
        low_out.append(i)
    if (i > max_IQR):
        high_out.append(i)