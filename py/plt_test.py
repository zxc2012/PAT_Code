import pandas as pd 
import matplotlib.pyplot as plt
import numpy as np
df = pd.read_csv("weather.csv",encoding='gb2312')
# df.plot()
x = df['时间']
y1 = df['日平均气温']
y2 = df['日最高气温']
y3 = df['日最低气温']
z = df['生长速率']

fig = plt.figure(figsize=(15,9))
# left
ax1 = fig.add_subplot(111)

ax1.plot(list(x),list(y2),color='orange')
ax1.plot(list(x),list(y1),color="green")
ax1.plot(list(x),list(y3),color="skyblue")
ax1.legend(['日最高气温','日平均气温','日最低气温'],ncol=1,loc=2)
# 设置y轴标题
ax1.set_ylabel('温度:摄氏度')
# 设置x轴刻度
ax1.set_xticks([0,5,10,15,20,25])
# 设置x轴标题
ax1.set_xlabel('日期')

#right
realx = []
realz = []
ax2 = ax1.twinx()
for point in range(len(list(z))):
    if np.isnan(z[point]) == False:
        realx.append(x[point])
        realz.append(z[point])
ax2.plot(realx,realz,color="red",marker="*")
ax2.set_ylabel('生长速率: cm/d')
ax2.legend(['生长速率'],ncol=1)
# 设置标注

plt.show()