#include<bits/stdc++.h>
using namespace std;
struct Node{
    int son,mother;
};
long long gcd(long long a,long long b){return b==0?a:gcd(b,a%b);}
Node add(Node a,Node b){
    Node x;int frac;
    long long son=a.son*b.mother+a.mother*b.son;
    long long mother=a.mother*b.mother;
    if(mother<0){son=-son;mother=-mother;}
    if(son==0){mother=1;frac=1;}
    else frac=find(abs(son),abs(mother));
    x.son=son/frac;x.mother=mother/frac;
    return x;
}
int main(){
    int n,x,y;cin>>n;
    Node temp={0,1};
    for(int i=0;i<n;++i){
        if(i!=n-1)scanf("%d/%d ",&x,&y);
        else scanf("%d/%d",&x,&y);
        Node m={x,y};
        temp=add(temp,m);
    }
    x=temp.son/temp.mother;y=temp.son%temp.mother;
    if(x!=0){
        printf("%d",x);
        if(y!=0)printf(" ");
    }
    if(y!=0)
    printf("%d/%d",y,temp.mother);
    if(x==0&&y==0)printf("0");
    return 0;
}
