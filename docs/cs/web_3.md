# React
## Component
Make states stay, make props pass

- props -- Input information passed from a parent to a child component(properties)

- states -- Private information maintained by a component

```js
//Parent Component
changeCatHappinneess=()=>{
    this.setState=({
        catHappiness: this.state.catHappiness+1,
        //change state
        prevState=>({
            persons:[...prevState.persons,"me"]
        })
    },()=>{
        console.log(this.state.persons);//callback
    });
}
render(){
    return (
        <childComponent propName={this.changeCatHappiness}/>
    );
}
//Child Component
this.props.catHappiness;
```
## JSX

syntax extension to JavaScript that allows us to write HTML code snippets in JavaScript files

- () allows us to write HTML code inside JavaScript

- {} allows us to return to JavaScript inside the HTML environment inside the JavaScript class

## Lifecyle method

![20210716151248](https://raw.githubusercontent.com/zxc2012/image/main/20210716151248.png)
