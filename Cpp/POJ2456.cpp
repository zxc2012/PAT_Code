#include<bits/stdc++.h>
using namespace std;
int a[100000];
int m,c;//space
int f(int d){
    auto x=a;
    for(int i=1;i<c;++i){
        x=lower_bound(x,a+m,*x+d);
        if(x==a+m)return 0;
    }
    return 1;
}
int main(){
    while(~scanf("%d %d",&m,&c)){
        for(int i=0;i<m;++i)scanf("%d",&a[i]);
        sort(a,a+m);
        int l=1,r=*(a+m-1)-*a+1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(f(mid)==0)r=mid;
            else l=mid+1;
        }
        printf("%d\n",l-1);
    }
    return 0;
}
