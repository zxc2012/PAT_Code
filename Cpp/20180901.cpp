#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
    int n,b;
    scanf("%d",&n);for(int i=0;i<n;++i)scanf("%d",&a[i+1]);
    for(int i=1;i<=n;++i){
        if(i==1||i==n)b=2;else b=3;
        printf("%d",(a[i-1]+a[i]+a[i+1])/b);
        if(i!=n)printf(" ");
    }
    return 0;
}
