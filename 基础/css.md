# css.md

## 标签间关系

- 祖先

- 兄弟

- 父亲

- 子孙

## 选择器

- 通用选择器

  ```css
  * {
    margin: 0;
  }
  ```

- 元素选择器

  ```css
  p {
    margin: 0;
  }
  ```

- id选择器

  ```css
  #id {
    margin: 0;
  }
  ```

- 类选择器

  ```css
  .test-class {
    margin: 0;
  }
  ```

- 复合选择器

  ```css
  div.test {
    margin: 0;
  }
  ```

- 群组选择器

  ```css
  div, .test {
    margin: 0;
  }
  ```

- 后代选择器

  ```css
  div div.test span {
    margin: 0;
  }
  ```

- 子代选择器

  ```css
  div > div.test {
    margin: 0;
  }
  ```

- 伪类伪元素选择器

  ```css
  /* 伪类
  :active 向被激活的元素添加样式。
  :focus 向拥有键盘输入焦点的元素添加样式。
  :hover 当鼠标悬浮在元素上方时，向元素添加样式。
  :link 向未被访问的链接添加样式。
  :visited 向已被访问的链接添加样式。
  :first-child 向元素的第一个子元素添加样式。
  :lang 向带有指定 lang 属性的元素添加样式。
  */
  a:active {
    color: blue;
  }
  div:not(.text) {
    color: blue;
  }
  /* 伪元素 在css3中是::
  :first-letter 向文本的第一个字母添加特殊样式。
  :first-line 向文本的首行添加特殊样式。
  :before 在元素之前添加内容。
  :after 在元素之后添加内容。
  */
  h1::after {
    content: url(logo.gif);
  }
  ```

- 兄弟选择器

  ```css
  div + span {
    margin: 0;
    /* 后面一个兄弟元素 */
  }
  div ~ span {
    margin: 0;
    /* 后面所有兄弟元素 */
  }
  ```

- 属性选择器

  ```css
  /*
  [attribute] 用于选取带有指定属性的元素。
  [attribute=value] 用于选取带有指定属性和值的元素。
  [attribute~=value] 用于选取属性值中包含指定词汇的元素。
  [attribute|=value] 用于选取带有以指定值开头的属性值的元素，该值必须是整个单词。
  [attribute^=value] 匹配属性值以指定值开头的每个元素。
  [attribute$=value] 匹配属性值以指定值结尾的每个元素。
  [attribute*=value] 匹配属性值中包含指定值的每个元素。
  */
  input[text] {
    color: red;
  }
  ```

- 选择器优先级

  !important 1000 > 内联 > id 100 > 类/伪类/伪元素/属性10 > * 0 > 继承

## 标签元素划分

- 块级block

  ul/li/form/h1-h6/hr/p/div

- 行内块inline-block

  input/select/textarea/button

- 行内inline

  a/big/br/em/img/label/span/i
