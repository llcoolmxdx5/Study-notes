# webpack

## 起步

1. 先将当前开发设置为ES6模式
2. `npm init -y`    初始化项目生成package.json
3. `npm install webpack --save-dev`  安装webpack
4. 创建a.js文件

    ```js
    export default function play() {
        console.log("play");
    }
    ```

    export和import基于ES6
5. 创建主程序Main.js

    ```js
    import abc from "./a.js";
    abc();
    ```

    注意这里的地址前面一定要有./即使是在同一个目录下
6. 新建文件webpack.config.js
    该文件必须放在根目录下

    ```js
    module.exports={
        entry:"./js/Main.js",
        output: {
            filename: "Main.min.js"
        }
    };
    ```

    module.exports是模块导出的意思
    entry 是入口，注意这里，不管文件在任何位置都需要从当前根目录出发，并且要加./
    output 是一个对象，指输出的定义部分
    filename是输出的文件名，这里如果不指定路径表示生成到dist目录下，这个目录在生成的时候会自动建立，如果指定了目录，不加./就是dist目录下的目录，文件名可以自己定义
7. 执行webpack-cli
    自动生成dist文件夹，下面有对应的文件
8. 新建主文件index.html
    在body中写入`<script src="dist/Main.min.js"></script>`

## 资源管理打包

1. 先将当前开发设置为ES6模式
2. `npm init -y`    初始化项目生成package.json
3. `npm install webpack --save-dev`  安装webpack
4. 下载依赖包
    1）jquery包   `npm install --save jquery@1.12`
    2）处理css文件的包  `npm install --save-dev css-loader style-loader`
    3）处理图片的包   `npm install --save-dev url-loader file-loader`
    4）处理HTML   `npm install --save-dev html-webpack-plugin`
5. 创建项目结构
    - src
        - assets
            - css
                main.css

                ```css
                div {
                    width: 108px;
                    height:67px;
                    background-image: url("../img/icon_a.jpeg");
                }
                div:hover {
                    width: 960px;
                    height: 320px;
                    background-size: 100% 100%;
                    background-image: url("../img/a.jpeg");
                }
                ```

            - img
                - a.jpeg
                - icon_a.jpeg
            - json
                tsconfig.json

                ```json
                {
                    "assets": {
                        "css": ["a.css","b.css"],
                        "img":["a.jpeg","b.jpeg"],
                        "json":["a.json","b.json"],
                        "name":"xietian"
                    },
                    "date":"201811"
                }
                ```

            - js
                Method.js

                ```js
                export function abc() {
                    return "abc";
                }
                export function cde() {
                    return "cde";
                }
                ```

            - Main.js

                ```js
                import $ from "jquery";
                import {abc,cde} from "./js/Method.js";
                import config from "./assets/json/tsconfig.json";
                import "./assets/css/main.css";

                $("<div></div>").appendTo(document.body).text(abc()+cde()+JSON.parse(config));
                ```

    - index.html
    - package.json
    - webpack.config.js

        ```js
        var htmlPlugin=require("html-webpack-plugin");
        module.exports={
            entry:"./src/Main.js",
            output: {
                filename: "Main.min.js"
            },
            module: {
                rules: [
                    // 加载css
                    {
                        test: /\.css$/,
                        use: [
                            'style-loader', // 将js中的css动态插入到DOM中
                            'css-loader' // 将css加载到打包的js中
                        ]
                    },
                    // 加载图片
                    {
                        test: /\.(png|svg|jpg|gif|jpeg)$/,
                        use: ['file-loader']
                    }
                ]
            },
            plugins: [
                // 根据模板生成html(自动引入js/css)
                new htmlPlugin({
                    filename: 'index.html', //生成文件
                    template: 'index.html', //模板文件
                    inject: true //自动注入js/css
                })
            ]
        };
        ```

6. 运行cnpm run build
