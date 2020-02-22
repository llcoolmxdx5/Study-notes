# js

## 手写深克隆

```js
const clone = (source, target={}) => {
  let names = Object.getOwnPropertyNames(source)
  for (let i = 0; i < names.length; i++) {
    let desc = Object.getOwnPropertyDescriptor(source, names[i])
    if (typeof desc.value === 'object' && desc.value !== null) {
      let objs
      if (desc.value.constrctor === Date) {
        objs = new desc.value.constrctor(desc.value)
      } else if (desc.value.constrctor === RegExp) {
        objs = new desc.value.constrctor(desc.value, desc.value.flags) 
      } else {
        objs = new desc.value.constrctor()
      }
      Object.defineProperties(target, names[i], {
        configurable: desc.configurable,
        enumerable: desc.enumerable,
        writable: desc.writable,
        value: objs
      })
      clone(desc.value, objs)
    } else {
      Object.defineProperties(target, names[i], desc)
    }
  }
  return target
}
```

## call apply bind的区别

1. 第一个参数都是指定函数内部中this的指向（函数执行时所在的作用域），然后根据指定的作用域，调用该函数。
2. call和apply方法都是在调用之后立即执行的。而bind调用之后是返回原函数，需要再调用一次才行，
3. 都可以在函数调用时传递参数。call，bind方法需要直接传入，而apply方法需要以数组的形式传入。

```js
函数.call(对象,arg1,arg2....)
函数.apply(对象，[arg1,arg2,...])
var ss=函数.bind(对象,arg1,arg2,....)
```

## 手写bind

```js
Function.prototype.bind1 = function (content) {
  let args = [...arguments].slice(1)
  let resFn = () => this.apply(this instanceof resFn ? this : content, args.concat(...arguments))
  function tmp() { } // 此处不能用箭头函数
  tmp.prototype = this.prototype
  resFn.prototype = new tmp()
  return resFn
}
```

## 
