# vue

`https://cdn.staticfile.org/vue/2.6.10/vue.js`

`https://cdn.staticfile.org/vuex/3.1.0/vuex.min.js`

`https://cdn.staticfile.org/vue-router/3.0.2/vue-router.min.js`

`https://cdn.staticfile.org/vue-resource/1.5.1/vue-resource.min.js`

![MVC和MVVM关系图解](./media/01.MVC和MVVM的关系图解.png)

## vue基本指令

### v-cloak

这个指令保持在元素上直到关联实例结束编译。和 CSS 规则如 [v-cloak] { display: none } 一起用时，这个指令可以隐藏未编译的 Mustache 标签直到实例准备完毕。

```html
[v-cloak] {
    display: none;
}
<div v-cloak>
    {{ message }}
</div>
```

### v-text v-html

v-text:更新元素的 textContent。如果要更新部分的 textContent ，需要使用 {{ Mustache }} 插值。

```html
<span v-text="msg"></span>
<!-- 和下面的一样 -->
<span>{{msg}}</span>
```

v-html:更新元素的 innerHTML 。注意：内容按普通 HTML 插入 - 不会作为 Vue 模板进行编译 。如果试图使用 v-html 组合模板，可以重新考虑是否通过使用组件来替代。

在网站上动态渲染任意 HTML 是非常危险的，因为容易导致 XSS 攻击。只在可信内容上使用 v-html，永不用在用户提交的内容上。

`<div v-html="html"></div>`

### v-show

根据表达式之真假值，切换元素的 display CSS 属性。

当条件变化时该指令触发过渡效果。

### v-if else

v-if:根据表达式的值的真假条件渲染元素。在切换时元素及它的数据绑定 / 组件被销毁并重建。如果元素是 `<template>` ，将提出它的内容作为条件块。

当和 v-if 一起使用时，v-for 的优先级比 v-if 更高。

v-else:不需要表达式 为 v-if 或者 v-else-if 添加“else 块”。

v-else-if:表示 v-if 的 “else if 块”。可以链式调用。

>一般来说，v-if 有更高的切换消耗而 v-show 有更高的初始渲染消耗。因此，如果需要频繁切换 v-show 较好，如果在运行时条件不大可能改变 v-if 较好。

### v-for

基于源数据多次渲染元素或模板块。此指令之值，必须使用特定语法 alias in expression ，为当前遍历的元素提供别名

```html
<div v-for="item in items">
  {{ item.text }}
</div>
<!-- 另外也可以为数组索引指定别名 (或者用于对象的键) -->
<div v-for="(item, index) in items"></div>
<div v-for="(val, key) in object"></div>
<div v-for="(val, key, index) in object"></div>
<!-- v-for 默认行为试着不改变整体，而是替换元素。迫使其重新排序的元素，你需要提供一个 key 的特殊属性 -->
<div v-for="item in items" :key="item.id">
  {{ item.text }}
</div>
```

### v-on

- 缩写：@

- 预期：Function | Inline Statement | Object

- 参数：event

- 修饰符：

    .stop - 调用 event.stopPropagation()。

    .prevent - 调用 event.preventDefault()。

    .capture - 添加事件侦听器时使用 capture 模式。

    .self - 只当事件是从侦听器绑定的元素本身触发时才触发回调。

    .{keyCode | keyAlias} - 只当事件是从特定键触发时才触发回调。

    .native - 监听组件根元素的原生事件。

    .once - 只触发一次回调。

    .left - (2.2.0) 只当点击鼠标左键时触发。

    .right - (2.2.0) 只当点击鼠标右键时触发。

    .middle - (2.2.0) 只当点击鼠标中键时触发。

    .passive - (2.3.0) 以 { passive: true } 模式添加侦听器

- 用法:

    绑定事件监听器。事件类型由参数指定。表达式可以是一个方法的名字或一个内联语句，如果没有修饰符也可以省略。

    用在普通元素上时，只能监听原生 DOM 事件。用在自定义元素组件上时，也可以监听子组件触发的自定义事件。

    在监听原生 DOM 事件时，方法以事件为唯一的参数。如果使用内联语句，语句可以访问一个 $event 属性：v-on:click="handle('ok', $event)"。

    从 2.4.0 开始，v-on 同样支持不带参数绑定一个事件/监听器键值对的对象。注意当使用对象语法时，是不支持任何修饰器的。

```html
<button v-on:click="doThis"></button><!-- 方法处理器 -->
<button v-on:[event]="doThis"></button><!-- 动态事件 (2.6.0+) -->
<button v-on:click="doThat('hello', $event)"></button><!-- 内联语句 -->
<button @click="doThis"></button><!-- 缩写 -->
<button @[event]="doThis"></button><!-- 动态事件缩写 (2.6.0+) -->
<button @click.stop="doThis"></button><!-- 停止冒泡 -->
<button @click.prevent="doThis"></button><!-- 阻止默认行为 -->
<form @submit.prevent></form><!-- 阻止默认行为，没有表达式 -->
<button @click.stop.prevent="doThis"></button><!--  串联修饰符 -->
<input @keyup.enter="onEnter"><!-- 键修饰符，键别名 -->
<input @keyup.13="onEnter"><!-- 键修饰符，键代码 -->
<button v-on:click.once="doThis"></button><!-- 点击回调只会触发一次 -->
<button v-on="{ mousedown: doThis, mouseup: doThat }"></button><!-- 对象语法 (2.4.0+) -->
```

在子组件上监听自定义事件 (当子组件触发“my-event”时将调用事件处理器)：

```html
<my-component @my-event="handleThis"></my-component>
<my-component @my-event="handleThis(123, $event)"></my-component><!-- 内联语句 -->
<my-component @click.native="onClick"></my-component><!-- 组件中的原生事件 -->
```

示例:跑马灯

```html
<div id="app">
    <p>{{info}}</p>
    <input type="button" value="开启" @click="go">
    <input type="button" value="停止" @click="stop">
</div>
<script>
    var vm = new Vue({
        el: "#app",
        data: {
            info: "猥琐发育,别浪",
            intervalId: null
        },
        methods: {
            go(){
                if (this.intervalId != null) return;
                this.intervalId = setInterval(()=>{
                    this.info = this.info.substring(1) + this.info.substring(0, 1);
                },500);
            },
            stop(){
                clearInterval(this.intervalId);
                this.intervalId = null;
            }
        }
    });
</script>
```

### v-bind

- 缩写：:

- 预期：any (with argument) | Object (without argument)

- 参数：attrOrProp (optional)

- 修饰符：

    .prop - 被用于绑定 DOM 属性 (property)。(差别在哪里？)

    .camel - (2.1.0+) 将 kebab-case 特性名转换为 camelCase. (从 2.1.0 开始支持)

    .sync (2.3.0+) 语法糖，会扩展成一个更新父组件绑定值的 v-on 侦听器。

- 用法：

    动态地绑定一个或多个特性，或一个组件 prop 到表达式。

    在绑定 class 或 style 特性时，支持其它类型的值，如数组或对象。可以通过下面的教程链接查看详情。

    在绑定 prop 时，prop 必须在子组件中声明。可以用修饰符指定不同的绑定类型。

    没有参数时，可以绑定到一个包含键值对的对象。注意此时 class 和 style 绑定不支持数组和对象。

```html
<img v-bind:src="imageSrc"><!-- 绑定一个属性 -->
<button v-bind:[key]="value"></button><!-- 动态特性名 (2.6.0+) -->
<img :src="imageSrc"><!-- 缩写 -->
<button :[key]="value"></button><!-- 动态特性名缩写 (2.6.0+) -->
<img :src="'/path/to/images/' + fileName"><!-- 内联字符串拼接 -->
<div :class="{ red: isRed }"></div><!-- class 绑定 -->
<div :class="[classA, classB]"></div>
<div :class="[classA, { classB: isB, classC: isC }]">
<div :style="{ fontSize: size + 'px' }"></div><!-- style 绑定 -->
<div :style="[styleObjectA, styleObjectB]"></div>
<div v-bind="{ id: someProp, 'other-attr': otherProp }"></div><!-- 绑定一个有属性的对象 -->
<div v-bind:text-content.prop="text"></div><!-- 通过 prop 修饰符绑定 DOM 属性 -->
<my-component :prop="someThing"></my-component><!-- prop 绑定。“prop”必须在 my-component 中声明。-->
<child-component v-bind="$props"></child-component><!-- 通过 $props 将父组件的 props 一起传给子组件 -->
<svg><a :xlink:special="foo"></a></svg><!-- XLink -->
```

.camel 修饰符允许在使用 DOM 模板时将 v-bind 属性名称驼峰化，例如 SVG 的 viewBox 属性：

`<svg :view-box.camel="viewBox"></svg>`

在使用字符串模板或通过 vue-loader/vueify 编译时，无需使用 .camel。

### v-model

- 预期：随表单控件类型不同而不同。

- 限制：

    `<input>`

    `<select>`

    `<textarea>`

    `components`

- 修饰符：

    .lazy - 取代 input 监听 change 事件

    .number - 输入字符串转为有效的数字

    .trim - 输入首尾空格过滤

- 用法：在表单控件或者组件上创建双向绑定。

> v-bind 只能实现数据的单向绑定，从 M 自动绑定到 V， 无法实现数据的双向绑定
> v-model 指令，可以实现 表单元素和 Model 中数据的双向数据绑定
> v-model 只能运用在 表单元素中

## 自定义指令

> 除了核心功能默认内置的指令 (v-model 和 v-show)，Vue 也允许注册自定义指令。注意，在 Vue2.0 中，代码复用和抽象的主要形式是组件。然而，有的情况下，你仍然需要对普通 DOM 元素进行底层操作，这时候就会用到自定义指令。

```js
// 注册一个全局自定义指令 `v-focus`
Vue.directive('focus', {
  // 当被绑定的元素插入到 DOM 中时……
  inserted: function (el) {
    // 聚焦元素
    el.focus()
  }
})
```

如果想注册局部指令，组件中也接受一个 directives 的选项

```js
directives: {
  focus: {
    // 指令的定义
    inserted: function (el) {
      el.focus()
    }
  }
}
```

可以在模板中任何元素上使用新的 `v-focus` 属性:`<input v-focus>`

## 过滤器

>Vue.js 允许你自定义过滤器，**可被用作一些常见的文本格式化**。过滤器可以用在两个地方：**mustache 插值和 v-bind 表达式**。过滤器应该被添加在 JavaScript 表达式的尾部，由“管道”符指示；

```html
{{ message | capitalize }}<!-- 在双花括号中 -->
<div v-bind:id="rawId | formatId"></div><!-- 在 v-bind 中 -->
```

### 私有过滤器

可以在一个组件的选项中定义本地的过滤器

```js
filters: {// 私有局部过滤器，只能在 当前 VM 对象所控制的 View 区域进行使用
  capitalize: function (value) {
    if (!value) return ''
    value = value.toString()
    return value.charAt(0).toUpperCase() + value.slice(1)
  }
}
```

### 全局过滤器

```js
// 在创建 Vue 实例之前全局定义过滤器
Vue.filter('capitalize', function (value) {
  if (!value) return ''
  value = value.toString()
  return value.charAt(0).toUpperCase() + value.slice(1)
})
new Vue({
  // ...
})
```

注意：当有局部和全局两个名称相同的过滤器时候，会以就近原则进行调用，即：局部过滤器优先于全局过滤器被调用！

### 过滤器的串联

过滤器函数总接收表达式的值 (之前的操作链的结果) 作为第一个参数。在上述例子中，capitalize 过滤器函数将会收到 message 的值作为第一个参数。

```html
{{ message | filterA | filterB }}
```

filterA 被定义为接收单个参数的过滤器函数，表达式 message 的值将作为参数传入到函数中。然后继续调用同样被定义为接收单个参数的过滤器函数 filterB，将 filterA 的结果传递到 filterB 中。

过滤器是 JavaScript 函数，因此可以接收参数：

```html
{{ message | filterA('arg1', arg2) }}
```

filterA 被定义为接收三个参数的过滤器函数。其中 message 的值作为第一个参数，普通字符串 'arg1' 作为第二个参数，表达式 arg2 的值作为第三个参数。

## Vue的生命周期

> 所有的生命周期钩子自动绑定 this 上下文到实例中，因此你可以访问数据，对属性和方法进行运算。这意味着你不能使用箭头函数来定义一个生命周期方法 (例如 created: () => this.fetchTodos())。这是因为箭头函数绑定了父上下文，因此 this 与你期待的 Vue 实例不同，this.fetchTodos 的行为未定义。

- 什么是生命周期：从Vue实例创建、运行、到销毁期间，总是伴随着各种各样的事件，这些事件，统称为生命周期！

- [生命周期钩子](https://cn.vuejs.org/v2/api/#选项-生命周期钩子)：就是生命周期事件的别名而已；

- 生命周期钩子 = 生命周期函数 = 生命周期事件

### 主要的生命周期函数分类

1. 创建期间的生命周期函数：

   - beforeCreate：实例刚在内存中被创建出来，此时，还没有初始化好 data 和 methods 属性

   - created：实例已经在内存中创建OK，此时 data 和 methods 已经创建OK，此时还没有开始 编译模板

   - beforeMount：此时已经完成了模板的编译，但是还没有挂载到页面中

   - mounted：此时，已经将编译好的模板，挂载到了页面指定的容器中显示

2. 运行期间的生命周期函数：

   - beforeUpdate：状态更新之前执行此函数， 此时 data 中的状态值是最新的，但是界面上显示的 数据还是旧的，因为此时还没有开始重新渲染DOM节点

   - updated：实例更新完毕之后调用此函数，此时 data 中的状态值 和 界面上显示的数据，都已经完成了更新，界面已经被重新渲染好了！

3. 销毁期间的生命周期函数：

   - beforeDestroy：实例销毁之前调用。在这一步，实例仍然完全可用。

   - destroyed：Vue 实例销毁后调用。调用后，Vue 实例指示的所有东西都会解绑定，所有的事件监听器会被移除，所有的子实例也会被销毁。

![生命周期图示](./media/lifecycle.png)

## 组件

## 路由

## axios