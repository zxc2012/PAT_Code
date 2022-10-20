"use strict";(self.webpackChunkChance=self.webpackChunkChance||[]).push([[7628],{3905:(e,t,r)=>{r.d(t,{Zo:()=>l,kt:()=>f});var n=r(7294);function o(e,t,r){return t in e?Object.defineProperty(e,t,{value:r,enumerable:!0,configurable:!0,writable:!0}):e[t]=r,e}function s(e,t){var r=Object.keys(e);if(Object.getOwnPropertySymbols){var n=Object.getOwnPropertySymbols(e);t&&(n=n.filter((function(t){return Object.getOwnPropertyDescriptor(e,t).enumerable}))),r.push.apply(r,n)}return r}function a(e){for(var t=1;t<arguments.length;t++){var r=null!=arguments[t]?arguments[t]:{};t%2?s(Object(r),!0).forEach((function(t){o(e,t,r[t])})):Object.getOwnPropertyDescriptors?Object.defineProperties(e,Object.getOwnPropertyDescriptors(r)):s(Object(r)).forEach((function(t){Object.defineProperty(e,t,Object.getOwnPropertyDescriptor(r,t))}))}return e}function i(e,t){if(null==e)return{};var r,n,o=function(e,t){if(null==e)return{};var r,n,o={},s=Object.keys(e);for(n=0;n<s.length;n++)r=s[n],t.indexOf(r)>=0||(o[r]=e[r]);return o}(e,t);if(Object.getOwnPropertySymbols){var s=Object.getOwnPropertySymbols(e);for(n=0;n<s.length;n++)r=s[n],t.indexOf(r)>=0||Object.prototype.propertyIsEnumerable.call(e,r)&&(o[r]=e[r])}return o}var c=n.createContext({}),d=function(e){var t=n.useContext(c),r=t;return e&&(r="function"==typeof e?e(t):a(a({},t),e)),r},l=function(e){var t=d(e.components);return n.createElement(c.Provider,{value:t},e.children)},p={inlineCode:"code",wrapper:function(e){var t=e.children;return n.createElement(n.Fragment,{},t)}},u=n.forwardRef((function(e,t){var r=e.components,o=e.mdxType,s=e.originalType,c=e.parentName,l=i(e,["components","mdxType","originalType","parentName"]),u=d(r),f=o,m=u["".concat(c,".").concat(f)]||u[f]||p[f]||s;return r?n.createElement(m,a(a({ref:t},l),{},{components:r})):n.createElement(m,a({ref:t},l))}));function f(e,t){var r=arguments,o=t&&t.mdxType;if("string"==typeof e||o){var s=r.length,a=new Array(s);a[0]=u;var i={};for(var c in t)hasOwnProperty.call(t,c)&&(i[c]=t[c]);i.originalType=e,i.mdxType="string"==typeof e?e:o,a[1]=i;for(var d=2;d<s;d++)a[d]=r[d];return n.createElement.apply(null,a)}return n.createElement.apply(null,r)}u.displayName="MDXCreateElement"},1300:(e,t,r)=>{r.r(t),r.d(t,{assets:()=>c,contentTitle:()=>a,default:()=>p,frontMatter:()=>s,metadata:()=>i,toc:()=>d});var n=r(7462),o=(r(7294),r(3905));const s={},a="Leetcode 93 Restore IP Addresses",i={unversionedId:"OJ/Leetcode93",id:"OJ/Leetcode93",title:"Leetcode 93 Restore IP Addresses",description:"\u9898\u76ee",source:"@site/docs/OJ/Leetcode93.md",sourceDirName:"OJ",slug:"/OJ/Leetcode93",permalink:"/docs/OJ/Leetcode93",draft:!1,editUrl:"https://github.com/zxc2012/zxc2012.github.io/tree/master/docs/OJ/Leetcode93.md",tags:[],version:"current",frontMatter:{},sidebar:"OJ",previous:{title:"Leetcode4",permalink:"/docs/OJ/Leetcode4"},next:{title:"PAT1123 Is It a Complete AVL Tree",permalink:"/docs/OJ/PAT1123"}},c={},d=[],l={toc:d};function p(e){let{components:t,...r}=e;return(0,o.kt)("wrapper",(0,n.Z)({},l,r,{components:t,mdxType:"MDXLayout"}),(0,o.kt)("h1",{id:"leetcode-93-restore-ip-addresses"},"Leetcode 93 Restore IP Addresses"),(0,o.kt)("p",null,(0,o.kt)("a",{parentName:"p",href:"https://leetcode-cn.com/problems/restore-ip-addresses/"},"\u9898\u76ee")),(0,o.kt)("p",null,"Given a string s containing only digits, return all possible valid IP addresses that can be obtained from s. You can return them in any order."),(0,o.kt)("p",null,'A valid IP address consists of exactly four integers, each integer is between 0 and 255, separated by single dots and cannot have leading zeros. For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses and "0.011.255.245", "192.168.1.312" and "',(0,o.kt)("a",{parentName:"p",href:"mailto:192.168@1.1"},"192.168@1.1"),'" are invalid IP addresses.\xa0'),(0,o.kt)("pre",null,(0,o.kt)("code",{parentName:"pre",className:"language-cpp"},"vector<string> restoreIpAddresses(string s) {\n    int n=s.size();\n    vector<string> ans;\n    for(int a=1;a<=3;++a)for(int b=1;b<=3;++b)for(int c=1;c<=3;++c)\n    for(int d=1;d<=4;++d){\n        if(a+b+c+d==n){\n            int A=stoi(s.substr(0,a));\n            int B=stoi(s.substr(a,b));\n            int C=stoi(s.substr(a+b,c));\n            int D=stoi(s.substr(a+b+c,d));\n            if(A<=255&&B<=255&&C<=255&&D<=255){\n                string temp=to_string(A)+'.'+to_string(B)+'.'+to_string(C)+'.'+to_string(D);\n                if(temp.size()==n+3)ans.push_back(temp);\n            }\n        }\n    }\n    return ans;\n}\n")))}p.isMDXComponent=!0}}]);