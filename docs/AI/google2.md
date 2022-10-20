# Google Tensorflow练习
## 机器学习速成课程练习中的常用超参数

- steps：训练迭代的总次数。一步计算一批样本产生的损失，然后使用该值修改一次模型的权重。
- batch size：单步的样本数量（随机选择）。例如，SGD 的批次大小为 1。

>以下公式成立:

total_number_of_trained_examples=batch_size*steps
  
- periods：控制报告的粒度。例如，如果 periods 设为 7 且 steps 设为 70，则练习将每 10 步输出一次损失值（即 7 次）。与超参数不同，我们不希望您修改 periods 的值。请注意，修改 periods 不会更改模型所学习的规律。

>以下公式成立：

number_of_training_examples_in_each_period=batch_size*steps/periods
# 李宏毅2019机器学习hw1
## Description
本次作業的資料是從行政院環境環保署空氣品質監測網所下載的觀測資料。
希望大家能在本作業實作 linear regression 預測出PM2.5的數值。

本次作業使用豐原站的觀測記錄，分成train set跟test set，train set是豐原站每個月的前20天所有資料。test set則是從豐原站剩下的資料中取樣出來。

- train.csv: 每個月前20天的完整資料。
- test.csv : 從剩下的資料當中取樣出連續的10小時為一筆，前九小時的所有觀測數據當作feature，第十小時的PM2.5當作answer。

一共取出240筆不重複的test data，請根據feauure預測這240筆的PM2.5。
## Code
### 用heatmap分析PM2.5的影响成分
```py
'''
读取数据,预处理
3600=3200 400
'''
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
train_data=pd.read_csv('train.csv',usecols=range(2,27))
train_data=train_data.replace('NR',0)
train_data=np.array(train_data)
new=np.empty((18,1))
for i in range(0,4320,18):
    new=np.concatenate((new,train_data[i:i+18,1:]),axis=1)
new=new[:,1:].T
temp={}
for i in range(18):
    temp[train_data[i,0]]=new[:,i]
new=pd.DataFrame(temp,dtype=float)
cr=new.corr()
sns.heatmap(cr,mask=cr<0.4)#,annot=True)
```
>notes:

- *1.预处理*
- *2.数组维度一致，行列向量的转换*

![heatmap](https://s2.ax1x.com/2020/02/20/3Z5ZDJ.jpg)
### 梯度下降法
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
            w_diff[i] += beta*w[i]
            w_diff[i]/=n
        for j in range(n):
            b_diff-=targets[j]-b-w.dot(feature[j,:])
            loss+=(targets[j]-b-w.dot(feature[j,:]))**2
        b_diff/=n
        loss+=np.sum(np.square(w))
        loss/=n
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
#### Result

画曲线总结

```py
class Drawtest():
    #函数开始时创建盛放loss与acc的容器
    def __init__(self):
        self.color = {}
        self.color[0]='r'
        self.color[1]='g'
        self.color[2]='k'
        self.color[3]='m'
        self.text = {}
        self.text[0]='CNN-Res'
        self.text[1]='FL-CNN-Res'
        self.text[2]='FL-CNN-RC'
        self.text[3]='FL-CNN-RC2'
 
    #绘图，这里把每一种曲线都单独绘图，若想把各种曲线绘制在一张图上的话可修改此方法
    def draw_p(self, lists, label, type,num):
        plt.plot(range(len(lists)), lists, self.color[num], label=self.text[num])
        plt.ylabel(label)
        plt.xlabel('epoch')
        plt.title(type+label)
        plt.legend(loc="upper right")
        if label=='loss' and type =='train_epoch':
            self.ax1=plt.gca()
        else:
            self.ax2=plt.gca()
        plt.savefig('model/'+type+'_'+label+'.jpg')

    def end_draw(self,num,acc,loss):
        if num ==0 :
            plt.figure()
        else:
            plt.sca(self.ax1)   
        self.draw_p(loss, 'loss', 'train_epoch',num)
        if num ==0 :
            plt.figure()
        else:
            plt.sca(self.ax2)   
        self.draw_p(acc, 'acc', 'train_epoch',num)
```

![result](https://s2.ax1x.com/2020/02/20/3e656A.jpg)
![result1](https://s2.ax1x.com/2020/02/20/3ecUBt.png)