#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int h,w=0,mode=0;
    void solve(vector<vector<char>>& board) {
        int i,j;
        h=board.size();if(h>0)w=board[0].size();
        vector<vector<int>>visit(h,vector<int>(w,0));
        for(i=0;i<w;++i)if(!visit[0][i]&&board[0][i]=='O')dfs(0,i,board,visit);
        for(i=0;i<h;++i)if(!visit[i][0]&&board[i][0]=='O')dfs(i,0,board,visit);
        for(i=0;i<w;++i)if(!visit[h-1][i]&&board[h-1][i]=='O')dfs(h-1,i,board,visit);
        for(i=0;i<h;++i)if(!visit[i][w-1]&&board[i][w-1]=='O')dfs(i,w-1,board,visit);
        mode=1;
        for(i=1;i<h-1;++i){
            for(j=1;j<w-1;++j)
            if(!visit[i][j]&&board[i][j]=='O')dfs(i,j,board,visit);
        }
    }
    void dfs(int x,int y,vector<vector<char>>& board,vector<vector<int>>& visit){
        int a[4]={1,-1,0,0},b[4]={0,0,1,-1},i;
        if(mode==1)board[x][y]='X';visit[x][y]=1;
        for(i=0;i<4;++i){
            if(x+a[i]>=h-1||x+a[i]<=0||y+b[i]>=w-1||y+b[i]<=0)continue;
            if(!visit[x+a[i]][y+b[i]]&&board[x+a[i]][y+b[i]]=='O')
            dfs(x+a[i],y+b[i],board,visit);
        }
    }
};
int main(){
    Solution s;
    vector<vector<char>> v(4,vector<char>(6));
    int i,j;
    for(i=0;i<4;++i){
        for(j=0;j<6;++j){
            scanf("%c",&v[i][j]);
            if(i!=3||j!=5)getchar();
        }
    }
    s.solve(v);
    for(i=0;i<4;++i){
        for(j=0;j<6;++j){
            printf("%c",v[i][j]);
            if(j!=5)printf(" ");
        }
        printf("\n");
    }
    return 0;
}
