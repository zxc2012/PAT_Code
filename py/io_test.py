
import matplotlib.pyplot as plt
from matplotlib.ticker import MaxNLocator
xpoints = []
for i in range(2004,2024):
    xpoints.append(i)
ypoints = [85000,85000,85000,85000,85000,163000,85000,85000,85000,85000,124000,172500,233000,236000,199000,190098,201011,275000,308613,483927]
for a,b in zip(xpoints[16:],ypoints[16:]):
    plt.text(a, b, '%d' % b, fontsize=9)
plt.plot(xpoints,ypoints,marker = 'o')
plt.gca().xaxis.set_major_locator(MaxNLocator(integer=True))

plt.gca().yaxis.set_major_locator(MaxNLocator(integer=True))
plt.savefig('../x.jpg')