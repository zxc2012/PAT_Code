import numpy as np
import random
b = np.array([[[1,2,3,4],[1,3,4,5]],[[2,4,7,5],[8,4,3,5]],[[2,5,7,3],[1,5,3,7]]]);
# print("before:\n",b,"\nend");
c=np.sort(b,axis=1);
rg=np.eye(3,6,0,dtype=np.int)
a=np.arange(16).reshape(4,4)
s=np.linalg.norm(b,axis=1);

print(a*np.pi)
print(random.random())
print(np.sqrt(10))