#include<bits/stdc++.h>
using namespace std;
bool isprime(int a){
    if(a<2)return 0;
    else{
        for(int i=2;i<=sqrt(a);++i){
            if(a%i==0)return 0;
        }
    }
    return 1;
}
int main(){
    int n,i;
    scanf("%d",&n);
    if(isprime(n)&&isprime(n-6))printf("Yes\n%d",n-6);
    else if(isprime(n)&&isprime(n+6))printf("Yes\n%d",n+6);
    else{
        printf("No\n");i=1;
        while(!(isprime(n+i)&&(isprime(n+6+i)||isprime(n+i-6))))++i;
        printf("%d",n+i);
    } 
    return 0;
}