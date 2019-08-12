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
