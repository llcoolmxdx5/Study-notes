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
