#include <bits/stdc++.h>
using namespace std;
int m[6] = {0,0,0,0,1,-1};
int n[6] = {0,0,1,-1,0,0};
int l[6] = {1,-1,0,0,0,0};
int M, N, L, T;
int visit[60][1286][128]={0};
int sq[60][1286][128] = {0};
struct Node
{
    int i;
    int j;
    int k;
} node;
int bfs(int i,int j,int k)
{
    queue<Node> q;
    Node temp;
    int sum=0;
    node = {i,j,k};
    q.push(node);
    visit[i][j][k] = 1;
    while(!q.empty()){
        temp=q.front();
        q.pop();
        sum++;
        for (int r = 0;r<6; ++r){
            node = {temp.i + l[r], temp.j + m[r], temp.k + n[r]};
            if (node.i < 0 || node.j < 0 || node.k < 0 || node.i >= L || node.j >= M || node.k >= N || visit[node.i][node.j][node.k]||!sq[node.i][node.j][node.k])
                continue;
            else
            {
                q.push(node);
                visit[node.i][node.j][node.k] = 1;
            }
        }
    }
    printf("%d\n",sum);
    if(sum>=T)
        return sum;
    else
        return 0;
}
int main(){
    int i,j,k;
    int total=0;
    scanf("%d%d%d%d",&M,&N,&L,&T);
    for (i = 0;i<L; ++i)
        for (j = 0; j < M; ++j)
            for (k = 0; k < N; ++k)
                scanf("%d",&sq[i][j][k]);
    for (i = 0; i < L; ++i)
        for (j = 0; j < M; ++j)
            for (k = 0; k < N; ++k)
            if(!visit[i][j][k]&&sq[i][j][k])
                total += bfs(i, j, k);
    printf("%d", total);
    return 0;
}
