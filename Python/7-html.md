# 1.超链接

`<a href="" target="_blank"></a>`

# 2.插入图片

`<img src="" alt="">`

# 3.特殊文本

```html
<b>加粗</b><i>斜体</i><u>下划线</u>
<s>删除线</s><sup>上标</sup><sub>下标</sub>
&nbsp;&lr;&gt;&yen;&copy;
```

# 4.列表

```html
<ol type="1/A/a/I/i" start="">有序列表</ol>
<ul type="disc/circle/square/none">无序列表</ul>
```

# 5.表格

```html
<table border="" cellpadding="" cellspacing=""></table>
<tr></tr><td colspan="" rowspan=""></td>
<thead></thead><tbody></tbody><tfoot></tfoot>
```

# 6.表单

都是行内块元素

```html
<form action="" method="post"></form>

<textarea cols="30" rows="10"></textarea><!-- 多行文本域 -->

<button type="submit/reset/buttonb"></button><!-- 按钮 -->

<select>
  <option value=""></option><!-- 下拉选择框 -->
</select>

<input type="text" maxlength="" placeholder="" required><!-- 1.文本输入框 -->

10<input type="range" min="10" max="100">100<!-- 2.范围 -->

<input type="search"><!-- 3.搜索 -->

<input type="number" max="" min="" step=""><!-- 4.数字 -->

<input type="tel"><!-- 5.手机号 -->

<input type="email"><!-- 6.邮箱 -->

<input type="color"><!-- 7.颜色 -->

<input type="date"><!-- 8.日期 -->

<input type="datetime-local"><!-- 9.时间日期 -->

<input type="file" multiple><!-- 10.文件选择 -->

<input type="hidden"><!-- 11.隐藏域 -->

<input type="radio" checked=""><!-- 12.单选框 -->

<input type="checkbox"><!-- 13.复选框 -->

<input type="button" type="submit/reset/button"><!-- 14.按钮 -->
```

# 7.行内元素 与 块元素

## 1.块元素

只要在网页中能独占一行/一块的元素都称为块级元素，简称为块元素
p,h1,h2,h3,h4,h5,h6,div
作用：都可以做布局
所有的块元素都会具备align属性

## 2.行内元素

多个元素能够在一行内显示的，就是行内元素
span,i,b,s,u,sub,sup
作用：处理文本的样式
