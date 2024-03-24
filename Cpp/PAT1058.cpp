#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[3],b[3],c;
    scanf("%d.%d.%d %d.%d.%d",&a[2],&a[1],&a[0],&b[2],&b[1],&b[0]);
    a[0]+=b[0];
    c=a[0]/29;
    a[0]%=29;
    a[1]+=b[1]+c;
    c=a[1]/17;
    a[1]%=17;
    a[2]+=b[2]+c;
    printf("%d.%d.%d",a[2],a[1],a[0]);
    return 0;
}
