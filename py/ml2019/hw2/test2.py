import numpy as np
def norm_by_colum(X,s_colum=None,refer=0):
    '''
    X:输入矩阵,s_colum:列表,refer:{0:minimax,1:norm}
    '''
    if s_colum == None:
        s_colum=np.arange(np.size(X,1))
    leng=len(s_colum)
    if refer ==0:
        xm=np.min(X[:,s_colum],0).reshape(1,leng)
        xM=np.max(X[:,s_colum],0).reshape(1,leng)
        X[:,s_colum]=(X[:,s_colum]-xm)/(xM-xm)
    else :
        xm=np.mean(X[:,s_colum],0).reshape(1,leng)
        xd=np.std(X[:,s_colum],0).reshape(1,leng)##np.std/var
        X[:,s_colum]=(X[:,s_colum]-xm)/xd
    return X

def train_slice(X,portion=0.9):
    '''
    切片

    portion:train/(train+val)
    '''
    leng=np.size(X,0)
    t_len=int(leng*portion)
    x_train,x_val=X[:t_len,:],X[t_len:,:]
    return x_train,x_val

def sigmoid(x,w):
    '''
    求f=1/1+exp(-z)
    '''
    z=np.sum(w*x,1)
    z=z[:,np.newaxis]
    return 1/(1+np.exp(-z))
def update(feature,targets,steps,lr,scale=1):
    '''
    更新

    scale={1:BGD,0:mini-BGD}
    '''
    ## init
    n=np.size(targets,0)#sample
    if scale ==1:
        batch_size=n
    else:
        batch_size=500
    m=np.size(feature,1)#input_feature
    w=np.zeros(m)
    b=0
    b_diff=0
    beta=0.012
    w_diff=np.zeros(m)
    sig_x=sigmoid(feature,w)##更改
    print("sample:",n,"tait:",m)
    losses=[]
    for x in range(steps):
        loss=0
        h=int(n/batch_size)
        for idx in range(h):
            start=idx*batch_size
            end=min((idx+1)*batch_size,n)
            stp=0
            for i in range(m):
                for j in range(start,end):
                    w_diff[i] -= feature[j,i]*(targets[j]-b-sig_x[j])##更改
                    stp+=1
                w_diff[i] += beta*w[i]
                w_diff[i]/=stp
            for j in range(start,end):
                b_diff-=targets[j]-b-sig_x[j]##更改
            b_diff/=stp
            w_diff_2=np.sqrt(np.sum(w_diff*w_diff))
            b_diff_2=np.sqrt(np.sum(b_diff*b_diff))
            w-=lr*w_diff/w_diff_2
            b-=lr*b_diff
        loss=np.sum(np.square(targets-b-sig_x[j]))+beta*np.sum(w*w)
        loss/=n
        losses.append(loss)
        ## count loss
        if x%20==0:##steps_per_period
            print("after {} epochs,Loss is".format(x),loss)
    ## plot
    plt.figure()
    plt.plot(losses)
    plt.xlabel("periods")
    plt.ylabel("Loss")
    plt.title("learing rate:{} beta:{}".format(lr,beta))

if __name__ == "__main__":
    ## Load and slice
    x_train= np.loadtxt('E:/Git_Code/py/ml2019/hw2/X_train',delimiter=',',skiprows=1)
    y_train=np.loadtxt('E:/Git_Code/py/ml2019/hw2/Y_train',delimiter=',',skiprows=1)
    y_train=y_train[:,np.newaxis]

    x_train=norm_by_colum(x_train,s_colum=[0,1,3,4,5],refer=1)

    x_train,x_val=train_slice(x_train,portion=0.88)
    y_train,y_val=train_slice(y_train,portion=0.88)
    ## update
    update(x_train,y_train,200,lr=0.01)
