# HTML & CSS
html: hypertext markup language

css: cascading style sheets

## HTML
### Basic HTML tags

```markdown
<html> root of html content
<head> info about document
    <title> show on tab page
<body> ducument body
    <h1,h2,h3> header tags
    <p> paragraph tag
<div> generic block section tag(division)
```
### Attributes
![W0 & HTML CSS](https://raw.githubusercontent.com/zxc2012/image/main/W0%20%26%20HTML%20CSS.jpg)
(1)anchor and hypertext reference
```markdown
<a href="">
content
</a>
```
(2)img,insert css
```markdown
<img src="push.gif" />
<link rel="stylesheet" href="style.css" /> <!-- rel:relation between  the linked document to the current document -->
```
(3)div
- class
- id

(4)
```markdown
<ul><!-- unordered list-->
<li></li>
</url>
```
(5)Other

hr : horizontal rule

## CSS

![W0 & HTML CSS (1)](https://raw.githubusercontent.com/zxc2012/image/main/W0%20%26%20HTML%20CSS%20(1).jpg)

### ID and class
|~|id|class|
|-|-|-|
|Notes|An element can have only one *unique* ID|An element can have multiple classes|
|css|#id {…}|.classname {…}|

### Selector
#### Attribute Selector

[attr=value]
![20210804152555](https://raw.githubusercontent.com/zxc2012/image/main/20210804152555.png) 

#### Combinators
- Siblings

    - Adjacent siblings: +
    ```css
    h2 + p {}/* selects all <p> that directly follow an <h2>*/ 
    ```

    - General siblings: ~
    ```css
    p ~ span {}/* selects all <span> that follow an <p> */
    ```
- Child/Descendant
    - Child: >
    ```css
    ul > li {}/*selects all <li> directly inside a <ul>*/
    ```

    - Descendant: ' '(space)
    ```css
    div span {} /*selects all <span> anywhere inside a <div>*/ 
    ```

#### Pseudo-Classes/Elements

```css
element:hover {}/*cool hover rules*/
a:active {} /*clicking on a link*/ 
input:focus {} /*tabbing/clicking on an input*/ 
p:nth-child(4n) {} /*every 4th <p>*/ 
p::first-line {} /*first line of a <p>*/ 
::selection {}/*user highlighted text*/ 
a::after {}	/*styling placed in a generated element after every <a>*/
```

![20210804153651](https://raw.githubusercontent.com/zxc2012/image/main/20210804153651.png)


### Box Model

![20210730203640](https://raw.githubusercontent.com/zxc2012/image/main/20210730203640.png)

- padding:
    - 1 value: all
    - 2 value: 上下 左右
    - 3 value: 上 左右 下 
- border-radius: specify the radius
    - 1 value: all
    - 2 value: 左上右下 右上左下
    - 3 value: 左上 右上左下 右下
    - /: horizontal radius/vertical radius 

### Layout

#### display
<table>
    <tr>
        <th>Properties</th><th>Choices</th><th>Notes</th>
    </tr>
    <tr>
        <td rowspan="6">display</td><td>block</td><td>big blocks that stretch across, always sit on new lines.(i.e. div,section,ul,p,h1-6,header)</td>
    </tr>
    <tr>
        <td>inline</td><td>an element that is part of text, size is always proportional to text.they do NOT accept width/height properties and top/bottom margins(i.e. span, a, img)</td>
    </tr>
    <tr>
        <td>inline-block</td><td>stays within text, but can have its own size independent from text,you CAN set width and height.useful for including non-text elements within text</td>
    </tr>
    <tr>
        <td>flex</td><td>flexibly contain and distribute elements inside itself flexible</td>
    </tr>
    <tr>
        <td>grid</td><td>grid-template-columns/grid-template-rows(1fr: fraction)</td>
    </tr>
    <tr>
        <td>none</td><td></td>
    </tr>

</table>

flex:
- flex-direction: |column |column-reverse|row |row-reverse 
![20210817205612](https://raw.githubusercontent.com/zxc2012/image/main/20210817205612.png)

- justify-content:(主轴)
![20210817205407](https://raw.githubusercontent.com/zxc2012/image/main/20210817205407.png)

- align-items:(各自在主轴)
![20210818095851](https://raw.githubusercontent.com/zxc2012/image/main/20210818095851.png)
#### position

vh:viewpoint height

vw:viewpoint width

<table>
    <tr>
        <th>Properties</th><th>Choices</th><th>Notes</th>
    </tr>
    <tr>
        <td rowspan="4">position</td><td>static</td><td>(default)renders boxes position based on order in document</td>
    </tr>
    <tr>
        <td>relative</td><td>positions the element "relative" to where it would be if static</td>
    </tr>
    <tr>
        <td>absolute</td><td>ppositions the element relative to first ancestor positioned non-statically</td>
    </tr>
    <tr>
        <td>fixed</td><td>positions the element relative to the screen</td>
    </tr>
</table>

### Transitions & Animations

![20210804143850](https://raw.githubusercontent.com/zxc2012/image/main/20210804143850.png)


```css
.box{
    animation: rolling 1s infinite;
    /*<keyframes-name> <time> <single-animation-iteration-count>*/
}
@keyframes rolling{
    0%{
        transform: rotate(-180deg)
    }
    100%{
        transform: rotate(180deg)
    }
}
```
## Web Standards

### HTTP

*hypertext transfer protocol*

- Primary Methods
    - GET gets data
    - POST creates data
    - PUT modifies data
    - DELETE deletes data

- Status Code
    - 2xx success
    - 3xx redirection
    - 4xx client error
    - 5xx server
error

### URL

*uniform resource locator*

```html
<protocol>://<hostname>/<path>？<query>#<fragment_id>
```
*fragment_id* points to the HTML element with the given ID
