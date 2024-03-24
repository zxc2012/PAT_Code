#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in(numCourses);vector<int> ot;
        vector<vector<int>> g(numCourses);
        for(auto &p:prerequisites){
            g[p[1]].push_back(p[0]);
            in[p[0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;++i)if(in[i]==0)q.push(i);
        while(!q.empty()){
            int x=q.front();
            q.pop();ot.push_back(x);
            for(auto &p:g[x])if(--in[p]==0)q.push(p);
        }
        if(ot.size()!=numCourses)ot.clear();
        return ot;
    }
};
int main(){
    Solution s;
    int n,m;
    scanf("%d%d",&n,&m);
    vector<vector<int>> v(m,vector<int>(2));
    vector<int> r;
    for(int i=0;i<m;++i)scanf("%d%d",&v[i][0],&v[i][1]);
    r=s.findOrder(n,v);
    for(auto &p:r)printf("%d",p);
    return 0;
}
