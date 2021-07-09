a= input()
a=a[1:-1]
ds=[]
ns=[]
b=[]
for i in a.split(','):
    b.append(eval(i))
ds.append(b[0])
ns.append(0)
n=len(b)
for i in range(n):
    ds.append(ns[i-1]+b[i])
    ns.append(max(ns[i-1],ds[i-1]))
print(max(ds[n-1],ns[n-1]))