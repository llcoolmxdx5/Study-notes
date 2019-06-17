# css

## 1.文本

```css
font:font-style font-weight  font-size/line-height  font-family; /*必有family*/
Font-style: normal | italic;      /*normal 默认值  italic  斜体*/
Font-weight: 700;   /*值从100-900，文字粗细，不推荐使用font-weight:bold;*/
font-size:16px;  /*文字大小*/
line-height: 行高 /*行高=文字大小+上下间距*/
Font-family:微软雅黑 Microsoft Yahei; 宋体 SimSun  /*文本的字体 **必有*/
文本修饰：text-decoration: none/underline/line-through
vertical-align:middle; /*图片和文字垂直居中对齐*/
text-indent: -999em /*隐藏文字*/
```

## 2.标签分类

- 块元素 `display:block;`

  `Div,h1-h6,p,ul,li`
  独占一行,可以设置宽高
  嵌套（包含）下，子块元素宽度（没有定义情况下）和父块元素宽度默认一致。

- 行内元素 display:inline

  `span  ,a,  ,strong , em,  del,  ins`
  在一行上显示,不能直接设置宽高
  元素的宽和高就是内容撑开的宽高。

- 行内块元素(内联元素) `display:inline-block;`

  `input  img`
  在一行上显示,可以设置宽高

行内元素尽量包含行内元素，行内元素不要包含块元素

## 3.链接伪类

`a:link{属性:值;}`      链接默认状态
`a:visited{属性:值;}`     链接访问之后的状态
`a:hover{属性:值;}`      鼠标放到链接上显示的状态
`a:active{属性:值;}`      链接激活的状态
`a:focus{属性:值；}`     获取焦点

## 4.背景属性

```css
background: color image repeat position attachment; /*无顺序要求,必有image*/
background-color    red  /*背景颜色*/
background-image    url()  /*背景图片*/
background-repeat repeat(默认)/no-repeat/repeat-x/repeat-y    /*背景平铺*/
background-position  left/right/enter/top/bottom/具体数值  /*背景定位(可写一个或2个,一个时另一个默认居中)*/
background-attachment  scroll/fixed  /*背景是否滚动*/
```

## 5.盒子模型

```css
boder/boder-top: style color width; 无顺序要求,style必有
boder-style: solid  实线/dotted 点线/dashed  虚线/none 去掉边框
border-color   边框颜色
border-width   边框粗细
border-collapse:collapse  边框合并
outline-style: none; 去掉轮廓线
padding-top/bottom/left/right: 20px; 内边距
margin-top/bottom/left/right: 20px; 外边距
   可有1 2 4个值,上,上 下,上 右 下 左
```

- 垂直方向外边距合并

  两个盒子垂直一个设置上外边距，一个设置下外边距，取的设置较大的值。

- 嵌套的盒子外边距塌陷

  - 给父盒子设置边框

  - 给父盒子`overflow:hidden;`   bfc   格式化上下文

- 在盒子内，一行文字行高和盒子的高度相等，这行垂直居中

- 盒子居中显示:

  1. 标准流: `margin:0 auto;`

  2. 定位 先左右走父元素盒子的一半50%，在向左走子盒子的一半(`margin-left:负值`。)

      - 父元素相对定位,子元素绝对定位

      - 子元素`{width:100px;left:50%;margin-left:-50px}`

## 6.浮动布局

- float: left/right

  - 元素浮动之后不占据原来的位置（脱标）

  - 浮动的盒子在一行上显示

  - 行内元素浮动之后转换为行内块元素。（不推荐使用，转行内元素最好使用display: inline-block;）

- 清除浮动

   1. 在最后一个浮动元素后添加标签

      `<div style='clear:both;'></div>`

   2. 给父元素使用overflow:hidder;

      若有内容出了盒子不能用此方法

   3. 伪元素清除浮动(推荐)

     ```css
    .clearfloat:after{display:block;clear:both;content:"";visibility:hidden;height:0}
    .clearfloat{zoom:1} /*兼容IE6*/
     ```

    两句结合起来可清除所有浮动,且有很好兼容性

- overflow:visible/hidden/scroll/auto

- position:static 默认定位

  - absolute 绝对定位,从浏览器出发,嵌套的盒子，转为行内块 脱标
          父盒子使用定位，子盒子绝对定位，子盒子位置是从父元素位置出发

  - relative 相对定位 从自身出发,仍占据之前的位置,元素相对定位，子元素绝对定位,不能转行内块

  - fixed 固定定位 从浏览器出发,脱标,转行内块

## 7.Css可见性

```css
overflow:hidden;   /* 溢出隐藏 */
visibility:hidden;   /* 隐藏元素  隐藏之后还占据原来的位置。 */
display:none;      /* 隐藏元素  隐藏之后不占据原来的位置。*/
display:block;     /* 元素可见 */
display:none  /* 和display:block  常配合js使用 */
```

## 8.内容移除(网页优化)

```css
a{display:inline-block;text-indent:-5000em;}
.box{height:0;padding-top:xpx;overflow:hidden}
```

## x.淘宝css初始化

```css
body, h1, h2, h3, h4, h5, h6, hr, p, blockquote, dl, dt, dd, ul, ol, li, pre, form, fieldset, legend, button, input, textarea, th, td { margin:0; padding:0; }
body, button, input, select, textarea { font:12px/1.5tahoma, arial, \5b8b\4f53; }
h1, h2, h3, h4, h5, h6{ font-size:100%; }
address, cite, dfn, em, var { font-style:normal; }
code, kbd, pre, samp { font-family:couriernew, courier, monospace; }
small{ font-size:12px; }
ul, ol { list-style:none; }
a { text-decoration:none; }
a:hover { text-decoration:underline; }
sup { vertical-align:text-top; }
sub{ vertical-align:text-bottom; }
legend { color:#000; }
fieldset, img { border:0; }
button, input, select, textarea { font-size:100%; }
table { border-collapse:collapse; border-spacing:0; }
```

## xx.杂

### 精灵图

将多个小图合并成一张大图用background-image加载,然后用background-position定位到小图

### css属性选择器

`input[type=text][class]{width:300px;}`

### 文本溢出隐藏

```css
span{
   width:50px; 或max-width: 160px;
   display:inline-block;
   overflow: hidden;
   white-space: nowrap;
   text-overflow: ellipsis;
}
word-break: break-all;表示文本长度超过就自动换行
```

### 清除img间默认间隙

```css
img {
   div{font-size:0}; 方案一
   img{ display:block}; 方案二
   img{vertical-align:top;} 方案三
   div{ margin-bottom:-3px }; 方案四
}
```

### 不让文字被选中

```css
-webkit-user-select:none;
-moz-user-select:none;
-ms-user-select:none;
user-select:none;
```
