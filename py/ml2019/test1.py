'''
读取数据,预处理
3600=3200 400
'''
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
train_data=pd.read_csv('E:/Git_Code/py/ml2019/train.csv',usecols=range(3,27))
train_data=train_data.replace('NR',0)
train_data=np.array(train_data)
train_data=np.array(train_data).astype(float)
'''
初步结论:
WS_HR,PM10,NO
'''
# plt.figure(1)
# for i in range(9):
#     plt.plot(train_data[i,1:],label=train_data[i,0])
# plt.figure(2)
# for i in range(10,18):
#     plt.plot(train_data[i,1:],label=train_data[i,0])
# plt.figure(3)
# plt.plot(train_data[9,1:],label=train_data[i,0])
lr=0.001
my_feature,my_targets=[],[]
for i in range(0,4320,18):
    for j in range(24-10):
        use_f=train_data[[i+4,i+8,i+17],j:j+9]
        use_t=train_data[i+9,j+10]
        my_feature.append(use_f)
        my_targets.append(use_t)
my_feature=np.array(my_feature)[:,0:3330]
my_targets=np.array(my_targets)[0:370]
'''
更新
'''
def update(feature,targets,steps):
    #init
    n=np.size(targets)#sample
    w=np.zeros(n)
    w_diff=np.zeros(n)
    b=0
    b_diff=0
    beta=0
    m=np.size(feature,0)#input_feature
    for x in range(steps):
        for i in range(m):
            for j in range(n):
                w_diff[i] -= feature[i,j]*(targets[j]-b-w.dot(feature[:,j]))
            w_diff[i] += beta*w[i]*w[i]
            w_diff[i]/=n
        for j in range(n):
            b_diff-=targets[j]-b-w.dot(feature[:,j])
        b_diff/=n
        w_diff_2=np.sqrt(np.sum(w_diff*w_diff))
        b_diff_2=np.sqrt(np.sum(b_diff*b_diff))
        w-=lr*w_diff/w_diff_2
        b-=lr*b_diff
    ## count loss
    if x%100==0:
        loss=0
        for j in range(n):
            loss+=(targets[j]-b-w.dot(feature[:,j]))**2
        loss/=n
        print("after {} epochs,Loss is".format(i),loss)   
update(my_feature,my_targets,500)