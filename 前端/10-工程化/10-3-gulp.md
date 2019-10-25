# gulp

## 什么是Gulp

Gulp 是一个自动化工具，前端开发者可以使用它来处理常见任务：

- 搭建web服务器
- 文件保存时自动重载浏览器
- 使用预处理器如Sass、LESS
- 优化资源，比如压缩CSS、JavaScript、压缩图片

## gulp的安装

- npm初始化，新建package.json
    npm init -y
- 先安装全局
    npm install gulp -g
- 再需要在当前项目中安装
    npm install gulp
- 装两遍是为了版本的灵活性

## 开始使用Gulp

在根目录下新建gulpfile.js文件

这个文件就是配置运行文件。我们先尝试写一个最简单的内容

```js
var gulp=require("gulp");
gulp.task("init",function () {
    console.log("init");
});
```

1. require就是讲刚才下载的gulp模块加载导入进来
2. gulp下有一个方法task用来定义任务，第一个参数是任务名，第二个参数是任务执行后的执行函数
3. 在命令行输入gulp init这个init就是刚才起的任务名，执行后就会执行函数，打印出init

## Gulp的方法

- gulp工作方式

  gulp实际工作是使用nodejs中的stream来处理的，简单来说，如果需要合并两个文件，就需要讲两个文件都加载进来，然后再处理将文件合并，注意这里加载进来的文件并不是文本形式加载，而是以二进制数据流的方式，也就是steam加载进入。被加载进入的文件是以二进制数据流模式存在的，内容中除了含有文件内容，还包括了文件的地址，文件名等等一系列相关信息。然后再将所有的数据流处理生产新文件。因此这里就用到了nodejs中stream的方法pipe

  pipe

  - 管道，流向的意思，可以在这里理解为写入到
  - a.pipe(b) 将a写入到b中

- src方法

  读取文件的数据流

  - gulp.src(globs)
  - globs参数是读取文件的筛选条件，可以写入字符串，也可以是数组，数组含有多个读取条件
    - gulp.src("js/a.js") 读取一个文件
    - gulp.src(["js/a.js","js/b.js"]) 读取两个文件
    - gulp.src("js/*.js") js文件夹下所有的js文件
  - 匹配条件

    - `*` 匹配文件路径中的0个或多个字符，但不会匹配路径分隔符，除非路径分隔符出现在末尾
    - `**` 匹配路径中的0个或多个目录及其子目录,需要单独出现，即它左右不能有其他东西了。如果出现在末尾，也能匹配文件。也就是能匹配某个目录下所有文件包括其子目录下的所有内容
    - `?` 匹配文件路径中的一个字符(不会匹配路径分隔符)
    - `[...]` 匹配方括号中出现的字符中的任意一个，当方括号中第一个字符为^或!时，则表示不匹配方括号中出现的其他字符中的任意一个，类似js正则表达式中的用法
    - `!(pattern|pattern|pattern)` 匹配任何与括号中给定的任一模式都不匹配的
    - `?(pattern|pattern|pattern)` 匹配括号中给定的任一模式0次或1次，类似于js正则中的`(pattern|pattern|pattern)?`
    - `+(pattern|pattern|pattern)` 匹配括号中给定的任一模式至少1次，类似于js正则中的`(pattern|pattern|pattern)+`
    - `*(pattern|pattern|pattern)` 匹配括号中给定的任一模式0次或多次，类似于js正则中的`(pattern|pattern|pattern)*`
    - `@(pattern|pattern|pattern)` 匹配括号中给定的任一模式1次，类似于js正则中的`(pattern|pattern|pattern)`

- dest方法

  给文件写入数据流 `gulp.dest(path)` path参数是要写入文件存放的路径

  ```js
  gulp.task("init",function () {
      gulp.src("./js/*.js").pipe(gulp.dest("./dist/"))
  });
  ```

  这样就会将当前目录下，js文件夹下所有的js读入，然后写入到当前目录的dist文件夹下
  用gulp.dest()把文件流写入文件后，文件流仍然可以继续使用。

- task方法:定义任务

    如果需要有多个任务操作时就需要定义任务

    gulp.task(任务名,任务所依赖前面任务名的数组,任务执行的函数);

    ```js
    gulp.task("default",function () {
        console.log("aaa");
    });
    ```

    这是默认执行，执行gulp就可以，无需输入任务名

    ```js
    gulp.task("one",function () {
        console.log("one");
    });
    gulp.task("two",["one"],function () {
        console.log("two")
    });
    ```

    如果执行 gulp two 这时候就会先执行任务one，再执行任务two

- watch方法:监视文件变化

  `gulp.watch("监视的文件",[监视文件发生变化后需要执行任务名的数组])`

  ```js
  gulp.task("default",function () {
      gulp.watch('js/*.js', function(event){
          console.log(event.type); //变化类型 added为新增,deleted为删除，changed为改变
          console.log(event.path); //变化的文件的路径
      });
  });
  ```

  这里启动任务后，会开始监视，如果js文件夹下那个文件修改了，或者删除，增加，这里都会打印出来

## Gulp4

在gulp4中所有的前置任务都被修改了，例如task中的数组不再使用，改为series和parallel

- series
  
  前置任务完成后，执行下一个任务，同步执行
  
  - 回调函数法

    ```js
    gulp.task("js",function(done){
        gulp.src("./src/**/*.js")
        .pipe(load.babel({
            "presets": ["@babel/env"]
        }))
        .pipe(gulp.dest("./dist"))
        done();
    })
    gulp.task("save",gulp.series("js",function(){
        console.log("aaaa")
        gulp.src("./dist/**/*.js")
        .pipe(load.concat("main.min.js"))
        .pipe(load.uglify())
        .pipe(gulp.dest("./dist"));
    }));
    ```

    注意上面的done，在函数中有参数done，当完成当前任务内容后执行回调函数done，以为这后续任务save中的function函数被执行，会打印aaaa，如果不执行done，不会执行后续任务

  - promise法

    ```js
    gulp.task("js",function(){
        return new Promise(function(res,rej){
            gulp.src("./src/**/*.js")
            .pipe(load.babel({
                    "presets": ["@babel/env"]
                }))
            .pipe(gulp.dest("./dist"));
            res();
        })
    })
    gulp.task("save",gulp.series("js",function(){
        console.log("aaaa")
        gulp.src("./dist/**/*.js")
        .pipe(load.concat("main.min.js"))
        .pipe(load.uglify())
        .pipe(gulp.dest("./dist"));
    }));
    ```

    上面这种promise写法，通过return promise，在执行完成任务后，执行其中的res，执行后续save任务中的函数方法，打印aaaa

  - 事件完成操作后回调

    以上的案例是js任务解决了ES6转换ES5，任务save重新获取转换好的js文件合并压缩后存储为main.min.js。但是使用上面两个方法后，我们发现后面没有合并存储，原因是什么呢？上面的两种写法在任务中标识完成了，但是不代表操作就完成了，js任务最后存储是需要时间的，但是当开始存储时就已经执行了后续的任务，显然在后续任务中不能找到这个被转换后的文件。那么我们应该通过什么操作，这里我们需要等待上面内容完成后才可以操作后续内容

    ```js
    gulp.task("js",function(done){
        gulp.src("./src/**/*.js")
        .pipe(load.babel({
            "presets": ["@babel/env"]
        }))
        .pipe(gulp.dest("./dist"))
        .on("end",done);
    })
    gulp.task("save",gulp.series("js",function(){
        console.log("aaaa")
        gulp.src("./dist/**/*.js")
        .pipe(load.concat("main.min.js"))
        .pipe(load.uglify())
        .pipe(gulp.dest("./dist"));
    }));
    ```

    通过事件end判断完成存储后再继续执行后续任务

- parallel

  前置任务和当前任务一同执行

  ```js
  gulp.task("js",function(){
  gulp.src("./src/**/*.js")
  .pipe(load.babel({
      "presets": ["@babel/env"]
  }))
  .pipe(gulp.dest("./dist"))
  })
  gulp.task("save",gulp.parallel("js",function(){
      console.log("aaaa")
      gulp.src("./js/**/*.js")
      .pipe(load.concat("main.min.js"))
      .pipe(load.uglify())
      .pipe(gulp.dest("./dist"));
  }));
  ```

  这个任务中，使用了parallel在处理任务中是并行的，可以看到后续任务并不需要依赖js任务完成而执行，是在于js任务同时开始的，因此，js任务也不需要执行回调函数或者promise

## 一些常用的gulp插件

- 自动加载插件

  gulp-load-plugins

  `npm install --save-dev gulp-load-plugins`

  在gulpfile中如果需要使用别的插件，导入方法我们使用require。那么如果需要加载很多就会出现这种情况

  ```js
  var gulp = require('gulp'),
  //一些gulp插件,abcd这些命名只是用来举个例子
  a = require('gulp-a'),
  b = require('gulp-b'),
  c = require('gulp-c'),
  d = require('gulp-d'),
  e = require('gulp-e'),
  f = require('gulp-f'),
  g = require('gulp-g'),
  //更多的插件...
  z = require('gulp-z');
  ```

  我们可以这样做：

    安装并导入gulp-load-plugins
    在package.json的devDependencies中写下需要加载的插件，这个是开发依赖

    ```js
    var load=require("gulp-load-plugins")();
    load.rename("a.js") // 这里的rename就是一个插件，这插件叫gulp-rename
    ```

- 压缩文件

  gulp-uglify

  `npm install --save-dev gulp-uglify`

  可以将文件中的空格去除

  ```js
  gulp.task("default",function () {
      gulp.src("./js/a.js")
      .pipe(uglify())
      .pipe(gulp.dest("./dist"))
  });
  ```

- 重命名

  gulp-rename

  `npm install --save-dev gulp-rename`

  可以重新给文件起名

  ```js
  gulp.task('rename', function () {
      gulp.src('js/jquery.js')
      .pipe(uglify())  //压缩
      .pipe(rename('jquery.min.js')) //会将jquery.js重命名为jquery.min.js
      .pipe(gulp.dest('js'));
  });
  ```

- css文件压缩

  gulp-minify-css

  `npm install --save-dev gulp-minify-css`

  ```js
  var gulp = require('gulp'),
  var minifyCss = require("gulp-minify-css");
  gulp.task('minify-css', function () {
      gulp.src('css/*.css') // 要压缩的css文件
      .pipe(minifyCss()) //压缩css
      .pipe(gulp.dest('dist/css'));
  });
  ```

- html文件压缩

  gulp-minify-html

  `npm install --save-dev gulp-minify-html`

  ```js
  var gulp = require('gulp'),
  var minifyHtml = require("gulp-minify-html");
  gulp.task('minify-html', function () {
      gulp.src('html/*.html') // 要压缩的html文件
      .pipe(minifyHtml()) //压缩
      .pipe(gulp.dest('dist/html'));
  });
  ```

- 文件合并

  gulp-concat

  `npm install --save-dev gulp-concat`

  ```js
  var gulp = require('gulp'),
  var concat = require("gulp-concat");
  gulp.task('concat', function () {
      gulp.src('js/*.js')  //要合并的文件
      .pipe(concat('all.js'))  // 合并匹配到的js文件并命名为 "all.js"
      .pipe(gulp.dest('dist/js'));
  });
  ```

- sass解析
  
  gulp-sass

  `npm install --save-dev gulp-sass`

  ```js
  var gulp = require('gulp'),
  var sass = require("gulp-sass");
  gulp.task('compile-sass', function () {
      gulp.src('sass/*.sass')
      .pipe(sass())
      .pipe(gulp.dest('dist/css'));
  });
  ```

- 图片压缩

  gulp-imagemin

  `npm install --save-dev gulp-imagemin`
  
  ```js
  var gulp = require('gulp');
  var imagemin = require('gulp-imagemin');
  gulp.task('default', function(){
      gulp.src('src/images/*')
      .pipe(imagemin())
      .pipe(gulp.dest('dist/images'))
  });
  ```

- 静态服务器搭建

  ```js
  var gulp=require("gulp");
  var load=require("gulp-load-plugins")();
  var browser=require("browser-sync").create();
  gulp.task("save",function(done){
  gulp.src("./src/**/*.js")
  .pipe(load.babel({
      presets:['@babel/env']
  }))
  .pipe(load.concat("main.min.js"))
  .pipe(load.uglify())
  .pipe(gulp.dest("./dist"))
  .on("end",browser.reload);
  });
  gulp.task("server",function(){
  browser.init({
      server:"./",
      port:3009
  })
  gulp.watch("./src/**/*.js",gulp.series("save"));
  })
  ```

  browser-sync是静态服务器，create()开启创建

  使用browser.init创建服务位置和端口

  使用gulp.watch做监听，并且重新执行js的合并压缩打包等处理，最后当存储完成后，刷新网页browser.reload是重载页面
