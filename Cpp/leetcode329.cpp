#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int i,j,sum=0;
        m=matrix.size();if(m!=0)n=matrix[0].size();
        vector<vector<int>>sol(m,vector<int>(n,0));
        for(i=0;i<m;++i){
            for(j=0;j<n;++j){
                int flag=0;
                for(int r=0;r<4;++r){
                    if(i+dm[r]<0||i+dm[r]>m-1||j+dn[r]<0||j+dn[r]>n-1)continue;
                    if(matrix[i+dm[r]][j+dn[r]]<matrix[i][j]){flag=1;break;}
                }
                if(flag==0)sum=max(sum,dfs(i,j,matrix,sol));
            }    
        }
        return sum; 
    }
private:
    int dm[4]={0,0,1,-1},dn[4]={1,-1,0,0},m,n;
    int dfs(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& sol){
        if(sol[i][j]!=0)return sol[i][j];
        int x=0;
        for(int r=0;r<4;++r){
            if(i+dm[r]<0||i+dm[r]>m-1||j+dn[r]<0||j+dn[r]>n-1)continue;
            if(matrix[i+dm[r]][j+dn[r]]>matrix[i][j])x=max(x,dfs(i+dm[r],j+dn[r],matrix,sol));
        }
        return sol[i][j]=x+1;
    }
};
int main(){
    Solution s;
    int a[3][3]={3,4,5,3,2,6,2,2,1};
    vector<vector<int>>v(3);
    for(int i=0;i<3;++i)
    for(int j=0;j<3;++j)v[i].push_back(a[i][j]);
    cout<<"\n"<<s.longestIncreasingPath(v);
    return 0;
}
