# 1.使用

```html
<标记 style="样式声明">
<style></style>
<link rel="stylesheet" href="">
```

# 2.选择器

元素选择器 div
类选择器 .
id选择器 #
群组选择器 逗号隔开
后代选择器 空格隔开
子代选择器 >连接
伪类选择器
  1.链接伪类
    :link
    :visited
  2.动态伪类
    :hover
    :active
    :focus

# 3.尺寸

width
height
overflow:visible/hidden/scroll/auto

# 4.边框

```css
border:width style color
style:solid dashed dotted
color:transparent
border:none
outline:none;
border-radius
box-shadow:h-shadow v-shadow blur spread color;
          水平偏移 垂直偏移 阴影模糊大小 阴影大小 颜色
margin
padding
box-sizing:content-box内容区域/border-box总区域
border-collapse:separate/collapse
border-spacing
```

# 5.背景

```css
background:color url() repeat position;
background-color
background-image:url()
background-repeat:no-repeat
background-position:x y
background-size:width height
```

# 6.文本

```css
color
text-align
text-decoration:none/underline/overline/line-through
line-height
font-style:normal/italic
font-weight:normal/bold/数字
font-size
font-family:"microsoft yahei",Arial,Helvetica;
font:style weight size family必须写family
```

# 7.过度

```css
transition:property duration timing-function delay
transition-property:all
transition-duration
transition-timing-function:ease/linear/ease-in/ease-out
transition-delay
```

# 8.定位

1.普通流定位(默认定位方式)/文档流定位
2.浮动定位
3.相对定位
  元素会相对于它原来的位置偏移某个距离
4.绝对定位
  1.绝对定位的元素会脱离文档流-不占据页面空间
  2.绝对定位的元素会相对于离它最近的，已定位的，祖先元素去实现位置的初始化
  3.如果元素没有最近的，已定位的祖先元素的话，那么则相对于body去实现位置的初始化
5.固定定位
float:none/left/right
clear:none/left/right/both
position:static/relative/absolute/fixed
  top:以元素的上边为基准边移动元素
  left:
  right:
  bottom:
z-index:数字

# 9.显示

```css
display:none/block/inline/inline-block
visibility:visible/hidden
opacity:0(完全透明)~1(完全不透明)
vertical-align:top/middle/bottom/baseline
```

# 10.光标

cursor:
  1.default
  2.pointer ：小手
  3.text ：I
  4.crosshair ：+
  5.wait ：等待
  6.help ：帮助

# 11.列表

list-style-type:none/disc/circle/square
list-style:none

# 12.转换

```css
transform:none/转换函数(多个用空格隔开)
transform-origin:2个值
transform:translate(x/y/x,y)
transform:scale(x/y/value)
transform:rotate(ndeg)
```

# 13.万能清理浮动

```css
.clear{
  clear:both;
  *zoom:1;注:解决ie兼容性问题
}
.clear:after{
  clear:both;
  height:0;
  content:'';内容
  visibility:hidden;
  display:block;
}
```