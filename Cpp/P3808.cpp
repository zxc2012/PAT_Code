#include<bits/stdc++.h>
using namespace std;
char s1[1000000],s2[1000000];
int nxt[1000000]={0};
int main(){
    int i,j=-1;
    scanf("%s",s1);int a=strlen(s1);
    scanf("%s",s2);int b=strlen(s2);
    nxt[0]=-1;
    for(i=1;i<b;++i){
        while(j!=-1&&s2[j+1]!=s2[i])j=nxt[j];
        if(s2[j+1]==s2[i])++j;
        nxt[i]=j;
    }j=-1;
    for(i=0;i<a;++i){
        while(j!=-1&&s2[j+1]!=s1[i])j=nxt[j];
        if(s2[j+1]==s1[i])++j;
        if(j==b-1)printf("%d\n",i-b+2);
    }
    for(i=0;i<b;++i){
        printf("%d",nxt[i]+1);
        if(i!=b-1)printf(" ");
    }
    return 0;
}
