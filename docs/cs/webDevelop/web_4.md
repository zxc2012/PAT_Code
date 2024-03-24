# 4 Node.js
npm: node package manager

## CommonJS
Before a module's code is executed, Node.js will wrap it with a function wrapper that looks like the following:(值拷贝)
```js
(function(exports, require, module, __filename, __dirname) {
// Module code actually lives in here
});
```
exports is a reference to the module.exports
```js
//Both are correct
//1
module.exports = class Square {
  constructor(width) {
    this.width = width;
  }

  area() {
    return this.width ** 2;
  }
};
//2 circle.js
exports.area = (r) => PI * r ** 2;
exports.circumference = (r) => 2 * PI * r;
```
loads the module
```js
const circle = require('./circle.js');
// Importing a module from node_modules or Node.js built-in module:
const crypto = require('crypto');
```
## ECMAScript Modules
值引用

You can have multiple named exports per module but only one default export.

- named exports:{} 
- default:no{}
```js
export { variable1 as name1, variable2 as name2, …, nameN };
// Exporting individual features
export let name1, name2, …, nameN;
// Exporting destructured assignments with renaming
export const { name1, name2: bar } = o;
//export { name1 as default, … };
```
```js
import { export1 as alias1 } from "module-name";
import defaultExport, {foo, bar}from "module-name";
```

## Webpack

### Loader

- test: enables Webpack to determine which files it should transform. 
- use: specifies what loader to use for it.
```js
module : {
 rules : [
 {
    test : /\.(jpg|png)$/, 
    use : { loader : "url-loader" } 
  }]
}
```