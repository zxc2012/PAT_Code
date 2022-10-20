# Leetcode 93 Restore IP Addresses

[题目](https://leetcode-cn.com/problems/restore-ip-addresses/)

Given a string s containing only digits, return all possible valid IP addresses that can be obtained from s. You can return them in any order.

A valid IP address consists of exactly four integers, each integer is between 0 and 255, separated by single dots and cannot have leading zeros. For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses and "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses. 

```cpp
vector<string> restoreIpAddresses(string s) {
    int n=s.size();
    vector<string> ans;
    for(int a=1;a<=3;++a)for(int b=1;b<=3;++b)for(int c=1;c<=3;++c)
    for(int d=1;d<=4;++d){
        if(a+b+c+d==n){
            int A=stoi(s.substr(0,a));
            int B=stoi(s.substr(a,b));
            int C=stoi(s.substr(a+b,c));
            int D=stoi(s.substr(a+b+c,d));
            if(A<=255&&B<=255&&C<=255&&D<=255){
                string temp=to_string(A)+'.'+to_string(B)+'.'+to_string(C)+'.'+to_string(D);
                if(temp.size()==n+3)ans.push_back(temp);
            }
        }
    }
    return ans;
}
```