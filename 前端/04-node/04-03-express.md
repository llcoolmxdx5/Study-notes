# express

> Express是一个路由和中间件Web框架，其自身的功能很少：Express应用程序本质上是一系列中间件函数调用

## express生成器

`npm install express-generator -g`
`express --view=ejs --css=sass  myapp`

## 路由

```js
const express = require('express')
const ejs = require('ejs');
let router = express.Router();
//http://localhost:3000/user/getinfo?name=xiaoming&age=20
router.get('/getinfo', function (req, res) {
  res.send(req.query)
  // res.json({ name: 'aaa' }) // 直接发送json
  // res.download('a.txt') // 下载
})
// http://localhost:3000/flights/LAX-SFO
router.get('/flights/:from-:to', function (req, res) {
  res.send({
    from: req.params.from,
    to: req.params.to
  })
})
// 服务端渲染
router.get('/info', function (req, res) {
  let html = ejs.render(
    `<% if (user) { %>
    <h2><%= user.name %></h2>
  <% } %>`, { user: { name: 'xiaoming' } })
  res.send(html);
})
// 重定向
// res.redirect([status,] path)
// res.redirect(301, 'http://example.com');
app.route('/book')
  .get(function (req, res) {
    res.send('Get a random book')
  })
  .post(function (req, res) {
    res.send('Add a book')
  })
  .put(function (req, res) {
    res.send('Update the book')
  })
module.exports = router;
```

## 静态文件

```js
app.use(express.static('public'))
// http://localhost:3000/js/app.js
app.use('/static', express.static(path.join(__dirname, 'public')))
// http://localhost:3000/static/js/app.js
```

## 中间件
