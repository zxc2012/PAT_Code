#include<bits/stdc++.h>
using namespace std;
int a[100000]={0}; 
int main(){
    int n,i,j,m,sum=0;
    cin>>n;
    for(i=0;i<n;++i){
        cin>>m;
        a[m]=i;
    }
    i=0;
    while(1){
        while(a[0]!=0){
            swap(a[0],a[a[0]]);
            sum++;
        }
        while(a[i]==i)i++;
        if(i==n)break;
        else{
            swap(a[0],a[i]);
            sum++;
		}       
    }
    printf("%d",sum);
    return 0;
}
