## 单模匹配--KMP
定义两个字符串text和pattern,pattern不断位移的过程中,需要让其中间断掉的时候剪枝

Eg:*ABAABAB*
### 建next数组-->最长相等前后缀[0...k] [i-k...i]
i:0->pattern.length()-1,j=-1
- case1:p[j+1]=p[i]-->j++;
- case2:上一个元素内拆前后缀
while(j!=-1&&p[i]!=p[j+1])j=next[j];
p[j+1]=p[i]-->j++;

`状态转移:next[i]=j;`

### 移位匹配
i:0->text.length()-1,j=-1
- case1:p[j+1]=t[i]-->j++;
- case2:上一个元素内拆前后缀
while(j!=-1&&t[i]!=p[j+1])j=next[j];
p[j+1]=t[i]-->j++;

判断：j==m-1-->return true

### 代码模板
```cpp
scanf("%s%s",s1,s2);int a=strlen(s1);//text
int b=strlen(s2);//pattern
nxt[0]=-1;
for(i=1;i<b;++i){
    while(j!=-1&&s2[j+1]!=s2[i])j=nxt[j];
    if(s2[j+1]==s2[i])++j;
    nxt[i]=j;
}j=-1;
for(i=0;i<a;++i){
    while(j!=-1&&s2[j+1]!=s1[i])j=nxt[j];
    if(s2[j+1]==s1[i])++j;
    if(j==b-1)printf("%d\n",i-b+2);
}
```
## 多模匹配--AC自动机
定义text和pattern,pattern1在某位fail时可以从该位fail想办法剪枝

### 建fail数组
根据fail来源建表顺序可以是BFS,指向为了进行下一个模板,fail为了记录跳转的起点

每取一个u,i:26capital
- case1:e[u][i]!=0`回到0或者上一个fail下面p`
#### fail[e[u][i]]=e[fail[u]][i];
- case2:e[u][i]=0指向上一个fail下面p
#### e[u][i]=e[fail[u]][i];

### 插入trie
i:pattern,j=0
- case1:e[j][i]=0->e[j][i]=++cnt(总序号);
- case2:e[j][i]!=0

判断:val[pattern.length()-1]=1;

`状态转移:j=e[j][i]`

### query

是否允许串重复出现-->是否设置val[]=-1

i:text

去重处理t=j,while(t)fail[t]=-1,t=fail[t];
- case1:val[j]!=-1->sum+=val[j];
- case2:val[j]=-1

`状态转移:j=e[j][i]`

### 代码
```cpp
struct AC{
    int fail[500010],val[500010],e[500010][26],cnt=0;
    void ins(char* p){
        int len=strlen(p);int j=0;
        for(int i=0;i<len;++i){
            int x=p[i]-'a';
            if(e[j][x]==0)e[j][x]=++cnt;
            j=e[j][x];
        }
        val[j]++;
    }
    void build(){
        for(int i=0;i<26;++i)if(e[0][i])fail[e[0][i]]=0,q.push(e[0][i]);
        while(!q.empty()){
            int u=q.front();q.pop();
            for(int i=0;i<26;++i)
	            if(e[u][i])fail[e[u][i]]=e[fail[u]][i],q.push(e[u][i]);
	            else e[u][i]=e[fail[u]][i];
        }
    }
    int query(char* p){
        int len=strlen(p),j=0,sum=0;
        for(int i=0;i<len;++i){
            int x=p[i]-'a';j=e[j][x];int t=j;
            while(t&&val[t]!=-1)sum+=val[t],val[t]=-1,t=fail[t];
        }
        return sum;
    }
}at;
```