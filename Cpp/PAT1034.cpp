#include <bits/stdc++.h>
using namespace std;
const int M = 26 * 26 * 26;
vector<int> node,g[M];//edge
vector<int> w(M, 0), visit(M, 0); //point
map<string, int> ot;
int head,number,sum;
int str2num(char *a)
{
    return 26 * 26 * (a[0]-'A') + 26 * (a[1]-'A') + (a[2]-'A');
}
string num2str(int num){
    string a(3,0);
    a[0] = num / (26 * 26)+'A';
    a[1] = num / 26 % 26 + 'A';
    a[2] = num % 26 + 'A';
    return a;
}
void dfs(int start){
    visit[start] = 1;
    number++;
    sum += w[start];
    if(w[start]>w[head])
        head = start;
    //printf("\n%s %d %d", num2str(head).c_str(), number, w[head]);
    for (int i = 0;i<g[start].size(); ++i)
    if(!visit[g[start][i]])
        dfs(g[start][i]);
}
int main(){
    int n, k,i,m;
    char c1[3], c2[3];
    scanf("%d%d\n",&n,&k);
    node.resize(n);
    for (i = 0;i<n; ++i)
    {
        if(i==n-1)
            scanf("%c%c%c %c%c%c %d", &c1[0], &c1[1], &c1[2], &c2[0], &c2[1], &c2[2], &m);
        else
        scanf("%c%c%c %c%c%c %d\n", &c1[0], &c1[1], &c1[2], &c2[0], &c2[1], &c2[2], &m);
        int d1 = str2num(c1);
        int d2 = str2num(c2);
        w[d1] += m;
        w[d2] += m;
        g[d1].push_back(d2);
        g[d2].push_back(d1);
        node[i]=d1;
    }
    for (i = 0; i < node.size(); ++i){
        head = node[i];
        number = 0;
        sum = 0;
        dfs(node[i]);
        if(number>2&&sum>2*k)
            ot[num2str(head)] = number;
    }
    printf("%d\n",ot.size());
    for (auto it = ot.begin();it!=ot.end(); ++it)
        printf("%s %d\n",it->first.c_str(),it->second);
        return 0;
}