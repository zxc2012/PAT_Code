Cpp:PAT甲级/乙级 g++4.72

py:python学习

### `Markdown:`
#### 自动发博客
在本地.git/hooks/目录下添加./cnblogs_automatic_blog_uploading/hooks下内容
>chmod - change file mode bits

>x execute (or search for directories) 
#### Cpp
 - [树](Cpp/markdown/tree.md)
 - [图](Cpp/markdown/graph.md)
 - [搜索](Cpp/markdown/searching.md)
 - [STL](Cpp/markdown/map.md)
 - [暴力求解，数论](Cpp/markdown/base.md)
 - [动态规划](Cpp/markdown/dp.md)

#### Py
 - [文本分类](py/markdown/classify.md)

### `Jupyter Notebook`

nohup jupyter notebook --allow-root &

### `Git Notes`

Git_Code ctrl+~运行bash终端

- local repository

```bash
git init:添加.git
touch README.md
git add README.md
git commit -m ""
```
```matlab
fatal: The remote end hung up unexpectedly
法1:$ git config --local http.postBuffer 524288000
法2:修改config文件
[http]
    postBuffer = 524288000 //500MB
``` 
-  git web server
    - git config --global user.name "zxc2012"
    - git config --global user.email "xxxxxxx@xxx.com"
    - git remote add origin https://github.com/zxc2012/Algorithm_post_graduate.git
    - git push -u origin main

![avatar](https://img-blog.csdn.net/2018052909403110)

Cpp/Py:打开对应文件夹可以单独调试

### `DevCpp配置`
>Tools--Compiler Options--General--Add the following commands when calling compiler---std=c++11

![Devcpp](https://img-blog.csdn.net/20170409111041454)
>Settings-linker-Generate debugging information-Yes

![Devcpp](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9pLmxvbGkubmV0LzIwMTkvMDcvMTkvNWQzMWUyMTc4MDExNjkzNzUwLnBuZw)
