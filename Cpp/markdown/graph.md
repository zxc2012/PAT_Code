## 图
1.数连通分量(并查集)

法1:每次dfs前判断visit[i]==0;
法2:数根结点father[v]==v;

2.有关是对边dfs还是点dfs
PAT1034问题每个点至少有一个连线，故可以对边搜
PAT1021可能存在孤立点

3.set vs vector
注意剔除重复点时要用set(往往隐含)

4.dfs结构总结
```cpp
void dfs(int x){
    temp.push_back(x);
    if (pre[x][0] == -1){
        ......
    }
    for(int i=0;i<pre[x].size();i++){
        dfs(pre[x][i]);
    }
    temp.pop_back();
}
```