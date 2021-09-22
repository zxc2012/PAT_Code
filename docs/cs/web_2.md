# Javascript
## Basic
### Primitive types
- Boolean (true, false)
- Number (12, 1.618, -46.7, 0, etc.)
- String ("hello", "world!", "12", etc.)
- Null (no value)
- Undefined (declared but not yet assigned a value)
- Symbol
- BigInt

#### Const,let and var

||hoist|scope|
|-|-|-|
|var|Only declarations are hoisted|function scope|
|let const|block hoisted,but not initialized with 'undefined'|block scope|

TDZ: from the start of the block until the initialization has completed.

**block:{}**
```js
/**Example 1:hoist ***/
x = 1; 
console.log(x + " " + y); // '1 undefined'
var y = 2; // Declare and Initialize y
console.log(num);//Cannot access 'num' before initialization
let num="fasd";
/**Example 2:scope ***/
function varTest() {
  var x = 1;
  {
    var x = 2;  // same variable!
    console.log(x);  // 2
  }
  console.log(x);  // 2
}

function letTest() {
  let x = 1;
  {
    let x = 2;  // different variable
    console.log(x);  // 2
  }
  console.log(x);  // 1
}
/**Example3: TDZ**/
function go(n) {
  // n here is defined!
  console.log(n); // Object {a: [1,2,3]}

  for (let n of n.a) { // ReferenceError,n.a先找block内的再找function内的
    console.log(n);
  }
}

go({a: [1, 2, 3]});
```
#### Symbol
- Symbol.for(key)

    Searches for existing Symbols with the given key and returns it if found. Otherwise a new Symbol gets created in the global Symbol registry with key.

- Symbol.keyFor(sym)

    Retrieves a shared Symbol key from the global Symbol registry for the given Symbol.

### Operators
1. "==" forces the arguments to be of the same type before comparing them

    *use a===b*
2. '+'触发隐式类型转换
3. for...in iterates over all enumerable *properties* of an object that are keyed by strings

   for...of creates a loop iterating over *iterable objects*.
4. Spread syntax (...) allows an iterable such as an array expression or string to be expanded in places where zero or more arguments (for function calls) or elements (for array literals) are expected, or an object expression to be expanded in places where zero or more key-value pairs (for object literals) are expected.
### Function
- Arrow Function: 
    - Does not have its own bindings to this or super, and should not be used as methods.
    - Can not be used as constructors.(new)
- Traditional Function:
    - 每次调用都会创建this和arguments

```js
//一个参数时()可省略
(param1, param2, …, paramN) => { statements }
(param1, param2, …, paramN) => expression
//相当于：(param1, param2, …, paramN) =>{ return expression; }
```
```js
//常用函数
setTimeout(handler: TimerHandler, timeout?: number, ...arguments: any[]): number//timeout default:0
```
#### Prototype
```js
function doSomething(){}
doSomething.prototype.foo = "bar";
var doSomeInstancing = new doSomething();
doSomeInstancing.prop = "some value";
console.log("doSomeInstancing.prop:      " + doSomeInstancing.prop);//some value
console.log("doSomeInstancing.foo:       " + doSomeInstancing.foo);//bar
console.log("doSomething.prop:           " + doSomething.prop);//undefined
console.log("doSomething.foo:            " + doSomething.foo);//undefined
console.log("doSomething.prototype.prop: " + doSomething.prototype.prop);//undefined
console.log("doSomething.prototype.foo:  " + doSomething.prototype.foo);//bar
```
### Ouput
Function.prototype.call(),Function.prototype.blind()
```js
Function.prototype.mycall = function(thisArg, ...args) {
  if(thisArg===null||thisArg===undefined)thisArg=window;
  thisArg=Object(thisArg);
  let key = Symbol();
  thisArg[key]=this;
  let result = thisArg[key](...args);
  delete thisArg[key];
  return result;
}
```
## Object
### Declaration
```js
let person={
    name:"ycy",
    age:29,
    color:"red"
};
let {name,age}=person;//Object destructuring is a shorthand to obtain multiple properties at once.

```
### Array
```js
let a=[1,2,3];
//改变数组
a.splice(1,1,4);//于p1删除p2个元素并在p1插入=>[1,4,3]
//不改变数组
a.concat(1,[2,3],[5,[6,7]])//[1,4,3,1,2,3,5,[6,7]]//flatten array,but not arrays of arrays
a.map(x=>x+3);//return [4,7,6] but not change
a.foreach(value=>sum+=value);
a.filter(x=>x>2);//return [4,3]
a.reduce((x,y)=>x+y);//8,reduce right process from right-to-left
```
#### Other function
<table>
    <tr>
        <th>Category</th>
        <th>Function</th>
        <th>Notes</th>
    </tr>
    <tr>
        <td>find</td>
        <td>indexOf(),lastIndexOf()</td>
        <td>starts at the beginning/end</td>
    </tr>
    <tr>
        <td>fill</td>
        <td>fill(value: number, start?: number, end?: number)</td>
        <td>start default:0,end default:array.length</td>
    </tr>
    <tr>
        <td rowspan="2">stacks & queues</td>
        <td>push(),pop()</td>
    </tr>
    <tr>
        <td>shift(),unshift()</td>
        <td>delete index 0,insert index 0</td>
    </tr>
</table>

## Closure
this is determined by the enclosing lexical context

### Global Context

```js
function f1() {
  return this;
}
// In a browser:
f1() === window; // true
// In Node:
f1() === globalThis; // true
```
### Class Context
Within a class constructor, "this" is a regular object. 

All non-static methods within the class are added to the prototype of "this"
### Inside Object
Object有自己的Execution context,但没有this.

When a function is called as a method of an object, "this" is set to the object the method is called on.

```js
var obj = {
  bar: function() {
    var x = (() => this);
    return x;
  },
  doSomethingLater : function (){
    setTimeout(function(){
        this.count++;
        console.log(this);
    }, 300);
  }
};
var fn = obj.bar();
console.log(fn() === obj); // true
// But caution if you reference the method of obj without calling it
var fn2 = obj.bar;
// Calling the arrow function's this from inside the bar method()
// will now return window, because 把函数拉到下面去了
console.log(fn2()() == window); // true
obj.doSomethingLater(); 
//In a browser:window,In Node:Timeout {...}
```
## DOM
Document Object Model: how your browser interprets the HTML “tree”

### Function
```js
HTMLOrForeignElement.blur()// 从当前焦点元素中移除键盘焦点。
HTMLElement.click()// 向元素发送鼠标单击事件。
HTMLOrForeignElement.focus()// 使元素成为当前键盘焦点。
HTMLElement.forceSpellCheck()// 对元素的内容运行拼写检查程序
```

- Create and add elements on the fly

    ```js
    const list=document.getElementById("shopping list");
    const newEL=document.createElement("li");
    newEl.innerHTML="apples";
    list.appendChild(newEl));
    ```
- Change the contents/style of an element

    ```js
    const list=document.getElementById("shopping list");
    list.style.color="red";
    ```
- Give elements actions by adding event listeners

    ```js
    const button=document.getElementById("button");
    button.addEventListener("click",()=>{
        addParagraph("");
    });//common events include load, click, input, mouseover
    ```

## Promise
### 实现promise.all
```js
/**
 * @param {Array<any>} promises - notice input might have non-Promises
 * @return {Promise<any[]>}
 */
function all(promises) {
  return new Promise((resolve,reject)=>{
    if(!Array.isArray(promises))reject(new TypeError("参数错误"));
    let results=[];
    if(promises.length==0)resolve(promises);
    promises.forEach(promise=>{
      Promise.resolve(promise).then(value=>{
        results.push(value);
        if(results.length===promises.length)
          resolve(results);
      },err=>reject(err));
    })
  }
  )
}
```
## debounce & throttle
```js
function debounce(func, wait) {
  let timer=null;
  return function(...args){
    if(timer){
      clearTimeout(timer);
    }
    timer=setTimeout(()=>{
      func.call(this,args);
    },wait);
  }
}
function throttle(func, wait) {
  let timer=null;
  let lastargs;
  return (...args)=>{
    if(timer)lastargs=args;
    else{
      func.call(this,...args);
      timer=setTimeout(()=>{
        if(lastargs)func.call(this,lastargs);
        timer=null;
      },wait)
    }
  } 
}
```

