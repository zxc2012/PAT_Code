#include<bits/stdc++.h>
using namespace std;
struct Node{long long son,mother;}x1,x2;
long long gcd(long long a,long long b){return b==0?a:gcd(b,a%b);}
void transfer(Node x){
    if(x.mother==0){printf("Inf");return;}
    if(x.mother<0){x.son=-x.son;x.mother=-x.mother;}
    if(x.son==0)x.mother=1;
    else{
        long long m=gcd(abs(x.son),abs(x.mother));
        x.son/=m;x.mother/=m;
    }
    if(x.son<0)printf("(");
    int t1=x.son/x.mother,t2=x.son%x.mother;
    if(t1!=0){printf("%d",t1);if(t2!=0)printf(" ");}
    if(t2!=0)printf("%d/%d",t1!=0?abs(t2):t2,x.mother);
    if(x.son<0)printf(")");
    if(t1==0&&t2==0)printf("0");
}
int main(){
    long long x,y,r,s;
    scanf("%lld/%lld %lld/%lld",&x,&y,&r,&s);
    x1={x,y};x2={r,s};
    long long t1=x*s+r*y,t2=y*s,t3=x*s-r*y,t4=x*r,t5=x*s,t6=y*r;
    transfer(x1);printf(" + ");transfer(x2);printf(" = ");transfer({t1,t2});printf("\n");
    transfer(x1);printf(" - ");transfer(x2);printf(" = ");transfer({t3,t2});printf("\n");
    transfer(x1);printf(" * ");transfer(x2);printf(" = ");transfer({t4,t2});printf("\n");
    transfer(x1);printf(" / ");transfer(x2);printf(" = ");transfer({t5,t6});            
    return 0;
}
