# 第十五章 使用 Canvas 绘图

## 基本用法

要使用`<canvas>`元素，必须先设置其 width 和 height 属性，指定可以绘图的区域大小。出现在开始和结束标签中的内容是后备信息，如果浏览器不支持`<canvas>`元素，就会显示这些信息。下面就是`<canvas>`元素的例子。

`<canvas id="drawing" width=" 200" height="200">A drawing of something.</canvas>`

要在这块画布（canvas）上绘图，需要取得绘图上下文。而取得绘图上下文对象的引用，需要调用getContext()方法并传入上下文的名字。传入"2d"，就可以取得 2D 上下文对象。

```js
var drawing = document.getElementById("drawing");
//确定浏览器支持<canvas>元素
if (drawing.getContext) {
  var context = drawing.getContext("2d");
  //更多代码
}
```

使用 toDataURL()方法，可以导出在`<canvas>`元素上绘制的图像。这个方法接受一个参数，即图像的 MIME 类型格式，而且适合用于创建图像的任何上下文。比如，要取得画布中的一幅 PNG 格式的图像，可以使用以下代码。

```js
var drawing = document.getElementById("drawing");
//确定浏览器支持<canvas>元素
if (drawing.getContext){
  //取得图像的数据 URI
  var imgURI = drawing.toDataURL("image/png");
  //显示图像
  var image = document.createElement("img");
  image.src = imgURI;
  document.body.appendChild(image);
}
```

默认情况下，浏览器会将图像编码为 PNG 格式（除非另行指定）。Firefox 和 Opera 也支持基于"image/jpeg"参数的 JPEG 编码格式。

## 2D上下文

使用 2D 绘图上下文提供的方法，可以绘制简单的 2D 图形，比如矩形、弧线和路径。2D 上下文的坐标开始于`<canvas>`元素的左上角，原点坐标是(0,0)。所有坐标值都基于这个原点计算，x 值越大表示越靠右，y 值越大表示越靠下。默认情况下，width 和 height 表示水平和垂直两个方向上可用的像素数目。

### 填充和描边

填充，就是用指定的样式（颜色、渐变或图像）填充图形；描边，就是只在图形的边缘画线。大多数 2D 上下文操作都会细分为填充和描边两个操作，而操作的结果取决于两个属性：fillStyle 和 strokeStyle。这两个属性的值可以是字符串、渐变对象或模式对象，而且它们的默认值都是"#000000"。如果为它们指定表示颜色的字符串值，可以使用 CSS 中指定颜色值的任何格式，包括颜色名、十六进制码、rgb、rgba、hsl 或 hsla。举个例子：

```js
var drawing = document.getElementById("drawing");
//确定浏览器支持<canvas>元素
if (drawing.getContext) {
  var context = drawing.getContext("2d");
  context.strokeStyle = "red";
  context.fillStyle = "#0000ff";
}
```

### 绘制矩形

矩形是唯一一种可以直接在 2D 上下文中绘制的形状。与矩形有关的方法包括 fillRect()、strokeRect()和 clearRect()。这三个方法都能接收 4 个参数：矩形的 x 坐标、矩形的 y 坐标、矩形宽度和矩形高度。这些参数的单位都是像素。

首先，fillRect()方法在画布上绘制的矩形会填充指定的颜色。填充的颜色通过 fillStyle 属性指定，比如：

```js
var drawing = document.getElementById("drawing");
// 确定浏览器支持<canvas>元素
if (drawing.getContext) {
  var context = drawing.getContext("2d");
  /*
  * 根据 Mozilla 的文档
  * http://developer.mozilla.org/en/docs/Canvas_tutorial:Basic_usage
  */
  //绘制红色矩形
  context.fillStyle = "#ff0000";
  context.fillRect(10, 10, 50, 50);
  //绘制半透明的蓝色矩形
  context.fillStyle = "rgba(0,0,255,0.5)";
  context.fillRect(30, 30, 50, 50);
}
```

strokeRect()方法在画布上绘制的矩形会使用指定的颜色描边。描边颜色通过 strokeStyle 属性指定。比如：

```js
var drawing = document.getElementById("drawing");
// 确定浏览器支持<canvas>元素
if (drawing.getContext) {
  var context = drawing.getContext("2d");
  /*
  * 根据 Mozilla 的文档
  * http://developer.mozilla.org/en/docs/Canvas_tutorial:Basic_usage
  */
  //绘制红色描边矩形
  context.strokeStyle = "#ff0000";
  context.strokeRect(10, 10, 50, 50);
  //绘制半透明的蓝色描边矩形
  context.strokeStyle = "rgba(0,0,255,0.5)";
  context.strokeRect(30, 30, 50, 50);
}
```

描边线条的宽度由 lineWidth 属性控制，该属性的值可以是任意整数。另外，通过 lineCap 属性可以控制线条末端的形状是平头、圆头还是方头（"butt"、"round"或"square"），通过 lineJoin 属性可以控制线条相交的方式是圆交、斜交还是斜接（"round"、"bevel"或"miter"）。

最后，clearRect()方法用于清除画布上的矩形区域。本质上，这个方法可以把绘制上下文中的某一矩形区域变透明。通过绘制形状然后再清除指定区域，就可以生成有意思的效果，例如把某个形状切掉一块。下面看一个例子。

```js
var drawing = document.getElementById("drawing");
//确定浏览器支持<canvas>元素
if (drawing.getContext) {
  var context = drawing.getContext("2d");
  /*
  * 根据 Mozilla 的文档
  * http://developer.mozilla.org/en/docs/Canvas_tutorial:Basic_usage
  */
  //绘制红色矩形
  context.fillStyle = "#ff0000";
  context.fillRect(10, 10, 50, 50);
  //绘制半透明的蓝色矩形
  context.fillStyle = "rgba(0,0,255,0.5)";
  context.fillRect(30, 30, 50, 50);
  //在两个矩形重叠的地方清除一个小矩形
  context.clearRect(40, 40, 10, 10);
}
```
