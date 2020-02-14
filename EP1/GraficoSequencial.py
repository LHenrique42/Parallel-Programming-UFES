
import matplotlib.pyplot as plt
import matplotlib.patches as mpatches
import matplotlib as mpl
import numpy as np


VersaoOriginal = [
[1301.77, 1095.57, 1072.37, 1098.84, 1082.54, 1072.77, 1077.02, 1064.8, 1078.98, 1073.13],
[1302.33, 1120.45, 1118.84, 1195.82, 1125.94, 1118.16, 1095.58, 1397.04, 1177.12, 1107.94],
[6254.76, 6141.31, 6083.04, 6263.79, 6133.52, 6138.32, 6146.14, 6875.4, 6870.89, 6089.77],
[30417.2, 28786.5, 30984.7, 29786.7, 30851.6, 30733.9, 30736.1, 31862.3, 30239.1, 30067],
[65677, 61473.8, 62121, 64058.7, 62327.5, 63169.5, 60323.3, 60448.9, 61385.2, 61775.4],
[274184, 283355, 264650, 257518, 255302, 255814, 253137, 252226, 253290, 259322]
]

Versao1 = [
[1227.02, 1056.94, 1042.96, 1044.62, 1036.95, 1043.09, 1059.02, 1064, 1069.15, 1053.99],
[1104.04, 1095.74, 1088.14, 1388.75, 1655.68, 1083.29, 1099.71, 1105.69, 1097.34, 1098.94],
[5238.73, 5194.65, 5171.52, 5202.47, 5191.7, 5176.61, 5173.54, 5201.46, 5183.47, 5172.58],
[21902.8, 22948.3, 21768.4, 21897, 21961.6, 23142.9, 22036.9, 21897.7, 22075.3, 22029.5],
[43456.4, 45023, 45157.5, 45012.3, 45157, 45359.6, 45751.6, 45458.8, 46487.8, 46938.8],
[209611, 207822, 209319, 209690, 207822, 208758, 207433, 209805, 209686, 207701]
]

Versao2 = [
[1211.33, 1065.79, 1041.12, 1042.86, 1048.84, 1051.17, 1054.81, 1052.55, 1057.83, 1052.26],
[1090.34, 1097.44, 1091.34, 1097.26, 1090.28, 1100.44, 1092.76, 1081.57, 1081.33, 1089.83],
[5093.69, 5077.83, 5093.22, 5080.87, 5088.36, 5076.84, 5081.1, 5214.46, 5117.43, 5159.11],
[21035.9, 21553.3, 21499.5, 21311.2, 20891.6, 21767.4, 21972.7, 21544.2, 21509.4, 21363.9],
[41974.9, 42420.9, 42023.2, 42410.8, 42879.1, 42076.5, 42598.7, 42789, 42249.4, 42867.1],
[204100, 202892, 205451, 204863, 203724, 206075, 205637, 205448, 205834, 203996]
]

Versao3 = [
[1205.91, 1060.93, 1068.69, 1053.02, 1057.48, 1051.84, 1057.44, 1049.07, 1061.32, 1052.58],
[1091.08, 1079.06, 1071.54, 1246.75, 1779.17, 1080.82, 1082.79, 1078.6, 1078.59, 1082.2],
[4929.39, 4942.65, 4923.83, 4924.06, 4931.07, 4911.97, 4915.2, 4915.99, 4927.45, 4925.1],
[21234.9, 21060.3, 20438.1, 20890.9, 21233.8, 21001, 20624, 20659, 21315.5, 21428.5],
[41496.8, 41526.3, 42042.5, 42379, 42487.9, 42527.9, 42254.6, 41882.1, 42082, 42608.4],
[203135, 203398, 203479, 203063, 203672, 203075, 204017, 202630, 204109, 203547]
]

Versao4 = [
[1226.17, 1082.81, 1051.26, 1039.54, 1056.45, 1062.88, 1055.88, 1063.7, 1053.24, 1052.16],
[1082.18, 1076.4, 1071.94, 1095.98, 1087.06, 1089.82, 1298.15, 1735.17, 1079.83, 1086.1],
[5101.49, 5074.27, 5064.33, 5284.56, 5295.7, 5265.5, 5185.82, 5161.3, 5118.71, 5239.53],
[21592.3, 22052, 22365.8, 22171.4, 21982.6, 21652.8, 21567.3, 21902.8, 22005.2, 22884.4],
[43919.5, 43686.2, 44305.8, 43602.3, 44130.1, 43965.6, 43659.2, 44391.1, 43590.5, 44488.5],
[211364, 211298, 211087, 210795, 211184, 211314, 210765, 211620, 211637, 211001],
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
ax1.set_title('Busca Sequencial Paralela', fontsize=fontSize+3, fontweight='bold')
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

plt.savefig('GraficoSequencial.pdf',bbox_inches='tight')
