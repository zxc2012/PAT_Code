#include<bits/stdc++.h>
using namespace std;
#define num 30000
char a[num],b[num];   
int main(){
    while(~scanf("%s %s",a,b)){    
        vector<int>dp(strlen(b),0),last(strlen(b),0);
        for(int i=0;i<strlen(a);++i){
            for(int j=0;j<strlen(b);++j){
                if(a[i]==b[j])dp[j]=(j-1<0?0:last[j-1])+1;
                else dp[j]=max(j-1<0?0:dp[j-1],last[j]);
            }
            last=dp;
        }
        printf("%d\n",dp[strlen(b)-1]);
    }
    return 0;
}
