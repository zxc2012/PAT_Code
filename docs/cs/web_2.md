# Javascript
## Basic
### Primitive types
- Boolean (true, false)
- Number (12, 1.618, -46.7, 0, etc.)
- String (“hello”, “world!”, “12”, “”, etc.)
- Null (no value)
- Undefined (declared but not yet assigned a value)

### Operators
"==" forces the arguments to be of the same type before comparing them

*use a===b*
### Ouput

```js
console.log();
alert("");//generate a pop-up notification with the given content
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
a.splice(1,1,4);//于p1删除p2个元素并在p1插入=>[1,4,3]
a.map(x=>x+3);//return [4,7,6] but not change
a.filter(x=>x>2);//return [4,3]
```
## function
```js
let addTwo=x=>{
    return x+2;
}
```

## DOM
Document Object Model: how your browser interprets the HTML “tree”
```html
<ul id="shopping list">
    <li>milk</li>
</ul>
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
    });
    ```