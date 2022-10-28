# Java Application Design--Containers

## Introduction

Containers

- Collection
  - list:hold the element in a particular sequence 
  - set
- Map: key-value object pairs

![在这里插入图片描述](https://img-blog.csdnimg.cn/20201016212410955.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM5MzgwMjMw,size_16,color_FFFFFF,t_70#pic_center)

## Collection
### Function

![在这里插入图片描述](https://img-blog.csdnimg.cn/2020101715285823.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM5MzgwMjMw,size_16,color_FFFFFF,t_70#pic_center)

![在这里插入图片描述](https://img-blog.csdnimg.cn/20201016210354543.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM5MzgwMjMw,size_16,color_FFFFFF,t_70#pic_center)

![在这里插入图片描述](https://img-blog.csdnimg.cn/2020101621042813.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM5MzgwMjMw,size_16,color_FFFFFF,t_70#pic_center)

### List

- ArrayList: implement with an array, slow for inserting and removing.
- LinkedList: inexpensive insertions and deletions, slow for random access.

![在这里插入图片描述](https://img-blog.csdnimg.cn/20201016210913913.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM5MzgwMjMw,size_16,color_FFFFFF,t_70#pic_center)

Deque[dek]--double ended queue

![在这里插入图片描述](https://img-blog.csdnimg.cn/20201016211342737.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM5MzgwMjMw,size_16,color_FFFFFF,t_70#pic_center)

### Set

- HashSet: Objects must also define hashCode()
- TreeSet: An ordered Set backed by a tree.

## Map

- HashMap
- TreeMap

## Generics

:::tip
无论是什么泛型，getClass()均是同一个
:::

### 机制

Java--类型参数(**Cannot use primitive types**)作为类的成员变量

C++(模板)--源代码的源代码

### Class

```java
public class ArrayMap<K, V> {
  private K[] keys; 
  private V[] values;
  private int size;
  public ArrayMap() {
    keys = (K[]) new Object[100];
    values = (V[]) new Object[100];
    size = 0;
  }
  public void put(K key, V value) {
    int i = getKeyIndex(key);
    if (i > -1) {
      values[i] = value; return; }
    keys[size] = key;
    values[size] = value;
    size += 1;	
  } 

  public V get(K key) {       
    return values[findKey(key)];
  }
  public static void main(String[] args){
    ArrayMap<Integer, String> ismap = new ArrayMap<Integer, String>();
    ismap.put(5, "hello");
    ismap.put(10, "ketchup");
  }
}
```

### Method

Create a class MapHelper with two methods:
- get(key): Returns the item in the map if it exists, otherwise null.
- maxKey(): Returns the maximum of all keys. Works only if keys can be compared.
- allBark(): Makes all keys bark. Works only for keys of type Dog.

Implement get():

![20221028105223](https://raw.githubusercontent.com/zxc2012/image/main/20221028105223.png)

#### Type Upperbound

Implement maxKey():

![20221028105644](https://raw.githubusercontent.com/zxc2012/image/main/20221028105644.png)

Can use extends keyword as a type upper bound. Only allow use on ArrayMaps with Comparable keys.

```java
public static <K extends Comparable<K>, V> K maxKey(ArrayMap<K, V> am) {//Meaning: Any ArrayMap you give me must have actual parameter type that is a subtype of Comparable<T>.

   ...
     	if (k.compareTo(largest) > 0) {
   ...
}
```

#### Convariance 

Implement allBark():

```java
ArrayMap<FrenchDog, Integer> am2 = new ArrayMap<FrenchDog, Integer>();
am2.put(new FrenchDog("francis"), 10);
am2.put(new FrenchDog("francis jr"), 20);
allBark(am2);

//Method1: generic method
public static <V> void allBark(ArrayMap<Dog, V> am) {
   for (Dog d : am.keys()) {
       d.bark(); 	
   }
}

//Method2: WildCard
/*
public static void allBark(ArrayMap<Dog, ?> am) {
   for (Dog d : am.keys()) {
       d.bark(); 	
   }
}
*/
```
:::danger

MapHelper.java:62: error: incompatible types: ArrayMap<FrenchDog,Integer> cannot be converted to ArrayMap<Dog,?>

:::

Arrays are convariant in java, but generic types are invariant

反证: 
if 2(√) then 4(x) so 2(x)

```java
List<FrenchDog> fg = new ArrayList<FrenchDog>();
List<Dog> g = fg;
g.add(new Dog());
FrenchDog s = g.get(0);
```

Fix

```java
//正确
public static <K extends Dog> void allBark(ArrayMap<K, ?> am) {
   for (Dog d : am.keys()) {
       d.bark();
   }
}
//or 
public static void allBark(ArrayMap<?extends Dog,?> am){
    for(Dog d : am.keys()){
        d.bark();
    }
}

```