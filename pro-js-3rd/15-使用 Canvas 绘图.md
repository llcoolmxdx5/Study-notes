# 第十五章 使用 Canvas 绘图

## 基本用法

要使用`<canvas>`元素，必须先设置其 width 和 height 属性，指定可以绘图的区域大小。出现在开始和结束标签中的内容是后备信息，如果浏览器不支持`<canvas>`元素，就会显示这些信息。下面就是`<canvas>`元素的例子。

`<canvas id="drawing" width=" 200" height="200">A drawing of something.</canvas>`

要在这块画布（canvas）上绘图，需要取得绘图上下文。而取得绘图上下文对象的引用，需要调用getContext()方法并传入上下文的名字。传入"2d"，就可以取得 2D 上下文对象。

```js
var drawing = document.getElementById("drawing");
// 确定浏览器支持<canvas>元素
if (drawing.getContext) {
  var context = drawing.getContext("2d");
  // 更多代码
}
```

使用 toDataURL()方法，可以导出在`<canvas>`元素上绘制的图像。这个方法接受一个参数，即图像的 MIME 类型格式，而且适合用于创建图像的任何上下文。比如，要取得画布中的一幅 PNG 格式的图像，可以使用以下代码。

```js
var drawing = document.getElementById("drawing");
// 确定浏览器支持<canvas>元素
if (drawing.getContext){
  // 取得图像的数据 URI
  var imgURI = drawing.toDataURL("image/png");
  // 显示图像
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
// 确定浏览器支持<canvas>元素
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
//  确定浏览器支持<canvas>元素
if (drawing.getContext) {
  var context = drawing.getContext("2d");
  /*
  * 根据 Mozilla 的文档
  * http:// developer.mozilla.org/en/docs/Canvas_tutorial:Basic_usage
  */
  // 绘制红色矩形
  context.fillStyle = "#ff0000";
  context.fillRect(10, 10, 50, 50);
  // 绘制半透明的蓝色矩形
  context.fillStyle = "rgba(0,0,255,0.5)";
  context.fillRect(30, 30, 50, 50);
}
```

strokeRect()方法在画布上绘制的矩形会使用指定的颜色描边。描边颜色通过 strokeStyle 属性指定。比如：

```js
var drawing = document.getElementById("drawing");
//  确定浏览器支持<canvas>元素
if (drawing.getContext) {
  var context = drawing.getContext("2d");
  /*
  * 根据 Mozilla 的文档
  * http:// developer.mozilla.org/en/docs/Canvas_tutorial:Basic_usage
  */
  // 绘制红色描边矩形
  context.strokeStyle = "#ff0000";
  context.strokeRect(10, 10, 50, 50);
  // 绘制半透明的蓝色描边矩形
  context.strokeStyle = "rgba(0,0,255,0.5)";
  context.strokeRect(30, 30, 50, 50);
}
```

描边线条的宽度由 lineWidth 属性控制，该属性的值可以是任意整数。另外，通过 lineCap 属性可以控制线条末端的形状是平头、圆头还是方头（"butt"、"round"或"square"），通过 lineJoin 属性可以控制线条相交的方式是圆交、斜交还是斜接（"round"、"bevel"或"miter"）。

最后，clearRect()方法用于清除画布上的矩形区域。本质上，这个方法可以把绘制上下文中的某一矩形区域变透明。通过绘制形状然后再清除指定区域，就可以生成有意思的效果，例如把某个形状切掉一块。下面看一个例子。

```js
var drawing = document.getElementById("drawing");
// 确定浏览器支持<canvas>元素
if (drawing.getContext) {
  var context = drawing.getContext("2d");
  /*
  * 根据 Mozilla 的文档
  * http:// developer.mozilla.org/en/docs/Canvas_tutorial:Basic_usage
  */
  // 绘制红色矩形
  context.fillStyle = "#ff0000";
  context.fillRect(10, 10, 50, 50);
  // 绘制半透明的蓝色矩形
  context.fillStyle = "rgba(0,0,255,0.5)";
  context.fillRect(30, 30, 50, 50);
  // 在两个矩形重叠的地方清除一个小矩形
  context.clearRect(40, 40, 10, 10);
}
```

### 绘制路径

要绘制路径，首先必须调用 beginPath()方法，表示要开始绘制新路径。然后，再通过调用下列方法来实际地绘制路径

- arc(x, y, radius, startAngle, endAngle, counterclockwise)：以(x,y)为圆心绘制一条弧线，弧线半径为 radius，起始和结束角度（用弧度表示）分别为 startAngle 和endAngle。最后一个参数表示 startAngle 和 endAngle 是否按逆时针方向计算，值为 false表示按顺时针方向计算。

- arcTo(x1, y1, x2, y2, radius)：从上一点开始绘制一条弧线，到(x2,y2)为止，并且以给定的半径 radius 穿过(x1,y1)。

- bezierCurveTo(c1x, c1y, c2x, c2y, x, y)：从上一点开始绘制一条曲线，到(x,y)为止，并且以(c1x,c1y)和(c2x,c2y)为控制点。

- lineTo(x, y)：从上一点开始绘制一条直线，到(x,y)为止。

- moveTo(x, y)：将绘图游标移动到(x,y)，不画线。

- quadraticCurveTo(cx, cy, x, y)：从上一点开始绘制一条二次曲线，到(x,y)为止，并且以(cx,cy)作为控制点。

- rect(x, y, width, height)：从点(x,y)开始绘制一个矩形，宽度和高度分别由 width 和height 指定。这个方法绘制的是矩形路径，而不是 strokeRect()和 fillRect()所绘制的独立的形状。

创建了路径后，接下来有几种可能的选择。如果想绘制一条连接到路径起点的线条，可以调用closePath()。如果路径已经完成，你想用 fillStyle 填充它，可以调用 fill()方法。另外，还可以调用 stroke()方法对路径描边，描边使用的是 strokeStyle。最后还可以调用 clip()，这个方法可以在路径上创建一个剪切区域。

下面看一个例子，即绘制一个不带数字的时钟表盘。

```js
var drawing = document.getElementById("drawing");
//  确定浏览器支持<canvas>元素
if (drawing.getContext) {
  var context = drawing.getContext("2d");
  // 开始路径
  context.beginPath();
  // 绘制外圆
  context.arc(100, 100, 99, 0, 2 * Math.PI, false);
  // 绘制内圆
  context.moveTo(194, 100);
  context.arc(100, 100, 94, 0, 2 * Math.PI, false);
  // 绘制分针
  context.moveTo(100, 100);
  context.lineTo(100, 15);
  // 绘制时针
  context.moveTo(100, 100);
  context.lineTo(35, 100);
  // 描边路径
  context.stroke();
}
```

由于路径的使用很频繁，所以就有了一个名为 isPointInPath()的方法。这个方法接收 x 和 y 坐标作为参数，用于在路径被关闭之前确定画布上的某一点是否位于路径上，例如：

```js
if (context.isPointInPath(100, 100)) {
  alert("Point (100, 100) is in the path.");
}
```

### 绘制文本

绘制文本主要有两个方法：fillText()和 strokeText()。这两个方法都可以接收 4 个参数：要绘制的文本字符串、x 坐标、y 坐标和可选的最大像素宽度。而且，这两个方法都以下列 3 个属性为基础。

- font：表示文本样式、大小及字体，用 CSS 中指定字体的格式来指定，例如"10px Arial"。

- textAlign：表示文本对齐方式。可能的值有"start"、"end"、"left"、"right"和"center"。建议使用"start"和"end"，不要使用"left"和"right"，因为前两者的意思更稳妥，能同时适合从左到右和从右到左显示（阅读）的语言。

- textBaseline：表示文本的基线。可能的值有"top"、"hanging"、"middle"、"alphabetic"、"ideographic"和"bottom"。

这几个属性都有默认值，因此没有必要每次使用它们都重新设置一遍值。fillText()方法使用fillStyle 属性绘制文本，而 strokeText()方法使用 strokeStyle 属性为文本描边。相对来说，还是使用 fillText()的时候更多，因为该方法模仿了在网页中正常显示文本。例如，下面的代码在前一节创建的表盘上方绘制了数字 12：

```js
context.font = "bold 14px Arial"
context.textAlign = "center"
context.textBaseline = "middle"
context.fillText("12", 100, 20)
```

修改textBaseline 属性的值可以调整文本的垂直对齐方式：值为"top"，y 坐标表示文本顶端；值为"bottom"，y 坐标表示文本底端；值为"hanging"、"alphabetic"和"ideographic"，则 y 坐标分别指向字体的特定基线坐标

### 变换

通过上下文的变换，可以把处理后的图像绘制到画布上。2D 绘制上下文支持各种基本的绘制变换。创建绘制上下文时，会以默认值初始化变换矩阵，在默认的变换矩阵下，所有处理都按描述直接绘制。为绘制上下文应用变换，会导致使用不同的变换矩阵应用处理，从而产生不同的结果。

可以通过如下方法来修改变换矩阵。

- rotate(angle)：围绕原点旋转图像 angle 弧度。

- scale(scaleX, scaleY)：缩放图像，在 x 方向乘以 scaleX，在 y 方向乘以 scaleY。scaleX和 scaleY 的默认值都是 1.0。

- translate(x, y)：将坐标原点移动到(x,y)。执行这个变换之后，坐标(0,0)会变成之前由(x,y)表示的点。

- transform(m1_1, m1_2, m2_1, m2_2, dx, dy)：直接修改变换矩阵，方式是乘以如下矩阵。
  m1_1 m1_2 dx
  m2_1 m2_2 dy
   0    0    1

- setTransform(m1_1, m1_2, m2_1, m2_2, dx, dy)：将变换矩阵重置为默认状态，然后再调用 transform()。

变换有可能很简单，但也可能很复杂，这都要视情况而定。比如，就拿前面例子中绘制表针来说，如果把原点变换到表盘的中心，然后再绘制表针就容易多了。请看下面的例子。

```js
var drawing = document.getElementById("drawing");
// 确定浏览器支持<canvas>元素
if (drawing.getContext) {
  var context = drawing.getContext("2d");
  // 开始路径
  context.beginPath();
  // 绘制外圆
  context.arc(100, 100, 99, 0, 2 * Math.PI, false);
  // 绘制内圆
  context.moveTo(194, 100);
  context.arc(100, 100, 94, 0, 2 * Math.PI, false);
  // 变换原点
  context.translate(100, 100);
  // 绘制分针
  context.moveTo(0,0);
  context.lineTo(0, -85);
  // 绘制时针
  context.moveTo(0, 0);
  context.lineTo(-65, 0);
  // 描边路径
  context.stroke();
}
```

```js
context.fillStyle = "#ff0000";
context.save();
context.fillStyle = "#00ff00";
context.translate(100, 100);
context.save();
context.fillStyle = "#0000ff";
context.fillRect(0, 0, 100, 200); // 从点(100,100)开始绘制蓝色矩形
context.restore();
context.fillRect(10, 10, 100, 200); // 从点(110,110)开始绘制绿色矩形
context.restore();
context.fillRect(0, 0, 100, 200); // 从点(0,0)开始绘制红色矩形
```

需要注意的是，save()方法保存的只是对绘图上下文的设置和变换，不会保存绘图上下文的内容。

### 绘制图像

2D 绘图上下文内置了对图像的支持。如果你想把一幅图像绘制到画布上，可以使用 drawImage()方法。根据期望的最终结果不同，调用这个方法时，可以使用三种不同的参数组合。最简单的调用方式是传入一个 HTML `<img>`元素，以及绘制该图像的起点的 x 和 y 坐标。例如：

```js
var image = document.images[0];
context.drawImage(image, 10, 10);
```

这两行代码取得了文档中的第一幅图像，然后将它绘制到上下文中，起点为(10,10)。绘制到画布上的图像大小与原始大小一样。如果你想改变绘制后图像的大小，可以再多传入两个参数，分别表示目标宽度和目标高度。通过这种方式来缩放图像并不影响上下文的变换矩阵。例如：

```js
context.drawImage(image, 50, 10, 20, 30);
```

除了上述两种方式，还可以选择把图像中的某个区域绘制到上下文中。drawImage()方法的这种调用方式总共需要传入 9 个参数：要绘制的图像、源图像的 x 坐标、源图像的 y 坐标、源图像的宽度、源图像的高度、目标图像的 x 坐标、目标图像的 y 坐标、目标图像的宽度、目标图像的高度。这样调用drawImage()方法可以获得最多的控制。例如：

```js
context.drawImage(image, 0, 10, 50, 50, 0, 100, 40, 60);
```

除了给 drawImage()方法传入 HTML `<img>`元素外，还可以传入另一个`<canvas>`元素作为其第一个参数。这样，就可以把另一个画布内容绘制到当前画布上。

结合使用 drawImage()和其他方法，可以对图像进行各种基本操作。而操作的结果可以通过toDataURL()方法获得(Canvas 对象的方法)。不过，有一个例外，即图像不能来自其他域。如果图像来自其他域，调用toDataURL()会抛出一个错误。

### 阴影

2D 上下文会根据以下几个属性的值，自动为形状或路径绘制出阴影。

- shadowColor：用 CSS 颜色格式表示的阴影颜色，默认为黑色。

- shadowOffsetX：形状或路径 x 轴方向的阴影偏移量，默认为 0。

- shadowOffsetY：形状或路径 y 轴方向的阴影偏移量，默认为 0。

- shadowBlur：模糊的像素数，默认 0，即不模糊。

这些属性都可以通过 context 对象来修改。只要在绘制前为它们设置适当的值，就能自动产生阴影。例如：

```js
var context = drawing.getContext("2d");
//设置阴影
context.shadowOffsetX = 5;
context.shadowOffsetY = 5;
context.shadowBlur = 4;
context.shadowColor = "rgba(0, 0, 0, 0.5)";
//绘制红色矩形
context.fillStyle = "#ff0000";
context.fillRect(10, 10, 50, 50);
//绘制蓝色矩形
context.fillStyle = "rgba(0,0,255,1)";
context.fillRect(30, 30, 50, 50);
```
