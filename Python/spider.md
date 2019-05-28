# spider

## 1.urllib

### 1.request

#### 1.urlopen(url,data=None,[timeout])

data:用data参数时,为post方式提交,格式为bytes类型

- bytes(str,encoding='')

- str可以用urllib.parse.urlencode({'key':'value'})生成

timeout:超时时间

返回:response对象

res.read().decode()

#### 2.Request(url,data=None,headers={},origin_req_host=None,unverifiable=False,method='')

data:bytes类型

origin_req_host:请求方的host名称或ip地址

unverifiable:请求是否是无法验证的

method:请求方法 POST GET PUT

返回:request对象

req.add_headers('User-Agent','浏览器')

urlopen(req)

#### 3.高级

1. 验证

    ```python
    from urllib.request import HTTPPasswordMgrWithDefaultRealm,
                        HTTPBasicAuthHandler, build_opener
    p = HTTPPasswordMgrWithDefaultRealm()
    p.add_password(None, url, username, password)
    auth_handler = HTTPBasicAuthHandler(p)
    opener = build_opener(auth_handler)
    result = opener.open(url)
    html = result.read().decode('utf-8')
    print(html)
    ```

2. 代理

    ```python
    from urllib.request import ProxyHandler, build_opener
    proxy_handler = ProxyHandler({
        'http': 'http://127.0.0.1:9743',
        'https': 'https://127.0.0.1:9743'
    })
    opener = build_opener(proxy_handler)
    ```

3. Cookies

    ```python
    import http.cookiejar, urllib.request
    cookie = http.cookiejar.CookieJar()
    handler = urllib.request.HTTPCookieProcessor(cookie)
    opener = urllib.request.build_opener(handler)
    response = opener.open('http://www.baidu.com')
    for item in cookie:
        print(item.name+"="+item.value)
    ```

### 2.parse

#### 1.urlparse(urlstring, scheme='', allow_fragments=True)

urlstring:待解析的URL

scheme:默认的协议（比如http或https等）

allow_fragments=True:是否忽略fragment

url='`http://www.baidu.com/index.html;user?id=5#comment`'

返回:ParseResult(scheme='http', netloc='www.baidu.com',
                path='/index.html', params='user',
                query='id=5', fragment='comment')
    ParseResult实际是个元组 可以用索引或属性名取值

#### 2.urlunparse()

参数:可迭代对象，但是它的长度必须是6

#### 3.urlsplit()

与urlparse()相似 仅返回值不同

返回:SplitResult(scheme='http', netloc='www.baidu.com',
    path='/index.html;user', query='id=5',
    fragment='comment')

没有params 会合并到path中

#### 4.urlunsplit()

参数:可迭代对象，但是它的长度必须是5

#### 5.urljoin(base_url,new_url)

会分析base_url的scheme、netloc和path这3个内容并对新链接缺失的部分进行补充，最后返回结果。

#### 6.urlencode(dict)

将字典序列化为GET请求参数

#### 7.parse_qs()

一串GET请求参数，利用parse_qs()方法，就可以将它转回字典

返回{'':[''],'':['']}

#### 8.parse_qsl()

将GET请求参数转化为元组组成的列表

返回:[('', ''), ('', '')]

#### 9.quote()

将内容转化为URL编码的格式

#### 10.unquote()

进行URL解码

### 3.error

#### 1.URLError

具有一个属性reason，即返回错误的原因

#### 2.HTTPError

处理HTTP请求错误，比如认证请求失败等

属性:

- code：返回HTTP状态码
- reason：同父类一样，用于返回错误的原因。
- headers：返回请求头

#### 3.URLError是HTTPError的父类，所以可以先选择捕获子类的错误再去捕获父类的错误

### 4.robotparser

## 2.requests

### 1.基础用法

requests.get(url,headers,params)

参数:params 字典

返回:response对象

- res.status_code
- res.text
- res.cookies
- res.content 获取二进制码
- res.headers
- res.history
- res.url
- res.json()
- requests.put(url)
- requests.post(url)
- requests.codes.ok 状态码200

### 2.高级用法

#### 1.文件上传

res = requests.post("", files=files)

#### 2.Cookies

```python
for key, value in res.cookies.items():
    print(key + '=' + value)
jar = requests.cookies.RequestsCookieJar()
jar.set(key, value)
requests.get("", cookies=jar, headers=headers)
```

#### 3.会话维持

s = requests.Session()

res = s.get()

利用Session，可以做到模拟同一个会话而不用担心Cookies的问题。

它通常用于模拟登录成功之后再进行下一步的操作。

#### 4.SSL证书验证

requests.get('', verify=False)

忽略警告

from requests.packages import urllib3
urllib3.disable_warnings()

设置证书

requests.get('', cert=)
参数:cert:可以是单个文件（包含密钥和证书）
          或一个包含两个文件路径的元组

#### 5.代理设置

requests.get("", proxies=proxies)

#### 6.超时设置

requests.get("", timeout=)

#### 7.身份认证

requests.get('',auth=('username','password'))

#### 8.Prepared Request

```python
from requests import Request, Session
s = Session()
req = Request('POST', url, data=data, headers=headers)
prepped = s.prepare_request(req)
res = s.send(prepped)
res.text
```

## 3.解析库

### 1.re

### 2.xpath

#### 1.基本规则

nodename 选取此节点的所有子节点

/        从当前节点选取直接子节点

//       从当前节点选取子孙节点

.        选取当前节点

..       选取当前节点的父节点

@        选取属性

轴名称::节点测试[谓语]

序号以1开头

#### 2.lxml.etree

1. 匹配

    1.代码
      from lxml import etree
      html = etree.parse('HTML文件路径', etree.HTMLParser())
      html = etree.parse(str)
      result = html.xpath('//li/a')
      print(result)
      提取结果是一个列表形式，其中每个元素都是一个 Element对象

    2.属性匹配
      html.xpath('//li[class='']/a')

    3.属性多值匹配
      比如一个class属性有多个值时使用
      text = '''
      `<li class="li li-first"><a href="link.html">first item</a></li>`
      '''
      html = etree.HTML(text)
      result = html.xpath('//li[contains(@class, "li")]/a/text()')

    4.多属性匹配
      result = html.xpath('//li[contains(@class, "li") \
                          and @name="item"]/a/text()')

    5.按序选择
      result = html.xpath('//li[1]/a/text()')
      result = html.xpath('//li[last()]/a/text()')
      result = html.xpath('//li[position()<3]/a/text()')
      result = html.xpath('//li[last()-2]/a/text()')

    6.节点轴选择
      result = html.xpath('//li[1]/ancestor::*')
        获取所有祖先节点
      result = html.xpath('//li[1]/ancestor::div')
        获取祖先为div的节点
      result = html.xpath('//li[1]/attribute::*')
        获取所有属性值
      result = html.xpath('//li[1]/child::a[@href="link1.html"]')
        获取指定的属性值的直接子节点
      result = html.xpath('//li[1]/descendant::span')
        获取指定的子孙节点
      result = html.xpath('//li[1]/following::*[2]')
        获取当前节点之后的所有节点,然后再取第二个后续节点
      result = html.xpath('//li[1]/following-sibling::*')
        获取当前节点之后的所有同级节点

2. 获取

    1.文本获取
      result = html.xpath('//li/a/text()')

    2.属性获取
      result = html.xpath('//li/a/@href')

### 3.Beautiful Soup

#### 1.代码

```python
from bs4 import BeautifulSoup
soup = BeautifulSoup(html, 'lxml')
print(soup.prettify()) # 把要解析的字符串以标准的缩进格式输出
print(soup.title.string) # 输出HTML中title节点的文本内容
```

#### 2.解析器

1. html.parser

    Python标准库
    BeautifulSoup(markup, "html.parser")
    Python的内置标准库、执行速度适中、文档容错能力强
    Python 2.7.3及Python 3.2.2之前的版本文档容错能力差

2. lxml

    lxml HTML解析器
    BeautifulSoup(markup, "lxml")
    速度快、文档容错能力强
    需要安装C语言库

3. xml
    lxml XML解析器
    BeautifulSoup(markup, "xml")
    速度快、唯一支持XML的解析器
    需要安装C语言库

4. html5lib

    html5lib
    BeautifulSoup(markup, "html5lib")
    最好的容错性、以浏览器的方式解析文档、生成HTML5格式的文档
    速度慢、不依赖外部扩展

#### 3.节点选择器

1. soup.title 获取元素

2. soup.title.name 获取名称

3. soup.p.attrs soup.p.attrs['name'] 获取属性

4. soup.p.string 获取文本内容

5. soup.head.title 嵌套选择

6. 关联选择

    1.直接子节点
      soup.p.contents 返回直接子节点的列表
      soup.p.childen 返回直接子节点的生成器
      for i,child in enumerate(soup.p.childen):
          print(i,child)
      for child in soup.p.childen:
          print(child)

    2.子孙节点
      soup.p.descendants 返回子孙节点的生成器对象

    3.父节点
      soup.a.parent  直接父节点
      soup.a.parents 返回祖先节点的生成器对象

    4.兄弟节点
      soup.a.next_sibling 返回下一个兄弟节点
      soup.a.next_siblings 返回之后的兄弟节点生成器对象
      soup.a.previous_sibling 返回上一个兄弟节点
      soup.a.previous_siblings 返回之前的兄弟节点生成器对象

7. 方法选择器

    soup.find_all(name,attrs,recursive,text)

      1.name 节点名查询
        soup.find_all(name='li') 返回节点列表

      2.attrs 属性查询
        soup.find_all(attrs={'id':'list-1'})
        soup.find_all(id='list-1')
        soup.find_all(class_='')   返回列表

      3.text  匹配节点的文本
        字符串或正则表达式对象
        soup.find_all(text=re.compile('link')) 返回列表

    find() 返回第一个匹配的元素
    find_parents()和find_parent()：前者返回所有祖先节点，后者返回直接父节点。
    find_next_siblings()和find_next_sibling()：前者返回后面所有的兄弟节点，后者返回后面第一个兄弟节点。
    find_previous_siblings()和find_previous_sibling()：前者返回前面所有的兄弟节点，后者返回前面第一个兄弟节点。
    find_all_next()和find_next()：前者返回节点后所有符合条件的节点，后者返回第一个符合条件的节点。
    find_all_previous()和find_previous()：前者返回节点后所有符合条件的节点，后者返回第一个符合条件的节点。

8. css选择器

    soup.select('ul li') 选择所有ul节点下的li节点 返回列表

    1.嵌套选择

      for ul in soup.select('ul'):
          print(ul.select('li'))

    2.获取属性

        for ul in soup.select('ul'):
            print(ul['id']);print(ul.attrs['id'])

    3.获取文本

      for li in soup.select('li'):
          print(li.get_text());print(li.string)

### 4.pyquery

`from pyquery import PyQuery as pq`

#### 1.初始化

doc = pq(str)
doc = pq(url=)
doc = pq(filename=)

#### 2.查找节点

1. 子孙节点
  find()
  items = doc('.list')
  items.find('li')

2. 子节点
  childen()

3. 父节点
  parent()

4. 祖先节点
  parents()

5. 兄弟节点
  siblings() 不传入css选择器时,获取所有兄弟节点
  要选取某个兄弟节点时,传入css选择器

6. 伪类选择器
  li = doc('li:first-child') 第一个li节点
  li = doc('li:last-child') 最后一个li节点
  li = doc('li:nth-child(2)') 第二个li节点
  li = doc('li:gt(2)') 第三个li之后的li节点
  li = doc('li:nth-child(2n)') 偶数位置的li节点
  li = doc('li:contains(second)') 包含second文本的li节点

#### 3.获取信息

1. 返回值
  结果为单个节点时可以直接打印 或是用str()
  结果为多个节点时
    lis = doc('li').items() # 得到一个生成器
    for li in lis:
        print(li);print(str(li))

2. 获取属性
  attr()
  a = doc(''); a.attr('href')
  返回结果包含多个节点时,只能得到第一个节点的属性 要遍历

3. 获取文本
  text() html()
  a.text() a.html()
  多个节点时,text()会返回所有文本信息,中间用空格隔开
            html()只返回第一个节点的内部html内容

#### 4.修改节点

## 4.文件存储

### 1.csv

`import csv`

#### 1.写入

```python
with open('data.csv', 'w', encoding='utf-8') as csvfile:
    writer = csv.writer(csvfile, delimiter=',')
    writer.writerow([,,])
    writer.writerows([[,,],[,,],[,,]]) 二维列表

    fieldnames = [,,]
    writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
    writer.writeheader() 写入头信息
    writer.writerow({'':'','':'','':''})
```

#### 2.读取

```python
with open('data.csv', 'r', encoding='utf-8') as csvfile:
    reader = csv.reader(csvfile)
    for row in reader:
        print(row) 列表
```

### 2.MySQL

### 3.MongoDB

### 4.Redis

#### 1.连接redis

1. StrictRedis类

    ```python
    from redis import StrictRedis, ConnectionPool
    redis = StrictRedis(host='localhost', port=6379, db=0, password='foobared')
    ```

2. ConnectionPool

    ```python
    pool = ConnectionPool(host='localhost', port=6379, db=0, password='foobared')
    redis = StrictRedis(connection_pool=pool)
    ```

3. ConnectionPool:url

    ```sh
    redis://[:password]@host:port/db Redis TCP连接
    rediss://[:password]@host:port/db Redis TCP+SSL连接
    unix://[:password]@/path/to/socket.sock?db=db Redis UNIX socket连接
    ```

    ```python
    url = 'redis://:foobared@localhost:6379/0'
    pool = ConnectionPool.from_url(url)
    redis = StrictRedis(connection_pool=pool)
    ```

#### 2.操作

`https://cuiqingcai.com/5587.html`

#### 3.RedisDump

1. redis-dump用于导出数据

    参数
      -u代表Redis连接字符串，-d代表数据库代号，-s代表导出之后的休眠时间，
      -c代表分块大小，默认是10000，-f代表导出时的过滤器，-O代表禁用运行时优化，
      -V用于显示版本，-D表示开启调试。
    redis-dump -u :foobared@localhost:6379
    redis-dump -u localhost:6379

    另外，可以使用-d参数指定某个数据库的导出，例如只导出1号数据库的内容：
      redis-dump -u :foobared@localhost:6379 -d 1 > ./redis.data.jl

    只想导出特定的内容，比如想导出以adsl开头的数据，可以加入-f参数用来过滤，命令如下：
      redis-dump -u :foobared@localhost:6379 -f adsl:* > ./redis.data.jl

2. redis-load用于导入数据

    参数
      -u代表Redis连接字符串，-d代表数据库代号，默认是全部，-s代表导出之后的休眠时间，
      -n代表不检测UTF-8编码，-V表示显示版本，-D表示开启调试。

    我们可以将JSON行文件导入到Redis数据库中：
      < redis_data.json redis-load -u :foobared@localhost:6379
      cat redis_data.json | redis-load -u :foobared@localhost:6379

## 5.scrapy

### 1.架构

#### 1.engine 引擎

处理整个系统的数据流处理,触发事物,是整个框架的核心

#### 2.item 项目

定义爬去对象的数据结构,爬取的数据会被赋值成该item对象

#### 3.scheduler 调度器

#### 4.Downloader 下载器

#### 5.spiders

#### 6.Item Pipeline

#### 7.Downloader Middlewares

#### 8.Spider Middlewares

### 2.项目结构

1.scrapy.cfg
  项目配置文件 项目配置文件路径 部署相关信息
2.items.py
  定义item数据结构
3.Pipelines.py
  Item Pipeline实现
4.settings.py
  项目全局配置
5.middlewares.py
  Spider Middlewares 和 Downloader Middlewares实现
6.spiders
  内含多个spider实现 每个spider一个py文件

### 3.入门

1.创建项目
  scrapy startproject 项目名
2.创建Spider
  cd 项目
  scrapy genspider 项目名 域名
3.创建Item
  继承 scrapy.Item类
  定义类型为scrapy.Field()的字段
4.解析response
  在spiders文件中的def parse(self, response)
  1.css选择器
    r = response.css('选择器')
    选择器::text 获取文本
    选择器::attr(属性) 获取属性
    r.extract_first()
      获取列表的第一个元素
    r.extract()
      获取整个列表
  2.xpath
5.使用Item
  在spiders文件中的def parse
  yield item 返回一个字典
6.后续Request
  在spiders文件中的def parse
  获取下一页的相对路径
  next = response.css(' a::attr(href)').extract_first()
  url = response.urljoin(next)
  yield scrapy.Request(url=url, callback=self.parse)
7.使用Item Pipeline
8.运行
  进入目录
  scrapy crawl 项目
9.保存
  scrapy crawl 项目 -o 项目名.后缀
  支持json jl jsonlines csv xml pickle marshal
  ftp `ftp://user:pass@ftp.example.com/path/项目名.后缀`

### 4.selector 用法

1.直接使用
  from scrapy import Selector
  selector = Selector(text=html)
  title = selector.xpath().extract_first()
2.xpath选择器
  response.selector.xpath()
  response.xpath()
3.css选择器
  response.selector.css()
  response.css('a[href=""] img::attr(src)')
4.正则匹配
  不能直接调用re
  response.xpath('.').re()
    会输出匹配到的所有分组
  response.xpath('.').re_first()
    输出匹配到的第一个分组
注:
  选择器可以混用 例如:response.css().xpath().re()

### 5.Spider用法

1.作用
  1.定义爬取网站的动作
  2.分析爬取下来的网页
2.scrapy.Spider.Spider类
  1.name 爬虫名称
  2.allowed_domains 允许爬取的域名 可选配置
  3.custom_settings 字典 专属于本Spider的配置 
  4.crawler 获取项目的配置信息
  5.settings 直接获取项目的全局配置变量
  6.start_requests()
    生成初始请求 返回一个可迭代对象
    默认以 start_urls来构造Request Get请求方式
    初始为post请求方式时,需重写
  7.parse()
    返回一个包含Request或Item的可迭代对象
    处理Response,处理返回结果
  8.closed()
    Spider关闭时,调用

### 6.Downloader Middleware 用法

1.作用
  在Request执行下载前对其修改
  生成的Response被Spider解析前对其修改
  修改User-Agent 处理重定向 设置代理 失败重试
  设置Cookies
2.核心方法
  1.process_request(request, spider)
    返回:
      1.None 继续调度其他process_request方法,最后到 Downloader执行
      2.Response对象 更低优先级的process_request和process_exception方法不会被调用,每个process_response依次调用,最后将Response对象发给Spider处理
      3.Request对象 更低优先级的process_request方法停止执行,放入调度队列,被调度后,更低优先级的process_request方法继续执行
    如果抛出IgnoreRequest异常 所有process_exception依次执行
  2.process_response(requset, response, spider)
    返回:
      1.Request对象
      2.Response对象
    抛出IgnoreRequest异常
  3.process_exception(request, exception, spider)
    必须返回 None Request对象 Response对象

### 7.Spider Middleware 用法

1.作用
  1.在Response发送给Spider之前对Response进行处理
  2.在Request发送给Schedule之前对Request进行处理
  3.在Item发送给Item Pipeline之前对Item进行处理
2.核心方法
  1.process_spider_input(response, spider)
    返回None或抛出异常
    当Response被 Spider Middleware处理时被调用
  2.process_spider_output(response,result,spider)
    result:Spider返回的结果
    返回一个包含Request或Item的可迭代对象
  3.process_spider_exception(response,exception,spider)
    返回None或 一个包含Request或Item的可迭代对象
  4.process_start_requests(start_requests,spider)
    start_requests: Start Request
    返回另一个包含Request对象的可迭代对象

### 8.Item Pipeline用法

1.作用
  1.清理HTML数据
  2.验证爬取数据,检查爬取字段
  3.查重并丢弃重复内容
  4.将爬取结果保存到字符串
2.核心方法
  1.process_item(item,spider)该方法必须实现
    对Item进行处理
    进行数据处理或将数据写进数据库等操作
    返回Item类型或抛出DropItem异常
  2.open_spider(spider)
    Spider开启时自动调用
    做初始化操作,如数据库连接等
  3.close_spider(spider)
    Spider关闭时自动调用
  4.from_crawler(cls,crawler)
    返回一个Class实例
    通过crawler对象,拿到Scrapy所有核心组件,然后创建一个Pipeline实例

### 9.settings.py 配置

  1.MySQL
    MYSQL_HOST = 'localhost'
    MYSQL_DATABASE = ''
    MYSQL_USER = 'root'
    MYSQL_PASSWORD = '123456'
    MYSQL_PORT = 3306
  2.MongoDB
    MONGO_URI = 'localhost'
    MONGO_DB = ''
  3.Redis
  4.ITEM_PIPELINES
  5.Spider Middleware
  6.DOWNLOADER_MIDDLEWARES
    自己设置的优先级应在默认的之前
    DOWNLOADER_MIDDLEWARES_BASE=
    {
    'scrapy.downloadermiddlewares.robotstxt.RobotsTxtMiddleware': 100, 
    'scrapy.downloadermiddlewares.httpauth.HttpAuthMiddleware': 300, 
    'scrapy.downloadermiddlewares.downloadtimeout.DownloadTimeoutMiddleware': 350, 
    'scrapy.downloadermiddlewares.defaultheaders.DefaultHeadersMiddleware': 400, 
    'scrapy.downloadermiddlewares.useragent.UserAgentMiddleware': 500, 
    'scrapy.downloadermiddlewares.retry.RetryMiddleware': 550, 
    'scrapy.downloadermiddlewares.ajaxcrawl.AjaxCrawlMiddleware': 560, 
    'scrapy.downloadermiddlewares.redirect.MetaRefreshMiddleware': 580, 
    'scrapy.downloadermiddlewares.httpcompression.HttpCompressionMiddleware': 590, 
    'scrapy.downloadermiddlewares.redirect.RedirectMiddleware': 600, 
    'scrapy.downloadermiddlewares.cookies.CookiesMiddleware': 700, 
    'scrapy.downloadermiddlewares.httpproxy.HttpProxyMiddleware': 750, 
    'scrapy.downloadermiddlewares.stats.DownloaderStats': 850, 
    'scrapy.downloadermiddlewares.httpcache.HttpCacheMiddleware': 900, }
  7.DOWNLOAD_TIMEOUT
    默认180 (秒)
  8.splash
    SPLASH_URL = ''
    DUPEFILTER_CLASS = 'scrapy_splash.SplashAwareDupeFilter'
    HTTPCACHE_STORAGE = 'scrapy_splash.SplashAwareFSCacheStorage'
    DOWNLOADER_MIDDLEWARES = {
    'scrapy_splash.SplashCookiesMiddleware': 723,
    'scrapy_splash.SplashMiddleware': 725,
    'scrapy.downloadermiddlewares.httpcompression.HttpCompressionMiddleware': 810
    }
    SPIDER_MIDDLEWARES = {
    'scrapy_splash.SplashDeduplicateArgsMiddleware': 100,
    }
    在spider.py的start_request中
      from scrapy_splash import SplashRequest
      yield SplashRequest(url, callback=self.parse, endpoint='execute',
                          args={'lua_source': script, 'page': page, 'wait': 7})
      script = """
      function main(splash, args)
        splash.images_enabled = false
        assert(splash:go(args.url))
        assert(splash:wait(args.wait))
        js = string.format("document.querySelector('#mainsrp-pager div.form > input').value=%d;
              document.querySelector('#mainsrp-pager div.form > span.btn.J_Submit').click()", args.page)
        splash:evaljs(js)
        assert(splash:wait(args.wait))
        return splash:html()
      end
      """
