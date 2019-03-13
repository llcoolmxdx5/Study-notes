# 响应式开发

## 1.响应式网页

>一个网页随浏览设备不同自动改变布局

### 1.网页布局方式

1.固定宽度布局：为网页设置一个固定的宽度，通常以px做为长度单位，常见于PC端网页。

2.流式布局：为网页设置一个相对的宽度，通常以百分比做为长度单位。

3.栅格化布局：将网页宽度人为的划分成均等的长度，然后排版布局时则以这些均等的长度做为度量单位，通常利用百分比做为长度单位来划分成均等的长度。

4.响应式布局：通过检测设备信息，决定网页布局方式，即用户如果采用不同的设备访问同一个网页，有可能会看到不一样的内容，一般情况下是检测设备屏幕的宽度来实现。

注：以上几种布局方式并不是独立存在的，实际开发过程中往往是相互结合使用的。

### 2.使用bootstrap框架

```html
<!DOCTYPE html>
<html>
   <head>
      <title>Bootstrap 模板</title>
      <meta name="viewport" content="width=device-width, initial-scale=1.0"><!-- viewport  视口 -->
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

![按钮1](http://www.runoob.com/wp-content/uploads/2014/06/buttonoptions_demo.jpg)

![按钮2](http://www.runoob.com/wp-content/uploads/2014/06/buttonsize_demo.jpg)

![按钮3](http://www.runoob.com/wp-content/uploads/2014/06/buttondisabledstate_demo.jpg)

### 3.2图片

```css
.img-rounded/* 为图片添加圆角 (IE8 不支持) */
.img-circle/* 将图片变为圆形 (IE8 不支持) */
.img-thumbnail/* 缩略图功能 */
.img-responsive/* 图片响应式 (将很好地扩展到父元素) */
/* .img-responsive 类将 max-width: 100%; 和 height: auto; 样式应用在图片上： */
```

![图片](http://www.runoob.com/wp-content/uploads/2014/06/image_demo.jpg)

### 3.3辅助类

```css
/* 不同的文本颜色 褐色(#a94442)/黄色(#8a6d3b)/浅蓝色(#31708f)/浅绿色(#3c763d)/蓝色(#428bca)/浅灰色(#999) */
.text-danger/warning/info/success/primary/muted
.bg-danger/.../* 不同的背景颜色 */
.text-left/center/right/justify/* 不同的文本对齐方式 */
.text-uppercase/lowercase/capitalize/* 不同的大小写转换 大写/小写/首字母大写 */
.pull-left/pull-right/clearfix/* 元素浮动到左边/右边/清除浮动 */
.show/hidden/* 强制元素显示/隐藏 */
.close/caret/* 关闭按钮/下拉功能 */
<p>插入符实例
  <span class="caret"></span>
</p>
.center-block/* 任意元素居中显示 */
.text-hide/* 将元素的文本内容替换为一张背景图 */
```

### 3.4表格

```css
.table/* 为任意 <table> 添加基本样式 (只有横向分隔线) */
.table-bordered/* 为所有表格的单元格添加边框 */
.table-hover/* 在 <tbody> 内的任一行启用鼠标悬停状态 */
.table-striped/* 在 <tbody> 内添加斑马线形式的条纹 ( IE8 不支持) */
.table-condensed/* 让表格更加紧凑*/
.table-responsive/* 响应式表格为任意table的父元素div样式 */
```

### 3.5栅格

div.container

div.row

.container > .row > .col

bootstrap 每行均分12等分

针对不屏幕设宽度占比   .col-lg-1/2.3/12 .col-md-1..  .col-sm-1  .col-xs-1.1

列适用性.col-xs-6     sm-6/md-6/lg-6

偏移列:大屏显示器 .col-lg-offset-* .col-md-offset-*

一个列可以指定在不同屏幕下宽度占比div.col-xs-12 .col-sm-6 .col-md-3

列隐藏.hidden-xs  .hidden-sm

嵌套.container > .row >.col > .row >.col

```html
<!-- 基本网格结构 -->
<div class="container">
   <div class="row">
      <div class="col-*-*"></div>
      <div class="col-*-*"></div>
   </div>
   <div class="row">...</div>
</div>
```

### 3.6居中

```css
class="text-center"/* 文本居中 */
class="center-block"/* 图片居中 */
/* 其他元素居中 */
/* bootstrap3水平居中:列偏移 */
class="col-md-6 col-md-offset-3"
/* 设定目标所占列数为6,偏移数3,即以363来展示,实现居中 */
class="m-auto"/* bootstrap4水平居中 */
```

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