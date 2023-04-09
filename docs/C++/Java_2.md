# 2 Collection
## Collection

Deque[dek]--double ended queue

![20221031160055](https://raw.githubusercontent.com/zxc2012/image/main/20221031160055.png)

```java
Interface Iterable<T>{
  default void forEach(Consumer<? super T> action)//Performs the given action for each element of the Iterable until all elements have been processed or the action throws an exception.
  Iterator<T> iterator()//Returns an iterator over elements of type T.
}
public interface Collection<E> extends Iterable<E>{
  int size();
  boolean add(E e);
  boolean addAll(Collection<? extends E> c);
  void clear();
  boolean contains(Object);
  boolean containsAll(Collection<?> c);
  boolean isEmpty();
  default Stream<E>	stream();//Returns a sequential Stream with this collection as its source.
  default Stream<E>	parallelStream();//Returns a possibly parallel Stream with this collection as its source.
  boolean remove(Object o);
  boolean removeAll(Collection<?> c);
  boolean retainAll(Collection<?> c);//Retains only the elements in this collection that are contained in the specified collection 
  Object[] toArray();//Returns an array containing all of the elements in this collection.
  <T> T[] toArray(T[] a);
}
```

Consumer Inferface

```java
@FunctionalInterface
public interface Consumer<T>{
  void accept(T t);
}
```

### List

- ArrayList: implement with an array, slow for inserting and removing.
- LinkedList: inexpensive insertions and deletions, slow for random access.

  - LinkedList is a doubly-linked list implementation of the List and Deque interfaces

### Set

- HashSet: Objects must also define hashCode()
- TreeSet: An ordered Set backed by a tree.

## Map

![20221031212205](https://raw.githubusercontent.com/zxc2012/image/main/20221031212205.png)

```java
public interface Map<K,V>{
  int size();
  void clear();
  boolean containsKey(Object key);
  boolean containsValue(Object value);
  default void forEach(BiConsumer<? super K,? super V> action);
  V get(Object key);//Returns the value or null
  boolean isEmpty();
  V remove(Object key);
  default V	replace(K key, V value);
}
```
## Collections

```java
public class Collections extends Object{
  static <T> void fill(List<? super T> list, T obj);//Replaces all of the elements of the specified list with the specified element.
  static <T> T max(Collection<? extends T> coll,Comparator<? super T> comp);
  static <T> T min(Collection<? extends T> coll,Comparator<? super T> comp);
  static void reverse(List<?> list);
  static <T> void sort(List<T> list, Comparator<? super T> c);
  static void swap(List<?> list, int i, int j);
}
```

## Generics

:::tip
无论是什么泛型，getClass()均是同一个
:::

### 机制

Java--类型参数(**Cannot use primitive types**)作为类的成员变量

C++(模板)--源代码的源代码

The most commonly used type parameter names are:

- E: Element
- K: Key
- N: Number
- T: Type
- V: Value

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

Create a class MapHelper with three methods:
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
if 2(√),I made 3 without telling List, then 4(x) => 2(x)

```java
Object[] numArray = new int[]{1,2,3}; // Correct
List<Dog> fg = new ArrayList<Dog>();
List<Animal> g = fg;
g.add(new Cat());
Dog s = g.get(0);
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

#### Type Inference

*Type inference* is a Java compiler's ability to look at each method invocation and corresponding declaration to determine the type argument (or arguments) that make the invocation applicable.

```java
Map<String, List<String>> myMap = new HashMap<>();// <String,List<String>>
class MyClass<X> {
  <T> MyClass(T t) {
    // ...
  }
}
MyClass<Integer> myObject = new MyClass<>("");// X should be Integer, T should be String
```