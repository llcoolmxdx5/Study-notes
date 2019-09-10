# 第一阶段总结

## 网页制作技术

web标准
w3c组织（万维网联盟） 制定的是 结构、表现的标准
结构 XHTML XML
表现 css
ECMA(欧洲电脑厂商协会)
行为 DOM,ECMAScript

W3C制定的 结构和表现的标准
结构   xhtml xml
表现    css

ECMA 欧洲电脑厂商协会制定的行为标准
行为    DOM,ECMAScript

### 1.1 前端开发所用到的技术(网页制作技术)

ＸHTML+CSS       标记语言

### 1.1.2WEB标准的概念及组成

Web标准是一个复杂的概念集合，它由一系列标准组成。这些标准大部分由W3C起草与发布，也有一些标准是其它标准组织制订，如ECMA（European Computer Manufactrrers Association,欧洲电脑厂商联合会）的ECMAScript标准。
结构，表现，行为

W3C( World Wide Web Consortium )万维网联盟，创建于1994年是Web技术领域最具权威和影响力的国际中立性技术标准机构。(制定了结构和表现的标准，非盈利的）
结构：(xhtml ,xml)
表现：(css)
ECMA（欧洲电脑厂商联合会）制定的行为标准
行为：(DOM,ECMAScript)（ECMA制定的）；

## 1.2 HTML及相关概念的介绍

### 1.2.1 HTML 、XHTML 、HTML5

HTML 指的是超文本标记语言 (Hyper Text Markup Language)

XHTML指可扩展超文本标记语言（标识语言） （The EXtensible HyperText Markup Language）。 XHTML 是更严格更纯净的 HTML 版本

SML， HTML1.0， HTML2.0 ，HTML3.0， HTML4.0 ，
XHTML1.0
HTML5

目前推荐遵循的是W3C于2000年1月26日发布的XHTML1.0
HTML5    指的是HTML的第五次重大修改
(HTML5 是 W3C 与 WHATWG 合作的结果，是最新的html规范）
  
WHATWG网页超文本应用技术工作小组是一个以推动网络HTML 5 标准为目的而成立的组织。在2004年，由Opera、Mozilla基金会和苹果这些浏览器厂商组成。

## 1.3 相关准备工作

## 1.3.1 编辑器的使用 -Dreamweaver

Fireworks是Macromedia公司发布的一款专为网络图形设计的图形编辑软件，2005年，Adobe用34亿美元收购macromedia公司，fireworks随之跟随至adobe。
1、新建，打开，保存        2， 预览页面      3，建立站点

### 1.3.2 PC端调试工具的使用的浏览器

测试浏览器(chrome,ie,firefox)

### 1.3.3 移动端调试工具的使用

chrome可以测试移动端页面（有很多模拟器）

## 1.4 HTML5 基本结构

```html
<!DOCTYPE html>命名文档类型
<html>说明我们写的是标记语言 根标签
<head>
    <meta charset="utf-8" />编码格式
    <title></title>文件标题
</head>文件头部
<body></body>文件主体(里面放着页面里所有展示的内容)
</html>
```

HTML页面是由标签和属性构成，一起 用于标识各个文档部件；
一个HTML文档包含两部分内容：对这个文件简单描述区(head)和文档本身(body)的内容区。
HTML文档具有以下特点：
结构化
简单，易维护
与平台无关

HTML架构:
1、`<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">`
定义文档类型

有三种： Strict（严格型)、Trasitional（过渡型）、Frameset（框架型）

文件命名规则：用英文，不用中文
名称全部用英文字母、数字、下划线的组合，其中不得包含汉字、空格和特殊字
符,以英文字母开头。

### 1.4.2 XHTML基本语法

1、常规标记 (双标记)
语法：<标记  属性=“属性值”   属性=“属性值”>内容</标记>

2.空标记 （单标记）
语法：<标记 属性=“属性值”  />

说明：
1.写在<>中的第一个单词叫做标记，标签，元素。
2.标记和属性用空格隔开，属性和属性值用等号连接，属性值必须放在“”号内。
3.一个标记可以没有属性也可以有多个属性，属性和属性之间不分先后顺序，用空格隔开。
4.空标记没有结束标签，用“/”代替。

## 1.5 XHTML常用标记

### 1.5.1 文本标题（h1-h6）

`<h1>一级标题</h1>`
`<h2>二级标题</h2>`
...
`<h6>六级标题</h6>`

### 1.5.2 段落标签

`<p>段落文本内容</p>`

### 1.5.2 转义字符

`&nbsp;`      空格
Html中常用的转义字符：
常见的如下：
`&gt;` >右尖括号
`&lt;` <左尖括号
`&copy;` 备案中图标版权 ©

### 1.5.5 加粗

1.`<b>加粗内容</b>`
2.`<strong>加粗内容</strong>` 更具有语义化

### 1.5.6倾斜

1、`<em>倾斜</em>` 语义化
2、`<i>倾斜</i>`

### 1.5.4 强制换行

`<br />`

### 1.5.10设置文本加下划线

`<u></u>`  

删除线   `<del></del>` `<s></s>`

### 1.5.8设置字体上标

`<sup></sup>`

### 1.5.9 设置字体下标

`<sub></sub>`

### 1.5.7水平线

`<hr />`空标记

### 1.5.11 span文本结点

`<span></span>`

### 1.5.12 文档区域，文档布局对象

`<div></div>`

### 1.5.13 列表(ul,ol,dl)

HTML中有三种列表，分别是：无序列表，有序列表，自定义列表
1.无序列表

```html
<ul>
    <li>列表项内容</li>
    <li>列表项内容</li>
   ...
</ul>
```

2.有序列表

```html
<ol>
    <li></li>
    ...
</ol>
```

type:规定列表中的列表项目的项目符号的类型
语法：`<ol type="a"></ol>`
start 属性规定有序列表的开始点。(start的属性值必须是数字)
语法：`<ol start="5"></ol>`

1 数字顺序的有序列表（默认值）（1, 2, 3, 4）。
a 字母顺序的有序列表，小写（a, b, c, d）。
A 字母顺序的有序列表，大写（A,B,C,D)
i 罗马数字，小写（i, ii, iii, iv）。
I 罗马数字，大写（I,II,III,IV,V）。

3、自定义列表

```html
<dl>
     <dt>名词</dt>
     <dd>解释</dd>
</dl>
```

### 1.5.14插入图片

语法：`<img  src="目标文件路径及全称"  />`
一、相对路径的说明：
1)当当前文件与目标文件在同一目录下，直接书写目标文件文件名+扩展名；
2)当当前文件与目标文件所处的文件夹在同一目录下，写法如下：文件夹名/目标文件全称+扩展名；
3)当当前文件所处的文件夹和目标文件所处的文件夹在同一目录下，写法如下：../目标文件所处文件夹名/目标文件全称+扩展名；

width=""    宽度 height="" 高度

`<img src="目标文件路径及全称"   alt="图片替换文本"   title="图片标题"  />`

title:指的是标题，当鼠标划过的时候，会显示在鼠标右下方，起到提示作用；

alt:是当图片因某种原因没有正确显示的时候，显示在图片所在位置上面的内容，用来提示用户；

二、相对路径使用的特殊符号
以下为建立路径所使用的几个特殊符号，及其所代表的意义。
“./”：代表目前所在的目录。
“../”：代表上一层目录。
以”/”开头：代表根目录。

## 1.6  超链接

`<a href="#"></a>`
target 属性参数定义了打开链接的目标窗口。

_blank 在新窗口中打开链接页面（会保留原窗口）
_self 在当前窗口打开链接页面，此为默认值

## 1.7 table(表格的使用)

作用：显示数据

```html
<table>
    <tr>
        <td>...</td>
        <td>...</td>
    </tr>
    <tr>
        <td>...</td>
        <td>...</td>
    </tr>
   ......
</table>
```

注：一组tr表示一行;一组td表示一列(一个单元格)

*数据表格的相关属性
1）width="表格的宽度"
2）height="表格的高度"
3）border="表格的边框"
4）bordercolor="表格边框颜色"
5）bgcolor="表格的背景色"
6）cellspacing="单元格与单元格之间的间距"
7）cellpadding="单元格与内容之间的空隙"
8）水平对齐方式：align="left/center/right";
垂直对齐方式：valign="top/middle/bottom";

9)合并单元格属性：
colspan=“所要合并的单元格的列数”      横向合并;

```html
<table width="300" height="90" cellspacing="0" cellpadding="0" border="1">
  <tr>
    <td border="1" colspan="2">一行</td>
  </tr>
  <tr>
    <td border="1">一行</td>
    <td border="1">一行</td>
  </tr>
</table>
```

rowspan=“所要合并单元格的行数”    纵向合并;

```html
<table width="300" height="90" cellspacing="0" cellpadding="0" border="1">
  <tr>
    <td border="1" rowspan="2">一行</td>
    <td border="1">一行</td>
  </tr>
  <tr>
    <td border="1">一行</td>
  </tr>
</table>
```

## 1.8 部分表单元素的使用

表单的作用：用来收集用户信息

1、表单控件
1)单行文本框
`<input type="text" value="默认值"/>`

2)密码框
`<input type="password" />`
`<input type="password" placeholder="密码" />`

placeholder：提示信息属性

3)提交按钮
`<input type="submit" value="按钮内容" />`

4)重置按钮
`<input type="reset" value="按钮内容" />`

表单域：
`<form method="post/get(传输方式)" action=""></form>`

扩展知识点：post和get的区别

1. get是从服务器上获取数据，post是向服务器传送数据。

2. get是把参数数据队列加到提交表单的action属性所指的URL中，在URL中可以看到。post是通过HTTP post机制，用户看不到这个过程。

3. get传送的数据量较小，不能大于2KB。post传送的数据量较大，一般被默认为不受限制。

4. get安全性非常低，post安全性较高。但是执行效率却比Post方法好。

## 一 、CSS基础

css简介
cascading style sheet    汉译 :层叠样式表；

表现标准语言在网页中主要对网页信息的显示进行控制，简单说就是如何修饰网页信息的显示样式。
目前推荐遵循的是W3C发布的CSS3.0
用来表现HTML或者XML等样式文件的计算机语言。
 1998年5月21日由w3C正式推出的css2.0
(在css1的基础上增加了高级功能，浮动，定位，高级选择器等。
CSS 3 在包含了所有 CSS 2.0 所支持的基础上进行了改进.（css3遵循的是模块化开发，发布的时间不是一个点而是一个时间段）

## 二、css语法

语法：
选择符{ 属性:属性值; 属性:属性值 ; 属性:属性值   属性值   属性值；}
<标记   属性=“属性值”    属性=“属性值”></标记>
div{
      width:200px;
      height:200px;
      background:#f00;
      border:1px olid #f00;
}
说明：
1）  css语法由两部分组成，分别是选择符和声明，声明包括属性和属性值；声明包必须放在{}内；
2）属性与属性值用冒号连接
3）当一个选择符有多个属性时，用分号隔开；
4）当一个属性有多个属性值时，属性值和属性值之间用空格分隔；
5）使用空格、换行不影响css样式的显示。

## 三、样式表的创建

### 1、内部样式表创建

语法：
`<style type="text/css"></style>`

说明：使用style标记创建内部样式表时，最好把该标记写在`<head></head>`之中。

css属性：
width:100px;                      宽度
height:100px;                     高度
background-color:red;    背景颜色
border:1px solid red;       边框
color:#ff00ff ；                文本颜色

### 2、外部样式表

外部样式表的调用
（1）第一种方法：`<link rel="stylesheet "   type="text/css"  href="目标文件路径及全称" />`

（2)第二种方法：

```html
<style type="text/css">
    @import url(目标路径及全称);
</style>
```

link和@import的区别（建议使用link元素加载外部样式表）
本质上，这两种方式都是为了加载CSS文件，但还是存在着细微的差别。

差别1：老祖宗的差别。link属于XHTML标签，而@import完全是CSS提供的一种方式。

差别2：link标签除了可以加载CSS外，还可以做很多其它的事情，比如定义RSS，定义rel连接属性等，@import就只能加载CSS了。

差别3：加载顺序的差别。当一个页面被加载的时候（就是被浏览者浏览的时候），link引用的CSS会同时被加载，而@import引用的CSS 会等到页面全部被下载完再被加载。所以有时候浏览@import加载CSS的页面时开始会没有样式（就是闪烁），网速慢的时候还挺明显（梦之都加载CSS 的方式就是使用@import，我一边下载一边浏览梦之都网页时，就会出现上述问题）。

差别4：兼容性的差别。由于@import是CSS2.1提出的所以老的浏览器不支持，@import只有在IE5以上的才能识别，而link标签无此问题。

差别5：使用dom控制样式时的差别。当使用javascript控制dom去改变样式的时候，只能使用link标签，因为@import不是dom可以控制的。

### 3、内联样式表（也叫样式表或直进式样式表或者叫做行内样式）

语法：<标记 style="属性：属性值；属性：属性值;"></标记>

### 4、样式表的作用域

内联样式表的作用域：只针对当前标签起作用；
内部样式表的作用域：只针对于当前页面起作用
外部样式表的作用域：可以连接到多个页面，对多个页面起作用。

### 5、样式表的优先级

内部样式表、外部样式表、内联样式表
（1）内联样式的优先级别最高
（2）内部样式和外部样式的优先级与书写位置有关，后书写的优先级别高。

### 6、css选择符

选择符的概念：选择符表示要定义样式的对象，可以是元素本身，也可以是一类元素或者指定名称的元素

1）类型选择符
语法：元素名称{属性:属性值;}
说明：类型选择符就是以文档语言对象类型作为选择符，即、使用结构中元素名称作为选择符；
例如：body 、div、 p/i/u/b/strong等
用法：
（1）如果想改变某个元素的默认样式时，可以使用类型选择符；（如：改变一个p段落样式）

（2）当统一文档某个元素的显示效果时，可以使用类型选择符；（如：改变文档所有p段落样式）

2）id选择符
语法：#id名{属性：属性值；}
说明：
a、 id选择符的语法格式是“#”加上自定义的id名；
b、当我们使用id选择符时，应先为每个元素定义一个id属性，如`<div id="top"></div>；`
c、一个id名称只能对应于文档中一个具体的元素对象，因为id只能够定义页面某一个唯一的元素对象。

3）class选择符（也叫类选择符）
语法：.class名{属性:属性值;}

说明：
a、类选择符的语法格式是：“.”加上定义的class名称，也就是类名称；
b、当我们使用类选择符时，应先为每个元素定义一个class属性，如：`<div class="red   elloe"></div>`。

4）群组选择符（提取同分类项）
语法：选择符1，选择符2，选择符3{属性：属性值；}
说明：当多个选择符应用相同样式时，可以将选择符用英文逗号分隔的方式，合并为一组；

5）包含选择符
语法：选择符1  选择符2{ 属性：属性值；}
说明：选择符1和选择符2 之间用空格隔开。含义就是所有选择符1中包含选择符2。

6）动态伪类选择符
伪类选择符的语法和超链接的4个状态：
:link{属性:属性值;}       超链接的初始状态；
:visited{属性:属性值;}   超链接被访问后的状态；
:hover{属性:属性值;}    鼠标悬停，即鼠标滑过的状态；
:active{属性:属性值;}    超链接被激活时状态，即按下鼠标时的状态；

说明：
1、为简化代码，可以把伪类选择符中相同的声明提出来放在a选择符中；（相同的属性，后写的起作用）
2、当这4个超链接伪类选择符联合使用时，应注意他们的顺序；（错误的顺序有时会使超链接的样式失效）
3、使用与超链接相关的伪类选择符时，应为a元素定义href属性。

7）通配符
语法：*{属性：属性值；}
说明：通配选择符的写法是“*”，其含义就是所有元素。

全局样式
*{margin:0;padding:0;}
margin   :   外边界值
padding   :   内填充值

### 7、选择符的权重(特殊性)

css中，用4位数字表示权重，权重的表达方式如：0,0,0,0
类型选择符的权重为：0001
类（class）选择符的权重为：0010
ID选择符的权重为：0100
伪类选择符的权重为：0010
包含选择符的权重为,包含选择符权重之和
内联样式的权重：1000
通配符权重：0000；
伪元素选择符的权重为：0001
子选择符的权重为：0000
属性选择符的权重为：0010
继承的样式权重为0000；

HTML 注释`<!--注释语句-->`

css注释`/*注释语句*/`

## 一、css属性

1）每个css样式都必须由两部分组成：选择符（Selector）和声明（Decleration）
注：声明又包括属性（Properyt）和属性值（Value）
2）css属性：属性是指定选择符具有的属性，他是css的核心，css2共有150多个属性；
3）css属性值 ：属性值包括法定属性值和常规的数值加单位或颜色值(colorValue)；如（25px）。

table{border-spacing:0;}
div{width:100px; font-weight:bolder; color:#ff0000;}

### A、关于文本的css声明

1、文字大小{font-size：value；}
说明：
a、属性值为数值型时，必须给属性值加单位 (px)，属性值为0时除外；
b、单位还可以是pt;  9pt=12px;
c、为了减小系统的字体显示差异，IE、Netscape Mozilla的浏览器制作商于1999年召开会议，共同确定16px/ppi为标准字体大小，默认值即1em,默认情况下，1em=16px,    0.75em=12px;
d、使用绝对大小关键字
xx-small         =9px
x-small           =11px
small              =13px
medium         =16px
large             =19px
x-large         =23px
xx-large       =27px

2、文本颜色：{color：#colorValue;}
十进制：0,1,2,3,4,5,6,7，8，9
二进制：0,1
八进制：0,1,2,3,4,5,6,7
十六进制：0,1,2,3,4,5,6,7,8,9,a,b,c,d,e,f

  R    G     B

```css
#       00      00     00
#       Fa      FF   FF    #faffff
#        CC      CC   CC
#        F0      F0   F0
#        0F      0F   0F     #0f0f0f
#        ff      00     00
#        ff     ff    00   #ff0
```

说明：用十六进制表示颜色值时前面要加#号；
每表示三原色的三组数字同时相同时，可以缩写为3位。

3、文本字体：{font-family:字体；}
Windows中文版本操作系统下，中文默认字体为宋体或者新宋体，英文字体默认为Arial.
说明：
当字体是中文字体时，需加双引号；
当英文字体中有空格时，需加双引号如（“Times New Roman”）
当英文字体只有一个单词组成是不加双引号；如：（Arial）；

设置多个字体的语法：{font-family:字体1，字体2，字体3；}

注：当同时设置中英文字体的时候，中文字体要写在英文字体之后；
说明：浏览器首先会寻找字体1、如存在就使用改字体来显示内容，如在字体1不存在的情况下，则会寻找字体2，如字体2也不存在，按字体3显示内容，如果字体3 也不存在；则按系统默认字体显示；

4、加粗：{font-weight:bolder(更粗的)/bold（加粗）/normal（常规）/100—900;}
说明：在css规范中，把字体的粗细分为9个等级，分别为100——900，其中100对应最轻的字体变形，而900对应最重的字体变形，
一般400=normal，700=bold。

100-500 常规显示
600-900 加粗显示

5、倾斜：font-style：italic(倾斜度小)/oblique（倾斜度大）/normal（取消倾斜，常规显示）;

6、设置小型的大写字母  {font-variant:normal/ small-caps ;}
取值为：normal(正常的字体)  
                small-caps(小型的大写字母字体)
说明： 对小写英文内容起作用。

7、首行缩进：{text-indent：Value;}
说明：（1）text-indent可以取负值；
              （2）text-indent属性只对第一行起作用。

8、水平对齐方式{text-align:left /  right / center / justify;}
                                             左对齐  右对齐  居中对齐 两端对齐

9、垂直对齐方式{vertical-align:top/bottom/middle/baseline;}上下居中基线

10、行高{line-height：normal/value;}

说明：
（1）当单行文本行高等于容器高时，可实现单行文本在容器中垂直中齐效果；
（2）当单行文本的行高小于容器高时，可实现单行文本在容器中垂直中齐以上任意位置定位;
（3）当单行文本的行高大于容器高时，可实现单行文本在容器中垂直以下任意位置定位。

倍行高：{line-height:2;} 2倍 ，{line-height:1.5em;}1.5倍；注：当使用倍行高时，单位不加PX

11、复合式写法：{font：style variant weight  size/ line-height     family；}
倾斜   小型大写字母     加粗       字号 /  行高 字体

说明：按以上顺序;size 、line-height和family固定不可和其他属性位置互换；
注：当字号大小，字体和行高缩写时，字号和行高要用斜杠合并成一个属性值，且同时有字号大小和字体时，才能缩写。

12、控制英文大小写  {text-transform:none(默认值)/capitalize(每个单词首字母大写)/uppercase (都为大写字母) /lowercase ( 都为小写字母 ) }

13、文本修饰：
{text-decoration:none:没有修饰(取消修饰)/underline:添加下划线/overline:添加上划线/line-through:添加删除线/blink：闪烁}
说明：
blink：闪烁(高版本浏览器不支持blink属性);}
underline overline line-through这三个属性值是可以同时存在的,用空格分隔；

14、字间距{letter-spacing：Value;}控制字间距；

15、词间距{word-spacing:Value;}控制英文单词词间距

16、文本流控制{layout-flow:horizontal/vertical-ideographic;}（只支持IE浏览器）
说明：
（1）horizontal 自左向右；
（2）vertical-ideographic;自上而下；

### B、关于列表的css声明

1、定义列表符号样式：
list-style-type：disc(实心圆)/circle(空心圆)/square(实心方块)/none(去掉列表符号)；

2、使用图片作为列表符号：
list-style-image：url(所使用图片的路径及全称)；

3、定义列表符号的位置：
list-style-position:outside(外边)/inside(里边)；

关于列表的属性语法（缩写）list-style：属性值1   属性值2    属性值3；

例：{list-style:url(images/aa.jpg)   inside;}
        list-style:none;   取消列表符号

### C、关于背景的css声明

1、背景颜色
background-color:#colorValue;

2、背景图片的设置
语法：background-image：url(背景图片的路径及全称)；
说明：
（1）网页上有两种图片形式：插入图片、背景图；插入图片为网页内容，背景图为网页的表现;默认情况下，背景图上面可以显示其他内容和图片，而插入图片上面是不能显示
其他内容和图片的。
（2）背景图片的显示方式
a、背景图片大小小于元素大小，默认平铺；
b、背景图片大小等于元素大小，完全显示；
c、背景图片大小大于元素大小，只显示元素范围大小的背景图；

3、背景图平铺设置
语法：background-repeat：no-repeat（不平铺）/repeat(平铺)/repeat-x（横向平铺）/repeat-y（纵向平铺）;

4、背景图片的位置
语法：background-position:left/right/center(水平方向上的对齐方式)      top/center/bottom(垂直方向上的对齐方式) 或数值

背景属性的缩写语法：background:属性值1   属性值2   属性值3；
例：background:url(背景图片的路径及全称)  no-repeat center top；

5、 背景图的固定
语法：background-attachment：scroll(滚动)/fixed(固定)；

## 二、浮动属性

首先要知道，div是块级元素，在页面中独占一行，自上而下排列，也就是传说中的流
div1

div2

div3

di4
无论多么复杂的布局，其基本出发点均是：“如何在一行显示多个div元素”。

显然标准流已经无法满足需求，这就要用到浮动。

浮动可以理解为让某个div元素脱离标准流，漂浮在标准流之上，和标准流不是一个层次。
页面浮动多个DIV的规律：

假如某个div元素A是浮动的，如果A元素上一个元素也是浮动的，那么A元素会跟随在上一个元素的后边(如果一行放不下这两个元素，那么A元素会被挤到下一行)；如果A元素上一个元素是标准流中的元素，那么A的相对垂直位置不会改变，也

就是说A的顶部总是和上一个元素的底部对齐。

div的顺序是HTML代码中div的顺序决定的。

靠近页面边缘的一端是前，远离页面边缘的一端是后。

经过上边的学习，可以看出：元素浮动之前，也就是在标准流中，是竖向排列的，而浮动之后可以理解为横向排列

语法：float:none/left/right;
有三个取值：
left:元素左浮动
right:元素右浮动
none:默认值，不浮动。

浮动的目的：就是让竖着的元素进行横向排列，也就是能让元素和元素并排显示

浮动的显示规则：浮动对象会像左或者右移动直到遇到边框（border）、填充值（padding）、外边界（margin）或者另一个块元素为止。

float:定义网页中其它文本如何环绕该元素显示

清除浮动语法：
clear : none | left | right | both
none：默认值。允许两边都可以有浮动对象
left：不允许左边有浮动对象
right  :  不允许右边有浮动对象
both  :  不允许有浮动对象

有一点是要记住的那就是
对于CSS的清除浮动(clear)，一定要牢记：这个规则只能影响使用清除的元素本身，不能影响其他元素
清除浮动可以理解为打破横向排列。

有三种情况float:不生效
1）当宽+宽大于父级元素的宽时；

2）只给一个元素加了float时；

3）单词写错

## 六、盒模型

学习目标
1、认识盒子模型
2、盒子模型的组成部分
3、学习盒子模型的相关元素 margin padding border
4、文本溢出相关的属性

盒模型概念：
盒模型是css布局的基石，它规定了网页元素如何显示以及元素间相互关系，css定义所有的元素都可以像盒子一样的外形和平面空间
，即包含内容区、填充区（padding）、边框（border）、边界（margin）,这就是盒模型。

### 1、填充（padding)

padding是指在内容与边框的空白区域，也称补白。

作用：
(1)  用来调整子元素在父元素的位置关系；
（2） 调整内容在容器中的关系；

注：padding写在父元素上

用法：
（1）padding值是额外加在元素原有大小之上的，要想原来尺寸不变,加完padding值后在原始数值上减去加上的padding值；
（2）可单独设置一方向填充，如：padding-top：10px;padding-right：10px;padding-bottom：10px;padding-left:10px;
padding:2px;                      定义元素上下左右填充值都为2px;
padding:2px 4px;               定义元素上下填充值分别为2px，左右填充值分别为4px;
padding:2px 4px 6px;       定义元素上填充值为2px，左右填充值分别为4px，下填充值为6px;
padding:2px 4px 6px 8px;定义元素上填充值为2px，右填充值分别为4px，下填充值为6px，左填充值为8px

补充：1、padding属性处于内容与边框之间，我们可以利用该属性设置图片与边框间的空隙；
2、背景图不受padding值得影响；

### 2、边界：margi

> 在边框外边的空白区域，被称为边界。

作用：用来调整并列元素间的位置关系；
margin:2px;　　　　　　   定义元素上下左右边界都为2px;
margin:2px 4px;　　　　　   定义元素上下边界分别为2px，左右边界分别为4px;
margin:2px 4px 6px;　　　　定义元素上边界为2px，左右边界分别为4px，下边界为6px;
margin:2px 4px 6px 8px;　　 定义元素上边界为2px，右边界分别为4px，下边界为6px，左边界8px;
margin-top:10px;
margin-right:10px;
margin-bottom:10px;
margin-left:10px;

margin:0 auto； 定义元素上下边界为0，且在浏览器中横向居中；
margin可以写负值
margin-top:-20px;

### 3、边框：border

作用：网页中很多修饰性的线条都是由边框来实现；

边框宽度：border-width：2px;
边框样式：border-style：solid(实线)/ dotted（点）/ dashed（虚线）/ double（双边线）/none(取消边框)；
边框颜色：border-color：#ff0f0f;

缩写(复合式写法)：border:width  style  color;
    例：     border:1px  solid  #ff00ff;

可单独设置一方向边框：
上边框 border-top:width  style  color;
左边框border-left:width  style  color;
右边框border-right:width  style  color;
下边框 border-bottom:width  style  color;

补充：border:none; 取消边框

盒子实际占有宽度区域
宽 =左右margin + 左右border + 左右padding + width

盒子实际占有高度的区域
高 =上下margin + 上下border + 上下padding + height

以上是标准盒模型所占有区域的实际大小。

## 一、文本溢出属性

text-overflow:clip /ellipsis
取值：
clip：不显示省略标记（...），而是简单的裁切。
ellipsis：当对象内文本溢出时显示省略标记（...）

说明：
text-overflow属性仅是注解当文本溢出时是否显示省略标记。并不具备其它的样式属性定义。要实现溢出时产生省略号的效果还须定义：
1.容器宽度；width:value;
2.强制文本在一行内显示 ,   white-space:nowrap
3.溢出内容为隐藏,     overflow:hidden
4.溢出文本显示省略号，text-overflow:ellipsis;

## 二、关于文本溢出

### 1. 溢出属性

overflow :visible/hidden/scroll/auto/inherit
值
描述
visible
默认值。内容不会被修剪，会呈现在元素框之外。
hidden
内容会被修剪，并且其余内容是不可见的。
scroll
内容会被修剪，但是浏览器会显示滚动条以便查看其余的内容。
auto
如果内容被修剪，则浏览器会显示滚动条以便查看其余的内容。
inherit
规定应该从父元素继承 overflow 属性的值。
overflow-x:hidden; 隐藏横向滚动条
overflow-y:hidden; 隐藏纵向滚动条

### 2.空余空间属性 (该属性用来设置如何处理元素内的空白；)

  white-space:normal/pre/nowrap/pre-wrap /pre-line /inherit
normal：默认值，空白会被浏览器忽略，
nowrap:文本不会换行，文本会在同一行上继续，直到遇到标签`<br />`为止
pre：空白会被浏览器保留，其行为方式类似HTML中的pre标签；
pre-wrap：保留空白符序列，但是正常的进行换行；
pre-line:合并空白符序列，但是保留换行符；
inherit：规定应该从父元素继承White-space属性的值；(ie浏览器不支持此属性值)

## position 定位属性，检索对象的定位方式

### 一、语法

position：static （无特殊定位）/absolute（绝对定位）/relative（相对定位）/fixed（固定定位）/sticky：　粘性定位/inherit继承父元素的属性
1、static：默认值，无特殊定位，对象遵循HTML原则；
2、absolute：绝对定位，将对象从文档流中拖出，使用left/right/top/bottom等属性相对其最接近的一个并有定位设置的父元素进行绝对定位；如果不存在这样的父对象，则依
据窗口对象定位，而其层叠通过z-index属性定义；
3、relative ：相对定位，将依据right，top，left，bottom（相对定位）等属性在正常文档流中偏移位置；

### 二、包含块的概念及作用

包含块是绝对定位的基础，包含块就是为决定定位元素提供坐标、偏移和显示范围的参照物，即、确定绝对定位的偏移起点和百分比 长度的参考；
默认状态下，窗口是一个大的包含块，所有绝对定位的元素都是根据窗口来定自己所处的位置和百分比大小显示的，如果我们定义了包含元素为包含元素块以后，对于被包含的绝对定位元素来说，就会根据最接近的具有定位功能的上级包含元素来定位自己的显示位置。
定义元素为包含块：给绝对定位元素的父元素添加声明position：relative；

### 三、定位元素的层叠属性：z-index:auto|number(数值，并且不加单位)

检索或设置对象的层叠顺序
值
描述
auto
默认。堆叠顺序与父元素相等。
number
设置元素的堆叠顺序。
注：number:较大值得对象会覆盖较小值的对象，如两个绝对定位对象的number值一样大时，那么将依据他们在HTML 文档中声明的顺序层叠，此属性仅仅作用于position的值为relative或absolute或fixed的对象上。

### 六、绝对定位和相对定位的区别

1、参照物不同，绝对定位的参照物是包含块，相对定位的参照物是元素本身位置；
2、绝对定位将对象从文档流中拖出，相对定位不破坏正常的文档流顺序；
4、fixed：(固定定位)，相对浏览器的定位，是相对于浏览器窗口的指定坐标进行定位。此元素的位置可通过 "left"、"top"、"right" 以及"bottom" 属性来规定。不论窗口
滚动与否，元素都会留在那个位置。
5、sticky：　粘性定位：设置了sticky的元素，在屏幕范围（viewport）时该元素的位置并不受到定位影响（设置是top、left等属性无效），当该元素的位置将要移出偏移范围
时，定位又会变成fixed，根据设置的left、top等属性成固定位置的效果。
6、inherit：继承父元素的position属性，但需要注意的是IE8以及以前的版本都不支持inherit属性。

### 四、命名锚点链接的应用

定义：是网页制作中超级链接的一种，又叫命名锚记。命名锚记像一个迅速定位器一样是一种页面内的超级链接，运用相当普遍。

作用：在页面内的不同位置进行跳转。

命名锚点链接的应用：
1.给元素定义命名锚记名
语法：<标记 id="命名锚记名"> </标记>

2.命名锚记连接
语法：`<a href="#命名锚记名称"></a>`

### 五、透明属性

opacity:value;    (value的取值范围0-1)
filter:alpha(opacity=value) ; (value的取值范围0-100);兼容IE8及以下浏览器写法：

### 七、Flash和marquee(滚动字幕)

1、插入flash
1）语法：

```html
<object width="value" height="value">
    <embed width="value" height="value" src="flash路径及全称" wmode="transparent">   </embed>
</object>
```

说明：flash源文件格式.fla；
导出影片为.swf；
创建播放器格式为.exe；

2）将flash背景设置为透明
给`<embed>`标记添加属性：wmode="transparent"

3）IE中不显示flash,可做如下操作：
A.下载安装flash player;
B.打开IE浏览器，选择工具菜单--Internet选项----安全----低。

2、滚动字幕的应用：

```html
<marquee behavior（行为）="scroll(滚动)/alternate（晃动）"     direction（方向）="up(从下向上)/down（从上向下）/left（从右向左）/right（从左向右）"    scrollamount（滚动速度）="value"     height="value(上下滚动范围)"   width=""(左右滚动范围)>内容
</marquee>
```

### 八、滚动条

1,Overflow内容溢出时的设置
overflow 水平及垂直方向内容溢出时的设置
overflow-x; 水平方向内容溢出时的设置
overflow-y 垂直方向内容溢出时的设置

以上三个属性设置的值为visible、scroll、hidden、auto
visible 默认值。使用该值时，无论设置的"width"和"height"的值是多少，其中的内容无论是否超出范围都将被强制显示。
hidden 效果与visible相反。任何超出"width"和"height"的内容都会不可见。
scroll 无论内容是否超越范围，都将显示滚动条。
auto 当内容超出范围时，显示滚动条，否则不显示。
应用:
没有水平滚动条:`<div style="overflow-x:hidden">test</div>`
没有垂直滚动条 :`<div style="overflow-y:hidden">test</div>`

没有滚动条 :`<div style="overflow-x:hidden;overflow-y:hidden"` 或
`style="overflow:hidden">test</div>`
自动显示滚动条
`<div style="height:100px;width:100px;overflow:auto;">test</div>`

2,自己定义滚动条的颜色

我们一般默认的滚动条样式如下左图,右图是放大了1600倍的样
子,我们可以看到滚动条有几种言责组合的,我给他们标了7个号,
分别注释在下面的css代码的后面了,注意css的注释代码是放在
两个斜杠内的两个星号之间,如:`/*这里放注释的代码*/`

```css
Body {
scrollbar-arrow-color: #f4ae21; /*三角箭头的颜色*/
scrollbar-face-color: #333; /*立体滚动条的颜色*/
scrollbar-3dlight-color: #666; /*立体滚动条亮边的颜
色*/
scrollbar-highlight-color: #666; /*滚动条空白部分的
颜色*/
scrollbar-shadow-color: #999; /*立体滚动条阴影的颜
色*/
scrollbar-darkshadow-color: #666; /*立体滚动条强阴
影的颜色*/
scrollbar-track-color: #666; /*立体滚动条背景颜色*/
scrollbar-base-color:#f8f8f8; /*滚动条的基本颜色*/
Cursor:url(mouse.cur); /*自定义个性鼠标*/
}
```

以上2项适用与`<body>、<div>、<textarea>、<iframe>`

## 一、图片整合

### 图片整合技术 — css Sprites（ 精灵图 ，雪碧图)

将导航背景图片，按钮背景图片等有规则的合并成为一张背景图，即将多张图片合为一张整图，然后用background-position来实现背景图片的定位技术。

### 图片整合的优势

通过整合图片，减少对服务器的请求次数，从而加快页面加载速度，减小图片体积。

### 3、图片整合原则

1）边切图边整合。
2）定位时避免使用bottom,right等，用具体的数值，为了避免当你的宽度或高度上扩展sprites图时出现位置的错误。
3）将小图标预留足够的空间，因为使用这些图标元素通常会有大量的内容而且可能需要扩展的间距，以至于其它的图片可能会意外出现在本区域内。一般的情况下，会将这些小图标整合到文件的最右侧。
4）单张整合好的sprite图片在100KB以内。
5）按分类整合图片。
6）为了方便计算尺寸，一般情况会将sprites图的坐标计算成整数倍。
7）整合好的图片必须是背景透明的图片png或者gif。

## 浏览器兼容

## 一、为什么会出现浏览器兼容问题

由于各大主流浏览器由不同的厂家开发，所用的核心也不同，架构代及码也很难重和，这就为各种莫名其妙的Bug(代码错误）提供了温床。再加上各大厂商出于自身利益考虑而设置的种种技术壁垒，都让CSS应用起来比想象得要麻烦。浏览器的兼容问题是我们必须去克服的。

## 二、关于浏览器

### 1、主流浏览器

Internet Explorer、 Safari、Mozilla Firefox、 Google  Chrome、Opera、360 苹果浏览器

### 2、最早的图形浏览器 : Mosaic

NCSA Mosaic，或简称Mosaic，是互联网历史上第一个获普遍使用和能够显示图片的网页浏览器。它是由伊利诺伊大学厄巴纳-香槟分校的NCSA组织在1993年所发表，并于1997年1月7日正式终止开发和支持。在当时人气爆发，大受欢迎。Mosaic的出现，算是点燃了后期互联网热潮的火种之一。

Netscape Navigator(网景领航者)（1994-2008）简称NN
1994年12月15日网景浏览器1.0版正式发布，软件名改为网景导航者

后来网景导航者浏览器的开发工作，聘用了许多原有的Mosaic浏览器工程师，但是没有采用Mosaic网页浏览器的任何代码。

传承网景浏览器代码的后裔为Firefox浏览器。

### 3、浏览器大战

第一次世界大战 上个世纪90年代

第二次世界大战 20世纪

这是 Six Revisions 制作的一幅浏览器近20年来的发展简史图，从最早的 WorldWideWeb Browser 到现在最新的 Google Chrome，期间包含了 Mosaic， Netscape， IE， Opera， Mozilla， Safari， Firefox."

s

1991年，WorldWideWeb 浏览器发布

这款由 Web 之父 Tim Berners-Lee 亲手设计的图形化浏览器还包含一个所见即所得 HTML 编辑器，为了避免同 WWW 混淆，这个浏览器后来改名为 Nexus.

1993年，Mosaic 发布

Internet 的流行应该归功于 Mosaic，这款浏览器将 Web 带向了大众。诸如 IE， Firefox 一类的当代浏览器仍然在延用 Mosaic 的图形化操作界面思想。

1994年，Netscape 成立

Marc Andreessen 带领 Mosaic 的程序员成立了 Netscape 公司，并发布了第一款商业浏览器 Netscape Navigator.

1995年，IE 发布，浏览器之战即将爆发

微软针对 Netscape 发布了他们自己的浏览器，IE，第一场浏览器之战爆发。

1996年，Opera 发布

Telenor 是挪威最大的通讯公司，他们推出了 Opera，并在两年后进军移动市场，推出 Opera 的移动版。

1998年，Mozilla 项目成立

Netscape 成立 Mozilla 开源项目，开发下一代浏览器，后来证明，使用原有代码开发新东西是一种负担，接着他们着手从新开发。

1998年，Netscape 浏览器走向开源

随着同 IE 征战的失利，Netscape 市场份额急剧下降，Netscape 决定将自己的浏览器开源以期重整山河。

2002年(+微信关注网络世界)，IE 开始主导浏览器市场

市场份额达到95%，借助同操作系统的捆绑优势，IE 赢得第一场浏览器之战。

2003年，苹果 Safari 浏览器登场

苹果进入了浏览器市场，推出自己的 Webkit 引擎，该引擎非常优秀，后来被包括 Google， Nokia 之类的厂商用于手机浏览器。

2004年，Firefox 引发第二场浏览器之战

Firefox 1.0 推出。早在 Beta 测试期间就积累了大量人气的 Firefox 引发了第二场浏览器之战，当年年底，Firefox 已经赢得 7.4% 的市场份额。

2006年，IE7 发布

IE6 发布后的第六年，迫于 Firefox 的压力，微软匆匆推出 IE7 应战，吸取了 Firefox 的一些设计思想，如标签式浏览，反钓鱼等。但这款浏览器现在看来并不成功。

2008年，Google 携 Chrome 参战

Google 发布了他们自己的浏览器，加入这场战争。轻量，快，异常的稳固让这款浏览器成为不可轻视的一个对手。

### 4、浏览器内核

说到浏览器，当然要从浏览器的内核说起。浏览器最关键的部分就是它的渲染引擎（Rendering Engine），也就是大家平常所说的的“内核”。

## 三、五大浏览器内核

Trident （MSHTML，IE核心） IE浏览器    （三叉戟；三叉线；三齿鱼叉）
Gecko   （壁虎）   火狐
Presto        （ 迅速的）  欧朋
Webkit     （急速）   谷歌 、苹果
Blink （急速）    欧朋、谷歌

### 浏览器内核介绍

1、Trident核心，代表产品Internet Explorer    简称IE
–说起Trident，很多人都会感到陌生，但提起IE（Internet Explorer）则无人不知无人不晓，因为IE捆绑在Windows中，所以得到了极高的市场占有率，所以我们又经常称其为IE核心。 Trident（又称为MSHTML），是NACA MOSAIC基础上开发而来，对Trident核心而言，微软是最大的贡献者。而且除IE外，许多产品都在使用Trident核心，比如Windows的Help程序、RealPlayer、Windows Media Player、Windows Live Messenger、Outlook Express等等都使用了Trident技术。 使用Trident引擎的浏览器有很多，比如Maxthon遨游、Theworld世界之窗、腾讯TT、360浏览器等等，但Trident只能应用于Windows平台，且是不开源的。

2、Gecko核心，代表作品Mozilla Firefox 火狐浏览器
Gecko是一套开放源代码的、是以C++编写的网页排版引擎。 目前为Mozilla家族网页浏览器以及Netscape 6以后版本浏览器所使用。这软件原本是由网景通讯公司开发的，现在则由Mozilla基金会和全世界愿意参与开发的网友共同维护，其中Mozilla对这个排版引擎所做的贡献最大。它的最大优势是跨平台，能在Microsoft Windows、Linux和MacOS X等主要操作系统上运行，而且它提供了一个丰富的程序界面以供互联网相关的应用程式使用，例如网页浏览器、HTML编辑器、客户端/服务器等等。 Gecko是最流行的排版引擎之一，由于Gecko的特点是代码完全公开，因此，其可开发程度很高，全世界的程序员都可以为其编写代码，增加功能。因为这是个开源内核，因此受到许多人的青睐，采用Gecko内核的浏览器也很多，这也是Gecko内核虽然年轻但市场占有率能够迅速提高的重要原因。它的流行度仅次于Trident。使用这个作为内核的浏览器有Firefox、Netscape6至9。

3、WebKit核心，代表作品Safari（苹果）、Chrome（谷歌）
–webkit 是一个开源项目，包含了来自KDE项目和苹果公司的一些组件，主要用于Mac OS系统，它的特点在于源码结构清晰、渲染速度极快。主要代表作品有Safari（苹果系统自带的浏览器）和Google的浏览器Chrome（谷歌浏览器）。

4、Presto核心，代表作品Opera 欧朋浏览器
Presto是由Opera Software开发的浏览器排版引擎，供Opera 7.0及以上使用。它取代了旧版Opera 4至6版本使用的Elektra排版引擎，包括加入动态功能，例如网页或其部分可随着DOM及Script语法的事件而重新排版。 Presto在推出后不断有更新版本推出，使不少错误得以修正，以及阅读Javascript效能得以最佳化，并成为速度最快的引擎，它是世界上公认的渲染速度最快的引擎。 然而代价是牺牲了网页的兼容性。

5、Blink核心，代表作 谷歌 和opera
是由 WebKit 内核衍生出来的，是由 Chromium 和opera开发维护的新项目。

## 五、主流浏览器市场份额

2013年2月份全球主流浏览器市场份额排行榜

2014年11月份全球主流浏览器市场份额排行榜

2015年5月份全球主流浏览器市场份额排行榜

2016年4月份全球主流浏览器市场份额排行榜

至此，Chrome首次超过IE登顶第一。

## 六、兼容（css bug、css hack、filter）

说明：
（1）CSS Bug:CSS样式在各浏览器中解析不一致的情况，或者说CSS样式在浏览器中不能正确显示的问题称为CSS bug.
（2）CSS Hack: CSS中，Hack是指一种兼容CSS在不同浏览器中正确显示的技巧方法，它们都属于个人对CSS代码的非官方的修改，或非官方的补丁， 有些人更喜欢使用patch(补丁)来描述这种行为。
css hack的弊端：会增加一些css代码,从而增加浏览器负担
（3）Filter:表示过滤器的意思，它是一种对特定的浏览器或浏览器组显示或隐藏规则和声明的方法。本质上讲，Filter是一种用来过滤不同浏览器的Hack类型。

### 1、IE6常见CSS解析Bug及hack

#### 1)默认高度（IE6）

描述：在IE6及以下版本中，部分块元素拥有默认高度（在16px左右）；
hack1:给元素添加声明：font-size:0;
hack2：给元素添加声明：overflow:hidden;

#### 2)加了超链接的图片有边框BUG （IE浏览器）

当图片加`<a href=“#”></a>`在IE上会出现边框
Hack:给图片加border:0;或者border:none;

#### 3)图片间隙

div,dt,li等中图片间隙中的图片间隙BUG
描述：在div中插入图片时，图片会将div下方撑大大约三像素。
hack1:将`</div>`与`<img>`写在一行上； ie6
hack2:将`<img>`转为块状元素，给`<img>`添加声明：display:block;
hack3:给图片添加vertical-align:top/middle/bottom.

#### 4) 双倍浮向（双倍边距）（只有IE6出现）

描述：当Ie6及更低版本浏览器在解析浮动元素时，会错误地把浮向边边界（margin）加倍显示。
hack:给浮动元素添加声明：display:inline;

#### 5)表单元素行高对齐不一致

描述：表单元素行高对齐方式不一致
hack:给表单元素添加声明：float:left;
hack2:给input改变垂直对齐方式 ，添加 vertical-align:top/middle/bottom.

#### 6)按钮元素默认大小不一

描述：各浏览器中按钮元素大小不一致
hack1： 统一大小/（用a标记模拟）
hack2:input外边套一个标签，在这个标签里写按钮的样式，把input的边框去掉。
hack3:如果这个按钮是一个图片，直接把图片作为按钮的背景图即可

#### 7)百分比bug

描述：在IE7及以下版本中在解析百分比时，会按四舍五入方式计算从而导致50%加50%大于100%的情况。
（也会受系统影响）
hack: 给右面的浮动元素添加声明：clear:right;           意思：清除右浮动。

#### 8)鼠标指针bug

描述：cursor属性的hand属性值只有IE9以下浏览器识别，其它浏览器不识别该声明，cursor属性的pointer属性值IE6.0以上版本及其它内核浏览器都识别该声明。

hack: 如统一某元素鼠标指针形状为手型，应添加声明：cursor:pointer;
cursor: ;

auto默认
hand 手形
crosshair加号
text文本
wait等待
help帮助
progress过程
inherit继承
move移动
ne-resize向上或向右移动
pointer手形

#### 9)透明属性

兼容其他浏览器写法：opacity:value;(value的取值范围0-1;
例：opacity:0.5;)
IE浏览器写法：filter:alpha(opacity=value);取值范围 0-100(整数)

#### 10）li列表的BUG

1）：当父元素(li) 有float:left;子元素(a) 没设置浮动的情况下会出现垂直bug；
Hack:给父元素li和子元素a都设置浮动；
2）：当给li中的a转成block；并且有height,并有float的时候，li中没设置浮动会出现阶梯显示，
hack：同时给li加float;

#### 11)当li里a、span 分别添加左右浮动时，并且li设置高度后，IE7及以下浏览器会出现 li下方多出3像素左右的空隙

hack：给li添加float：left；和width：100%；

#### 12）当前元素(父元素里面第一个子元素并且是块状元素)与父元素没有设置任何浮动的情况下，设置margin-top后，会错误的把margin-top加在父级元素上

Css hack:
1、给父级元素添加overflow:hidden;(推荐使用)
2、给父元素或者子元素加浮动
3、当父元素有边框时，可以直接给子元素添加margin-top值；

#### 13）margin BUG

当两个上下排列的元素，上元素有margin-bottom：30px；下面元素有margin-top:20px；他们中间的距离不会相加，而是会设置为较大的值；

### 2、过滤器（filter）

#### 1） _下划线属性过滤器

当一个属性前面增加了一个下划线后，由于符合标准的浏览器不能识别带有下划线的属性而忽略了这个声明，但是在IE6及以下版本浏览器中会继续解析这个规则；
语法：选择器{ _ 属性：属性值；}

#### 2）"*","+"过滤器

a:过滤ie7及以下浏览器
语法：选择器{ *属性：属性值；}

扩展：
IE8浏览器的 兼容符号\0 ，用这个符号来进行HACK技术
语法：选择器{ 属性:属性值  \0;}
\9 兼容IE8及以下浏览器
语法：选择器{ 属性：属性值   \ 9；}

## 综合布局实例

## 一、自适应

网页布局中经常要定义元素的宽和高。但很多时候我们希望元素的大小能够根据窗口或父元素自动调整，这就是自适应。元素自适应在网页布局中非常重要
，它能够使网页显示更灵活，可以适应在不同设备、不同窗口和不同分辨率下显示。

## 一）宽度自适应

元素宽度设置为100%。（块元素宽度默认为100%）

## 二）高度自适应

### 1、窗口高度自适应

设置方法：html,body{height:100%;}
自适应元素高度：height:100%;
扩展：
calc() 函数用于动态计算长度值。
CSS 语法：calc(expression)
值                            描述
expression 必须，一个数学表达式，结果将采用运算后的返回值。
注：
● 需要注意的是，运算符前后都需要保留一个空格，例如：width: calc(100% - 10px)；
● 任何长度值都可以使用calc()函数进行计算；
● calc()函数支持 "+", "-", "*", "/" 运算；
● calc()函数使用标准的数学运算优先级规则；

### 2、元素高度自适应

#### 1）非浮动元素的父元素,高度的自适应

hack1:      height:auto; 或不写height属性；
hack2:      min-height:value;_height:value;              _下划线过滤器只有IE6识别
hack3:      min-height:200px; height:auto !important; height:200px
！important; 关键字过滤器
他表示所附加的声明具有最高优先级的意思，但由于IE6及更低版本不能识别他，我们可以利用IE6 这个bug作为过滤器来兼容IE6和其他标准浏览器；
语法：选择符{属性:属性值  !important；}
注：同时设两个高度，优先级声明的属性要放到前面。

min-height（最小高度）
max-height(最大高度)
min-width(最小宽度)
max-width(最大宽度)
IE6不支持该组属性；

#### 2）浮动元素的父元素高度自适应（高度塌陷）

hack1：隐藏法    给父元素添加声明overflow:hidden;
hack2:  在浮动元素下方添加空div,并给该元素添加声明：clear:both;height:0;overflow:hidden;
hack3:万能清除浮动法
给浮动元素的父元素清除浮动；
:after{content:".";clear:both;display:block;height:0;overflow:hidden;visibility:hidden;}
zoom:1; 主要用来清除ie6、7的浮动问题，他是属于ie的属性，另外还有缩放的功能

伪元素选择符：
1、:after            与content:"";属性一起使用，定义在对象内后面的内容。
2、:before         与content属性一起使用，定义在对象内前面的内容
                          {content:url(图片路径);}
3、:first-line     定义对象内第一行的样式。
4、:first-letter  定义对象内第一个字符的样式。
说明：（伪元素选择符只能用于块元素有效，IE6不支持）

.box::selection{}
匹配E元素中被用户选中或处于高亮状态的部分,（鼠标划过高亮状态）

检索对象是否显示
visibility:hidden/visible和display:none ;
共同点：都是可以设置元素显示或者隐藏的属性；
区别：display:none ;在隐藏元素的同时，元素的位置也一起隐藏，而visibility:hidden；在隐藏元素的同时，原来所在的位置依然是保留的。

## 一、表单补充

### 1、button按钮（不进行提交）

```html
<input type="button" value="按钮内容" />
<button type="reset"> </button>
```

### 2、单选框(单选按钮)

`<input type="radio" name="ral" />`

### 3、复选框

`<input type="checkbox" />`
checked="checked";   默认选中
disabled="disabled" ；禁用
enabled=“enabled” ；可用

### 4、多行文本框（文本域）

`<textarea  cols="字符宽度"  rows="行数" ></textarea>`
阻止浏览器对窗口的拖动设置:{resize:none;}（css属性）

### 5、列表和菜单

```html
下拉菜单
<select >
    <option>选项1</option>
    <option>选项2</option>
   ......
</select>
```

注：`<select size="数值"></select>` (有size 属性的是列表)

### 6、上传文件框

文件域：`<input type="file" />`

### 7、隐藏表单，一般用作数据存储

文件域：`<input type="hidden" value="订单编号" />` 这是隐藏表单,一般用来传递参数,而又不想显示在客户端。

### 8、图像域

语法:
`<input type="image" src="目标图片路径" width="" height=""   />`

注：上面所有的都称为表单元素，表单元素要写在表单域里。

## 二、表单高级

表单的组成：表单域，表单元素(表单控件)，提示信息
表单域`<form name="" method="" action=""></form>`
表单元素`<input type="" value=""/>`
提示信息   如： 用户名     密码

### 1、提示信息标签

`<label></label>`
功能：label元素用来定义标签，为页面上的其他元素指定提示信息。要将label元素绑定到其他的控件上，可以将label元素的for属性设置为与该控件的id属性值相同。

### 2、表单字段集

`<fieldset></fieldset>`
功能：相当于一个方框，在字段集中可以包含文本和其他元素。该元素用于对表单中的元素进行分组并在文档中区别标出文本。fieldset元素可以嵌套，在其内部可以在
设置多个fieldset对象。

### 3、字段级标题

`<legend></legend>`
功能：legend元素可以在fieldset对象绘制的方框内插入一个标题。legend元素必须是fieldset内的第一个元素。

## 三、表格高级

作用:显示数据

```html
<table>
<tr>
<td></td>
</tr>  
</table>
```

（一）关于表格的CSS属性

### 1、单元格间距(该属性必须给table添加)

border-spacing:value;

### 2、合并相邻单元格边框

border-collapse:separate(边框分开)/collapse(边框合并)

### 3、无内容单元格显示、隐藏

empty-cells:show(显示)/hide（隐藏）;

### 4、表格布局算法(加快运行的速度,但不够灵活)

table-layout:auto/fixed(固定宽度，不会随内容多少改变单元格宽度)
说明：
自动表格布局：列的宽度是由列单元格中没有折行的最宽的内容设定的。
缺点：较慢（因为它需要在确定最终的布局前访问表格中的所有内容）。
优点：灵活

固定表格布局
优点：加快运行的速度,允许浏览器更快的对表格进行布局。
缺点:   不太灵活

### 5、表格标题

`<caption>标题内容</caption>`
表格标题位置：caption-side:top/right/bottom/left
说明：left,right,top,bottom位置只有火狐识别，top,bottom IE7以上版本支持，ie7及以下版本不支持其它属性值，只识别top;

### 6、表格布局元素

表格基本组成
table（表格）      tr（行）      td（列）
th 表格列标题（放在tr里）

html里table的重要属性：
1） colspan="value"    合并列   横向合并
2） rowspan="value"   和并行  纵向合并
3） valign="top/bottom/middle" 垂直对齐方式
align="left /center /right"
４） rules="rows/cols/all/none/groups"    添加分隔线
说明：
rows:位于行之间的线条
cols:位于列之间的线条
all：位于行和列之间的线条
none:没有线条
groups:位于行组和列组之间的线条

### 2、数据行分组

```html
<thead></thead>      表头
<tbody></tbody>      表体
<tfoot></tfoot>         表尾
```

说明：一个Table中，只能包含一个thead,一个tfoot,但可包含多个tbody。

### 3、数据列分组

`<colgroup span="value"></colgroup>`

说明：
1）colgroup元素会根据从左到右的顺序依次对数据表格进行列分组。
2）span属性显示指定相邻几列组成一组，span属性值默认为1，默认时仅定义一列为一组。
3）可以通过给table添加rules="groups"属性来给分组列添加组分割线。

## 4、CSS结构伪类选择器:nth-child()

tr:nth-child(n) 选择器匹配属于其父元素的第 N 个子元素，不论元素的类型。
tr:nth-child(2n-1){ }
odd     奇数
even   偶数

例：

```css
<style>
tr:nth-child(odd){background:#00ff00;}  奇数
p:nth-child(even){background:#0000ff;} 偶数
</style>
```

min-content/max-content
  