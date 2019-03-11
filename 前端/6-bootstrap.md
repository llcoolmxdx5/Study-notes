# 响应式网页

>一个网页随浏览设备不同自动改变布局

## 1.实现响应式网页总述

### 1.自定义式响应网页

viewport  视口

`<meta name="viewport" content="width=device-width, initial-scale=1">`

流式布局:float:left

容器;文字;图片; 大小相对

使用CSS3 媒体查询

### 2.使用bootstrap框架

```html
<!DOCTYPE html>
<html>
   <head>
      <title>Bootstrap 模板</title>
      <meta name="viewport" content="width=device-width, initial-scale=1.0">
      <!-- 引入 Bootstrap -->
      <link href="https://cdn.staticfile.org/twitter-bootstrap/3.3.7/css/bootstrap.min.css" rel="stylesheet">
      <!-- HTML5 Shiv 和 Respond.js 用于让 IE8 支持 HTML5元素和媒体查询 -->
      <!-- 注意： 如果通过 file://  引入 Respond.js 文件，则该文件无法起效果 -->
      <!--[if lt IE 9]>
         <script src="https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js"></script>
         <script src="https://oss.maxcdn.com/libs/respond.js/1.3.0/respond.min.js"></script>
      <![endif]-->
   </head>
   <body>
      <h1>Hello, world!</h1>
      <!-- jQuery (Bootstrap 的 JavaScript 插件需要引入 jQuery) -->
      <script src="https://cdn.staticfile.org/jquery/2.1.1/jquery.min.js"></script>
      <!-- 包括所有已编译的插件 -->
      <script src="https://cdn.staticfile.org/twitter-bootstrap/3.3.7/js/bootstrap.min.js"></script>
   </body>
</html>
```

## 2.媒体查询

媒体:指浏览网页设备(screen(pc/pad/phone);print;tv...)

媒体查询:查询当前浏览网页设备特性(尺寸/手持方向)

兼容性:IE9 Chrome21

实现

```css
/* 语法 */
@media mediatype and|not|only (media feature) {
    CSS-Code;
}
/* 实例 */
.example {
    padding: 20px;
    color: white;
}
/* Extra small devices (phones, 600px and down) */
@media only screen and (max-width: 600px) {
    .example {background: red;}
}

/* Small devices (portrait tablets and large phones, 600px and up) */
@media only screen and (min-width: 600px) {
    .example {background: green;}
}

/* Medium devices (landscape tablets, 768px and up) */
@media only screen and (min-width: 768px) {
    .example {background: blue;}
}

/* Large devices (laptops/desktops, 992px and up) */
@media only screen and (min-width: 992px) {
    .example {background: orange;}
}

/* Extra large devices (large laptops and desktops, 1200px and up) */
@media only screen and (min-width: 1200px) {
    .example {background: pink;}
}
```

## 3.全局样式

### 3.1按钮

```css
.btn/*  按钮基本样式 */
.btn-default/*  默认/标准按钮 */
.btn-danger/warning/success/info/primary/*  危险/警告/成功/信息/原始样式按钮 */
.btn-lg/.btn-sm/.btn-xs/*  大/小/超小按钮 */
.btn-block/*  块级按钮(拉伸至父元素100%宽度) */
<button type="button" class="btn btn-default btn-lg active">激活按钮</button>
<a href="#" class="btn btn-primary btn-lg disabled" role="button">禁用的原始链接</a>
/* 可以在 <a>、<button> 或 <input> 元素上使用按钮 class。但是建议您在 <button> 元素上使用按钮 class，避免跨浏览器的不一致性问题 */
```

### 3.2图片

.img-rounded

.img-circle

.img-thumbnail

.img-responsive

### 3.3文本

.text-danger/warning/info/success/primary

.bg-danger/...

.text-left/center/right/justify

.text-uppercase/lowercase/capitalize

### 3.4表格

.table

.table-bordered

.table-hover

.table-striped

.table-responsive  父元素 `<div>`

### 3.5栅格

布局方式: table;div+css;栅格

div.container

div.row

.container > .row > .col

bootstrap 每行均分12等分

针对不屏幕设宽度占比   .col-lg-1/2.3/12 .col-md-1..  .col-sm-1  .col-xs-1.1

列适用性.col-xs-6     sm-6/md-6/lg-6

列偏移.col-lg-offset-1/.22

一个列可以指定在不同屏幕下宽度占比div.col-xs-12 .col-sm-6 .col-md-3

列隐藏.hidden-xs  .hidden-sm

嵌套.container > .row >.col > .row >.col

## 4.组件

### 图标字体

`<span class="glyphicon glyphicon-pencil"></span>`

### 进度条

    .progress  > .progress-bar

### 小组件

面包屑
分页条
分页器
徽章
巨幕
水井

### 缩略图

.thumbnail
img
.caption

### 媒体对象

左中右
media
.media-left;.media-body;.media-right

### 面板

上中下
panel
.panel-heading;.panel-body;.panel-footer

## 5.js插件

>响应式导航条

.navbar-header
    .navbar-brand
    .navbar-toggle

.navbar-collapse

## 6.less动态样式语言

>less 动态样式语言(Sass/Stylus/Less)浏览器只能识别css静态样式语言, less编译成css

### 1. less支持所有css语法

### 2.注释

单行
    //...

多行
    /*..*/

### 3.变量

定义
    @变量名:值

使用
    color:@变量名

### 4.运算符

`+ - * / %`

### 5.混入

.选择器1{...}
.选择器2{...选择器1...}

### 6.带参数混入

.选择器1(@变量,@变量)
.选择器2{..选择器1(值1,值2)}

### 7.嵌入

.选择器1{
    .选择器2{}
}

### 8.less提供几十个内嵌函数

ceil()
floor()
darken()

### 9.引入  

01.less
02.less
    import "01.less"