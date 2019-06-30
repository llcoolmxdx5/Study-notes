# 第十一章 DOM扩展

## 选择符 API

### querySelector()方法

querySelector()方法接收一个 CSS 选择符，返回与该模式匹配的第一个元素，如果没有找到匹配的元素，返回 null。

```js
//取得 body 元素
var body = document.querySelector("body")
//取得 ID 为"myDiv"的元素
var myDiv = document.querySelector("#myDiv")
//取得类为"selected"的第一个元素
var selected = document.querySelector(".selected")
//取得类为"button"的第一个图像元素
var img = document.body.querySelector("img.button")
```

### querySelectorAll()方法

querySelectorAll()方法接收的参数与 querySelector()方法一样，都是一个 CSS 选择符，但返回的是所有匹配的元素而不仅仅是一个元素。这个方法返回的是一个 NodeList 的实例。

```js
//取得某<div>中的所有<em>元素（类似于 getElementsByTagName("em")）
var ems = document.getElementById("myDiv").querySelectorAll("em")
//取得类为"selected"的所有元素
var selecteds = document.querySelectorAll(".selected")
//取得所有<p>元素中的所有<strong>元素
var strongs = document.querySelectorAll("p strong")
```

要取得返回的 NodeList 中的每一个元素，可以使用 item()方法，也可以使用方括号语法

```js
var i, len, strong
for (i=0, len=strongs.length; i < len; i++) {
    strong = strongs[i]; //或者 strongs.item(i)
    strong.className = "important"
}
```

### matchesSelector()方法

这个方法接收一个参数，即 CSS 选择符，如果调用元素与该选择符匹配，返回 true；否则，返回 false。

兼容性很差

```js
if (document.body.matchesSelector("body.page1")) {
    //true
}
```

## HTML5

### 焦点管理

document.activeElement 属性，这个属性始终会引用 DOM 中当前获得了焦点的元素。元素获得焦点的方式有页面加载、用户输入（通常是通过按 Tab 键）和在代码中调用 focus()方法。

```js
var button = document.getElementById("myButton")
button.focus()
alert(document.activeElement === button); //true
```

### 自定义数据属性

HTML5 规定可以为元素添加非标准的属性，但要添加前缀 data-，目的是为元素提供与渲染无关的信息，或者提供语义信息。这些属性可以任意添加、随便命名，只要以 data-开头即可。

```html
<div id="myDiv" data-appId="12345" data-myname="Nicholas"></div>
<script>
    var div = document.getElementById("myDiv")
    // 取得自定义属性的值
    var appId = div.dataset.appId
    var myName = div.dataset.myname
    // 设置值
    div.dataset.appId = 23456
    div.dataset.myname = "Michael"
    // 有没有"myname"值呢？
    if (div.dataset.myname) {
        alert("Hello, " + div.dataset.myname)
    }
</script>
```

### innerHTML 属性

`div.innerHTML`

## 专有扩展

### innerText 属性

### children属性

`var childCount = element.children.length`
