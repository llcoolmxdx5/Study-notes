# 1.转义字符

\r         返回光标至行首
\f         换页
\t         水平制表符
\v         垂直制表符
\b         退格(删除)
\0         字符串,字符值为零
\xXX       XX为两位十六进制表示的字符
\uXXXX     Unicode16的十六进制表示的字符
\UXXXXXXXX Unicode32的十六进制表示的字符

# 2.字符串编码转换函数:

ord(c)  返回一个字符的Unicode值
chr(i)  返回i这个值对应的字符

# 3.可变类型拷贝的区别:

=浅拷贝:值相等,地址相等
copy浅拷贝:值相等,地址不相等
deepcopy深拷贝:值相等,地址不相等

# 4.字符串文本解析方法

```python
s.split(sep=None)
s.join(iterable)
```

# 5.推导式

```python
[表达式 for 变量 in 可迭代对象 if 真值表达式]
{键表达式:值表达式 for 变量 in 可迭代对象 if 真值表达式}
{表达式 for 变量 in 可迭代对象}
(表达式 for 变量  in 可迭代对象 [if 真值表达式])
```

# 6.可变不可变类型总结

不可变类型:
  bool,int,float,complex,str,tuple,bytes(字符串)
  frozenset(固定集合),以及None
可变类型:
  list,dict,set(集合),bytearray(字节数组)

# 7.集合的运算:

交集&,并集|,补集-,子集^,超集> <,in ,not in ,==,!=

# 8.一些函数

```python
lambda [形参1,形参2,...]:表达式
eval(source,globals=None,locals=None)
exec(source,globals=None,locals=None)
map(func,*iterable)
filter(function or None,iterable)
sorted(iterable,key=None,reverse=False)

from functools import partial
partial(func, params) # 偏函数 用于固定参数 可以pool.map()时使用传入多个参数
```

# 9.闭包

```python
def makepower(y):
    def fn(x):
        x**y
    return fn
```

# 10.装饰器

```python
def mydeco(fn): #装饰器函数
    def fx():
        print('+++++++')
        fn()
        print('-------')
    return fx
```

# 11.文件

```python
f =  open(file,mode='rt')
f.read(size = -1)
f.close()
f.write(text)
```

# 12.类

静态方法 @staticmethod
类方法 @classmethod
super(B, self).say_hello()  方法内外均可
super().say_hello() 方法内

