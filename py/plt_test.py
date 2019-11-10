import matplotlib.pyplot as plt
import numpy as np
import math

a=np.arange(0,200,0.001)
b=np.sin(a);
# ax=plt.subplots(2,2)
plt.figure()
plt.plot(a,b,'g')
plt.plot(a[a>np.pi],b[a>np.pi],'r')
plt.xlim(0,2*np.pi)
plt.xlabel("x")
plt.ylabel("y")
plt.show()
x=np.array([[0,4],
           [2,3] ])
print(np.linalg.norm(x,axis=0))
print(math.sqrt(pow(3,2)+pow(4,2)+pow(4,2)+pow(6,2)+pow(1,2)))
help(np.random)
