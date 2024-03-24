#include<bits/stdc++.h>
using namespace std;
struct Node{
    int x,y;
}node[50];
int dp[50][50];
inline int S(Node& i,Node& k,Node& j){return abs(k.y*j.x-i.y*j.x-k.y*i.x-k.x*j.y+i.x*j.y+k.x*i.y);}
bool check(int &i,int &k,int &j,int &m){
    for(int r=0;r<m;++r)if(r==i||r==k||r==j)continue;
    else if(S(node[i],node[k],node[r])+S(node[i],node[j],node[r])+S(node[k],node[j],node[r])==S(node[i],node[j],node[k]))return 0;
    return 1;
}
int main(){
    int n,i,j,m,k;scanf("%d",&n);
    for(int sq=0;sq<n;++sq){
        scanf("%d",&m);
        for(i=0;i<m;++i)scanf("%d%d",&node[i].x,&node[i].y);
        for(int z=2;z<m;++z)for(i=0;(j=i+z)<m;++i){
        	dp[i][j]=70000000;
        	for(k=i+1;k<j;++k){
                if(!check(i,j,k,m))continue;
	            int t[3]={dp[i][k],dp[k][j],S(node[i],node[k],node[j])};
	            dp[i][j]=min(dp[i][j],*max_element(t,t+3));
        	}
		}
        printf("%.1f\n",dp[0][m-1]/2.0);
    }
    return 0;
}