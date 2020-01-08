#include<algorithm>
#include<set>
using namespace std;
int dp[100][100],xp[100][100],c[100];
set<int>v;
int main(){
    int n,i,j,x,sum=0;scanf("%d\n",&n);
    for(i=n-1;i>=0;--i){
        scanf("%c %d",&c[i],&dp[i][i]);
        c[i+n]=c[i];xp[i][i]=xp[i+n][i+n]=dp[i+n][i+n]=dp[i][i];
        if(i!=0)getchar();
    }
    for(int z=1;z<n;++z)for(i=0;(j=i+z)<2*n;++i){
    	xp[i][j]=5000000;dp[i][j]=-5000000;
        for(int k=i;k<j;++k){
            if(c[k]=='t'){
                dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
                xp[i][j]=min(xp[i][j],xp[i][k]+xp[k+1][j]);
            }
            else{
                int y[5]={dp[i][j],dp[i][k]*dp[k+1][j],xp[i][k]*xp[k+1][j],dp[i][k]*xp[k+1][j],xp[i][k]*dp[k+1][j]};
                dp[i][j]=*max_element(y,y+5);y[0]=xp[i][j];
                xp[i][j]=*min_element(y,y+5);
            }
        }
    }
    for(i=0;i<n;++i){
        x=(i==0)?1:(n+1-i);
        if(dp[i][i+n-1]>sum){
            v.clear();v.insert(x);sum=dp[i][i+n-1];
        }
        else if(dp[i][i+n-1]==sum)v.insert(x);
    }
    printf("%d\n",sum);
    for(set<int>::iterator it=v.begin();it!=v.end();++it){
        if(it!=v.begin())printf(" ");
        printf("%d",*it);
    }
    return 0;
}
