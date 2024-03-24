#include<bits/stdc++.h>
using namespace std;
vector<int> pre, in, v;
void dfs(int prel,int prer,int inl,int inr){
    if(inl==inr&&prel!=0){
        printf("%d ",pre[prel]);
        return;
    }
    int i;
    for (i = inl;i<=inr; ++i)
    if(in[i]==pre[prel])
        break;
    if(i-1>=inl)
        dfs(prel+1,i-inl+prel,inl,i-1);
    if(i+1<=inr)
        dfs(i-inl+prel+1,prer,i+1,inr);
    if (prel==0)
        printf("%d", pre[prel]);
    else 
        printf("%d ", pre[prel]);
}
int main(){
    int n,i,num;
    char c[4] = "";
	scanf("%d",&n);//number
    for (i = 0; i < 2 * n;++i){
    	if(i==2*n-1)
    	        scanf("%s", &c);
    	else 
        scanf("%s ", &c);
        if(c[1]=='u'){
            scanf("%d", &num);
            pre.push_back(num);
            v.push_back(num);
        }
        else if (c[1] == 'o')
        {
            num = v.back();
            v.pop_back();
            in.push_back(num);
        }
    }
    dfs(0,n-1,0,n-1);
    return 0;
}
