import matplotlib.pyplot as plt
import numpy as np
import random
class LossHistory:
    def __init__(self):
        self.color = {}
        self.color[0]='r'
        self.color[1]='g'
        self.color[2]='k'
        self.color[3]='m'
        self.text = {}
        self.text[0]='CNN-Net-DL'
        self.text[1]='CNN-Net-Dense'
        self.text[2]='CNN-Net-Res'       
                
    def draw_p(self, lists, label, type,num):
        plt.plot(range(len(lists)), lists, self.color[i], label=self.text[num])
        plt.ylabel(label)
        plt.xlabel('epoch')
        plt.title(type+label)
        plt.legend(loc="upper right")
        if label=='loss' and type =='train_batch':
            self.ax1=plt.gca()
        elif label=='acc' and type =='train_batch':
            self.ax2=plt.gca()
        elif label=='loss' and type =='val_batch':
            self.ax3=plt.gca()   
        else:
            self.ax4=plt.gca()    
        plt.savefig(type+'_'+label+'.jpg')
        
    #由于这里的绘图设置的是5s绘制一次，当训练结束后得到的图可能不是一个完整的训练过程（最后一次绘图结束，有训练了0-5秒的时间）
    #所以这里的方法会在整个训练结束以后调用
    def end_draw(self,input,num):
        if num ==0 :
            plt.figure()
        else:
            plt.sca(self.ax1)   # 将ax1置为当前axes
        self.draw_p(input[0], 'loss', 'train_batch',num)
        if num ==0 :
            plt.figure()
        else:
            plt.sca(self.ax2)   # 将ax1置为当前axes
        self.draw_p(input[1], 'acc', 'train_batch',num)
        if num ==0 :
            plt.figure()
        else:
            plt.sca(self.ax3)   # 将ax1置为当前axes
        self.draw_p(input[2], 'loss', 'val_batch',num)
        if num ==0 :
            plt.figure()
        else:
            plt.sca(self.ax4)   # 将ax1置为当前axes
        self.draw_p(input[3], 'acc', 'val_batch',num)
x = np.linspace(-1,1,50)#从(-1,1)均匀取50个点
logs_loss = LossHistory()
for i in range(3):
    y={}
    random.shuffle(x)
    y[0] = 2 / x
    y[1] = 8 / x
    y[2] = 3 /x
    y[3] = 5 / x
    logs_loss.end_draw(y,i)