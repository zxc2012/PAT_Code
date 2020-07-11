#include<bits/stdc++.h>
using namespace std;
char a[50000];
void reverse(int s,int e){
    int half=(s+e)/2;
    for(int i=s;i<=half;++i){
        int temp=a[i];
        a[i]=a[e+s-i];
        a[e+s-i]=temp;
    }
}
int main(){
    int n,k;
    scanf("%d%d",&n,&k);getchar();
    for(int i=0;i<n;++i)scanf("%c",&a[i]);
    reverse(0,k-1);
    reverse(k,n-1);
    reverse(0,n-1);
    for(int i=0;i<n;++i)printf("%c",a[i]);
    return 0;
}
