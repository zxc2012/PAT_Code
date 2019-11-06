#include<bits/stdc++.h>
using namespace std;
map<string,int>m;
int main(){
    char c;
    string s,ss;
    int max=0;
    while(scanf("%c",&c)){
        if(c<48||(c>'9'&&c<65)||(c>'Z'&&c<97)||c>'z')
        {
            if(s.size()!=0){
                  m[s]++;
                if(m[s]>max){
                    max=m[s];
                    ss=s;
                    //cout<<ss<<max<<endl;
                }
                else if(m[s]==max){
                	string temp=s;
                    if(s<ss){
                    	temp=ss;
                    	ss=s;
					}
                    //cout<<"small"<<ss<<"big"<<temp<<endl;
                }
                s.clear();
            }
            if(c=='\n')break;//检查条件的逻辑顺序
        }
        else{
            if(c>=65&&c<97)c+=32;
            s.insert(s.end(),c);
        }
    }
    cout<<ss<<" "<<max;
    return 0;
}
