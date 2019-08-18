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
  /* 伪类 伪类用于选择DOM树之外的信息，或是不能用简单选择器进行表示的信息。
  :active 向被激活的元素添加样式。
  :focus 向拥有键盘输入焦点的元素添加样式。
  :hover 当鼠标悬浮在元素上方时，向元素添加样式。
  :link 向未被访问的链接添加样式。
  :visited 向已被访问的链接添加样式。
  :first-child 向元素的第一个子元素添加样式。
  :lang 向带有指定 lang 属性的元素添加样式。
  :first-of-type 选择满足是其父元素的第一个某类型子元素的元素。
  :empty 选择满足没有子元素的元素。
  :not(selector) 选择不满足selector的元素。
  */
  a:active {
    color: blue;
  }
  div:not(.text) {
    color: blue;
  }
  /* 伪元素 在css3中是:: 浏览器也支持:这种格式
  伪元素为DOM树没有定义的虚拟元素。不同于其他选择器，它不以元素为最小选择单元，它选择的是元素指定内容。
  伪元素要配合content属性一起使用。
  伪元素不会出现在DOM中，所以不能通过js来操作，仅仅是在 CSS 渲染层加入。
  伪元素的特效通常要使用:hover伪类样式来激活。
  ::first-letter 向文本的第一个字母添加特殊样式。
  ::first-line 向文本的首行添加特殊样式。
  ::before 在元素之前添加内容。
  ::after 在元素之后添加内容。
  ::selection 选择指定元素中被用户选中的内容
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

  !important > 内联(1000) > id(100) > 类/伪类/伪元素/属性10 > *(0) > 继承

## 标签元素划分

- 块级block

  ul/li/form/h1-h6/hr/p/div

- 行内块inline-block

  input/select/textarea/button

- 行内inline

  a/big/br/em/img/label/span/i
