"use strict";(self.webpackChunkChance=self.webpackChunkChance||[]).push([[1589],{7891:(a,e,t)=>{t.r(e),t.d(e,{assets:()=>l,contentTitle:()=>p,default:()=>o,frontMatter:()=>m,metadata:()=>r,toc:()=>i});var n=t(7462),s=(t(7294),t(3905));t(1839);const m={},p="CS61C Lecture5 --Parallelism",r={unversionedId:"cs/Computer_Architecture/cs61c_5",id:"cs/Computer_Architecture/cs61c_5",title:"CS61C Lecture5 --Parallelism",description:"Basics",source:"@site/docs/cs/Computer_Architecture/cs61c_5.md",sourceDirName:"cs/Computer_Architecture",slug:"/cs/Computer_Architecture/cs61c_5",permalink:"/docs/cs/Computer_Architecture/cs61c_5",draft:!1,editUrl:"https://github.com/zxc2012/zxc2012.github.io/tree/master/docs/cs/Computer_Architecture/cs61c_5.md",tags:[],version:"current",frontMatter:{},sidebar:"cs",previous:{title:"CS61C Lecture4 --Cache",permalink:"/docs/cs/Computer_Architecture/cs61c_4"},next:{title:"CS61C Lecture6 --Virtual Memory",permalink:"/docs/cs/Computer_Architecture/cs61c_6"}},l={},i=[{value:"Basics",id:"basics",level:2},{value:"Amdahl\u2019s Law",id:"amdahls-law",level:3},{value:"SIMD",id:"simd",level:2},{value:"SIMD Architecture",id:"simd-architecture",level:3},{value:"Example",id:"example",level:3},{value:"Loop Unrolling",id:"loop-unrolling",level:4},{value:"Matrix Multiply",id:"matrix-multiply",level:4},{value:"MIMD",id:"mimd",level:2},{value:"OpenMP",id:"openmp",level:3},{value:"Synchronization",id:"synchronization",level:4},{value:"Pitfalls",id:"pitfalls",level:4}],c={toc:i};function o(a){let{components:e,...t}=a;return(0,s.kt)("wrapper",(0,n.Z)({},c,t,{components:e,mdxType:"MDXLayout"}),(0,s.kt)("h1",{id:"cs61c-lecture5---parallelism"},"CS61C Lecture5 --Parallelism"),(0,s.kt)("h2",{id:"basics"},"Basics"),(0,s.kt)("p",null,(0,s.kt)("img",{parentName:"p",src:"https://raw.githubusercontent.com/zxc2012/image/main/20220428200039.png",alt:null})),(0,s.kt)("h3",{id:"amdahls-law"},"Amdahl\u2019s Law"),(0,s.kt)("p",null,(0,s.kt)("img",{parentName:"p",src:"https://raw.githubusercontent.com/zxc2012/image/main/20220428200528.png",alt:null})),(0,s.kt)("p",null,"Speedup =",(0,s.kt)("span",{parentName:"p",className:"math math-inline"},(0,s.kt)("span",{parentName:"span",className:"katex"},(0,s.kt)("span",{parentName:"span",className:"katex-mathml"},(0,s.kt)("math",{parentName:"span",xmlns:"http://www.w3.org/1998/Math/MathML"},(0,s.kt)("semantics",{parentName:"math"},(0,s.kt)("mrow",{parentName:"semantics"},(0,s.kt)("mfrac",{parentName:"mrow"},(0,s.kt)("msub",{parentName:"mfrac"},(0,s.kt)("mi",{parentName:"msub"},"t"),(0,s.kt)("mrow",{parentName:"msub"},(0,s.kt)("mi",{parentName:"mrow"},"p"),(0,s.kt)("mi",{parentName:"mrow"},"r"),(0,s.kt)("mi",{parentName:"mrow"},"e"),(0,s.kt)("mi",{parentName:"mrow"},"v"))),(0,s.kt)("msub",{parentName:"mfrac"},(0,s.kt)("mi",{parentName:"msub"},"t"),(0,s.kt)("mrow",{parentName:"msub"},(0,s.kt)("mi",{parentName:"mrow"},"c"),(0,s.kt)("mi",{parentName:"mrow"},"u"),(0,s.kt)("mi",{parentName:"mrow"},"r")))),(0,s.kt)("mo",{parentName:"mrow"},"="),(0,s.kt)("mfrac",{parentName:"mrow"},(0,s.kt)("mn",{parentName:"mfrac"},"1"),(0,s.kt)("mrow",{parentName:"mfrac"},(0,s.kt)("mo",{parentName:"mrow",stretchy:"false"},"("),(0,s.kt)("mn",{parentName:"mrow"},"1"),(0,s.kt)("mo",{parentName:"mrow"},"\u2212"),(0,s.kt)("mi",{parentName:"mrow"},"F"),(0,s.kt)("mo",{parentName:"mrow",stretchy:"false"},")"),(0,s.kt)("mo",{parentName:"mrow"},"+"),(0,s.kt)("mi",{parentName:"mrow"},"F"),(0,s.kt)("mi",{parentName:"mrow",mathvariant:"normal"},"/"),(0,s.kt)("mi",{parentName:"mrow"},"S")))),(0,s.kt)("annotation",{parentName:"semantics",encoding:"application/x-tex"},"\\frac{t_{prev}}{t_{cur}} = \\frac{1}{(1-F)+F/S}")))),(0,s.kt)("span",{parentName:"span",className:"katex-html","aria-hidden":"true"},(0,s.kt)("span",{parentName:"span",className:"base"},(0,s.kt)("span",{parentName:"span",className:"strut",style:{height:"1.383em",verticalAlign:"-0.4451em"}}),(0,s.kt)("span",{parentName:"span",className:"mord"},(0,s.kt)("span",{parentName:"span",className:"mopen nulldelimiter"}),(0,s.kt)("span",{parentName:"span",className:"mfrac"},(0,s.kt)("span",{parentName:"span",className:"vlist-t vlist-t2"},(0,s.kt)("span",{parentName:"span",className:"vlist-r"},(0,s.kt)("span",{parentName:"span",className:"vlist",style:{height:"0.9379em"}},(0,s.kt)("span",{parentName:"span",style:{top:"-2.655em"}},(0,s.kt)("span",{parentName:"span",className:"pstrut",style:{height:"3em"}}),(0,s.kt)("span",{parentName:"span",className:"sizing reset-size6 size3 mtight"},(0,s.kt)("span",{parentName:"span",className:"mord mtight"},(0,s.kt)("span",{parentName:"span",className:"mord mtight"},(0,s.kt)("span",{parentName:"span",className:"mord mathnormal mtight"},"t"),(0,s.kt)("span",{parentName:"span",className:"msupsub"},(0,s.kt)("span",{parentName:"span",className:"vlist-t vlist-t2"},(0,s.kt)("span",{parentName:"span",className:"vlist-r"},(0,s.kt)("span",{parentName:"span",className:"vlist",style:{height:"0.1645em"}},(0,s.kt)("span",{parentName:"span",style:{top:"-2.357em",marginLeft:"0em",marginRight:"0.0714em"}},(0,s.kt)("span",{parentName:"span",className:"pstrut",style:{height:"2.5em"}}),(0,s.kt)("span",{parentName:"span",className:"sizing reset-size3 size1 mtight"},(0,s.kt)("span",{parentName:"span",className:"mord mtight"},(0,s.kt)("span",{parentName:"span",className:"mord mathnormal mtight"},"c"),(0,s.kt)("span",{parentName:"span",className:"mord mathnormal mtight"},"u"),(0,s.kt)("span",{parentName:"span",className:"mord mathnormal mtight",style:{marginRight:"0.02778em"}},"r"))))),(0,s.kt)("span",{parentName:"span",className:"vlist-s"},"\u200b")),(0,s.kt)("span",{parentName:"span",className:"vlist-r"},(0,s.kt)("span",{parentName:"span",className:"vlist",style:{height:"0.143em"}},(0,s.kt)("span",{parentName:"span"}))))))))),(0,s.kt)("span",{parentName:"span",style:{top:"-3.23em"}},(0,s.kt)("span",{parentName:"span",className:"pstrut",style:{height:"3em"}}),(0,s.kt)("span",{parentName:"span",className:"frac-line",style:{borderBottomWidth:"0.04em"}})),(0,s.kt)("span",{parentName:"span",style:{top:"-3.5073em"}},(0,s.kt)("span",{parentName:"span",className:"pstrut",style:{height:"3em"}}),(0,s.kt)("span",{parentName:"span",className:"sizing reset-size6 size3 mtight"},(0,s.kt)("span",{parentName:"span",className:"mord mtight"},(0,s.kt)("span",{parentName:"span",className:"mord mtight"},(0,s.kt)("span",{parentName:"span",className:"mord mathnormal mtight"},"t"),(0,s.kt)("span",{parentName:"span",className:"msupsub"},(0,s.kt)("span",{parentName:"span",className:"vlist-t vlist-t2"},(0,s.kt)("span",{parentName:"span",className:"vlist-r"},(0,s.kt)("span",{parentName:"span",className:"vlist",style:{height:"0.1645em"}},(0,s.kt)("span",{parentName:"span",style:{top:"-2.357em",marginLeft:"0em",marginRight:"0.0714em"}},(0,s.kt)("span",{parentName:"span",className:"pstrut",style:{height:"2.5em"}}),(0,s.kt)("span",{parentName:"span",className:"sizing reset-size3 size1 mtight"},(0,s.kt)("span",{parentName:"span",className:"mord mtight"},(0,s.kt)("span",{parentName:"span",className:"mord mathnormal mtight"},"p"),(0,s.kt)("span",{parentName:"span",className:"mord mathnormal mtight"},"re"),(0,s.kt)("span",{parentName:"span",className:"mord mathnormal mtight",style:{marginRight:"0.03588em"}},"v"))))),(0,s.kt)("span",{parentName:"span",className:"vlist-s"},"\u200b")),(0,s.kt)("span",{parentName:"span",className:"vlist-r"},(0,s.kt)("span",{parentName:"span",className:"vlist",style:{height:"0.2819em"}},(0,s.kt)("span",{parentName:"span"})))))))))),(0,s.kt)("span",{parentName:"span",className:"vlist-s"},"\u200b")),(0,s.kt)("span",{parentName:"span",className:"vlist-r"},(0,s.kt)("span",{parentName:"span",className:"vlist",style:{height:"0.4451em"}},(0,s.kt)("span",{parentName:"span"}))))),(0,s.kt)("span",{parentName:"span",className:"mclose nulldelimiter"})),(0,s.kt)("span",{parentName:"span",className:"mspace",style:{marginRight:"0.2778em"}}),(0,s.kt)("span",{parentName:"span",className:"mrel"},"="),(0,s.kt)("span",{parentName:"span",className:"mspace",style:{marginRight:"0.2778em"}})),(0,s.kt)("span",{parentName:"span",className:"base"},(0,s.kt)("span",{parentName:"span",className:"strut",style:{height:"1.3651em",verticalAlign:"-0.52em"}}),(0,s.kt)("span",{parentName:"span",className:"mord"},(0,s.kt)("span",{parentName:"span",className:"mopen nulldelimiter"}),(0,s.kt)("span",{parentName:"span",className:"mfrac"},(0,s.kt)("span",{parentName:"span",className:"vlist-t vlist-t2"},(0,s.kt)("span",{parentName:"span",className:"vlist-r"},(0,s.kt)("span",{parentName:"span",className:"vlist",style:{height:"0.8451em"}},(0,s.kt)("span",{parentName:"span",style:{top:"-2.655em"}},(0,s.kt)("span",{parentName:"span",className:"pstrut",style:{height:"3em"}}),(0,s.kt)("span",{parentName:"span",className:"sizing reset-size6 size3 mtight"},(0,s.kt)("span",{parentName:"span",className:"mord mtight"},(0,s.kt)("span",{parentName:"span",className:"mopen mtight"},"("),(0,s.kt)("span",{parentName:"span",className:"mord mtight"},"1"),(0,s.kt)("span",{parentName:"span",className:"mbin mtight"},"\u2212"),(0,s.kt)("span",{parentName:"span",className:"mord mathnormal mtight",style:{marginRight:"0.13889em"}},"F"),(0,s.kt)("span",{parentName:"span",className:"mclose mtight"},")"),(0,s.kt)("span",{parentName:"span",className:"mbin mtight"},"+"),(0,s.kt)("span",{parentName:"span",className:"mord mathnormal mtight",style:{marginRight:"0.13889em"}},"F"),(0,s.kt)("span",{parentName:"span",className:"mord mtight"},"/"),(0,s.kt)("span",{parentName:"span",className:"mord mathnormal mtight",style:{marginRight:"0.05764em"}},"S")))),(0,s.kt)("span",{parentName:"span",style:{top:"-3.23em"}},(0,s.kt)("span",{parentName:"span",className:"pstrut",style:{height:"3em"}}),(0,s.kt)("span",{parentName:"span",className:"frac-line",style:{borderBottomWidth:"0.04em"}})),(0,s.kt)("span",{parentName:"span",style:{top:"-3.394em"}},(0,s.kt)("span",{parentName:"span",className:"pstrut",style:{height:"3em"}}),(0,s.kt)("span",{parentName:"span",className:"sizing reset-size6 size3 mtight"},(0,s.kt)("span",{parentName:"span",className:"mord mtight"},(0,s.kt)("span",{parentName:"span",className:"mord mtight"},"1"))))),(0,s.kt)("span",{parentName:"span",className:"vlist-s"},"\u200b")),(0,s.kt)("span",{parentName:"span",className:"vlist-r"},(0,s.kt)("span",{parentName:"span",className:"vlist",style:{height:"0.52em"}},(0,s.kt)("span",{parentName:"span"}))))),(0,s.kt)("span",{parentName:"span",className:"mclose nulldelimiter"}))))))),(0,s.kt)("p",null,"F = Fraction of execution time speed up"),(0,s.kt)("p",null,"S = Scale of improvement"),(0,s.kt)("h2",{id:"simd"},"SIMD"),(0,s.kt)("h3",{id:"simd-architecture"},"SIMD Architecture"),(0,s.kt)("p",null,(0,s.kt)("img",{parentName:"p",src:"https://raw.githubusercontent.com/zxc2012/image/main/20220505211439.png",alt:null})),(0,s.kt)("p",null,"X86 Intrinsics AVX Data Type"),(0,s.kt)("p",null,(0,s.kt)("img",{parentName:"p",src:"https://raw.githubusercontent.com/zxc2012/image/main/20220505211808.png",alt:null})),(0,s.kt)("p",null,"Intrinsics AVX Code nomenclature ","[\u02c8nom\u0259n\u02ccklet\u0283\u025a]",(0,s.kt)("inlineCode",{parentName:"p"},"name call")),(0,s.kt)("p",null,(0,s.kt)("img",{parentName:"p",src:"https://raw.githubusercontent.com/zxc2012/image/main/20220505212039.png",alt:null})),(0,s.kt)("p",null,(0,s.kt)("img",{parentName:"p",src:"https://raw.githubusercontent.com/zxc2012/image/main/20220505212550.png",alt:null})),(0,s.kt)("h3",{id:"example"},"Example"),(0,s.kt)("h4",{id:"loop-unrolling"},"Loop Unrolling"),(0,s.kt)("p",null,"Loop Unrolling in C"),(0,s.kt)("pre",null,(0,s.kt)("code",{parentName:"pre",className:"language-cpp"},"for(i=0; i<1000; i++)\n    x[i] = x[i] + s;\n//Unrolling\nfor(i=0; i<1000; i=i+4) {\n    x[i] = x[i] + s;\n    x[i+1] = x[i+1] + s;\n    x[i+2] = x[i+2] + s;\n    x[i+3] = x[i+3] + s;\n}\n")),(0,s.kt)("p",null,"RISCV"),(0,s.kt)("pre",null,(0,s.kt)("code",{parentName:"pre",className:"language-armasm"},"Loop:\nlw t0, 0(s0)\naddu t0,t0,s1 # add b to array element\nsw t0,0(s0) # store result\naddi s0,s0,4 # move to next element\nbne s0,s2,Loop # repeat Loop if not done\n\nUnrolling Loop:\nlw t0,0(s0)\nlw t1,4(s0)\nlw t2,8(s0)\nlw t3,12(s0) # 4 wide SIMD Load\nadd t0,t0,s1\nadd t1,t1,s1\nadd t2,t2,s1\nadd t3,t3,s1 # 4 wide SIMD Add\nsw t0,0(s0)\nsw t1,4(s0)\nsw t2,8(s0)\nsw t3,12(s0) # 4 wide SIMD Store\naddi s0,s0,16\nbne s0,s2,Loop\n")),(0,s.kt)("h4",{id:"matrix-multiply"},"Matrix Multiply"),(0,s.kt)("p",null,(0,s.kt)("img",{parentName:"p",src:"https://raw.githubusercontent.com/zxc2012/image/main/20220505213302.png",alt:null})),(0,s.kt)("p",null,(0,s.kt)("img",{parentName:"p",src:"https://raw.githubusercontent.com/zxc2012/image/main/20220505214347.png",alt:null})),(0,s.kt)("p",null,"Now, i\u3001j\u3001k are N, we divide i by 4 each block."),(0,s.kt)("p",null,"so C","[i][j]"," whole row can be divided by 4, each column entry(j) can be divided by N(k)"),(0,s.kt)("pre",null,(0,s.kt)("code",{parentName:"pre",className:"language-cpp"},"#include <x86intrin.h>\nvoid mm_scalar(int N, double *a, double *b, double *c) {\n    for(int i=0;i<N;i+=4){\n        for(int j=0;j<N;++j){\n            __m256d c0 = {0,0,0,0};\n            for (k = 0; k < N; k++) {\n                c0 = _mm_add_pd(c0,_mm_mul_pd(_mm_load_pd(a+i+k*N),_mm_load1_pd(b+k+j*N)))\n                //c0 += a[i][k] * b[k][j]\n            }\n            _mm_store_pd(c+i+j*N,c0);\n        }\n    }\n    return 0;\n}\nconst int UNROLL = 4;\n// Unrolling\nvoid mm_unroll(int N, double *A, double *B, double *C) {\n    for (int i=0;  i<n;  i+= UNROLL*4) {\n        for (int j=0;  j<n;  j++) {\n            __m256d c[4];\n            for (int x=0;  x<UNROLL;  x++)\n                c[x] = _mm_load_pd(C+i+x*4+j*N);\n            for (int k=0;  k<n;  k++) {\n                __m256d b = _mm_load1_pd(B+k+j*n);\n                for (int x=0;  x<UNROLL;  x++)\n                    c[x] = _mm_add_pd(c[x],\n                           _mm_mul_pd(_mm_load_pd(A+i+x*4+k*N), b));\n            }\n            for (int x=0;  x<UNROLL;  x++) \n                _mm_store_pd(C+i+x*4+j*N, c[x]);     \n        }\n    }\n}\n// Cache Blocking\nconst int BLOCKSIZE = 32;\n\nvoid do_block(int n, int si, int sj, int sk, double *A, double *B, double *C) {\n    for (int i=si;  i<si+BLOCKSIZE;  i+=UNROLL*4)\n        for (int j=sj;  j<sj+BLOCKSIZE;  j++) {\n            __m256d c[4];\n            for (int x=0;  x<UNROLL;  x++)\n                c[x] = _mm_load_pd(C+i+x*4+j*N);\n            for (int k=sk;  k<sk+BLOCKSIZE;  k++) {\n                __m256d b = _mm_load1_pd(B+k+j*n);\n                for (int x=0;  x<UNROLL;  x++)\n                    c[x] = _mm_add_pd(c[x],\n                           _mm_mul_pd(_mm_load_pd(A+i+x*4+k*N), b));\n            }\n            for (int x=0;  x<UNROLL;  x++) \n                _mm_store_pd(C+i+x*4+j*N, c[x]); \n        }\n}\n\nvoid mm_block(int n, double* A, double* B, double* C) {\n    for(int sj=0;  sj<n;  sj+=BLOCKSIZE) \n        for(int si=0;  si<n;  si+=BLOCKSIZE)\n            for (int sk=0;  sk<n;  sk += BLOCKSIZE)\n                do_block(n, si, sj, sk, A, B, C);\n}\n\n")),(0,s.kt)("h2",{id:"mimd"},"MIMD"),(0,s.kt)("h3",{id:"openmp"},"OpenMP"),(0,s.kt)("h4",{id:"synchronization"},"Synchronization"),(0,s.kt)("p",null,"Reduction: specifies that 1 or more variables that are private to each thread are subject of ",(0,s.kt)("em",{parentName:"p"},"reduction")," operation at ",(0,s.kt)("strong",{parentName:"p"},"end")," of parallel region"),(0,s.kt)("pre",null,(0,s.kt)("code",{parentName:"pre",className:"language-cpp"},"double compute_sum(double *a, int a_len) {\n    double sum = 0.0;\n    #pragma omp parallel for reduction(+ : sum)\n    for (int i = 0; i < a_len; i++) {\n        sum += a[i];\n    }\n    return sum;\n}\n")),(0,s.kt)("h4",{id:"pitfalls"},"Pitfalls"),(0,s.kt)("ul",null,(0,s.kt)("li",{parentName:"ul"},(0,s.kt)("p",{parentName:"li"},"Data dependencies"),(0,s.kt)("pre",{parentName:"li"},(0,s.kt)("code",{parentName:"pre",className:"language-cpp"},"a[0] = 1;\nfor(i=1; i<5000; i++)\n    a[i] = i + a[i-1];\n"))),(0,s.kt)("li",{parentName:"ul"},(0,s.kt)("p",{parentName:"li"},"Sharing Issues"),(0,s.kt)("pre",{parentName:"li"},(0,s.kt)("code",{parentName:"pre",className:"language-cpp"},"// Problem\n#pragma omp parallel for //Each thread accesses different elements of a, b,and c, but the same temp\nfor(i=0; i<n; i++){\n    temp = 2.0*a[i];\n    a[i] = temp;\n    b[i] = c[i]/temp;\n} \n// Correct\n#pragma omp parallel for private(temp)\nfor(i=0; i<n; i++){\n    temp = 2.0*a[i];\n    a[i] = temp;\n    b[i] = c[i]/temp;\n}\n"))),(0,s.kt)("li",{parentName:"ul"},(0,s.kt)("p",{parentName:"li"},"Updating Shared Variables Simultaneously "),(0,s.kt)("p",{parentName:"li"},"  This can be done by surrounding the summation by a critical/atomic section or reduction clause")),(0,s.kt)("li",{parentName:"ul"},(0,s.kt)("p",{parentName:"li"},"Parallel Overhead"),(0,s.kt)("p",{parentName:"li"},"  Parallelize over the largest loop that you can (even though it will involve more work to declare all of the private variables and eliminate dependencies)"))))}o.isMDXComponent=!0}}]);