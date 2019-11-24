#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,temp;
    cin>>n;
    temp=n;
    string s,ss;
    s=to_string(temp);
    while(temp!=6174&&temp!=0||temp==6174&&s=="6174"){
    	s=to_string(temp);
        while(s.size()<4)s="0"+s;
        sort(s.begin(),s.end());
        ss=s;
        int x=stoi(s);
        reverse(ss.begin(),ss.end());
        int y=stoi(ss);
        temp=y-x;
        string m=to_string(temp);
        while(m.size()<4)m="0"+m;
        printf("%s - %s = %s\n",ss.c_str(),s.c_str(),m.c_str());
    }
    return 0;
}
