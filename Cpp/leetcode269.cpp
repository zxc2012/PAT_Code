#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string alienOrder(vector<string> &words) {
        unordered_map<char,vector<char>> mp;unordered_map<char,int> in;
        unordered_set<char> dic;
        string temp;
        for(int i=0;i<words.size();++i){
            string p=words[i];int j=0;
            dic.insert(words[i].begin(),words[i].end());
            if(i!=0){
                while(p[j]==temp[j])++j;
                mp[temp[j]].push_back(p[j]);
                in[p[j]]++;
            }
            temp=p;
        }
        for(auto &p:dic)in[p]++;
        priority_queue<char,vector<char>,greater<char>>q;temp="";
        for(char i='a';i<='z';++i)if(in[i]==1)q.push(i);
        while(!q.empty()){
            char x=q.top();
            q.pop();temp+=x;
            for(auto &p:mp[x])if(--in[p]==1)q.push(p);
        }
        if(temp.size()!=dic.size())temp="";
        return temp;
    }
};
int main(){
    Solution s;
    vector<string> r={"zy","zx"};
    cout<<"\n"<<s.alienOrder(r);
}
