
import matplotlib.pyplot as plt
import matplotlib.patches as mpatches
import matplotlib as mpl
import numpy as np


VersaoOriginal = [
[8314.57, 7290.16, 7182.63, 7498.15, 7640.31, 7614.92, 7642.35, 7663.24, 7635.66, 7730.46],
[7070.9, 7047.56, 7001.34, 7015.39, 6991.07, 7099.33, 7007.44, 7031.57, 7000.4, 6967.99],
[8153.73, 7924.25, 7931.6, 7897.96, 7940.86, 7929.96, 8140.54, 7913.97, 8197.5, 7969.08],
[7375.83, 7295.33, 7288.83, 7220.12, 7111.61, 7206.4, 7128.58, 7195.28, 7115.96, 7215.14],
[7307.93, 7010.81, 7229.27, 7097.67, 7308.07, 7137.38, 7013.17, 7052.9, 7117.98, 7094.07],
[6997.6, 7083.91, 7023.62, 7049.66, 7063.38, 7024.25, 7065.15, 7622.99, 7215.83, 7168.73]
]

Versao1 = [
[7622.33, 7718.23, 7666.02, 7720.97, 7491.9, 7363.1, 7504.93, 7672.65, 7715.88, 7645.62],
[7106.45, 7020.05, 6968.52, 7099.87, 7046.18, 7054.76, 7012.37, 7045.71, 7050.58, 7124.8],
[8024.21, 7931.55, 8170.36, 7934.44, 8206.52, 7950.47, 8114.18, 7972.58, 8078.33, 7950.93],
[7131.96, 7136.44, 7097.29, 7366.06, 7201.73, 7374.01, 7211.39, 7377.06, 7156.76, 7371.3],
[7279.04, 7049.7, 7349.97, 7135.88, 7026.33, 7125.64, 7328.16, 7066.43, 7273.11, 7061.41],
[7243.35, 7087.81, 7198.4, 7061.56, 7213.96, 7112.06, 7097.89, 7051.26, 7269.93, 7063.74]
]

Versao2 = [
[7662.86, 7660.43, 7684.56, 7679.61, 7749.04, 7630.29, 7502.61, 7319.29, 7792.6, 7828.47],
[7140.5, 7091.86, 7021.63, 7022.24, 7050.88, 7060, 7102.68, 7095.27, 7044.13, 7026.76],
[7894.61, 8568.88, 9116.54, 7928.25, 7890.59, 8052.83, 7940.07, 8153.02, 7954.2, 7905.08],
[7185.73, 7311.87, 7234.65, 7124.63, 7160.5, 7257.41, 7159.8, 7146.56, 7216.57, 7144.3],
[7263.07, 7117.52, 7199.46, 7168.94, 7049.45, 7069.42, 7276.94, 7135.38, 7308.43, 7181],
[7088.45, 7013.16, 7022.89, 7046.25, 6999, 7080.49, 7078.27, 7019.75, 7031.76, 7071.65]
]

Versao3 = [
[7666.13, 7770.39, 7740.63, 7626.16, 7737.93, 7666.76, 7611.49, 7114.63, 7678.02, 7636.44],
[7087.01, 7048.61, 7009.25, 7006.12, 7022.18, 6997.02, 7039.55, 7041.38, 7025.53, 7047.63],
[7930.25, 8105.15, 7902.57, 8125.79, 7987.36, 7890.53, 7863.98, 8098.5, 7910.82, 8118.19],
[7243.4, 7197.13, 7136.95, 7221.1, 7197.89, 7180.98, 7109.78, 7173.58, 7161.79, 7217.43],
[7284.5, 7093.48, 7204.37, 7146.19, 7150.61, 7119.09, 7318.4, 7052.17, 7306.64, 7122.29],
[7073.93, 7050.82, 7047.39, 7050.62, 6989.48, 7031.6, 7087.32, 7053.77, 7107.94, 7047.62]
]

Versao4 = [
[7673.93, 7642.59, 7095.27, 7186.77, 7118.04, 7036.6, 7076.38, 7030.93, 6992.39, 7066.53],
[6992.17, 7051.27, 7057.18, 6992.49, 7030.65, 7082.63, 7027.46, 7054.76, 7001.13, 7159.01],
[7958.65, 7881.28, 7847.45, 7836.74, 8100.33, 7907.4, 8136.25, 7907.11, 7896.35, 7909.43],
[7149.56, 7097.46, 7346.17, 7172.92, 7324.52, 7237.6, 7367.48, 7156.75, 7128.45, 7168.83],
[7282.52, 7138.94, 7113.77, 7115.47, 7053.44, 7064.73, 7223.92, 7118.95, 7218.87, 7194.67],
[7021.43, 7042.76, 7031.61, 7100.53, 7023.31, 7063.28, 7001.05, 7036.43, 6993.38, 7022.7]
]


mediaVersaoOriginal = []
stdVersaoOriginal = []
mediaVersao1 = []
stdVersao1 = []

mediaVersao2 = []
stdVersao2 = []
mediaVersao3 = []
stdVersao3 = []
mediaVersao4 = []
stdVersao4 = []

for i in range(6):
	mediaVersaoOriginal.append(np.mean(VersaoOriginal[i]))
	stdVersaoOriginal.append(np.std(VersaoOriginal[i]))
	mediaVersao1.append(np.mean(Versao1[i]))
	stdVersao1.append(np.std(Versao1[i]))

	mediaVersao2.append(np.mean(Versao2[i]))
	stdVersao2.append(np.std(Versao2[i]))
	mediaVersao3.append(np.mean(Versao3[i]))
	stdVersao3.append(np.std(Versao3[i]))
	mediaVersao4.append(np.mean(Versao3[i]))
	stdVersao4.append(np.std(Versao3[i]))

fig = plt.figure(figsize=(10,5))
ax1 = fig.add_subplot(111)


## Média e desvio padrão ##

plt.errorbar(np.array(range(len(mediaVersaoOriginal)))*2, mediaVersaoOriginal, stdVersaoOriginal,label=r'1 Thread', color='#1F77B4', fmt='o', lw=1, capsize=4, markersize=8, markeredgecolor='#1F77B4', markerfacecolor='#8FBBD9')
plt.plot(np.array(range(len(mediaVersaoOriginal)))*2, mediaVersaoOriginal, color='#1F77B4',lw=2)

plt.errorbar(np.array(range(len(mediaVersao1)))*2, mediaVersao1, stdVersao1,label=r'2 Thread', color='#D62728', fmt='s', lw=1, capsize=4, markersize=8, markeredgecolor='#D62728', markerfacecolor='#EA9393')
plt.plot(np.array(range(len(mediaVersao1)))*2, mediaVersao1, color='#D62728',lw=2)


plt.errorbar(np.array(range(len(mediaVersao2)))*2, mediaVersao2, stdVersao2,label=r'3 Thread', color='#2CA02C', fmt='v', lw=1, capsize=4, markersize=8, markeredgecolor='#2CA02C', markerfacecolor='#95CF95')
plt.plot(np.array(range(len(mediaVersao2)))*2, mediaVersao2, color='#2CA02C',lw=2)

plt.errorbar(np.array(range(len(mediaVersao3)))*2, mediaVersao3, stdVersao3,label=r'4 Thread', color='#FF7F0E', fmt='D', lw=1, capsize=4, markersize=8, markeredgecolor='#FF7F0E', markerfacecolor='#FFBF86')
plt.plot(np.array(range(len(mediaVersao3)))*2, mediaVersao3, color='#FF7F0E',lw=2)

plt.errorbar(np.array(range(len(mediaVersao4)))*2, mediaVersao4, stdVersao4,label=r'8 Thread', color='#1acca5', fmt='d', lw=1, capsize=4, markersize=8, markeredgecolor='#1acca5', markerfacecolor='#138ba5')
plt.plot(np.array(range(len(mediaVersao4)))*2, mediaVersao4, color='#1acca5',lw=2)



ax1.yaxis.grid(True, linestyle='-', linewidth=0.5, which='major', color='lightgrey',alpha=1.0)
# ax1.xaxis.grid(True, linestyle='-', linewidth=0.5, which='major', color='lightgrey',alpha=1.0)

fontSize=12

ax1.set_axisbelow(True)
ax1.set_title('Busca Binária Paralela', fontsize=fontSize+3, fontweight='bold')
ax1.set_xlabel(r'Quantidade de senhas a serem buscadas', fontsize=fontSize+2)
ax1.set_ylabel('Tempo médio (em ms)', fontsize=fontSize+2)
ax1.xaxis.set_label_coords(0.5, -0.08)
ax1.set_facecolor('white')


handles, labels = ax1.get_legend_handles_labels()
leg = ax1.legend(handles, labels, bbox_to_anchor=(0.01, 0.98), loc=2, borderaxespad=0., fontsize=fontSize)
leg.get_frame().set_facecolor('#FFFFFF')
# plt.legend(title=r'Compilador')




ticks = ['1', '2', '100', '500', '1000', '5000']
plt.xticks(range(0, len(ticks)*2, 2), ticks, fontsize=fontSize)
plt.yticks(fontsize=fontSize)
plt.xlim(-1, len(ticks)*2-1)
#plt.ylim(-10, 40)


plt.tight_layout()
# plt.show()

plt.savefig('GraficoBinaria.pdf',bbox_inches='tight')
