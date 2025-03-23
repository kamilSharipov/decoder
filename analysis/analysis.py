import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("results.txt", sep="\t")

data.columns = data.columns.str.strip()

majority_data = data[data["Algorithm"] == "Majority"]
bitflip_data = data[data["Algorithm"] == "BitFlip"]
uncoded_error_rate = data[data["Iterations"] == "Uncoded"]["BitErrorRate"].values[0]

majority_mean = majority_data.groupby("Iterations")["BitErrorRate"].mean().reset_index()
bitflip_mean = bitflip_data.groupby("Iterations")["BitErrorRate"].mean().reset_index()

plt.figure(figsize=(5, 3))
plt.plot(
    majority_mean["Iterations"],
    majority_mean["BitErrorRate"],
    label="Многопроходовое мажоритарное (среднее)",
    marker="o"
)
plt.plot(
    bitflip_mean["Iterations"],
    bitflip_mean["BitErrorRate"],
    label="Инвертирование бит (среднее)",
    marker="x"
)
plt.axhline(
    y=uncoded_error_rate,
    color="red",
    linestyle="--",
    label="Некодированная передача"
)
plt.title("Зависимость средней вероятности ошибки декодирования от числа итераций")
plt.xlabel("Число итераций")
plt.ylabel("Средняя вероятность ошибки декодирования на бит")
plt.legend()
plt.grid()
plt.show()