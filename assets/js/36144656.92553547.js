"use strict";(self.webpackChunkChance=self.webpackChunkChance||[]).push([[4924],{3905:(t,e,a)=>{a.d(e,{Zo:()=>m,kt:()=>d});var n=a(7294);function r(t,e,a){return e in t?Object.defineProperty(t,e,{value:a,enumerable:!0,configurable:!0,writable:!0}):t[e]=a,t}function l(t,e){var a=Object.keys(t);if(Object.getOwnPropertySymbols){var n=Object.getOwnPropertySymbols(t);e&&(n=n.filter((function(e){return Object.getOwnPropertyDescriptor(t,e).enumerable}))),a.push.apply(a,n)}return a}function o(t){for(var e=1;e<arguments.length;e++){var a=null!=arguments[e]?arguments[e]:{};e%2?l(Object(a),!0).forEach((function(e){r(t,e,a[e])})):Object.getOwnPropertyDescriptors?Object.defineProperties(t,Object.getOwnPropertyDescriptors(a)):l(Object(a)).forEach((function(e){Object.defineProperty(t,e,Object.getOwnPropertyDescriptor(a,e))}))}return t}function p(t,e){if(null==t)return{};var a,n,r=function(t,e){if(null==t)return{};var a,n,r={},l=Object.keys(t);for(n=0;n<l.length;n++)a=l[n],e.indexOf(a)>=0||(r[a]=t[a]);return r}(t,e);if(Object.getOwnPropertySymbols){var l=Object.getOwnPropertySymbols(t);for(n=0;n<l.length;n++)a=l[n],e.indexOf(a)>=0||Object.prototype.propertyIsEnumerable.call(t,a)&&(r[a]=t[a])}return r}var i=n.createContext({}),u=function(t){var e=n.useContext(i),a=e;return t&&(a="function"==typeof t?t(e):o(o({},e),t)),a},m=function(t){var e=u(t.components);return n.createElement(i.Provider,{value:e},t.children)},c={inlineCode:"code",wrapper:function(t){var e=t.children;return n.createElement(n.Fragment,{},e)}},k=n.forwardRef((function(t,e){var a=t.components,r=t.mdxType,l=t.originalType,i=t.parentName,m=p(t,["components","mdxType","originalType","parentName"]),k=u(a),d=r,s=k["".concat(i,".").concat(d)]||k[d]||c[d]||l;return a?n.createElement(s,o(o({ref:e},m),{},{components:a})):n.createElement(s,o({ref:e},m))}));function d(t,e){var a=arguments,r=e&&e.mdxType;if("string"==typeof t||r){var l=a.length,o=new Array(l);o[0]=k;var p={};for(var i in e)hasOwnProperty.call(e,i)&&(p[i]=e[i]);p.originalType=t,p.mdxType="string"==typeof t?t:r,o[1]=p;for(var u=2;u<l;u++)o[u]=a[u];return n.createElement.apply(null,o)}return n.createElement.apply(null,a)}k.displayName="MDXCreateElement"},7409:(t,e,a)=>{a.r(e),a.d(e,{assets:()=>i,contentTitle:()=>o,default:()=>c,frontMatter:()=>l,metadata:()=>p,toc:()=>u});var n=a(7462),r=(a(7294),a(3905));const l={},o="Linux\u57fa\u7840\u6307\u4ee4",p={unversionedId:"SDE/linux",id:"SDE/linux",title:"Linux\u57fa\u7840\u6307\u4ee4",description:"Linux\u547d\u4ee4\u884c\u7ed3\u6784",source:"@site/docs/SDE/linux.md",sourceDirName:"SDE",slug:"/SDE/linux",permalink:"/docs/SDE/linux",draft:!1,editUrl:"https://github.com/zxc2012/zxc2012.github.io/tree/master/docs/SDE/linux.md",tags:[],version:"current",frontMatter:{},sidebar:"SDE",previous:{title:"experience",permalink:"/docs/SDE/experience"},next:{title:"\u4e0a\u7f51\u73af\u5883\u57fa\u7840\u914d\u7f6e",permalink:"/docs/SDE/network"}},i={},u=[{value:"Linux\u547d\u4ee4\u884c\u7ed3\u6784",id:"linux\u547d\u4ee4\u884c\u7ed3\u6784",level:2},{value:"\u57fa\u672c\u6307\u4ee4",id:"\u57fa\u672c\u6307\u4ee4",level:2},{value:"Linux\u7f51\u7edc\u5206\u6790\u5de5\u5177",id:"linux\u7f51\u7edc\u5206\u6790\u5de5\u5177",level:2},{value:"Ping",id:"ping",level:3},{value:"Useful Tools",id:"useful-tools",level:2},{value:"gcc",id:"gcc",level:3},{value:"tmux",id:"tmux",level:3}],m={toc:u};function c(t){let{components:e,...a}=t;return(0,r.kt)("wrapper",(0,n.Z)({},m,a,{components:e,mdxType:"MDXLayout"}),(0,r.kt)("h1",{id:"linux\u57fa\u7840\u6307\u4ee4"},"Linux\u57fa\u7840\u6307\u4ee4"),(0,r.kt)("h2",{id:"linux\u547d\u4ee4\u884c\u7ed3\u6784"},"Linux\u547d\u4ee4\u884c\u7ed3\u6784"),(0,r.kt)("blockquote",null,(0,r.kt)("p",{parentName:"blockquote"},"$ command ","[[-]",(0,r.kt)("em",{parentName:"p"},"option(s)"),"][*option argument(s)*]"," ","[",(0,r.kt)("em",{parentName:"p"},"command argument(s)"),"]")),(0,r.kt)("h2",{id:"\u57fa\u672c\u6307\u4ee4"},"\u57fa\u672c\u6307\u4ee4"),(0,r.kt)("p",null,"1.Linux\u4e09\u5927\u67e5\u8be2\u547d\u4ee4man,info,--help"),(0,r.kt)("p",null,"man page:manual page"),(0,r.kt)("blockquote",null,(0,r.kt)("p",{parentName:"blockquote"},"man ls")),(0,r.kt)("blockquote",null,(0,r.kt)("p",{parentName:"blockquote"},"man passwd")),(0,r.kt)("blockquote",null,(0,r.kt)("p",{parentName:"blockquote"},"info pwd")),(0,r.kt)("blockquote",null,(0,r.kt)("p",{parentName:"blockquote"},"who --help")),(0,r.kt)("p",null,"2.uname(short for unix name)"),(0,r.kt)("p",null,"parameter:"),(0,r.kt)("ul",null,(0,r.kt)("li",{parentName:"ul"},"-n(-nodename)"),(0,r.kt)("li",{parentName:"ul"},"-p(-processor)")),(0,r.kt)("p",null,"3.",(0,r.kt)("em",{parentName:"p"},"cal")," command is a calendar command in Linux which is used to see the calendar of a specific month or a whole year."),(0,r.kt)("ol",{start:4},(0,r.kt)("li",{parentName:"ol"})),(0,r.kt)("table",null,(0,r.kt)("thead",{parentName:"table"},(0,r.kt)("tr",{parentName:"thead"},(0,r.kt)("th",{parentName:"tr",align:null},"Command"),(0,r.kt)("th",{parentName:"tr",align:null},"Interpretation"))),(0,r.kt)("tbody",{parentName:"table"},(0,r.kt)("tr",{parentName:"tbody"},(0,r.kt)("td",{parentName:"tr",align:null},"pwd"),(0,r.kt)("td",{parentName:"tr",align:null},"print working directory")),(0,r.kt)("tr",{parentName:"tbody"},(0,r.kt)("td",{parentName:"tr",align:null},"mkdir"),(0,r.kt)("td",{parentName:"tr",align:null},"make directory")),(0,r.kt)("tr",{parentName:"tbody"},(0,r.kt)("td",{parentName:"tr",align:null},"cd"),(0,r.kt)("td",{parentName:"tr",align:null},"change directory")),(0,r.kt)("tr",{parentName:"tbody"},(0,r.kt)("td",{parentName:"tr",align:null},"rmdir"),(0,r.kt)("td",{parentName:"tr",align:null},"remove(empty)directory")))),(0,r.kt)("h2",{id:"linux\u7f51\u7edc\u5206\u6790\u5de5\u5177"},"Linux\u7f51\u7edc\u5206\u6790\u5de5\u5177"),(0,r.kt)("h3",{id:"ping"},"Ping"),(0,r.kt)("blockquote",null,(0,r.kt)("p",{parentName:"blockquote"},"ping, ping6 - send ICMP ECHO_REQUEST to network hosts"),(0,r.kt)("pre",{parentName:"blockquote"},(0,r.kt)("code",{parentName:"pre",className:"language-Shell"},"ping [-LRUbdfnqrvVaAB] [-c count] [-i interval] [-s packetsize] [-t ttl] [hop ...] destination\n")),(0,r.kt)("h4",{parentName:"blockquote",id:"\u53c2\u6570\u89e3\u91ca"},"\u53c2\u6570\u89e3\u91ca"),(0,r.kt)("table",{parentName:"blockquote"},(0,r.kt)("thead",{parentName:"table"},(0,r.kt)("tr",{parentName:"thead"},(0,r.kt)("th",{parentName:"tr",align:null},"\u53c2\u6570"),(0,r.kt)("th",{parentName:"tr",align:null},"\u89e3\u91ca"))),(0,r.kt)("tbody",{parentName:"table"},(0,r.kt)("tr",{parentName:"tbody"},(0,r.kt)("td",{parentName:"tr",align:null},"[ -c count]"),(0,r.kt)("td",{parentName:"tr",align:null},"Stop after sending ",(0,r.kt)("em",{parentName:"td"},"count")," ECHO_REQUEST packets.")),(0,r.kt)("tr",{parentName:"tbody"},(0,r.kt)("td",{parentName:"tr",align:null},"[ -i interval]"),(0,r.kt)("td",{parentName:"tr",align:null},"Wait ",(0,r.kt)("em",{parentName:"td"},"interval")," seconds between sending each packet.",(0,r.kt)("strong",{parentName:"td"},"default:1"))),(0,r.kt)("tr",{parentName:"tbody"},(0,r.kt)("td",{parentName:"tr",align:null},"[ -s packetsize]"),(0,r.kt)("td",{parentName:"tr",align:null},"Specifies the number of data bytes to be sent. ",(0,r.kt)("strong",{parentName:"td"},"default:56 (64 ICMP data bytes=8 bytes of ICMP header data+56)"))),(0,r.kt)("tr",{parentName:"tbody"},(0,r.kt)("td",{parentName:"tr",align:null},"[ -t ttl]"),(0,r.kt)("td",{parentName:"tr",align:null},"Set the IP Time to Live.")))),(0,r.kt)("h3",{parentName:"blockquote",id:"traceroute"},"Traceroute"),(0,r.kt)("p",{parentName:"blockquote"},"traceroute,traceroute6(",(0,r.kt)("em",{parentName:"p"},"or")," traceroute -6)print the route packets trace to network host"),(0,r.kt)("pre",{parentName:"blockquote"},(0,r.kt)("code",{parentName:"pre",className:"language-Shell"},"traceroute [...] host [packet_len]\n")),(0,r.kt)("h4",{parentName:"blockquote",id:"\u53c2\u6570\u89e3\u91ca-1"},"\u53c2\u6570\u89e3\u91ca"),(0,r.kt)("table",{parentName:"blockquote"},(0,r.kt)("thead",{parentName:"table"},(0,r.kt)("tr",{parentName:"thead"},(0,r.kt)("th",{parentName:"tr",align:null},"\u53c2\u6570"),(0,r.kt)("th",{parentName:"tr",align:null},"\u89e3\u91ca"))),(0,r.kt)("tbody",{parentName:"table"},(0,r.kt)("tr",{parentName:"tbody"},(0,r.kt)("td",{parentName:"tr",align:null},"-4,-6"),(0,r.kt)("td",{parentName:"tr",align:null},"Explicitly force IPv4 or IPv6 traceouting. If resolving a host name returns both IPv4 and IPv6 addresses, traceroute will use IPv4.")),(0,r.kt)("tr",{parentName:"tbody"},(0,r.kt)("td",{parentName:"tr",align:null},"-n"),(0,r.kt)("td",{parentName:"tr",align:null},"Do not try to map IP addresses to host names when displaying them.")),(0,r.kt)("tr",{parentName:"tbody"},(0,r.kt)("td",{parentName:"tr",align:null},"-p port"),(0,r.kt)("td",{parentName:"tr",align:null},"For UDP tracing, specifies the destination port base traceroute will use (the destination port number will be incremented by each probe).For ICMP tracing, specifies the initial icmp sequence value (incremented by each probe too).For TCP specifies just the (constant) destination port to connect.")),(0,r.kt)("tr",{parentName:"tbody"},(0,r.kt)("td",{parentName:"tr",align:null},"-T"),(0,r.kt)("td",{parentName:"tr",align:null},"Use TCP SYN for probes")),(0,r.kt)("tr",{parentName:"tbody"},(0,r.kt)("td",{parentName:"tr",align:null},"-I"),(0,r.kt)("td",{parentName:"tr",align:null},"Use ICMP ECHO for probes")),(0,r.kt)("tr",{parentName:"tbody"},(0,r.kt)("td",{parentName:"tr",align:null},"-U"),(0,r.kt)("td",{parentName:"tr",align:null},"Use UDP to particular destination port for tracerouting (instead of increasing the port per each probe). ",(0,r.kt)("strong",{parentName:"td"},"default port:53"))))),(0,r.kt)("h4",{parentName:"blockquote",id:"example"},"Example"),(0,r.kt)("p",{parentName:"blockquote"},(0,r.kt)("img",{parentName:"p",src:"https://img-blog.csdnimg.cn/20200903113838628.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM5MzgwMjMw,size_16,color_FFFFFF,t_70#pic_center",alt:"\u5728\u8fd9\u91cc\u63d2\u5165\u56fe\u7247\u63cf\u8ff0"}),"\n",(0,r.kt)("img",{parentName:"p",src:"https://img-blog.csdnimg.cn/20200903113912107.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM5MzgwMjMw,size_16,color_FFFFFF,t_70#pic_center",alt:"\u5728\u8fd9\u91cc\u63d2\u5165\u56fe\u7247\u63cf\u8ff0"})),(0,r.kt)("h3",{parentName:"blockquote",id:"nslookup"},"Nslookup"),(0,r.kt)("p",{parentName:"blockquote"},"nslookup - query Internet domain name servers"),(0,r.kt)("pre",{parentName:"blockquote"},(0,r.kt)("code",{parentName:"pre",className:"language-shell"},"nslookup [-option] [name | -] [server]\n")),(0,r.kt)("h4",{parentName:"blockquote",id:"\u53c2\u6570\u89e3\u91ca-2"},"\u53c2\u6570\u89e3\u91ca"),(0,r.kt)("p",{parentName:"blockquote"},"-option:\n-query=hinfo")),(0,r.kt)("table",null,(0,r.kt)("thead",{parentName:"table"},(0,r.kt)("tr",{parentName:"thead"},(0,r.kt)("th",{parentName:"tr",align:null},"hinfo"),(0,r.kt)("th",{parentName:"tr",align:null},"\u89e3\u91ca"))),(0,r.kt)("tbody",{parentName:"table"},(0,r.kt)("tr",{parentName:"tbody"},(0,r.kt)("td",{parentName:"tr",align:null},"A"),(0,r.kt)("td",{parentName:"tr",align:null},"ipv4")),(0,r.kt)("tr",{parentName:"tbody"},(0,r.kt)("td",{parentName:"tr",align:null},"AAAA"),(0,r.kt)("td",{parentName:"tr",align:null},"ipv6")),(0,r.kt)("tr",{parentName:"tbody"},(0,r.kt)("td",{parentName:"tr",align:null},"CNAME"),(0,r.kt)("td",{parentName:"tr",align:null},"\u522b\u540d\u8bb0\u5f55")),(0,r.kt)("tr",{parentName:"tbody"},(0,r.kt)("td",{parentName:"tr",align:null},"MX"),(0,r.kt)("td",{parentName:"tr",align:null},"\u90ae\u4ef6\u670d\u52a1\u5668\u8bb0\u5f55")))),(0,r.kt)("h2",{id:"useful-tools"},"Useful Tools"),(0,r.kt)("h3",{id:"gcc"},"gcc"),(0,r.kt)("p",null,"gcc :GNU compiler collection(gcc, g++, gfortran, etc.)"),(0,r.kt)("p",null,"gdb :GNU symbolic debugger"),(0,r.kt)("p",null,"\u8054\u60f3Devcpp"),(0,r.kt)("ul",null,(0,r.kt)("li",{parentName:"ul"},"gcc ",(0,r.kt)("ul",{parentName:"li"},(0,r.kt)("li",{parentName:"ul"},"-g: the output will have debug symbols"),(0,r.kt)("li",{parentName:"ul"},"-o: file Place the output into file"),(0,r.kt)("li",{parentName:"ul"},"-Wall: Enables all compiler warnings"),(0,r.kt)("li",{parentName:"ul"},"-m32: Compiles the code for the i386 architecture."),(0,r.kt)("li",{parentName:"ul"},"-E: Preprocess only; do not compile, assemble or link"),(0,r.kt)("li",{parentName:"ul"},"-S: Invokes the COMPILER only."),(0,r.kt)("li",{parentName:"ul"},"-c: Invokes the COMPILER and ASSEMBLER only."))),(0,r.kt)("li",{parentName:"ul"},"gdb programname: look at a stack trace && inspect\nvariables()")),(0,r.kt)("h3",{id:"tmux"},"tmux"),(0,r.kt)("p",null,"tmux:terminal multiplexer"))}c.isMDXComponent=!0}}]);