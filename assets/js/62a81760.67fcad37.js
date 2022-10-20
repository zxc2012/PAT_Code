"use strict";(self.webpackChunkChance=self.webpackChunkChance||[]).push([[973],{3905:(e,n,t)=>{t.d(n,{Zo:()=>s,kt:()=>d});var a=t(7294);function r(e,n,t){return n in e?Object.defineProperty(e,n,{value:t,enumerable:!0,configurable:!0,writable:!0}):e[n]=t,e}function i(e,n){var t=Object.keys(e);if(Object.getOwnPropertySymbols){var a=Object.getOwnPropertySymbols(e);n&&(a=a.filter((function(n){return Object.getOwnPropertyDescriptor(e,n).enumerable}))),t.push.apply(t,a)}return t}function l(e){for(var n=1;n<arguments.length;n++){var t=null!=arguments[n]?arguments[n]:{};n%2?i(Object(t),!0).forEach((function(n){r(e,n,t[n])})):Object.getOwnPropertyDescriptors?Object.defineProperties(e,Object.getOwnPropertyDescriptors(t)):i(Object(t)).forEach((function(n){Object.defineProperty(e,n,Object.getOwnPropertyDescriptor(t,n))}))}return e}function o(e,n){if(null==e)return{};var t,a,r=function(e,n){if(null==e)return{};var t,a,r={},i=Object.keys(e);for(a=0;a<i.length;a++)t=i[a],n.indexOf(t)>=0||(r[t]=e[t]);return r}(e,n);if(Object.getOwnPropertySymbols){var i=Object.getOwnPropertySymbols(e);for(a=0;a<i.length;a++)t=i[a],n.indexOf(t)>=0||Object.prototype.propertyIsEnumerable.call(e,t)&&(r[t]=e[t])}return r}var c=a.createContext({}),p=function(e){var n=a.useContext(c),t=n;return e&&(t="function"==typeof e?e(n):l(l({},n),e)),t},s=function(e){var n=p(e.components);return a.createElement(c.Provider,{value:n},e.children)},m={inlineCode:"code",wrapper:function(e){var n=e.children;return a.createElement(a.Fragment,{},n)}},u=a.forwardRef((function(e,n){var t=e.components,r=e.mdxType,i=e.originalType,c=e.parentName,s=o(e,["components","mdxType","originalType","parentName"]),u=p(t),d=r,k=u["".concat(c,".").concat(d)]||u[d]||m[d]||i;return t?a.createElement(k,l(l({ref:n},s),{},{components:t})):a.createElement(k,l({ref:n},s))}));function d(e,n){var t=arguments,r=n&&n.mdxType;if("string"==typeof e||r){var i=t.length,l=new Array(i);l[0]=u;var o={};for(var c in n)hasOwnProperty.call(n,c)&&(o[c]=n[c]);o.originalType=e,o.mdxType="string"==typeof e?e:r,l[1]=o;for(var p=2;p<i;p++)l[p]=t[p];return a.createElement.apply(null,l)}return a.createElement.apply(null,t)}u.displayName="MDXCreateElement"},3734:(e,n,t)=>{t.r(n),t.d(n,{assets:()=>c,contentTitle:()=>l,default:()=>m,frontMatter:()=>i,metadata:()=>o,toc:()=>p});var a=t(7462),r=(t(7294),t(3905));const i={},l="CS61C Lecture5 --Parallelism",o={unversionedId:"cs/cs61c_5",id:"cs/cs61c_5",title:"CS61C Lecture5 --Parallelism",description:"Basics",source:"@site/docs/cs/cs61c_5.md",sourceDirName:"cs",slug:"/cs/cs61c_5",permalink:"/docs/cs/cs61c_5",draft:!1,editUrl:"https://github.com/zxc2012/zxc2012.github.io/tree/master/docs/cs/cs61c_5.md",tags:[],version:"current",frontMatter:{},sidebar:"cs",previous:{title:"CS61C Lecture4 --Cache",permalink:"/docs/cs/cs61c_4"},next:{title:"CS61C Lecture6 --Virtual Memory",permalink:"/docs/cs/cs61c_6"}},c={},p=[{value:"Basics",id:"basics",level:2},{value:"Amdahl\u2019s Law",id:"amdahls-law",level:3},{value:"SIMD",id:"simd",level:2},{value:"SIMD Architecture",id:"simd-architecture",level:3},{value:"Example",id:"example",level:3},{value:"Loop Unrolling",id:"loop-unrolling",level:4},{value:"Matrix Multiply",id:"matrix-multiply",level:4},{value:"MIMD",id:"mimd",level:2},{value:"OpenMP",id:"openmp",level:3},{value:"Synchronization",id:"synchronization",level:4},{value:"Pitfalls",id:"pitfalls",level:4}],s={toc:p};function m(e){let{components:n,...t}=e;return(0,r.kt)("wrapper",(0,a.Z)({},s,t,{components:n,mdxType:"MDXLayout"}),(0,r.kt)("h1",{id:"cs61c-lecture5---parallelism"},"CS61C Lecture5 --Parallelism"),(0,r.kt)("h2",{id:"basics"},"Basics"),(0,r.kt)("p",null,(0,r.kt)("img",{parentName:"p",src:"https://raw.githubusercontent.com/zxc2012/image/main/20220428200039.png",alt:null})),(0,r.kt)("h3",{id:"amdahls-law"},"Amdahl\u2019s Law"),(0,r.kt)("p",null,(0,r.kt)("img",{parentName:"p",src:"https://raw.githubusercontent.com/zxc2012/image/main/20220428200528.png",alt:null})),(0,r.kt)("p",null,"Speedup =$\\frac{t",(0,r.kt)("em",{parentName:"p"},"{prev}}{t"),"{cur}} = \\frac{1}{(1-F)+F/S}$"),(0,r.kt)("p",null,"F = Fraction of execution time speed up"),(0,r.kt)("p",null,"S = Scale of improvement"),(0,r.kt)("h2",{id:"simd"},"SIMD"),(0,r.kt)("h3",{id:"simd-architecture"},"SIMD Architecture"),(0,r.kt)("p",null,(0,r.kt)("img",{parentName:"p",src:"https://raw.githubusercontent.com/zxc2012/image/main/20220505211439.png",alt:null})),(0,r.kt)("p",null,"X86 Intrinsics AVX Data Type"),(0,r.kt)("p",null,(0,r.kt)("img",{parentName:"p",src:"https://raw.githubusercontent.com/zxc2012/image/main/20220505211808.png",alt:null})),(0,r.kt)("p",null,"Intrinsics AVX Code nomenclature ","[\u02c8nom\u0259n\u02ccklet\u0283\u025a]",(0,r.kt)("inlineCode",{parentName:"p"},"name call")),(0,r.kt)("p",null,(0,r.kt)("img",{parentName:"p",src:"https://raw.githubusercontent.com/zxc2012/image/main/20220505212039.png",alt:null})),(0,r.kt)("p",null,(0,r.kt)("img",{parentName:"p",src:"https://raw.githubusercontent.com/zxc2012/image/main/20220505212550.png",alt:null})),(0,r.kt)("h3",{id:"example"},"Example"),(0,r.kt)("h4",{id:"loop-unrolling"},"Loop Unrolling"),(0,r.kt)("p",null,"Loop Unrolling in C"),(0,r.kt)("pre",null,(0,r.kt)("code",{parentName:"pre",className:"language-cpp"},"for(i=0; i<1000; i++)\n    x[i] = x[i] + s;\n//Unrolling\nfor(i=0; i<1000; i=i+4) {\n    x[i] = x[i] + s;\n    x[i+1] = x[i+1] + s;\n    x[i+2] = x[i+2] + s;\n    x[i+3] = x[i+3] + s;\n}\n")),(0,r.kt)("p",null,"RISCV"),(0,r.kt)("pre",null,(0,r.kt)("code",{parentName:"pre",className:"language-armasm"},"Loop:\nlw t0, 0(s0)\naddu t0,t0,s1 # add b to array element\nsw t0,0(s0) # store result\naddi s0,s0,4 # move to next element\nbne s0,s2,Loop # repeat Loop if not done\n\nUnrolling Loop:\nlw t0,0(s0)\nlw t1,4(s0)\nlw t2,8(s0)\nlw t3,12(s0) # 4 wide SIMD Load\nadd t0,t0,s1\nadd t1,t1,s1\nadd t2,t2,s1\nadd t3,t3,s1 # 4 wide SIMD Add\nsw t0,0(s0)\nsw t1,4(s0)\nsw t2,8(s0)\nsw t3,12(s0) # 4 wide SIMD Store\naddi s0,s0,16\nbne s0,s2,Loop\n")),(0,r.kt)("h4",{id:"matrix-multiply"},"Matrix Multiply"),(0,r.kt)("p",null,(0,r.kt)("img",{parentName:"p",src:"https://raw.githubusercontent.com/zxc2012/image/main/20220505213302.png",alt:null})),(0,r.kt)("p",null,(0,r.kt)("img",{parentName:"p",src:"https://raw.githubusercontent.com/zxc2012/image/main/20220505214347.png",alt:null})),(0,r.kt)("p",null,"Now, i\u3001j\u3001k are N, we divide i by 4 each block."),(0,r.kt)("p",null,"so C","[i][j]"," whole row can be divided by 4, each column entry(j) can be divided by N(k)"),(0,r.kt)("pre",null,(0,r.kt)("code",{parentName:"pre",className:"language-cpp"},"#include <x86intrin.h>\nvoid mm_scalar(int N, double *a, double *b, double *c) {\n    for(int i=0;i<N;i+=4){\n        for(int j=0;j<N;++j){\n            __m256d c0 = {0,0,0,0};\n            for (k = 0; k < N; k++) {\n                c0 = _mm_add_pd(c0,_mm_mul_pd(_mm_load_pd(a+i+k*N),_mm_load1_pd(b+k+j*N)))\n                //c0 += a[i][k] * b[k][j]\n            }\n            _mm_store_pd(c+i+j*N,c0);\n        }\n    }\n    return 0;\n}\nconst int UNROLL = 4;\n// Unrolling\nvoid mm_unroll(int N, double *A, double *B, double *C) {\n    for (int i=0;  i<n;  i+= UNROLL*4) {\n        for (int j=0;  j<n;  j++) {\n            __m256d c[4];\n            for (int x=0;  x<UNROLL;  x++)\n                c[x] = _mm_load_pd(C+i+x*4+j*N);\n            for (int k=0;  k<n;  k++) {\n                __m256d b = _mm_load1_pd(B+k+j*n);\n                for (int x=0;  x<UNROLL;  x++)\n                    c[x] = _mm_add_pd(c[x],\n                           _mm_mul_pd(_mm_load_pd(A+i+x*4+k*N), b));\n            }\n            for (int x=0;  x<UNROLL;  x++) \n                _mm_store_pd(C+i+x*4+j*N, c[x]);     \n        }\n    }\n}\n// Cache Blocking\nconst int BLOCKSIZE = 32;\n\nvoid do_block(int n, int si, int sj, int sk, double *A, double *B, double *C) {\n    for (int i=si;  i<si+BLOCKSIZE;  i+=UNROLL*4)\n        for (int j=sj;  j<sj+BLOCKSIZE;  j++) {\n            __m256d c[4];\n            for (int x=0;  x<UNROLL;  x++)\n                c[x] = _mm_load_pd(C+i+x*4+j*N);\n            for (int k=sk;  k<sk+BLOCKSIZE;  k++) {\n                __m256d b = _mm_load1_pd(B+k+j*n);\n                for (int x=0;  x<UNROLL;  x++)\n                    c[x] = _mm_add_pd(c[x],\n                           _mm_mul_pd(_mm_load_pd(A+i+x*4+k*N), b));\n            }\n            for (int x=0;  x<UNROLL;  x++) \n                _mm_store_pd(C+i+x*4+j*N, c[x]); \n        }\n}\n\nvoid mm_block(int n, double* A, double* B, double* C) {\n    for(int sj=0;  sj<n;  sj+=BLOCKSIZE) \n        for(int si=0;  si<n;  si+=BLOCKSIZE)\n            for (int sk=0;  sk<n;  sk += BLOCKSIZE)\n                do_block(n, si, sj, sk, A, B, C);\n}\n\n")),(0,r.kt)("h2",{id:"mimd"},"MIMD"),(0,r.kt)("h3",{id:"openmp"},"OpenMP"),(0,r.kt)("h4",{id:"synchronization"},"Synchronization"),(0,r.kt)("p",null,"Reduction: specifies that 1 or more variables that are private to each thread are subject of ",(0,r.kt)("em",{parentName:"p"},"reduction")," operation at ",(0,r.kt)("strong",{parentName:"p"},"end")," of parallel region"),(0,r.kt)("pre",null,(0,r.kt)("code",{parentName:"pre",className:"language-cpp"},"double compute_sum(double *a, int a_len) {\n    double sum = 0.0;\n    #pragma omp parallel for reduction(+ : sum)\n    for (int i = 0; i < a_len; i++) {\n        sum += a[i];\n    }\n    return sum;\n}\n")),(0,r.kt)("h4",{id:"pitfalls"},"Pitfalls"),(0,r.kt)("ul",null,(0,r.kt)("li",{parentName:"ul"},(0,r.kt)("p",{parentName:"li"},"Data dependencies"),(0,r.kt)("pre",{parentName:"li"},(0,r.kt)("code",{parentName:"pre",className:"language-cpp"},"a[0] = 1;\nfor(i=1; i<5000; i++)\n    a[i] = i + a[i-1];\n"))),(0,r.kt)("li",{parentName:"ul"},(0,r.kt)("p",{parentName:"li"},"Sharing Issues"),(0,r.kt)("pre",{parentName:"li"},(0,r.kt)("code",{parentName:"pre",className:"language-cpp"},"// Problem\n#pragma omp parallel for //Each thread accesses different elements of a, b,and c, but the same temp\nfor(i=0; i<n; i++){\n    temp = 2.0*a[i];\n    a[i] = temp;\n    b[i] = c[i]/temp;\n} \n// Correct\n#pragma omp parallel for private(temp)\nfor(i=0; i<n; i++){\n    temp = 2.0*a[i];\n    a[i] = temp;\n    b[i] = c[i]/temp;\n}\n"))),(0,r.kt)("li",{parentName:"ul"},(0,r.kt)("p",{parentName:"li"},"Updating Shared Variables Simultaneously "),(0,r.kt)("p",{parentName:"li"},"  This can be done by surrounding the summation by a critical/atomic section or reduction clause")),(0,r.kt)("li",{parentName:"ul"},(0,r.kt)("p",{parentName:"li"},"Parallel Overhead"),(0,r.kt)("p",{parentName:"li"},"  Parallelize over the largest loop that you can (even though it will involve more work to declare all of the private variables and eliminate dependencies)"))))}m.isMDXComponent=!0}}]);