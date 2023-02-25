
import matplotlib.pyplot as plt
from matplotlib.ticker import MaxNLocator
xpoints = []
for i in range(2004,2024):
    xpoints.append(i)
ypoints = [85000,85000,85000,85000,85000,163000,85000,85000,85000,85000,124000,172500,233000,236000,199000,190098,201011,275000,308613,483927]

fig, ax1 = plt.subplots()

ax1.plot(xpoints,ypoints,marker = 'o')
ax1.legend(['Q'],ncol=1,loc=2)


ax2 = ax1.twinx()
y = [850,850,850,163,850,850,850,85,124,172,233,236,199,190,201,275,308,483]
ax2.plot(xpoints,y,color="red",marker="*")
ax2.legend(['V'],ncol=1)

plt.show()

