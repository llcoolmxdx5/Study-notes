# html.md

## 基本概念

### 浏览器

浏览器内核：

- blink chrome

- trident IE内核

- webkit safari

- gecko 火狐

### web标准

网页由结构、表现、行为组成

分离的优点：易维护、响应快、可访问性、设备兼容性、易于seo

## 标签

### 基础标签

- 基础

  ```html
  <!DOCTYPE html>
  <title>
  <h1> <h6>
  <p>
  <hr>
  <br>
  <!-- ... -->
  ```

- 图像

  ```html
  <img src="" alt="" title="">
  ```

- 格式

  ```html
  <em>
  <small>
  <b>
  ```

- 链接

  ```html
  <a href="javascript:void(0)" target="_blank/_self" download="下载的目标资源">百度一下</a>
  ```

- 列表

  ```html
  <ul type="square/disc/cicle"><li></li><ul>
  <ol type="1"><li></li><ol>
  <dl>
    <dt></dt>
    <dd></dd>
  </dl>
  ```

- 表单

  ```html
  <form action="">
  <input type="text/email/range/phone/number/password/submit/checkbox/date/color/file/radio" value="" placehold="">
  <textarea rows="" cols=""></textarea>
  <select>
    <option value=""></option>
  </select>
  <label></label>
  ```

- 样式/节

  ```html
  <style></style>
  <div></div>
  <span></span>
  ```

- 其他

  ```html
  <link href="/favicon.ico" rel="shortcut icon" type="image/x-icon">
  ```

- 表格

- html5新增标签

  ```html
  <header>
  <aside>
  <article>
  <section>
  <nav>
  <footer>
  <video width="320" height="240" controls="controls">
    <source src="movie.mp4" type="video/mp4" />
    <source src="movie.ogg" type="video/ogg" />
    <source src="movie.webm" type="video/webm" />
    <object data="movie.mp4" width="320" height="240">
      <embed src="movie.swf" width="320" height="240" />
    </object>
  </video>
  <audio controls="controls">
    <source src="song.mp3" type="audio/mp3" />
    <source src="song.ogg" type="audio/ogg" />
    <embed height="100" width="100" src="song.mp3" />
    Your browser does not support this audio format.
  </audio>
  <canvas>
  ```

- meta

  ```html
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <meta http-equiv="X-UA-Compatible" content="ie=edge,chrome=1">
  <meta name="keywords" content="">
  <meta name="description" content="">
  <meta name="renderer" content="webkit">
  ```
