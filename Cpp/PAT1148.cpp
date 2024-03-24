#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i,j,x,sum;
    string s;
    scanf("%d",&n);getchar();
    vector<int> say(n+1),fake(n+1),tr(n+1);
    for(i=1;i<=n;++i){
        getline(cin,s);fake[i]=stoi(s.substr(1));
        if(s[0]=='+')say[i]=fake[i];
        else say[i]=-fake[i];
    }
    for(i=1;i<n;++i){
        for(j=i+1;j<=n;++j){
            fill(tr.begin(),tr.end(),1);
            tr[i]=tr[j]=-1;
            x=1;sum=0;
            while(x<=n){if(say[x]!=fake[x]*tr[fake[x]])sum++;x++;}
            if(sum==2&&((say[i]!=fake[i]*tr[fake[i]])^(say[j]!=fake[j]*tr[fake[j]]))){
                printf("%d %d",i,j);
                return 0;
            }
        }
    }
    printf("No Solution");
    return 0;
}
