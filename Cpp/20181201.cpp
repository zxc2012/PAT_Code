#include<bits/stdc++.h>
using namespace std;
int main(){
    int r,y,g,n,s=0;
    scanf("%d%d%d",&r,&y,&g);scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d%d",&y,&g);
        if(y!=3)s+=g;
        if(y==2)s+=r;
    }
    printf("%d",s);
    return 0;
}