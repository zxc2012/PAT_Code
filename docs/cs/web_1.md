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
