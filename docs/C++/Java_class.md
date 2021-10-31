# Java Application Design--Class

## Primitive Data Types

C++(ILP32:int long pointer)
|Type|Storage(bits)|
|-|-|
|char|8|
|short|16|
|int|32|
|long|32|
|float|32|
|long long|64|
|double|64|

Java
|Type|Storage(bits)|Min Value|Max Value|
|-|-|-|-|
|boolean|-|-|-|
|byte|8|-128|127|
|short|16|$-2^{15}$|$2^{15}-1$|
|char|16|0|$2^{16}-1$|
|int|32|$-2^{31}$|$2^{31}-1$|
|long|64|$-2^{63}$|$2^{63}-1$|
|float|32|Approximately-3.4e+38 with 7 significant digits|Approximately3.4e+38 with 7 significant digits|
|double|64|Approximately-1.7e+308 with 15 significant digits|Approximately-1.7e+308 with 15 significant digits|

![vs](https://img-blog.csdnimg.cn/20201013163013271.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM5MzgwMjMw,size_16,color_FFFFFF,t_70#pic_center)

### Initialization
- Data Field
  - null for a reference type
  - 0 for a numeric type
  - false for a boolean type
  - '\u0000' for a char type
- no default value to a local
variable
### Operator precedence
单算移关与，异或逻条赋

- 单表示单目运算符：逻辑非(!),按位取反(~),自增(++),自减(--),取地址(&),取值(*)
- 算表示算术运算符：乘、除和求余(*,/,%)级别高于加减(+,-)
- 移表示按位左移(<<)和位右移(>>)
- 关表示关系运算符：大小关系(>,>=,<,<=)级别高于相等不相等关系(==,!=)
- 与表示按位与(&)
- 异表示按位异或(^)
- 或表示按位或(|)
- 逻表示逻辑运算符：逻辑与(&&)级别高于逻辑或(||)
- 条表示条件运算符(? :)
- 赋表示赋值运算符(=,+=,-=,*=,/=,%=,>>=,<<=,&=,^=, |=,!=)

### Pass by value
- For a parameter of a **primitive** type, the actual value is passed

- For a parameter of an **array** type, the reference value is passed

## Class

### Constructor

- Constructors must have the same name as the
class itself
- A constructor with no parameters is referred to as
a no-arg constructor(*default*: no-arg constructor with an
empty body)
- Constructors do not have a return type(Not even void)

###  Visibility Modifiers 

|Modifiers|Description|
|-|-|
|public|The class, data, or method is visible to any class in any package|
|(default)|the class, variable, or method can be accessed by any class in the same package|
|private|Modifier cannot be applied to a class, only its members/The data or methods can be accessed only by the declaring class|
|protected|Used in inheritance|

### Cleanup:finalize()

When the garbage collector is ready to release the storage used for your object,it will first call its **finalize()**
But **finalize()** is totally different from destructor of C++:


### Order of Initialization

1.Staic members is to be initialized in the loading of the class,属于类的数据(C++全局)

2.When a new object is create,顺序:
- Allocate enough storage for an object on the heap.
- Setting **all** the primitives in the object to their default values.(Any initializations that occur at the point of field definition are executed.)
- Constructors are executed.

## Inheritance & Polymorphism

### Inheritance

- super
  - constructor 
  - superclass method
  
    super.method(arguments);

    *private、static method cannot be overriden*(If a static method defined in the superclass is
    redefined in a subclass, the method defined
    in the superclass is hidden)


**Overriding**

- Have the same signature
- Are in different classes related by inheritance

**Overloading**

- Have the same name, but different parameter lists
- Can be either
  - In the same class
  - In different classes related by inheritance

Eg:

```java
System.out.println(true?Integer.valueOf(1):Double.valueOf(2))
//输出1.0,因为java是编译语言不是解释语言，编译器看到函数调用不会立即执行
//而是根据double确定println overload为double类型
```
## Object Class

|Function|Interpretion|
|-|-|
|public boolean equals(Object w)|判断两个对象变量是否指向同一个对象|
|public String toString()||
|public final Class getClass()||
|protected Object clone()|返回调用该方法的对象的一个副本|

## Other Class
### Scanner Class

```java
Scanner input = new Scanner(System.in);
int value = input.nextInt();
// nextByte() reads an integer of the byte type.
// nextShort() reads an integer of the short type.
// nextInt() reads an integer of the int type.
// nextLong() reads an integer of the long type.
// nextFloat() reads a number of the float type.
// nextDouble() reads a number of the double type.
```

### Array Class

get length: array.length(*variable*)
```java
/***Creation****/
int[] A = new int[4]; // A points to array of 4 0s.
int[] B; // Same thing, but in two steps.
B = new int[4];
int[] C = new int[] { 1, 2, 3, 4 }
// Array with explicit initial values.
int[] D = { 1, 2, 3, 4 } // Shorthand for the above
/***Method******/
public static <T> void sort(T[] a,
            int fromIndex,
            int toIndex,
            Comparator<? super T> c)
public static boolean equals(Object[] a,
             Object[] a2)//Returns true if the two specified arrays of Objects are equal to one another.
public static void fill(Object[] a,
        int fromIndex,
        int toIndex,
        Object val)             
```
Lambda Expression
- A comma-separated list of formal parameters enclosed in parentheses(Optional type declaration)

- The arrow token, ->

- A body, which consists of a single expression or a statement block. 
```java
//一个参数时()可省略
(param1, param2, …, paramN) -> { statements }
(param1, param2, …, paramN) -> expression
//相当于：(param1, param2, …, paramN) ->{ return expression; }
```

![20211004215118](https://raw.githubusercontent.com/zxc2012/image/main/20211004215118.png)


### String Class

|Method|Description|
|-|-|
|length()|Returns the number of characters in this string.|
|charAt(index)|Returns the character at the specified index from this string.|
|concat(s1)|Returns a new string that concatenates this string with string s1.|
|toUpperCase()|Returns a new string with all letters in uppercase.|
|toLowerCase()|Returns a new string with all letters in lowercase.|
|trim() |Returns a new string with whitespace characters trimmed on both sides.|
