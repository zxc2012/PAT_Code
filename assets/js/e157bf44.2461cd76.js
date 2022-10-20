"use strict";(self.webpackChunkChance=self.webpackChunkChance||[]).push([[2541],{3905:(t,e,a)=>{a.d(e,{Zo:()=>d,kt:()=>N});var n=a(7294);function l(t,e,a){return e in t?Object.defineProperty(t,e,{value:a,enumerable:!0,configurable:!0,writable:!0}):t[e]=a,t}function r(t,e){var a=Object.keys(t);if(Object.getOwnPropertySymbols){var n=Object.getOwnPropertySymbols(t);e&&(n=n.filter((function(e){return Object.getOwnPropertyDescriptor(t,e).enumerable}))),a.push.apply(a,n)}return a}function p(t){for(var e=1;e<arguments.length;e++){var a=null!=arguments[e]?arguments[e]:{};e%2?r(Object(a),!0).forEach((function(e){l(t,e,a[e])})):Object.getOwnPropertyDescriptors?Object.defineProperties(t,Object.getOwnPropertyDescriptors(a)):r(Object(a)).forEach((function(e){Object.defineProperty(t,e,Object.getOwnPropertyDescriptor(a,e))}))}return t}function i(t,e){if(null==t)return{};var a,n,l=function(t,e){if(null==t)return{};var a,n,l={},r=Object.keys(t);for(n=0;n<r.length;n++)a=r[n],e.indexOf(a)>=0||(l[a]=t[a]);return l}(t,e);if(Object.getOwnPropertySymbols){var r=Object.getOwnPropertySymbols(t);for(n=0;n<r.length;n++)a=r[n],e.indexOf(a)>=0||Object.prototype.propertyIsEnumerable.call(t,a)&&(l[a]=t[a])}return l}var m=n.createContext({}),u=function(t){var e=n.useContext(m),a=e;return t&&(a="function"==typeof t?t(e):p(p({},e),t)),a},d=function(t){var e=u(t.components);return n.createElement(m.Provider,{value:e},t.children)},k={inlineCode:"code",wrapper:function(t){var e=t.children;return n.createElement(n.Fragment,{},e)}},g=n.forwardRef((function(t,e){var a=t.components,l=t.mdxType,r=t.originalType,m=t.parentName,d=i(t,["components","mdxType","originalType","parentName"]),g=u(a),N=l,c=g["".concat(m,".").concat(N)]||g[N]||k[N]||r;return a?n.createElement(c,p(p({ref:e},d),{},{components:a})):n.createElement(c,p({ref:e},d))}));function N(t,e){var a=arguments,l=e&&e.mdxType;if("string"==typeof t||l){var r=a.length,p=new Array(r);p[0]=g;var i={};for(var m in e)hasOwnProperty.call(e,m)&&(i[m]=e[m]);i.originalType=t,i.mdxType="string"==typeof t?t:l,p[1]=i;for(var u=2;u<r;u++)p[u]=a[u];return n.createElement.apply(null,p)}return n.createElement.apply(null,a)}g.displayName="MDXCreateElement"},8155:(t,e,a)=>{a.r(e),a.d(e,{assets:()=>m,contentTitle:()=>p,default:()=>k,frontMatter:()=>r,metadata:()=>i,toc:()=>u});var n=a(7462),l=(a(7294),a(3905));const r={},p="CS61C Lecture3 --RISC V Single-Cycle Control and Pipelining",i={unversionedId:"cs/cs61c_3",id:"cs/cs61c_3",title:"CS61C Lecture3 --RISC V Single-Cycle Control and Pipelining",description:"Basics",source:"@site/docs/cs/cs61c_3.md",sourceDirName:"cs",slug:"/cs/cs61c_3",permalink:"/docs/cs/cs61c_3",draft:!1,editUrl:"https://github.com/zxc2012/zxc2012.github.io/tree/master/docs/cs/cs61c_3.md",tags:[],version:"current",frontMatter:{},sidebar:"cs",previous:{title:"CS61C Lecture2 --RISCV Assembly",permalink:"/docs/cs/cs61c_2"},next:{title:"CS61C Lecture4 --Cache",permalink:"/docs/cs/cs61c_4"}},m={},u=[{value:"Basics",id:"basics",level:2},{value:"Instruction Table",id:"instruction-table",level:2},{value:"Single Cycle",id:"single-cycle",level:2},{value:"Pipelined",id:"pipelined",level:2},{value:"Overview",id:"overview",level:3},{value:"Hazard",id:"hazard",level:3},{value:"Structural Hazard",id:"structural-hazard",level:4},{value:"Data Hazard",id:"data-hazard",level:4},{value:"Control Hazard",id:"control-hazard",level:4}],d={toc:u};function k(t){let{components:e,...a}=t;return(0,l.kt)("wrapper",(0,n.Z)({},d,a,{components:e,mdxType:"MDXLayout"}),(0,l.kt)("h1",{id:"cs61c-lecture3---risc-v-single-cycle-control-and-pipelining"},"CS61C Lecture3 --RISC V Single-Cycle Control and Pipelining"),(0,l.kt)("h2",{id:"basics"},"Basics"),(0,l.kt)("p",null,(0,l.kt)("img",{parentName:"p",src:"https://raw.githubusercontent.com/zxc2012/image/main/20220326211448.png",alt:"20220310173933"})),(0,l.kt)("p",null,(0,l.kt)("img",{parentName:"p",src:"https://raw.githubusercontent.com/zxc2012/image/main/20220331161846.png",alt:"20220310173933"})),(0,l.kt)("h2",{id:"instruction-table"},"Instruction Table"),(0,l.kt)("table",null,(0,l.kt)("thead",{parentName:"table"},(0,l.kt)("tr",{parentName:"thead"},(0,l.kt)("th",{parentName:"tr",align:null},"Inst","[31:0]"),(0,l.kt)("th",{parentName:"tr",align:null},"BrEq"),(0,l.kt)("th",{parentName:"tr",align:null},"BrLT"),(0,l.kt)("th",{parentName:"tr",align:null},"PCSel"),(0,l.kt)("th",{parentName:"tr",align:null},"ImmSel"),(0,l.kt)("th",{parentName:"tr",align:null},"BrUn"),(0,l.kt)("th",{parentName:"tr",align:null},"ASel"),(0,l.kt)("th",{parentName:"tr",align:null},"BSel"),(0,l.kt)("th",{parentName:"tr",align:null},"ALUSel"),(0,l.kt)("th",{parentName:"tr",align:null},"MemRW"),(0,l.kt)("th",{parentName:"tr",align:null},"RegWEn"),(0,l.kt)("th",{parentName:"tr",align:null},"WBSel"))),(0,l.kt)("tbody",{parentName:"table"},(0,l.kt)("tr",{parentName:"tbody"},(0,l.kt)("td",{parentName:"tr",align:null},"add"),(0,l.kt)("td",{parentName:"tr",align:null},"*"),(0,l.kt)("td",{parentName:"tr",align:null},"*"),(0,l.kt)("td",{parentName:"tr",align:null},"+4"),(0,l.kt)("td",{parentName:"tr",align:null},"*"),(0,l.kt)("td",{parentName:"tr",align:null},"*"),(0,l.kt)("td",{parentName:"tr",align:null},"Reg"),(0,l.kt)("td",{parentName:"tr",align:null},"Reg"),(0,l.kt)("td",{parentName:"tr",align:null},"Add"),(0,l.kt)("td",{parentName:"tr",align:null},"Read"),(0,l.kt)("td",{parentName:"tr",align:null},"1 (Y)"),(0,l.kt)("td",{parentName:"tr",align:null},"ALU")),(0,l.kt)("tr",{parentName:"tbody"},(0,l.kt)("td",{parentName:"tr",align:null},"sub"),(0,l.kt)("td",{parentName:"tr",align:null},"*"),(0,l.kt)("td",{parentName:"tr",align:null},"*"),(0,l.kt)("td",{parentName:"tr",align:null},"+4"),(0,l.kt)("td",{parentName:"tr",align:null},"*"),(0,l.kt)("td",{parentName:"tr",align:null},"*"),(0,l.kt)("td",{parentName:"tr",align:null},"Reg"),(0,l.kt)("td",{parentName:"tr",align:null},"Reg"),(0,l.kt)("td",{parentName:"tr",align:null},"Sub"),(0,l.kt)("td",{parentName:"tr",align:null},"Read"),(0,l.kt)("td",{parentName:"tr",align:null},"1"),(0,l.kt)("td",{parentName:"tr",align:null},"ALU")),(0,l.kt)("tr",{parentName:"tbody"},(0,l.kt)("td",{parentName:"tr",align:null},"(R-ROp)"),(0,l.kt)("td",{parentName:"tr",align:null},"*"),(0,l.kt)("td",{parentName:"tr",align:null},"*"),(0,l.kt)("td",{parentName:"tr",align:null},"+4"),(0,l.kt)("td",{parentName:"tr",align:null},"*"),(0,l.kt)("td",{parentName:"tr",align:null},"*"),(0,l.kt)("td",{parentName:"tr",align:null},"Reg"),(0,l.kt)("td",{parentName:"tr",align:null},"Reg"),(0,l.kt)("td",{parentName:"tr",align:null},"(Op)"),(0,l.kt)("td",{parentName:"tr",align:null},"Read"),(0,l.kt)("td",{parentName:"tr",align:null},"1"),(0,l.kt)("td",{parentName:"tr",align:null},"ALU")),(0,l.kt)("tr",{parentName:"tbody"},(0,l.kt)("td",{parentName:"tr",align:null},"addi"),(0,l.kt)("td",{parentName:"tr",align:null},"*"),(0,l.kt)("td",{parentName:"tr",align:null},"*"),(0,l.kt)("td",{parentName:"tr",align:null},"+4"),(0,l.kt)("td",{parentName:"tr",align:null},"I"),(0,l.kt)("td",{parentName:"tr",align:null},"*"),(0,l.kt)("td",{parentName:"tr",align:null},"Reg"),(0,l.kt)("td",{parentName:"tr",align:null},"Imm"),(0,l.kt)("td",{parentName:"tr",align:null},"Add"),(0,l.kt)("td",{parentName:"tr",align:null},"Read"),(0,l.kt)("td",{parentName:"tr",align:null},"1"),(0,l.kt)("td",{parentName:"tr",align:null},"ALU")),(0,l.kt)("tr",{parentName:"tbody"},(0,l.kt)("td",{parentName:"tr",align:null},"lw"),(0,l.kt)("td",{parentName:"tr",align:null},"*"),(0,l.kt)("td",{parentName:"tr",align:null},"*"),(0,l.kt)("td",{parentName:"tr",align:null},"+4"),(0,l.kt)("td",{parentName:"tr",align:null},"I"),(0,l.kt)("td",{parentName:"tr",align:null},"*"),(0,l.kt)("td",{parentName:"tr",align:null},"Reg"),(0,l.kt)("td",{parentName:"tr",align:null},"Imm"),(0,l.kt)("td",{parentName:"tr",align:null},"Add"),(0,l.kt)("td",{parentName:"tr",align:null},"Read"),(0,l.kt)("td",{parentName:"tr",align:null},"1"),(0,l.kt)("td",{parentName:"tr",align:null},"Mem")),(0,l.kt)("tr",{parentName:"tbody"},(0,l.kt)("td",{parentName:"tr",align:null},"sw"),(0,l.kt)("td",{parentName:"tr",align:null},"*"),(0,l.kt)("td",{parentName:"tr",align:null},"*"),(0,l.kt)("td",{parentName:"tr",align:null},"+4"),(0,l.kt)("td",{parentName:"tr",align:null},"S"),(0,l.kt)("td",{parentName:"tr",align:null},"*"),(0,l.kt)("td",{parentName:"tr",align:null},"Reg"),(0,l.kt)("td",{parentName:"tr",align:null},"Imm"),(0,l.kt)("td",{parentName:"tr",align:null},"Add"),(0,l.kt)("td",{parentName:"tr",align:null},"Write"),(0,l.kt)("td",{parentName:"tr",align:null},"0 (N)"),(0,l.kt)("td",{parentName:"tr",align:null},"*")),(0,l.kt)("tr",{parentName:"tbody"},(0,l.kt)("td",{parentName:"tr",align:null},"beq"),(0,l.kt)("td",{parentName:"tr",align:null},"0"),(0,l.kt)("td",{parentName:"tr",align:null},"*"),(0,l.kt)("td",{parentName:"tr",align:null},"+4"),(0,l.kt)("td",{parentName:"tr",align:null},"B"),(0,l.kt)("td",{parentName:"tr",align:null},"*"),(0,l.kt)("td",{parentName:"tr",align:null},"PC"),(0,l.kt)("td",{parentName:"tr",align:null},"Imm"),(0,l.kt)("td",{parentName:"tr",align:null},"Add"),(0,l.kt)("td",{parentName:"tr",align:null},"Read"),(0,l.kt)("td",{parentName:"tr",align:null},"0"),(0,l.kt)("td",{parentName:"tr",align:null},"*")),(0,l.kt)("tr",{parentName:"tbody"},(0,l.kt)("td",{parentName:"tr",align:null},"beq"),(0,l.kt)("td",{parentName:"tr",align:null},"1"),(0,l.kt)("td",{parentName:"tr",align:null},"*"),(0,l.kt)("td",{parentName:"tr",align:null},"ALU"),(0,l.kt)("td",{parentName:"tr",align:null},"B"),(0,l.kt)("td",{parentName:"tr",align:null},"*"),(0,l.kt)("td",{parentName:"tr",align:null},"PC"),(0,l.kt)("td",{parentName:"tr",align:null},"Imm"),(0,l.kt)("td",{parentName:"tr",align:null},"Add"),(0,l.kt)("td",{parentName:"tr",align:null},"Read"),(0,l.kt)("td",{parentName:"tr",align:null},"0"),(0,l.kt)("td",{parentName:"tr",align:null},"*")),(0,l.kt)("tr",{parentName:"tbody"},(0,l.kt)("td",{parentName:"tr",align:null},"bne"),(0,l.kt)("td",{parentName:"tr",align:null},"0"),(0,l.kt)("td",{parentName:"tr",align:null},"*"),(0,l.kt)("td",{parentName:"tr",align:null},"ALU"),(0,l.kt)("td",{parentName:"tr",align:null},"B"),(0,l.kt)("td",{parentName:"tr",align:null},"*"),(0,l.kt)("td",{parentName:"tr",align:null},"PC"),(0,l.kt)("td",{parentName:"tr",align:null},"Imm"),(0,l.kt)("td",{parentName:"tr",align:null},"Add"),(0,l.kt)("td",{parentName:"tr",align:null},"Read"),(0,l.kt)("td",{parentName:"tr",align:null},"0"),(0,l.kt)("td",{parentName:"tr",align:null},"*")),(0,l.kt)("tr",{parentName:"tbody"},(0,l.kt)("td",{parentName:"tr",align:null},"bne"),(0,l.kt)("td",{parentName:"tr",align:null},"1"),(0,l.kt)("td",{parentName:"tr",align:null},"*"),(0,l.kt)("td",{parentName:"tr",align:null},"+4"),(0,l.kt)("td",{parentName:"tr",align:null},"B"),(0,l.kt)("td",{parentName:"tr",align:null},"*"),(0,l.kt)("td",{parentName:"tr",align:null},"PC"),(0,l.kt)("td",{parentName:"tr",align:null},"Imm"),(0,l.kt)("td",{parentName:"tr",align:null},"Add"),(0,l.kt)("td",{parentName:"tr",align:null},"Read"),(0,l.kt)("td",{parentName:"tr",align:null},"0"),(0,l.kt)("td",{parentName:"tr",align:null},"*")),(0,l.kt)("tr",{parentName:"tbody"},(0,l.kt)("td",{parentName:"tr",align:null},"blt"),(0,l.kt)("td",{parentName:"tr",align:null},"*"),(0,l.kt)("td",{parentName:"tr",align:null},"1"),(0,l.kt)("td",{parentName:"tr",align:null},"ALU"),(0,l.kt)("td",{parentName:"tr",align:null},"B"),(0,l.kt)("td",{parentName:"tr",align:null},"0"),(0,l.kt)("td",{parentName:"tr",align:null},"PC"),(0,l.kt)("td",{parentName:"tr",align:null},"Imm"),(0,l.kt)("td",{parentName:"tr",align:null},"Add"),(0,l.kt)("td",{parentName:"tr",align:null},"Read"),(0,l.kt)("td",{parentName:"tr",align:null},"0"),(0,l.kt)("td",{parentName:"tr",align:null},"*")),(0,l.kt)("tr",{parentName:"tbody"},(0,l.kt)("td",{parentName:"tr",align:null},"bltu"),(0,l.kt)("td",{parentName:"tr",align:null},"*"),(0,l.kt)("td",{parentName:"tr",align:null},"1"),(0,l.kt)("td",{parentName:"tr",align:null},"ALU"),(0,l.kt)("td",{parentName:"tr",align:null},"B"),(0,l.kt)("td",{parentName:"tr",align:null},"1"),(0,l.kt)("td",{parentName:"tr",align:null},"PC"),(0,l.kt)("td",{parentName:"tr",align:null},"Imm"),(0,l.kt)("td",{parentName:"tr",align:null},"Add"),(0,l.kt)("td",{parentName:"tr",align:null},"Read"),(0,l.kt)("td",{parentName:"tr",align:null},"0"),(0,l.kt)("td",{parentName:"tr",align:null},"*")),(0,l.kt)("tr",{parentName:"tbody"},(0,l.kt)("td",{parentName:"tr",align:null},"jalr"),(0,l.kt)("td",{parentName:"tr",align:null},"*"),(0,l.kt)("td",{parentName:"tr",align:null},"*"),(0,l.kt)("td",{parentName:"tr",align:null},"ALU"),(0,l.kt)("td",{parentName:"tr",align:null},"I"),(0,l.kt)("td",{parentName:"tr",align:null},"*"),(0,l.kt)("td",{parentName:"tr",align:null},"Reg"),(0,l.kt)("td",{parentName:"tr",align:null},"Imm"),(0,l.kt)("td",{parentName:"tr",align:null},"Add"),(0,l.kt)("td",{parentName:"tr",align:null},"Read"),(0,l.kt)("td",{parentName:"tr",align:null},"1"),(0,l.kt)("td",{parentName:"tr",align:null},"PC+4")),(0,l.kt)("tr",{parentName:"tbody"},(0,l.kt)("td",{parentName:"tr",align:null},"jal"),(0,l.kt)("td",{parentName:"tr",align:null},"*"),(0,l.kt)("td",{parentName:"tr",align:null},"*"),(0,l.kt)("td",{parentName:"tr",align:null},"ALU"),(0,l.kt)("td",{parentName:"tr",align:null},"J"),(0,l.kt)("td",{parentName:"tr",align:null},"*"),(0,l.kt)("td",{parentName:"tr",align:null},"PC"),(0,l.kt)("td",{parentName:"tr",align:null},"Imm"),(0,l.kt)("td",{parentName:"tr",align:null},"Add"),(0,l.kt)("td",{parentName:"tr",align:null},"Read"),(0,l.kt)("td",{parentName:"tr",align:null},"1"),(0,l.kt)("td",{parentName:"tr",align:null},"PC+4")),(0,l.kt)("tr",{parentName:"tbody"},(0,l.kt)("td",{parentName:"tr",align:null},"auipc"),(0,l.kt)("td",{parentName:"tr",align:null},"*"),(0,l.kt)("td",{parentName:"tr",align:null},"*"),(0,l.kt)("td",{parentName:"tr",align:null},"+4"),(0,l.kt)("td",{parentName:"tr",align:null},"U"),(0,l.kt)("td",{parentName:"tr",align:null},"*"),(0,l.kt)("td",{parentName:"tr",align:null},"PC"),(0,l.kt)("td",{parentName:"tr",align:null},"Imm"),(0,l.kt)("td",{parentName:"tr",align:null},"Add"),(0,l.kt)("td",{parentName:"tr",align:null},"Read"),(0,l.kt)("td",{parentName:"tr",align:null},"1"),(0,l.kt)("td",{parentName:"tr",align:null},"ALU")))),(0,l.kt)("h2",{id:"single-cycle"},"Single Cycle"),(0,l.kt)("p",null,(0,l.kt)("img",{parentName:"p",src:"https://raw.githubusercontent.com/zxc2012/image/main/20220326210350.png",alt:"20220310173933"})),(0,l.kt)("p",null,"Critical Path:"),(0,l.kt)("p",null,"$t",(0,l.kt)("em",{parentName:"p"},"{Load}\\geq t"),"{clk-to-q}+t",(0,l.kt)("em",{parentName:"p"},"{IMEMread}+t"),"{RFRead}+t",(0,l.kt)("em",{parentName:"p"},"{mux}+t"),"{ALU}+t",(0,l.kt)("em",{parentName:"p"},"{DMEMRead}+t"),"{mux}+t_{RFsetup}$"),(0,l.kt)("p",null,"$t",(0,l.kt)("em",{parentName:"p"},"{Arithmetic I-Type}\\geq t"),"{clk-to-q}+t",(0,l.kt)("em",{parentName:"p"},"{IMEMread}+max(t"),"{RFRead},t",(0,l.kt)("em",{parentName:"p"},"{imm})+t"),"{mux}+t",(0,l.kt)("em",{parentName:"p"},"{ALU}+t"),"{mux}+t_{RFsetup}$"),(0,l.kt)("p",null,"$t",(0,l.kt)("em",{parentName:"p"},"{S-Type}\\geq t"),"{clk-to-q}+t",(0,l.kt)("em",{parentName:"p"},"{IMEMread}+t"),"{RFRead}+t",(0,l.kt)("em",{parentName:"p"},"{mux}+t"),"{ALU}+t",(0,l.kt)("em",{parentName:"p"},"{DMEMWrite}+t"),"{RFsetup}$"),(0,l.kt)("ul",null,(0,l.kt)("li",{parentName:"ul"},"R-Type\u3001Arithmetic I-Type\u3001SB-Type: No DMem"),(0,l.kt)("li",{parentName:"ul"},"Load I-Type: DMem Read"),(0,l.kt)("li",{parentName:"ul"},"S-Type: DMem Write,No second Mux(WB)"),(0,l.kt)("li",{parentName:"ul"},"U-Type: No $RF_{Read}$")),(0,l.kt)("p",null,"Note: ",(0,l.kt)("em",{parentName:"p"},"comparator is omitted because branch comparison is\ndone in parallel with RegFile/ALU, which takes much longer time.")),(0,l.kt)("p",null,"Control Logic"),(0,l.kt)("ul",null,(0,l.kt)("li",{parentName:"ul"},(0,l.kt)("p",{parentName:"li"},"ImmSel:"),(0,l.kt)("p",{parentName:"li"},"  ",(0,l.kt)("img",{parentName:"p",src:"https://raw.githubusercontent.com/zxc2012/image/main/20220331174415.png",alt:"20220331174415"})),(0,l.kt)("p",{parentName:"li"},"  ",(0,l.kt)("img",{parentName:"p",src:"https://raw.githubusercontent.com/zxc2012/image/main/20220326220059.png",alt:"20220310173933"}))),(0,l.kt)("li",{parentName:"ul"},(0,l.kt)("p",{parentName:"li"},"BrUn,BrEq,BrLT:"),(0,l.kt)("p",{parentName:"li"},"  ",(0,l.kt)("img",{parentName:"p",src:"https://raw.githubusercontent.com/zxc2012/image/main/20220326220429.png",alt:"20220310173933"}))),(0,l.kt)("li",{parentName:"ul"},(0,l.kt)("p",{parentName:"li"},"ALUSel: "),(0,l.kt)("p",{parentName:"li"},"  ",(0,l.kt)("img",{parentName:"p",src:"https://raw.githubusercontent.com/zxc2012/image/main/20220326211210.png",alt:"20220310173933"})))),(0,l.kt)("h2",{id:"pipelined"},"Pipelined"),(0,l.kt)("h3",{id:"overview"},"Overview"),(0,l.kt)("p",null,(0,l.kt)("img",{parentName:"p",src:"https://raw.githubusercontent.com/zxc2012/image/main/20220331211348.png",alt:"20220331211348"})),(0,l.kt)("p",null,"IF : $t",(0,l.kt)("em",{parentName:"p"},"{clk-to-q} + t"),"{IMEMread} + t_{Regsetup}$ "),(0,l.kt)("p",null,"ID : $t",(0,l.kt)("em",{parentName:"p"},"{clk-to-q}+ t"),"{RFread} + t_{Regsetup}$"),(0,l.kt)("p",null,"EX : $t",(0,l.kt)("em",{parentName:"p"},"{clk-to-q}+ t"),"{mux} + t",(0,l.kt)("em",{parentName:"p"},"{ALU} + t"),"{Regsetup}$ "),(0,l.kt)("p",null,"MEM : $t",(0,l.kt)("em",{parentName:"p"},"{clk-to-q} + t"),"{DMEMread} + t_{Regsetup}$ "),(0,l.kt)("p",null,"WB : $t",(0,l.kt)("em",{parentName:"p"},"{clk-to-q} + t"),"{mux} + t_{RFsetup}$"),(0,l.kt)("p",null,"$t_{clk}\\geq max(IF, ID, EX,MEM,WB)$"),(0,l.kt)("p",null,"Forwarding Path"),(0,l.kt)("p",null,"Compare destination of older instructions in pipeline with sources of new instruction in decode stage"),(0,l.kt)("p",null,(0,l.kt)("img",{parentName:"p",src:"https://raw.githubusercontent.com/zxc2012/image/main/20220617104410.png",alt:"20220331211348"})),(0,l.kt)("h3",{id:"hazard"},"Hazard"),(0,l.kt)("h4",{id:"structural-hazard"},"Structural Hazard"),(0,l.kt)("ul",null,(0,l.kt)("li",{parentName:"ul"},(0,l.kt)("p",{parentName:"li"},"Problem"),(0,l.kt)("p",{parentName:"li"},"  Two or more instructions in the pipeline compete for access to a single ",(0,l.kt)("strong",{parentName:"p"},"physical resource"))),(0,l.kt)("li",{parentName:"ul"},(0,l.kt)("p",{parentName:"li"},"Solution"),(0,l.kt)("pre",{parentName:"li"},(0,l.kt)("code",{parentName:"pre"},"- (1)Instructions take turns using resource, some\n")),(0,l.kt)("p",{parentName:"li"},"instructions have to stall (wait)"),(0,l.kt)("pre",{parentName:"li"},(0,l.kt)("code",{parentName:"pre"},"- (2)Add more hardware to machine\n")))),(0,l.kt)("p",null,"Example:"),(0,l.kt)("ol",null,(0,l.kt)("li",{parentName:"ol"},(0,l.kt)("p",{parentName:"li"},"RegFile Hazard"),(0,l.kt)("p",{parentName:"li"},(0,l.kt)("img",{parentName:"p",src:"https://raw.githubusercontent.com/zxc2012/image/main/20220401220248.png",alt:"20220310173933"})),(0,l.kt)("p",{parentName:"li"},"Solution:"),(0,l.kt)("ul",{parentName:"li"},(0,l.kt)("li",{parentName:"ul"},(0,l.kt)("p",{parentName:"li"},(0,l.kt)("strong",{parentName:"p"},"Double Pumping")," "),(0,l.kt)("p",{parentName:"li"},"  Prepare to write during 1st half, write on falling edge, read during 2nd half of each clock cycle")),(0,l.kt)("li",{parentName:"ul"},(0,l.kt)("p",{parentName:"li"},"Build RegFile with independent read and write ports")))),(0,l.kt)("li",{parentName:"ol"},(0,l.kt)("p",{parentName:"li"},"Memory"),(0,l.kt)("p",{parentName:"li"},(0,l.kt)("img",{parentName:"p",src:"https://raw.githubusercontent.com/zxc2012/image/main/20220402165402.png",alt:"20220310173933"})),(0,l.kt)("p",{parentName:"li"},"Solution:"),(0,l.kt)("p",{parentName:"li"},"Instruction and Data Caches\n",(0,l.kt)("img",{parentName:"p",src:"https://raw.githubusercontent.com/zxc2012/image/main/20220402165639.png",alt:"20220310173933"})))),(0,l.kt)("h4",{id:"data-hazard"},"Data Hazard"),(0,l.kt)("p",null,"Data dependency between instructions"),(0,l.kt)("ol",null,(0,l.kt)("li",{parentName:"ol"},(0,l.kt)("p",{parentName:"li"},"R Type Instructions"),(0,l.kt)("p",{parentName:"li"},(0,l.kt)("img",{parentName:"p",src:"https://raw.githubusercontent.com/zxc2012/image/main/20220402173254.png",alt:"20220402173254"})),(0,l.kt)("p",{parentName:"li"},"Solution"),(0,l.kt)("p",{parentName:"li"},"(1)Stalling"),(0,l.kt)("p",{parentName:"li"},"Bubble: NOP(add x0 x0 x0)"),(0,l.kt)("p",{parentName:"li"},(0,l.kt)("img",{parentName:"p",src:"https://raw.githubusercontent.com/zxc2012/image/main/20220402173525.png",alt:"20220402173254"})),(0,l.kt)("p",{parentName:"li"},"(2)Forwarding(Bypass)"),(0,l.kt)("p",{parentName:"li"},(0,l.kt)("img",{parentName:"p",src:"https://raw.githubusercontent.com/zxc2012/image/main/20220402173656.png",alt:"20220402173254"}))),(0,l.kt)("li",{parentName:"ol"},(0,l.kt)("p",{parentName:"li"},"Load"),(0,l.kt)("p",{parentName:"li"},"Forwarding Problem\n",(0,l.kt)("img",{parentName:"p",src:"https://raw.githubusercontent.com/zxc2012/image/main/20220402174121.png",alt:"20220402174121"})),(0,l.kt)("p",{parentName:"li"},"Solution"),(0,l.kt)("p",{parentName:"li"},"(1)Hardware Stall"),(0,l.kt)("p",{parentName:"li"},(0,l.kt)("img",{parentName:"p",src:"https://raw.githubusercontent.com/zxc2012/image/main/20220402211411.png",alt:"20220402174121"})),(0,l.kt)("p",{parentName:"li"},"(2)Stall"),(0,l.kt)("p",{parentName:"li"},(0,l.kt)("img",{parentName:"p",src:"https://raw.githubusercontent.com/zxc2012/image/main/20220402211539.png",alt:"20220402211539"})),(0,l.kt)("p",{parentName:"li"},"(3)Code Scheduling"),(0,l.kt)("p",{parentName:"li"},(0,l.kt)("img",{parentName:"p",src:"https://raw.githubusercontent.com/zxc2012/image/main/20220402211912.png",alt:"20220402211539"})))),(0,l.kt)("h4",{id:"control-hazard"},"Control Hazard"))}k.isMDXComponent=!0}}]);