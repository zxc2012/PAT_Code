#include<bits/stdc++.h>
using namespace std;
int dp[3];
int main(){
	dp[1]=dp[2]=1;
	int n;
	scanf("%d",&n);
	for(int i=3;i<=n;i+=2){
		dp[1]=dp[1]+dp[2];
		dp[2]=dp[1]+dp[2];
	}
	int s=n%2==0?dp[2]:dp[1];
	printf("%d\n",s);
}
