#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i,j,step=0,flag,x=0;
    cin>>n;
    vector<int> v[2];
    for(i=0;i<2;++i){
        v[i].resize(n);
        for(j=0;j<n;++j)
        scanf("%d",&v[i][j]);
    }
    i=0;
    while(i+1<n&&v[1][i]<=v[1][i+1])++i;
    if(v[1][i]>v[1][i+1]){
        step=i+1;
        i++;
    }
    while(i<n&&v[1][i]==v[0][i])++i;
    if(i==n){
        printf("Insertion Sort\n");
        sort(v[1].begin(),v[1].begin()+step+1);
        for(j=0;j<n;++j){
            printf("%d",v[1][j]);
            if(j!=n-1)printf(" ");
        }
    }
    else{
        printf("Merge Sort\n");flag=1;
        while(flag<=n){
            for(j=0;j<n;j+=flag)sort(v[0].begin()+j,v[0].begin()+min(j+flag,n));
            if(x==1)break;
            if(v[0]==v[1])x=1;
            flag*=2;
        }
        for(j=0;j<n;++j){
            printf("%d",v[0][j]);
            if(j!=n-1)printf(" ");
        }
    } 
    return 0;
}
