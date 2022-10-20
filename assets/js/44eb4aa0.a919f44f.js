"use strict";(self.webpackChunkChance=self.webpackChunkChance||[]).push([[3420],{3905:(n,e,t)=>{t.d(e,{Zo:()=>p,kt:()=>d});var r=t(7294);function i(n,e,t){return e in n?Object.defineProperty(n,e,{value:t,enumerable:!0,configurable:!0,writable:!0}):n[e]=t,n}function s(n,e){var t=Object.keys(n);if(Object.getOwnPropertySymbols){var r=Object.getOwnPropertySymbols(n);e&&(r=r.filter((function(e){return Object.getOwnPropertyDescriptor(n,e).enumerable}))),t.push.apply(t,r)}return t}function o(n){for(var e=1;e<arguments.length;e++){var t=null!=arguments[e]?arguments[e]:{};e%2?s(Object(t),!0).forEach((function(e){i(n,e,t[e])})):Object.getOwnPropertyDescriptors?Object.defineProperties(n,Object.getOwnPropertyDescriptors(t)):s(Object(t)).forEach((function(e){Object.defineProperty(n,e,Object.getOwnPropertyDescriptor(t,e))}))}return n}function a(n,e){if(null==n)return{};var t,r,i=function(n,e){if(null==n)return{};var t,r,i={},s=Object.keys(n);for(r=0;r<s.length;r++)t=s[r],e.indexOf(t)>=0||(i[t]=n[t]);return i}(n,e);if(Object.getOwnPropertySymbols){var s=Object.getOwnPropertySymbols(n);for(r=0;r<s.length;r++)t=s[r],e.indexOf(t)>=0||Object.prototype.propertyIsEnumerable.call(n,t)&&(i[t]=n[t])}return i}var c=r.createContext({}),l=function(n){var e=r.useContext(c),t=e;return n&&(t="function"==typeof n?n(e):o(o({},e),n)),t},p=function(n){var e=l(n.components);return r.createElement(c.Provider,{value:e},n.children)},u={inlineCode:"code",wrapper:function(n){var e=n.children;return r.createElement(r.Fragment,{},e)}},f=r.forwardRef((function(n,e){var t=n.components,i=n.mdxType,s=n.originalType,c=n.parentName,p=a(n,["components","mdxType","originalType","parentName"]),f=l(t),d=i,m=f["".concat(c,".").concat(d)]||f[d]||u[d]||s;return t?r.createElement(m,o(o({ref:e},p),{},{components:t})):r.createElement(m,o({ref:e},p))}));function d(n,e){var t=arguments,i=e&&e.mdxType;if("string"==typeof n||i){var s=t.length,o=new Array(s);o[0]=f;var a={};for(var c in e)hasOwnProperty.call(e,c)&&(a[c]=e[c]);a.originalType=n,a.mdxType="string"==typeof n?n:i,o[1]=a;for(var l=2;l<s;l++)o[l]=t[l];return r.createElement.apply(null,o)}return r.createElement.apply(null,t)}f.displayName="MDXCreateElement"},8703:(n,e,t)=>{t.r(e),t.d(e,{assets:()=>c,contentTitle:()=>o,default:()=>u,frontMatter:()=>s,metadata:()=>a,toc:()=>l});var r=t(7462),i=(t(7294),t(3905));const s={},o="PAT1141 PAT Ranking of Institutions (25 \u5206)",a={unversionedId:"OJ/PAT1141",id:"OJ/PAT1141",title:"PAT1141 PAT Ranking of Institutions (25 \u5206)",description:"",source:"@site/docs/OJ/PAT1141.md",sourceDirName:"OJ",slug:"/OJ/PAT1141",permalink:"/docs/OJ/PAT1141",draft:!1,editUrl:"https://github.com/zxc2012/zxc2012.github.io/tree/master/docs/OJ/PAT1141.md",tags:[],version:"current",frontMatter:{},sidebar:"OJ",previous:{title:"PAT1123 Is It a Complete AVL Tree",permalink:"/docs/OJ/PAT1123"},next:{title:"POJ2456 Aggressive cows",permalink:"/docs/OJ/POJ2456"}},c={},l=[],p={toc:l};function u(n){let{components:e,...t}=n;return(0,i.kt)("wrapper",(0,r.Z)({},p,t,{components:e,mdxType:"MDXLayout"}),(0,i.kt)("h1",{id:"pat1141-pat-ranking-of-institutions-25-\u5206"},"PAT1141 PAT Ranking of Institutions (25 \u5206)"),(0,i.kt)("pre",null,(0,i.kt)("code",{parentName:"pre",className:"language-cpp"},"#include<bits/stdc++.h>\nusing namespace std;\nstruct Node{\n   string s;\n   float tws=0.0;\n   int ns=0;\n   int d;\n};\nvector<Node> v;\nmap<string,int> m;\nbool cmp(Node a,Node b){\n   if((int)a.tws!=(int)b.tws)return (int)a.tws>(int)b.tws;\n   else if(a.ns!=b.ns)return a.ns<b.ns;\n   else return a.s<b.s;\n}\nint main(){\n   int n,i,j,g;\n   char id[7],s[7];\n   scanf(\"%d\",&n);\n   for(i=0;i<n;++i){\n      getchar();\n      scanf(\"%s %d %s\",&id,&g,&s);\n      for(j=0;j<6;++j)s[j]=tolower(s[j]);\n      string ss=s;\n      if(m[ss]==0){\n         m[ss]=v.size()+1;\n         Node y;\n         y.s=ss;\n         if(id[0]=='B')y.tws+=g/1.5;\n         else if(id[0]=='A')y.tws+=g;\n         else y.tws+=g*1.5;\n         y.ns+=1;\n         v.push_back(y);\n      }\n      else{\n         if(id[0]=='B')v[m[ss]-1].tws+=g/1.5;\n         else if(id[0]=='A')v[m[ss]-1].tws+=g;\n         else v[m[ss]-1].tws+=g*1.5;\n         v[m[ss]-1].ns+=1;\n      }          \n   }\n   sort(v.begin(),v.end(),cmp);\n   printf(\"%d\\n\",v.size());\n   for(i=0;i<v.size();++i){\n      v[i].d=i+1;\n      if(i>0&&(int)v[i].tws==(int)v[i-1].tws)v[i].d=v[i-1].d;\n      printf(\"%d %s %d %d\\n\",v[i].d,v[i].s.c_str(),(int)v[i].tws,v[i].ns);\n   }\n   return 0; \n}\n")))}u.isMDXComponent=!0}}]);