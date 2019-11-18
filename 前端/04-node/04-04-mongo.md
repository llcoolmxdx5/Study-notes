# mongo

> yarn add mongoose

cd /usr/local/opt/mongodb-community@4.0/bin
mongod --dbpath=./data/db
mongo

## 连接

```js
// db.js
const mongoose = require('mongoose');
const DB_URL = 'mongodb://localhost:27017/mongoosesample'; /** * 连接 */
mongoose.connect(DB_URL); /** * 连接成功 */
mongoose.connection.on('connected', function () {
  console.log('Mongoose connection open to ' + DB_URL);
}); /** * 连接正常 */
mongoose.connection.on('error', function (err) {
  console.log('Mongoose connection error: ' + err);
}); /** * 连接断开 */
mongoose.connection.on('disconnected', function () {
  console.log('Mongoose connection disconnected');
});
module.exports = mongoose;
```

## scheme

```js
// user.js
const mongoose = require('./db.js');
let Schema = mongoose.Schema;
let UserSchema = new Schema({
  username: { type: String, index: true }, //用户账号
  userpwd: { type: String }, //密码
  userage: { type: Number }, //年龄
  logindate: { type: Date, default: Date.now } //最近登录时间
});
mongoose.set('useCreateIndex', true);
module.exports = mongoose.model('User',UserSchema); // 表名
```

### Schema Types内置类型

- String
- Number
- Boolean | Bool
- Array
- Buffer
- Date
- ObjectId | Oid
- Mixed

## 数据库操作方法

```js
// test.js
const User = require("./user.js");
// 插入数据
function insert() {
  let user = new User({
    username: 'Tracy McGrady', // 用户账号
    userpwd: 'abcd', // 密码
    userage: 37, // 年龄
    logindate: new Date() // 最近登录时间
  });
  user.save(function (err, res) {
    if (err) {
      console.log("Error:" + err);
    } else {
      console.log("Res:" + res);
    }
  });
}
// 根据用户名更新密码
function update() {
  let wherestr = { 'username': 'Tracy McGrady' };
  let updatestr = { 'userpwd': 'zzzz' };
  User.update(wherestr, updatestr, function (err, res) {
    if (err) {
      console.log("Error:" + err);
    } else {
      console.log("Res:" + res);
    }
  })
}
// 分页
function getByPager() {
  var pageSize = 5; //一页多少条
  var currentPage = 1; //当前第几页
  var sort = { 'logindate': -1 }; //排序（按登录时间倒序）
  var condition = {}; //条件
  var skipnum = (currentPage - 1) * pageSize; //跳过数
  User.find(condition).skip(skipnum).limit(pageSize).sort(sort).exec(function (err, res) {
    if (err) {
      console.log("Error:" + err);
    } else {
      console.log("Res:" + res);
    }
  })
}
// Model.findByIdAndUpdate(id, [update], [options], [callback]) // 根据id找到一条数据并更新
// Model.remove(conditions, [callback]) // 删除
// Model.findByIdAndRemove(id, [options], [callback])
// Model.findOneAndRemove(conditions, [options], [callback])
// Model.find(conditions, [fields], [options], [callback])
// Model.count(conditions, [callback])
// Model.findById(id, [fields], [options], [callback])
// Model.distinct(field, [conditions], [callback])　//去重
// Model.findOne(conditions, [fields], [options], [callback])　 //查找一条记录
// Model.findOneAndRemove(conditions, [options], [callback])　//查找一条记录并删除
// Model.findOneAndUpdate([conditions], [update], [options], [callback])　//查找一条记录并更新
```
