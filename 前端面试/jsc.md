# jsc

## 变量类型

### 1.JS 的数据类型分类

分为基本数据类型和引用数据类型。其中基本数据类型包括undefined、null、Boolean、Number、String、Symbol (ES6新增，表示独一无二的值)，而引用数据类型统称为Object对象，主要包括对象、数组和函数

### 2.数据类型的判断

1. typeof

    typeof返回一个表示数据类型的字符串，返回结果包括：number、boolean、string、symbol、object、undefined、function等7种数据类型，但不能判断null、array等

    ```js
    typeof Symbol ();// symbol 有效
    typeof ''; // string 有效
    typeof 1; // number 有效
    typeof true; // boolean 有效
    typeof undefined; //undefined 有效
    typeof newFunction (); // function 有效
    typeof null; // object 无效
    typeof []; // object 无效
    typeof newDate (); // object 无效
    typeof new RegExp(); //object 无效
    ```

2. instanceof

    instanceof 是用来判断A是否为B的实例，表达式为：A instanceof B，如果A是B的实例，则返回true,否则返回false。instanceof 运算符用来测试一个对象在其原型链中是否存在一个构造函数的 prototype 属性，但它不能检测null 和 undefined

    ```js
    [] instanceof Array; //true
    {} instanceof Object; //报错
    new Date() instanceof Date; //true
    new RegExp() instanceof RegExp; //true
    null instanceof null; //报错
    undefined instanceof undefined; //报错
    ```

3. constructor

    constructor作用和instanceof非常相似。但constructor检测 Object与instanceof不一样，还可以处理基本数据类型的检测。不过函数的 constructor 是不稳定的，这个主要体现在把类的原型进行重写，在重写的过程中很有可能出现把之前的constructor给覆盖了，这样检测出来的结果就是不准确的。

4. Object.prototype.toString.call()

    Object.prototype.toString.call() 是最准确最常用的方式 返回一个字符串

    ```js
    Object.prototype.toString.call(''); // [object String]
    Object.prototype.toString.call(1); // [object Number]
    Object.prototype.toString.call(true); // [object Boolean]
    Object.prototype.toString.call(undefined); // [object Undefined]
    Object.prototype.toString.call(null); // [object Null]
    Object.prototype.toString.call(new Function()); // [object Function]
    Object.prototype.toString.call(new Date()); // [object Date]
    Object.prototype.toString.call([]); // [object Array]
    Object.prototype.toString.call(new RegExp()); // [object RegExp]
    Object.prototype.toString.call(new Error()); // [object Error]
    ```

## 浅拷贝与深拷贝

浅拷贝只复制指向某个对象的指针，而不复制对象本身，新旧对象还是共享同一块内存。

浅拷贝的实现方式（详见`https://github.com/ljianshu/Blog/issues/5`）：

- Object.assign()：需注意的是目标对象只有一层的时候，是深拷贝

- Array.prototype.concat()

- Array.prototype.slice()

深拷贝就是在拷贝数据的时候，将数据的所有引用结构都拷贝一份。简单的说就是，在内存中存在两个数据结构完全相同又相互独立的数据，将引用型类型进行复制，而不是只复制其引用关系。

深拷贝的实现方式：

- 热门的函数库lodash，也有提供_.cloneDeep用来做深拷贝

- jquery 提供一个$.extend可以用来做深拷贝

- JSON.parse(JSON.stringify())

- 手写递归方法

递归实现深拷贝的原理：要拷贝一个数据，我们肯定要去遍历它的属性，如果这个对象的属性仍是对象，继续使用这个方法，如此往复。

```js

```
