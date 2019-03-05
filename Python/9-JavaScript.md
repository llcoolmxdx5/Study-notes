# 1.基础语法

## 1.引入
`<script src="JS文件路径"></script>`

## 2.声明变量并赋值

var 变量名=值;
const 常量名=值;

## 3.基本数据类型(原始类型)

number类型
string类型
boolean类型
undefined类型
使用typeof()或typeof查看变量的数据类型
变量.toString();将任意类型的数据转换为字符串
parseInt(数据);将任意类型的数据转换成整数
parseFloat(数据);允许转换为小数
Number(数据);将任意类型数据转换为数字 不能全转化为数字则NaN

## 4.运算符

```js
+，-，*，/，%，++，--
>,<,>=,<=,==,!=,===,!==
!.&&,||
```

& 与1做按位与操作，结果为1是奇数，结果为0是偶数
| 任意小数与0做按位或操作，快速取整
^ 在不借助第三方变量的前提下，交换两个数字的位置 a = a ^ b;b = b ^ a;a = a ^ b;
条件表达式 ? 表达式1 : 表达式2;

## 5.流程控制结构

顺序结构
分支结构(选择结构)
  if(){}else if(){}else{} 不打大括号的话if语句,只控制接下来的第一句话
  switch(变量){
      case 值1:语句块1; break; //可选，跳出switch结构
      case 值2:语句块2; break; //可选，同上
      ... ...
      default:语句块n;所有的case都未匹配上时，才执行default
循环结构
  while(条件){循环操作}
  do{循环操作}while(条件);
  for(表达式1;表达式2;表达式3){循环操作}

## 6.函数

function 函数名(参数列表){函数体[return ]}
window.onload = function(){... ...}

## 7.数组

var 数组名 = new Array();var 数组名 = [];
names[i] = 数据;设置数组的值
数组名.length
数组名.join(seperator)返回一个由seperator连接的数组的元素的字符串
数组名.reverse()
数组名.sort(排序函数)排序函数返回true则交换
push()向数组尾部添加新元素，并返回新数组的长度
pop()出栈，删除并返回数组尾部的元素
unshift()向数组头部添加新元素并返回新数组的长度
shift()删除并返回数组头部的元素
二维数组

## 8.字符串 - string

var str3 = new String("字符串3");var str2 = String("字符串2");
length 属性
toUpperCase()返回字符串的完全大写形式
toLowerCase()返回字符串的完全小写形式
charAt(index)获取指定位置的字符
charCodeAt(index)获取指定位置字符的Unicode码
indexOf(value,fromIndex)子字符串第一次出现的下标，查不到则返回 -1
lastIndexOf(value,fromIndex)该函数的查找方式是从后向前找
substring(start,end)返回字符串从start到end-1
split(seperator)返回拆分后的数组
/正则格式/修饰符(i:忽略大小写/g:全局匹配/m:允许多行匹配)
replace(substr/regexp,replacement)
match(substr/regexp)返回满足格式的子字符串(数组)

# 2.对象

## 1.内置对象 - ES定义

### 1.RegExp 对象

创建对象:var regExp = /匹配模式/修饰符;
方法:test(string)

### 2.Math 对象

属性:Math.PI/Math.E
方法:
  三角函数:Math.cos()/Math.tan()/Math.sin()
  计算函数:Math.log(x)/Math.sqrt(x)/Math.pow(x,y)
  数值函数:Math.max(a,b,c,d)/Math.round(x)/Math.random()/Math.abs(x)

### 3.Date 对象

1.创建对象
  var date = new Date();获取当前日期时间
  var date = new Date("2018/04/20 17:25:35");初始化自定义日期时间对象
2.方法
  getYear()自1900年以来，到当前日期对象所经过的年
  getFullYear()当前时间对象的年份
  getMonth()返回0-11的数字来表示1-12月
  getDate()返回当前时间日期对象的日
  getDay()返回当前时间日期对象是星期 返回 0-6 表示 星期日 - 星期六
  getHours() : 获取小时
  getMinutes() : 获取分钟
  getSeconds() : 获取秒
  getMilliseconds() : 获取毫秒
  toLocaleString()转换成本地时间字符串
  toLocaleTimeString()转换成本地时间字符串(时分秒)
  toLocaleDateString()转换成本地日期字符串(年月日)

## 2.外部对象window(BOM)/document(DOM)

1.BOM：Browser Object Model浏览器对象模型
2.DOM：Document Object Model文档对象模型

## 3.自定义对象 - function

## 4.对象：包含属性 和 方法(函数)

# 3.外部对象window(BOM)

window对象

## 1.对话框

1.警告框
  window.alert() / alert()
2.输入框
  window.prompt() / prompt()
3.确认框
  window.confirm("") / confirm("")
  点击"确定"按钮的话，返回 true
  其余的操作，一律都返回false

## 2.定时器

1.声明定时器
  var ret = setInterval(fun,time)
2.清除定时器
  clearInterval(timer);
3.一次性定时器
  var ret = setTimeout(fun,time);

## 3.属性

1.screen 属性
  属性:width / height/availWidth / availHeight
2.history 属性
  属性:length 访问过的URL的数量
  方法:back()后退/forward():前进/go(num)
3.location
  属性：href 为href设置值的话，相当于实现了浏览器跳转的功能
4.navigator
  属性:userAgent 显示浏览器的相关信息

# 4.外部对象document(DOM)

## DOM中节点的类型：

1.元素节点 - 表示网页中的一个元素
2.属性节点 - 表示元素中的一个属性
3.文本节点 - 表示元素中的文本内容
4.注释节点 - 表示网页中的一个注释
5.文档节点 - 表示整个HTML文档

## 1.查找所有节点的信息

1.根据ID查询
  var elem=document.getElementById("元素ID");
2.根据层级节点查询
  1.parentNode 属性
    根据当前节点的层级结构，返回元素的父元素节点
  2.childNodes
    根据当前节点的层级结构，返回当前元素的所有子元素数组
  3.children
    根据当前节点的层级结构，返回当前元素的所有子元素数组(元素节点)
  4.nextSibling
    获取当前节点的下一个兄弟节点
  5.nextElementSibling
    获取当前节点的下一个元素兄弟节点
  6.previousSibling
    获取当前节点的上一个兄弟节点
  7.previousElementSibling
    获取当前节点的上一个元素兄弟节点
3.通过标签名进行查询
  document|elem.getElementsByTagName("标签名")
  返回包含指定标签元素们的数组
4.通过元素的name属性进行查询
  document.getElementsByName("name属性值");
  返回值：包含指定name属性值的元素的数组
5.通过元素的class值进行查询
  document|elem.getElementsByClassName("class")
  返回包含指定class属性值的所有元素

## 2.读取节点的信息

1.节点的类型
  属性：nodeType
  值：
    返回1 ：元素节点
    返回2 ：属性节点
    返回3 ：文本节点
    返回8 ：注释节点
    返回9 ：文档节点
2.节点名称
  属性：nodeName
  元素节点 或 属性节点 ：返回标签名 或 属性名
  文本节点 ：返回 #text
  文档节点 ：返回 #document
  注释节点 ：返回 #comment

## 3.修改节点的信息

获取 或 设置 元素节点的 属性值
  getAttribute(attrName)
  setAttribute(attrName,attrValue)
  removeAttribute(attrName)
元素节点的样式(css)
  elem.setAttribute("class","类选择器名称");
  elem.className = "类选择器名称";
  elem.style.css属性名 = 值;

## 4.删除节点

1.删除body中的子元素
  document.body.removeChild(elem);
2.删除其他元素的子元素
  parentNode.removeChild(elem);

## 5.创建节点

1.创建元素节点
  var elem=document.createElement("元素名");
2.增加节点
  1.document.body.appendChild(elem)
  2.parentNode.appendChild(elem)
  3.parentNode.insertBefore(newElem,oldElem)

## 6. DOM对象属性

1.innerHTML
  修改(获取)或设置当前DOM对象的HTML文本
2.innerText
  修改(获取)或
  设置当前DOM对象的普通文本
3.value
  该属性只针对表单控件，允许获取或设置表单控件的值

# 5.事件

所有的事件在绑定时，必须加 on

## 1.触发事件的行为

1.鼠标事件
  click ：鼠标单击事件
  mouseover ：鼠标移入进元素时的事件
  mouseout ：鼠标移出元素时的事件
  mousemove ：鼠标在元素内移动时的事件
2.键盘事件
  keydown ：键位按下时的事件
  keypress ：键位按下时的事件
  keyup ：键位抬起时的事件
3.状态改变事件
  load ：元素加载完成时的事件(body,img)
  change ：元素发生改变时的事件(select)
  focus ：元素获取焦点时的事件
  blur ：元素失去焦点时的事件
  submit ：表单被提交时的事件

## 2.绑定事件的方式

1、在元素中绑定事件
  `<ANY onclick="">`
2.在js中动态的为元素绑定事件
  对象.on事件名=function(){事件操作}

## 3.事件行为

1.load事件
  所有内容都加载完成之后再执行的操作
2.submit事件
  在表单被提交的时候才起到作用
  返回为true，可以提交表单，返回为false则阻止表单提交

## 4.事件对象(event对象)

1.获取 event 对象
  <ANY on事件名="btn(event)">
  function btn(event){event 表示的就是事件对象}
2.通过 event.target 获取事件源 得到一个 DOM对象
3.鼠标事件(事件对象常用属性)
  鼠标事件：
    click,mouseover,mousemove,mouseout
  1.offsetX，offsetY
    获取鼠标在 元素上 的坐标点
    以元素的左上角为(0,0)
  2.clientX，clientY
    获取鼠标在 网页上 的坐标点
  3.screenX，screenY
    获取鼠标在 显示器上 的坐标点
4.键盘事件(事件对象常用属性)
  键盘事件：
    keypress,keydown,keyup
    1.keypress  
      1.which
        当前按下的字符的 ASCII 码
      2.key
        当前按下的字符
    2.keydown
      1.which
        当前按下的键位的键位码
        大小写键位是同一键位：键位码相同

## 5.事件冒泡

  父子/具备层级结构的事件设置了相同事件时,子事件激发,会导致父事件也执行
  阻止事件冒泡
    让事件只在当前元素中执行，不向上冒泡
    event.stopPropagation()

# 6.jQuery

## 1.先导入jqury库

`<script src="jquery-1.11.3.js"></script>`

## 2.DOM对象 和 jQuery对象之间的转换

1.将DOM对象转换为jQuery对象
  var $变量 = $(DOM对象);
2.将jQuery对象转换成DOM对象
  1.var dom对象 = jQuery对象.get(0);
  2.var dom对象 = jQuery对象[0];

## 3.jQuery选择器

1.基本选择器
  1.ID选择器
    $("#id")
    返回：页面中指定ID值的元素
  2.类选择器
    $(".className")
    返回：页面中指定className的所有元素
  3.元素选择器
    $("element")
    返回：页面中指定标记的所有元素
  4.群组选择器 / 复合选择器
    $("selector1,selector2,...")
    返回：满足函数内所有选择器的元素
2.层级选择器
  1.$("selector1 selector2")
    后代选择器
  2.$("selector1>selector2")
    子代选择器
  3.$("selector1+selector2")
    名称：相邻兄弟选择器
    作用：匹配紧紧跟在selector1后面且满足selector2选择器的元素
  4.$("selector1~selector2")
    名称：通用兄弟选择器
    作用：匹配selector1后面所有满足selector2的元素
3.基本过滤选择器
  过滤选择器通常都会配合着其他的选择器一起使用
  1.:first
    只匹配到第一个元素
  2.:last
    只匹配到最后一个元素
  3.:not(selector)
    将满足selector选择器的元素排除在外
  4.:odd
    匹配 偶数行 元素 (奇数下标)
  5.:even
    匹配 奇数行 元素 (偶数下标)
  6.:eq(index)
    匹配下标等于index的元素
  7.:gt(index)
    匹配下标大于index的元素
  8.:lt(index)
    匹配下标小于index的元素
4.属性过滤选择器
  1.[attribute]
    作用：匹配包含指定属性的元素
  2.[attribute=value]
    作用：匹配attribute属性值为value的所有元素
  3.[attribute!=value]
    作用：匹配attribute属性值不是value的所有元素
  4.[attribute^=value]
    作用：匹配attribute属性值是以value字符作为开始的元素
  5.[attribute$=value]
    作用：匹配attribute属性值是以value字符作为结束的元素
  6.[attribute*=value]
    作用：匹配attribute属性值中包含value字符的所有元素
    ex:
      匹配页面中所有的文本框
      $("input[type='text']")
5.子元素过滤选择器
  1.:first-child
    匹配属于其父元素中的首个子元素
  2.:last-child
    匹配属于其父元素中的最后一个子元素
  3.:nth-child(n)
    匹配属于其父元素中的第n个子元素

## 4.jQuery操作DOM

1.基本操作
  1.html()
  2.text()
  3.val()
  4.attr()
  5.removeAttr("attrName")
2.样式操作
  1.attr("class","className")
  2.addClass("className")
  3.removeClass("className")
  4.removeClass()
  5.toggleClass("className")有则添加,没有则删除
  6.css("属性","值")
  7.css(JSON对象)
3.遍历节点
  1.children() / children(selector)所有子元素，不考虑后代元素
  2.next() / next(selector)下一个兄弟元素
  3.prev() / prev(selector)上一个兄弟元素
  4.siblings() / siblings(selector)所有兄弟元素
  5.find(selector)所有后代元素
  6.parent()对象的父元素
4.创建对象
  $("创建的内容")
5.插入元素
  $obj.append($new)插入obj的最后一个子元素处
  $obj.prepend($new)插入obj的第一个子元素处
  $obj.after($new)将$new作为$obj的下一个兄弟元素插入进来
  $obj.before($new)将$new作为$obj的上一个兄弟元素插入进来
6.事件处理
  1、页面加载后的执行
    $(document).ready(function(){};
    $().ready(function(){};
    $(function(){};
  2.jQuery的事件绑定
    $obj.bind("事件名称",事件处理函数);事件名称不用加on
    $obj.事件名称(function(){});
  3.在绑定事件的时候，允许传递 event 参数来表示事件对象
7.删除节点
  1.$obj.remove()
    删除$obj元素
  2.$obj.remove("selector")
    将满足selector选择器的元素删除出去
  3.$obj.empty()
    清空$obj内的内容
8.动画
  1.基本显示 / 隐藏
    $obj.show() / $obj.show(执行时间);
    $obj.hide() / $obj.hide(执行时间);
  2.滑动式 显示/隐藏
    显示：$obj.slideDown() / $obj.slideDown(执行时间)
    隐藏：$obj.slideUp() / $obj.slideUp(执行时间)
  3.淡入淡出式显示/隐藏
    $obj.fadeIn() / $obj.fadeIn(执行时间) 显示
    $obj.fadeOut() / $obj.fadeOut(执行时间) 隐藏

## 5.jQuery - 插件

# 7.JSON对象

JSON一般也可以表示只有属性没有方法的对象
JSON对象必须使用{}来表示
使用键值对的方式来声明数据(表示属性和值)
