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

### Box Model

![20210730203640](https://raw.githubusercontent.com/zxc2012/image/main/20210730203640.png)

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
    <tr>
        <td rowspan="4">justify-content</td><td>space-between</td><td>push the child component as far away from each other as possible</td>
    </tr>
    <tr>
        <td>center</td><td>together center</td>
    </tr>
    <tr>
        <td>start</td><td>together start</td>
    </tr>
    <tr>
        <td>space-evenly</td><td></td>
    </tr>
</table>

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
    aninimation: rolling 1s infinite;
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
