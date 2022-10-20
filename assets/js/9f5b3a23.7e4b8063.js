"use strict";(self.webpackChunkChance=self.webpackChunkChance||[]).push([[915],{3905:(e,t,n)=>{n.d(t,{Zo:()=>c,kt:()=>p});var r=n(7294);function o(e,t,n){return t in e?Object.defineProperty(e,t,{value:n,enumerable:!0,configurable:!0,writable:!0}):e[t]=n,e}function i(e,t){var n=Object.keys(e);if(Object.getOwnPropertySymbols){var r=Object.getOwnPropertySymbols(e);t&&(r=r.filter((function(t){return Object.getOwnPropertyDescriptor(e,t).enumerable}))),n.push.apply(n,r)}return n}function a(e){for(var t=1;t<arguments.length;t++){var n=null!=arguments[t]?arguments[t]:{};t%2?i(Object(n),!0).forEach((function(t){o(e,t,n[t])})):Object.getOwnPropertyDescriptors?Object.defineProperties(e,Object.getOwnPropertyDescriptors(n)):i(Object(n)).forEach((function(t){Object.defineProperty(e,t,Object.getOwnPropertyDescriptor(n,t))}))}return e}function u(e,t){if(null==e)return{};var n,r,o=function(e,t){if(null==e)return{};var n,r,o={},i=Object.keys(e);for(r=0;r<i.length;r++)n=i[r],t.indexOf(n)>=0||(o[n]=e[n]);return o}(e,t);if(Object.getOwnPropertySymbols){var i=Object.getOwnPropertySymbols(e);for(r=0;r<i.length;r++)n=i[r],t.indexOf(n)>=0||Object.prototype.propertyIsEnumerable.call(e,n)&&(o[n]=e[n])}return o}var s=r.createContext({}),l=function(e){var t=r.useContext(s),n=t;return e&&(n="function"==typeof e?e(t):a(a({},t),e)),n},c=function(e){var t=l(e.components);return r.createElement(s.Provider,{value:t},e.children)},m={inlineCode:"code",wrapper:function(e){var t=e.children;return r.createElement(r.Fragment,{},t)}},d=r.forwardRef((function(e,t){var n=e.components,o=e.mdxType,i=e.originalType,s=e.parentName,c=u(e,["components","mdxType","originalType","parentName"]),d=l(n),p=o,w=d["".concat(s,".").concat(p)]||d[p]||m[p]||i;return n?r.createElement(w,a(a({ref:t},c),{},{components:n})):r.createElement(w,a({ref:t},c))}));function p(e,t){var n=arguments,o=t&&t.mdxType;if("string"==typeof e||o){var i=n.length,a=new Array(i);a[0]=d;var u={};for(var s in t)hasOwnProperty.call(t,s)&&(u[s]=t[s]);u.originalType=e,u.mdxType="string"==typeof e?e:o,a[1]=u;for(var l=2;l<i;l++)a[l]=n[l];return r.createElement.apply(null,a)}return r.createElement.apply(null,n)}d.displayName="MDXCreateElement"},715:(e,t,n)=>{n.r(t),n.d(t,{assets:()=>s,contentTitle:()=>a,default:()=>m,frontMatter:()=>i,metadata:()=>u,toc:()=>l});var r=n(7462),o=(n(7294),n(3905));const i={},a="leetcode1348 Tweet Counts Per Frequency",u={unversionedId:"OJ/Leetcode1348",id:"OJ/Leetcode1348",title:"leetcode1348 Tweet Counts Per Frequency",description:"\u7b2c 175 \u573a\u5468\u8d5b",source:"@site/docs/OJ/Leetcode1348.md",sourceDirName:"OJ",slug:"/OJ/Leetcode1348",permalink:"/docs/OJ/Leetcode1348",draft:!1,editUrl:"https://github.com/zxc2012/zxc2012.github.io/tree/master/docs/OJ/Leetcode1348.md",tags:[],version:"current",frontMatter:{},sidebar:"OJ",next:{title:"Leetcode 334 Increasing Triplet Subsequence",permalink:"/docs/OJ/Leetcode334"}},s={},l=[{value:"Description",id:"description",level:2},{value:"Constraints",id:"constraints",level:2},{value:"Example",id:"example",level:2},{value:"Input",id:"input",level:3},{value:"Output",id:"output",level:3},{value:"Explanation",id:"explanation",level:3},{value:"Code",id:"code",level:2},{value:"Summary",id:"summary",level:2}],c={toc:l};function m(e){let{components:t,...n}=e;return(0,o.kt)("wrapper",(0,r.Z)({},c,n,{components:t,mdxType:"MDXLayout"}),(0,o.kt)("h1",{id:"leetcode1348-tweet-counts-per-frequency"},"leetcode1348 Tweet Counts Per Frequency"),(0,o.kt)("p",null,(0,o.kt)("strong",{parentName:"p"},"\u7b2c 175 \u573a\u5468\u8d5b")),(0,o.kt)("h2",{id:"description"},"Description"),(0,o.kt)("p",null,"Implement the class TweetCounts that supports two methods:"),(0,o.kt)("ol",null,(0,o.kt)("li",{parentName:"ol"},"recordTweet(string tweetName, int time)")),(0,o.kt)("p",null,"Stores the tweetName at the recorded time (in seconds).\n2. getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime)"),(0,o.kt)("p",null,"Returns the total number of occurrences for the given tweetName per minute, hour, or day (depending on freq) starting from the startTime (in seconds) and ending at the endTime (in seconds).\nfreq is always minute, hour or day, representing the time interval to get the total number of occurrences for the given tweetName.\nThe first time interval always starts from the startTime, so the time intervals are [startTime, startTime + delta",(0,o.kt)("em",{parentName:"p"},"1>,  [startTime + delta"),"1, startTime + delta",(0,o.kt)("em",{parentName:"p"},"2>, [startTime + delta"),"2, startTime + delta",(0,o.kt)("em",{parentName:"p"},"3>, ... , [startTime + delta"),"i, min(startTime + delta*(i+1), endTime + 1)> for some non-negative number i and delta (which depends on freq).  "),(0,o.kt)("h2",{id:"constraints"},"Constraints"),(0,o.kt)("p",null,"There will be at most 10000 operations considering both recordTweet and getTweetCountsPerFrequency."),(0,o.kt)("ul",null,(0,o.kt)("li",{parentName:"ul"},"0 <= time, startTime, endTime <= 10^9"),(0,o.kt)("li",{parentName:"ul"},"0 <= endTime - startTime <= 10^4")),(0,o.kt)("h2",{id:"example"},"Example"),(0,o.kt)("h3",{id:"input"},"Input"),(0,o.kt)("p",null,'["TweetCounts","recordTweet","recordTweet","recordTweet","getTweetCountsPerFrequency","getTweetCountsPerFrequency","recordTweet","getTweetCountsPerFrequency"]',"[],",'["tweet3",0]',",",'["tweet3",60]',",",'["tweet3",10]',",",'["minute","tweet3",0,59]',",",'["minute","tweet3",0,60]',",",'["tweet3",120]',",",'["hour","tweet3",0,210]',"]"),(0,o.kt)("h3",{id:"output"},"Output"),(0,o.kt)("p",null,"[null,null,null,null,","[2]",",","[2,1]",",null,","[4]","]"),(0,o.kt)("h3",{id:"explanation"},"Explanation"),(0,o.kt)("pre",null,(0,o.kt)("code",{parentName:"pre",className:"language-java"},'TweetCounts tweetCounts = new TweetCounts();\ntweetCounts.recordTweet("tweet3", 0);\ntweetCounts.recordTweet("tweet3", 60);\ntweetCounts.recordTweet("tweet3", 10);                             // All tweets correspond to "tweet3" with recorded times at 0, 10 and 60.\ntweetCounts.getTweetCountsPerFrequency("minute", "tweet3", 0, 59); // return [2]. The frequency is per minute (60 seconds), so there is one interval of time: 1) [0, 60> - > 2 tweets.\ntweetCounts.getTweetCountsPerFrequency("minute", "tweet3", 0, 60); // return [2, 1]. The frequency is per minute (60 seconds), so there are two intervals of time: 1) [0, 60> - > 2 tweets, and 2) [60,61> - > 1 tweet.\ntweetCounts.recordTweet("tweet3", 120);                            // All tweets correspond to "tweet3" with recorded times at 0, 10, 60 and 120.\ntweetCounts.getTweetCountsPerFrequency("hour", "tweet3", 0, 210);  // return [4]. The frequency is per hour (3600 seconds), so there is one interval of time: 1) [0, 211> - > 4 tweets.\n')),(0,o.kt)("h2",{id:"code"},"Code"),(0,o.kt)("pre",null,(0,o.kt)("code",{parentName:"pre",className:"language-cpp"},'class TweetCounts {\npublic:\n    TweetCounts() {\n        t.clear();mp.clear();\n        t.resize(10);\n        r=0;\n    }\n    \n    void recordTweet(string tweetName, int time) {\n        if(mp[tweetName]==0){\n            mp[tweetName]=++r;\n        }\n        t[mp[tweetName]].push_back(time);\n    }\n    \n    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {\n        int f,i;\n        if(freq=="minute")f=60;\n        else if(freq=="hour")f=3600;\n        else if(freq=="day")f=24*3600;\n        vector<int>px((endTime-startTime)/f+1,0);\n        int index=mp[tweetName];\n        for(auto &u:t[index]){\n            if(u>endTime||u<startTime)continue;\n            else px[(u-startTime)/f]++;\n        }\n        return px;\n    }\nprivate:\n    vector<vector<int>> t;\n    unordered_map<string,int>mp;\n    int r;\n};\n')),(0,o.kt)("h2",{id:"summary"},"Summary"),(0,o.kt)("ul",null,(0,o.kt)("li",{parentName:"ul"},"unordered_map\u6613\u9519\u70b9:index\u548crecord_sum\u7684\u533a\u522b"),(0,o.kt)("li",{parentName:"ul"},"\u600e\u4e48\u627e\u5faa\u73af--\x3e\u6570\u7ec4\u662f\u5426\u53ef\u4ee5\u76f4\u63a5\u5b9a\u4f4d")))}m.isMDXComponent=!0}}]);