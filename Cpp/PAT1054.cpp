#include<bits/stdc++.h>
using namespace std;
int a[16777216]={0};
int main(){
    int m,n;
    int i,t,max=0,sq;
    cin>>m>>n;
    for(i=0;i<m*n;++i){
    scanf("%d",&t);
    a[t]+=1;
    if(a[t]>max){
        max=a[t]; 
        sq=t;
    } 
    }
    printf("%d",sq);
    return 0;
}
