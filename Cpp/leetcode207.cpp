#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int m=prerequisites.size(),x=0;
        vector<vector<int>>g(numCourses);
        vector<int>in(numCourses,0);
        for(auto &i:prerequisites){
            if(i[0]>=0&&i[1]>=0&&i[0]<numCourses&&i[1]<numCourses){
                g[i[1]].push_back(i[0]);
                in[i[0]]++;
            }
        }
        queue<int>q;
        for(int i=0;i<numCourses;++i)if(in[i]==0)q.push(i);
        while(!q.empty()){
            int u=q.front();
            q.pop();x++;
            for(auto& i:g[u])if(--in[i]==0)q.push(i);
        }
        return (x==numCourses);
    }
};
int main(){
    Solution s;
    int n,m,i;
    scanf("%d%d",&n,&m);
    vector<vector<int>>v(m,vector<int>(2));
    for(i=0;i<m;++i)scanf("%d%d",&v[i][0],&v[i][1]);
    printf("%d",s.canFinish(n,v));
    return 0;
}
