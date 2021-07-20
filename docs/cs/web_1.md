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

|~|id|class|
|-|-|-|
|备注|An element can have only one *unique* ID|An element can have multiple classes|
|css|#id {…}|.classname {…}|

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
