#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i;
    double sum=0.0,m;
    cin>>n;
    for(i=0;i<n;++i){
        cin>>m;
        sum+=m*(n-i)*(i+1);
    }
    printf("%.2lf",sum);
    return 0;
}
