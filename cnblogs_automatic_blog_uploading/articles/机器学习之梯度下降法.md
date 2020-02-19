concordance/kən'kɔːd(ə)ns/一致
```py
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
lr=0.01
my_feature,my_targets=[],[]
for i in range(0,4320,18):
    for j in range(15):
        # use_f=train_data[[i+4,i+8,i+17],j:j+9]
        use_f=train_data[i+9,j:j+9]
        use_t=train_data[i+9,j+9]
        my_feature.append(use_f)
        my_targets.append(use_t)
my_feature=np.array(my_feature)
my_targets=np.array(my_targets)
train_f,test_f=my_feature[0:3300],my_feature[3300:]
train_t,test_t=my_targets[0:3300],my_targets[3300:]
'''
更新
'''
def update(feature,targets,steps):
    #init
    n=np.size(targets)#sample
    b=0
    b_diff=0
    beta=0.012
    m=np.size(feature,1)#input_feature
    w=np.zeros(m)
    w_diff=np.zeros(m)
    print("sample:",n,"tait:",m)
    losses=[]
    for x in range(steps):
        loss=0
        for i in range(m):
            for j in range(n):
                w_diff[i] -= feature[j,i]*(targets[j]-b-w.dot(feature[j,:]))
            w_diff[i] += beta*w[i]*w[i]
            w_diff[i]/=n
        for j in range(n):
            b_diff-=targets[j]-b-w.dot(feature[j,:])
            loss+=(targets[j]-b-w.dot(feature[j,:]))**2
        b_diff/=n
        loss/=n
        loss=np.sqrt(loss)
        losses.append(loss)
        w_diff_2=np.sqrt(np.sum(w_diff*w_diff))
        b_diff_2=np.sqrt(np.sum(b_diff*b_diff))
        w-=lr*w_diff/w_diff_2
        b-=lr*b_diff
        ## count loss
        if x%100==0:
            print("after {} epochs,Loss is".format(x),loss)
    ## plot
    plt.figure()
    plt.plot(losses)
    plt.xlabel("periods")
    plt.ylabel("Loss")
    plt.title("learing rate:{} beta:{}".format(lr,beta))
def main():
    update(train_f,train_t,700)
    update(test_f,test_t,500)
    plt.show()
if __name__=='__main__':   
    main()
```