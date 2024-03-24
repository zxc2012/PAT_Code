#include<bits/stdc++.h>
using namespace std;
map<string,vector<int>> m;
vector<int> a;
bool cmp(int x,int y){
    return a[x]<a[y];
}
int main(){
    int n,M,i,j;
    cin>>n;
    int t;
    string str,temp;
    a.resize(n,0);
    for(i=0;i<n;++i){
        scanf("%d",&t);
        a[i]=t;
        getchar();
        for(j=0;j<2;++j){
            getline(cin,str);
            m[str].push_back(i);
        }
        getline(cin,str);
        for(j=0;j<str.size();++j){
            if(str[j]==' '){
                m[temp].push_back(i);
                temp.clear();
            }
            else temp+=str[j];
            if(j==str.size()-1){
                m[temp].push_back(i);
                temp.clear();
            }
        }
        getline(cin,str);
        m[str].push_back(i);
        getline(cin,str);
        m[str].push_back(i);
    }
    cin>>M;
    getchar();
    for(i=0;i<M;++i){
      getline(cin,str);
      cout<<str<<endl;
      str=str.substr(3);
      if(m.find(str)==m.end()){
            printf("Not Found\n");
      }
      else{
          sort(m[str].begin(),m[str].end(),cmp);
        for(auto it=m[str].begin();it!=m[str].end();++it){
            printf("%07d\n",a[*it]);
        }  
      }
    }
    return 0;
}