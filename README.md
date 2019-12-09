Cpp:PAT甲级/乙级 g++4.72

py:python学习

### `Markdown:`
 - [树](https://github.com/zxc2012/Algorithm_post_graduate/blob/master/Cpp/markdown/tree.md)
 - [图](https://github.com/zxc2012/Algorithm_post_graduate/blob/master/Cpp/markdown/graph.md)
 - [搜索](https://github.com/zxc2012/Algorithm_post_graduate/blob/master/Cpp/markdown/searching.md)
 - [STL](https://github.com/zxc2012/Algorithm_post_graduate/blob/master/Cpp/markdown/map.md)
 - [暴力求解，数论](https://github.com/zxc2012/Algorithm_post_graduate/blob/master/Cpp/markdown/base.md)

### `Structure:`

Git_Code ctrl+~运行bash终端

- git init:添加.git

```
touch README.md
git add README.md
```
```matlab
fatal: The remote end hung up unexpectedly
法1:$ git config --local http.postBuffer 524288000
法2:修改config文件
[http]
    postBuffer = 524288000 //500MB
``` 
- git config --global user.name "zxc2012"

- git config --global user.email "xxxxxxx@xxx.com"

- 远程仓库地址
git remote add origin https://github.com/zxc2012/Algorithm_post_graduate.git

![avatar](https://img-blog.csdn.net/2018052909403110)

Cpp/Py:打开对应文件夹可以单独调试

`DevCpp配置`
>Tools--Compiler Options--General--Add the following commands when calling compiler---std=c++11

![Devcpp](https://img-blog.csdn.net/20170409111041454)
>Settings-linker-Generate debugging information-Yes

![Devcpp](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9pLmxvbGkubmV0LzIwMTkvMDcvMTkvNWQzMWUyMTc4MDExNjkzNzUwLnBuZw)
