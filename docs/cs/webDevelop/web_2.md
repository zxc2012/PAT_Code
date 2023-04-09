# 2 Javascript
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

TDZ(temporal dead zones): from the start of the block until the initialization has completed.

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

### Prototype Chain

someObject.[[Prototype]] is used to designate the prototype of someObject. 

The [[Prototype]] internal slot can be accessed with the Object getPrototypeOf() and Object.setPrototypeOf() functions.

That prototype object has a prototype of its own, and so on until an object is reached with null as its prototype. By definition, null has no prototype, and acts as the final link in this prototype chain.

```js
const o = {
  a: 1,
  b: 2,
  // __proto__ sets the [[Prototype]]. It's specified here
  // as another object literal.
  __proto__: {
    b: 3,
    c: 4,
    __proto__: {
      d: 5,
    },
  },
};
// Prototype Chain
// { a: 1, b: 2 } ---> { b: 3, c: 4 } ---> { d: 5 } ---> Object.prototype ---> null

console.log(o.d); // 5
```

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
timeoutID = setTimeout(functionRef, delay, param1, param2, /* … ,*/ paramN);//delay default:0, ms
clearTimeout(timeoutID);
intervalID = setInterval(func, delay, arg0, arg1, /* … ,*/ argN);// epeatedly calls a function or executes a code snippet, with a fixed time delay(ms) between each call.
clearInterval(intervalID);
```

实现一个打点计时器，要求

- 从 start 到 end（包含 start 和 end）, 每隔 100 毫秒 console.log 当前数字，每次数字增幅为 1
- 返回的对象中需要包含一个 cancel 方法，用于停止定时操作
- start 需要立即输出

```js
function count(start, end) {
    console.log(start);
    let id = setInterval(()=>{
        console.log(++start);
        if(start === end) clearInterval(id);
    },100);
    return{
        cancel:()=>clearInterval(id)
    } 
}
```

#### Properties

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
#### Methods

Bind

The bind() method creates a new function that, when called, has its this keyword set to the provided value, with a given sequence of arguments preceding any provided when the new function is called.

Apply and Call

- Function.prototype.call() accepts an argument list
- Function.prototype.apply() accepts a single array of arguments

```js
// thisArg: The value to be passed as the this parameter to the target function func when the bound function is called
apply(thisArg, argsArray)// func.apply(this, ['eat', 'bananas'])
call(thisArg, arg1, /* …, */ argN)// func.call(this, 'eat', 'bananas')
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
//splice(start, deleteCount, item1, item2, itemN) // 于start删除deleteCount个元素并在start插入
a.splice(1,1,4);//[1,4,3]
//不改变数组
// concat: flatten array,but not arrays of arrays
a.concat(1,[2,3],[5,[6,7]])//return [1,4,3,1,2,3,5,[6,7]]
a.map(x=>x+3);//return [4,7,6] but not change
a.foreach(value=>sum+=value); // callback return value is discarded
a.filter(x=>x>2);//return [4,3]
a.reduce((x,y)=>x+y);//8, reduceRight() process from right-to-left
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

## This

`this` is determined by the enclosing lexical context

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
## Closure

A closure is the combination of a function and the lexical environment within which that function was declared, which gives you access to an outer function's scope from an inner function.

This environment consists of any local variables that were in-scope at the time the closure was created

```js
let myObj = {
    "gender": "man",
    makeFunc() {
        const name = this.gender;
        function displayName() {
          console.log(name)// "man"
          console.log(this)// window
        }
        return displayName;
    }
}
const myFunc = myObj.makeFunc();
myFunc();
```

In this case, myFunc is a reference to the instance of the function displayName that is created when makeFunc is run. The instance of displayName maintains a reference to its lexical environment, within which the variable name exists.

## DOM
Document Object Model: how your browser interprets the HTML “tree”

### Function
```js
HTMLOrForeignElement.blur()// 从当前焦点元素中移除键盘焦点。
HTMLElement.click()// 向元素发送鼠标单击事件。
HTMLOrForeignElement.focus()// 使元素成为当前键盘焦点。
HTMLElement.forceSpellCheck()// 对元素的内容运行拼写检查程序
document.querySelector() // returns the first Element within the document that matches the specified selector, or group of selectors
```

- Create and add elements on the fly

    ```js
    const list=document.querySelector("shopping list");
    const newEL=document.createElement("li");
    newEl.innerHTML="apples";
    list.appendChild(newEl));
    ```
- Change the contents/style of an element

    ```js
    const list=document.querySelector("shopping list");
    list.style.color="red";
    ```
- Give elements actions by adding event listeners

    ```js
    const button=document.querySelector("button");
    button.addEventListener("click",()=>{
        addParagraph("");
    });//common events include load, click, input, mouseover
    ```

## Promise

A Promise is in one of these states:

- pending: initial state, neither fulfilled nor rejected.
- fulfilled: meaning that the operation was completed successfully.
- rejected: meaning that the operation failed.

Promise.resolve() "resolves" a given value to a Promise. 

If the value is a promise, flattens nested layers of promise into a single layer

If the value is a thenable, first transform into a promise, then follow the flattening process

```js
const myPromise = new Promise((resolve, reject) => {
  setTimeout(() => {
    resolve("foo");
  }, 300);
});
myPromise
  .then(handleFulfilled)
  .catch(handleRejected);
```

### Method

promise.race

```js
function race(promises) {
  /*
  Wait until any of the promises is fulfilled or rejected.

  If the returned promise fulfills, it is fulfilled with the value of the first promise in the iterable that fulfilled.

  If it rejects, it is rejected with the reason from the first promise that was rejected.
  */
  return new Promise((resolve,reject)=>{
    promises.forEach(promise=>{
      Promise.resolve(promise).then(value=>resolve(value))
      .catch(e=>reject(e))
    })
  })
}
```

promise.all

```js
/**
  Wait for all promises to be fulfilled, or for any to be rejected.

  If the returned promise fulfills, it is fulfilled with an aggregating array of the values from the fulfilled promises, in the same order as defined in the iterable of multiple promises.

  If it rejects, it is rejected with the reason from the first promise in the iterable that was rejected.
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

promise.any

```js
/**
  Takes an iterable of Promise objects and, as soon as one of the promises in the iterable fulfills, returns a single promise that fulfills with the value from that promise.
 */
function any(promises) {
  return new Promise((resolve,reject)=>{
    if(promises.length===0) resolve(promises);
    let result = [];
    promises.forEach((promise,idx)=>Promise.resolve(promise)
      .then(value=>resolve(value))
      .catch(e=>{
        result[idx] = e;
        if(result.length === promises.length){
          reject(new AggregateError('No Promise in Promise.any was resolved',
            result
          ));
        }
      }
      )
    )
  }
  )
}
```

## debounce & throttle
```js
function debounce(func, wait) {
  let id = null;
  return (args)=>{
    if(id) clearTimeout(id);
    id = setTimeout(()=>func.call(this,...args),wait);
  }
}
function throttle(func, wait) {
  let id;
  let lastargs;
  return (args)=>{
    if(!id){
      func.call(this,...args);
      id = setTimeout(()=>{
        id = null;
        if(lastargs){
          func.call(this,...lastargs);
        }
      },wait);
    }
    else lastargs = args;
  } 
}
```

