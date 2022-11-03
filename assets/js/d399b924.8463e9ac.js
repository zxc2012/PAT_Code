"use strict";(self.webpackChunkChance=self.webpackChunkChance||[]).push([[7169],{5663:(n,e,t)=>{t.r(e),t.d(e,{assets:()=>l,contentTitle:()=>a,default:()=>o,frontMatter:()=>r,metadata:()=>s,toc:()=>m});var p=t(7462),i=(t(7294),t(3905));t(1839);const r={},a="5 Searching summary",s={unversionedId:"Algorithms/5",id:"Algorithms/5",title:"5 Searching summary",description:"DFS",source:"@site/docs/Algorithms/5.md",sourceDirName:"Algorithms",slug:"/Algorithms/5",permalink:"/docs/Algorithms/5",draft:!1,editUrl:"https://github.com/zxc2012/zxc2012.github.io/tree/master/docs/Algorithms/5.md",tags:[],version:"current",frontMatter:{},sidebar:"Algorithms",previous:{title:"4 Data Structure",permalink:"/docs/Algorithms/4"},next:{title:"6 Tree and Graph",permalink:"/docs/Algorithms/6"}},l={},m=[{value:"DFS",id:"dfs",level:2},{value:"BFS",id:"bfs",level:2}],u={toc:m};function o(n){let{components:e,...t}=n;return(0,i.kt)("wrapper",(0,p.Z)({},u,t,{components:e,mdxType:"MDXLayout"}),(0,i.kt)("h1",{id:"5-searching-summary"},"5 Searching summary"),(0,i.kt)("h2",{id:"dfs"},"DFS"),(0,i.kt)("p",null,"PAT1103\u6709\u4ee5\u4e0b\u51e0\u70b9\u4f53\u4f1a"),(0,i.kt)("p",null,(0,i.kt)("strong",{parentName:"p"},"1.\u5f00\u9500\u5927\u7684\u51fd\u6570\u53ef\u4ee5\u5efa\u8868")),(0,i.kt)("pre",null,(0,i.kt)("code",{parentName:"pre",className:"language-cpp"},"void init() {\n    int temp = 0, index = 1;\n    while (temp <= n) {\n        v.push_back(temp);\n        temp = pow(index, p);\n        index++;\n    }\n}\n")),(0,i.kt)("p",null,(0,i.kt)("strong",{parentName:"p"},"2.\u7ed3\u675f\u7684\u5199\u6cd5")),(0,i.kt)("p",null,"(1)\u6b63\u5e38\u5206\u5f00\u4e24\u79cd\u7ed3\u675f\uff0c\u4f7f\u7528return 0;"),(0,i.kt)("pre",null,(0,i.kt)("code",{parentName:"pre",className:"language-cpp"},'if (maxFacSum == -1) {\n    printf("Impossible");\n    return 0;\n}\nprintf("%d = ", n);\nfor (int i = 0; i < ans.size(); i++) {\n    if (i != 0) printf(" + ");\n    printf("%d^%d", ans[i], p);\n}\nreturn 0;\n')),(0,i.kt)("p",null,"(2)if else\u7ed3\u6784"),(0,i.kt)("pre",null,(0,i.kt)("code",{parentName:"pre",className:"language-cpp"},'if(!max_sum)\n    printf("Impossible");\nelse {\n    printf("%d = ", n);\n    for (i = 0; i < K-1; ++i)\n        printf("%d^%d + ", v[i],p);\n    printf("%d^%d", v[K-1], p);\n}\nreturn 0;\n')),(0,i.kt)("p",null,(0,i.kt)("strong",{parentName:"p"},"3.resize\u548creverse")),(0,i.kt)("admonition",{type:"tip"},(0,i.kt)("ul",{parentName:"admonition"},(0,i.kt)("li",{parentName:"ul"},"resize()\u4f1a\u6539\u53d8\u5f53\u524d\u5bb9\u5668\u7684\u201c\u5185\u5bb9\u201d(\u7a7a\u95f4\u5927\u5c0f\u548c\u5185\u5bb9\u503c\u90fd\u53ef\u88ab\u6539\u53d8) \u3002\u8be5\u51fd\u6570\u6709\u4e00\u6216\u4e24\u4e2a\u53c2\u6570\uff0c\u9ed8\u8ba4\u88650\u3002"),(0,i.kt)("li",{parentName:"ul"},"reverse()\u53ea\u4f1a\u6539\u53d8\u5f53\u524d\u5bb9\u5668\u7684\u201c\u5bb9\u91cf\u201d\u5927\u5c0f\u3002"),(0,i.kt)("li",{parentName:"ul"},"\u5f53resize\u6539\u53d8\u4e86size\u540e\uff0ccapacity\u4e5f\u53ef\u80fd\u88ab\u6539\u53d8\u3002\u4f46\u5f53reserve\u6539\u53d8\u4e86capacity\u540e\uff0csize\u5e76\u4e0d\u4f1a\u53d8\u5316"))),(0,i.kt)("p",null,(0,i.kt)("strong",{parentName:"p"},"4.\u5f15\u7528\u81ea\u300a\u7b97\u6cd5\u57fa\u7840\u5b9e\u8df5\u300b")),(0,i.kt)("p",null,"\u679a\u4e3e\u7684\u51e0\u4e2a\u8981\u70b9"),(0,i.kt)("p",null,"(1)\u641c\u7d22\u7ed3\u6784"),(0,i.kt)("ul",null,(0,i.kt)("li",{parentName:"ul"},(0,i.kt)("p",{parentName:"li"},"\u9012\u5f52\u7ed3\u6784"),(0,i.kt)("p",{parentName:"li"},"\u6700\u540e\u4e00\u5c42--\u526a\u679d\u5c42(\u524d2\u987a\u5e8f\u53ef\u6362)--\u9012\u5f52\u5c42"),(0,i.kt)("pre",{parentName:"li"},(0,i.kt)("code",{parentName:"pre",className:"language-cpp"},"void dfs(int num,int cur,int sum){\n    if (num>k) return;\n    if(num==k&&sum==n){\n        if(larger(temp, ans))\n            ans=temp;\n    }else if(num<k&&sum<n){\n        temp.push_back(cur);\n        dfs(num+1, cur, sum+(int)pow(cur, p));\n        temp.pop_back();\n        if(sum+(k-num)*pow(cur+1, p)<=n)\n            dfs(num, cur+1, sum);\n    }\n}\n"))),(0,i.kt)("li",{parentName:"ul"},(0,i.kt)("p",{parentName:"li"},"\u641c\u7d22\u7ed3\u6784"),(0,i.kt)("pre",{parentName:"li"},(0,i.kt)("code",{parentName:"pre",className:"language-cpp"},"void dfs(int n,int k,int p,int sum) {\n    for (int i = k<K?t[K-k-1]:lim; i>=1; --i) {\n        if(k>1) {\n            if(n-k+1>=pow(i,p)) {\n                t[K - k] = i;\n                dfs(n - pow(i, p), k - 1, p, sum + i);\n            }\n        }\n        if(k==1) {\n            if (n == pow(i, p)) {\n                t[K - 1] = i;\n                sum += i;\n                if(sum>max_sum) {\n                    max_sum = sum;\n                    v=t;\n                }\n                break;\n            } else if (n > pow(i, p))\n                break;\n        }\n    }\n}\n")))),(0,i.kt)("p",null,(0,i.kt)("strong",{parentName:"p"},"(2)\u641c\u7d22\u7684\u987a\u5e8f")),(0,i.kt)("p",null,"\u4e00\u822c\u5148\u8bd5\u9009\u62e9\u5c11\u7684\u6b65\u9aa4\uff0c\u540e\u8bd5\u9009\u62e9\u591a\u7684\u6b65\u9aa4"),(0,i.kt)("p",null,"eg:\u4e03\u5de7\u677f\u5148\u62fc\u5927\u5757"),(0,i.kt)("p",null,(0,i.kt)("strong",{parentName:"p"},"(3)\u526a\u679d\u4e0e\u72b6\u6001\u66f4\u65b0")),(0,i.kt)("p",null,"\u72b6\u6001\u66f4\u65b0:\u82e5\u53d8\u91cf\u4e0e\u6808\u7684\u56de\u9000\u6709\u5173\uff0c\u53ef\u5c06\u5176\u52a0\u5165\u5f62\u53c2\u800c\u4e0d\u662f\u5168\u5c40\u53d8\u91cf"),(0,i.kt)("pre",null,(0,i.kt)("code",{parentName:"pre",className:"language-cpp"},"sum += i;\n")),(0,i.kt)("p",null,"\u526a\u679d:\u53ef\u884c\u6027\u548c\u6700\u4f18\u6027\u526a\u679d"),(0,i.kt)("h2",{id:"bfs"},"BFS"),(0,i.kt)("p",null,"\u57fa\u672c\u7ed3\u6784"),(0,i.kt)("pre",null,(0,i.kt)("code",{parentName:"pre",className:"language-cpp"},"void bfs(){\n    \u8d77\u70b9\u5165\u5217\uff0c\u5df2\u8bbf\u95ee;\n    while(!\u975e\u7a7a){\n        \u53d6\u961f\u9996;\n        \u961f\u9996\u51fa\u961f;\n        \u961f\u9996\u5b69\u5b50\u7ed3\u70b9\u5165\u961f,\u5df2\u8bbf\u95ee;\n    }\n}\n")),(0,i.kt)("p",null,"PAT1091\u6709\u5982\u4e0b\u4f53\u4f1a"),(0,i.kt)("p",null,(0,i.kt)("strong",{parentName:"p"},"1.push\u548cpop\u5904\u7684\u5b89\u6392")),(0,i.kt)("p",null,"visit","[i][j]","[k]"," = 1;\u548csum++;\u7684\u4f4d\u7f6e\u9009\u53d6:"),(0,i.kt)("p",null,"\u7531\u4e8e\u6b64\u9898\u662f\u591a\u7c73\u8bfa\u9aa8\u724c\u5f0f\u8bbf\u95ee\uff0c\u82e5\u4e0d\u63d0\u524d\u7f6e1\u4f1a\u91cd\u590d\u8ba1\u6570(\u4e0d\u7136\u6ca1\u6709\u8d77\u5230\u641c\u7d22\u7684\u6548\u679c)\uff0c\u53ea\u8981\u4fdd\u8bc1\u4e86\u8fd9\u4e2a\u524d\u63d0\uff0csum++\u653e\u4e24\u4e2a\u5730\u65b9\u90fd\u884c"),(0,i.kt)("pre",null,(0,i.kt)("code",{parentName:"pre",className:"language-cpp"},"int bfs(int i,int j,int k)\n{\n    queue<Node> q;\n    Node temp;\n    int sum=0;\n    node = {i,j,k};\n    q.push(node);\n    visit[i][j][k] = 1;\n    while(!q.empty()){\n        temp=q.front();\n        q.pop();\n        sum++;\n        for (int r = 0;r<6; ++r){\n            node = {temp.i + l[r], temp.j + m[r], temp.k + n[r]};\n            if (node.i < 0 || node.j < 0 || node.k < 0 || node.i >= L || node.j >= M || node.k >= N || visit[node.i][node.j][node.k]||!sq[node.i][node.j][node.k])\n                continue;\n            else\n            {\n                q.push(node);\n                visit[node.i][node.j][node.k] = 1;\n            }\n        }\n\n    }\n    if(sum>=T)\n        return sum;\n    else\n        return 0;\n}\n")),(0,i.kt)("p",null,(0,i.kt)("strong",{parentName:"p"},"2.\u6ce8\u610ftemp\u7684\u8bbe\u7f6e\uff0c\u6bcf\u6b21for(6)\u5f97\u4fdd\u8bc1\u4e0d\u53d8")))}o.isMDXComponent=!0}}]);