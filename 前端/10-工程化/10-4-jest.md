# jest

## 什么是前端工程化

工程化就是软件工程的一种概念，项目在编写的时候要注意哪些地方

- 性能
- 稳定性
- 可用性
- 可维护性

要考虑的地方

- 生产的效率
- 维护的难易程度

解决方案

- 制定规范 ---> css bem规范 css私有化 sass less js规范 文件的规范
- 模块化与组件化 ---> 可维护性 可复用性强
  - 模块化
    - esmodule commonJs AMD CMD
    - 如何定义模块 导入导出模块
  - 组件
    - 页面上的任一部分
  - 多个模块组成一个组件

部署问题

- 代码审核
- 压缩打包
- 增量更新
- 单元测试

构建和编译

- 构建：构建是在编译的基础之上的
- 编译：单文件的一些编译

总结：注意的地方

- 模块化、组件化
- 自动化
- 规范
- 静态资源管理

## 前端为什么要做自动化测试

哪些方面

- UI测试
- 功能测试
- 性能测试
- 页面的一些特性检查

单元测试 集成测试 E2E测试

## jest基本介绍以及原理

1. 若需测试ES6的MODULE模块化时需要安装 `yarn add @babel/core @babel/preset-env jest@24.8.0 -D`
2. 配置.babelrc

    ```js
    {
      "presets": [
        [
          "@babel/preset-env",
          {
            "targets": {
              "node": "current"
            }
          }
        ]
      ]
    }
    ```

3. jest会自动进行.test.js文件的检测

## jest匹配器以及命令行操作

```js
expect({a:1}).toBe({a:1})//判断两个对象是否相等，用Object.is()判断对象的地址是否一致,测试数字用
expect(1).not.toBe(2)//判断不等
expect(n).toBeNull(); //判断是否为null
expect(n).toBeUndefined(); //判断是否为undefined
expect(n).toBeDefined(); //判断结果与toBeUndefined相反
expect(n).toBeTruthy(); //判断结果为true
expect(n).toBeFalsy(); //判断结果为false
expect(value).toBeGreaterThan(3); //大于3
expect(value).toBeGreaterThanOrEqual(3.5); //大于等于3.5
expect(value).toBeLessThan(5); //小于5
expect(value).toBeLessThanOrEqual(4.5); //小于等于4.5
expect(value).toBeCloseTo(0.3); // 浮点数判断相等
expect('Christoph').toMatch(/stop/); //正则表达式判断
expect(['one','two']).toContain('one'); //不解释
function compileAndroidCode() {
  throw new ConfigError('you are using the wrong JDK');
}
test('compiling android goes as expected', () => {
  expect(compileAndroidCode).toThrow();
  expect(compileAndroidCode).toThrow(ConfigError); //判断抛出异常
}）
```
