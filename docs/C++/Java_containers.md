# Java Application Design--Containers

## Introduction

Two Containers:**Collection** and **Map**

1.Collection:

**list**:hold the element in a particular sequence 

**set**

2.Map:
key-value object pairs
![在这里插入图片描述](https://img-blog.csdnimg.cn/20201016212410955.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM5MzgwMjMw,size_16,color_FFFFFF,t_70#pic_center)

## Collection
### Function
![在这里插入图片描述](https://img-blog.csdnimg.cn/2020101715285823.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM5MzgwMjMw,size_16,color_FFFFFF,t_70#pic_center)

![在这里插入图片描述](https://img-blog.csdnimg.cn/20201016210354543.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM5MzgwMjMw,size_16,color_FFFFFF,t_70#pic_center)
![在这里插入图片描述](https://img-blog.csdnimg.cn/2020101621042813.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM5MzgwMjMw,size_16,color_FFFFFF,t_70#pic_center)
### List

1.**ArrayList**:implement with an array,slow for inserting and removing.

2.**LinkedList**:inexpensive insertions and deletions,slow for random access.
![在这里插入图片描述](https://img-blog.csdnimg.cn/20201016210913913.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM5MzgwMjMw,size_16,color_FFFFFF,t_70#pic_center)
Deque[dek]--double ended queue
![在这里插入图片描述](https://img-blog.csdnimg.cn/20201016211342737.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM5MzgwMjMw,size_16,color_FFFFFF,t_70#pic_center)

### Set

1.**HashSet**:Objects must also define hashCode()

2.**TreeSet**:An ordered Set backed by a tree.

## Map

**HashMap** and **TreeMap**
## Generics
`注意无论是什么泛型，类型均是同一个`

### 机制
Java--类型参数作为类的成员变量

C++(模板)--源代码的源代码

### Method
我们知道String可以赋值给Object，但Object不能赋给String--反推2
![在这里插入图片描述](https://img-blog.csdnimg.cn/20201017155012620.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM5MzgwMjMw,size_16,color_FFFFFF,t_70#pic_center)
加进来的时候得限定不然成了Object，不能调用接口的方法
![在这里插入图片描述](https://img-blog.csdnimg.cn/20201017160239945.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM5MzgwMjMw,size_16,color_FFFFFF,t_70#pic_center)
