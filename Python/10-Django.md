# 1.Django 的框架模式 - MTV

M ：Models 层 ==M
    模型层，负责数据库的建模以及CRUD的操作
T ：Templates 层 ==V 
  模板层，用于处理用户显示的内容的 如：html
V ：Views视图层  ==C控制器
  处理与用户交互的部分内容，从模型中获取数据，再将数据发送给模板，显示给用户
  
# 2.开始项目

1.`django-admin startproject 项目名`
2.`python3 manage.py runserver 0.0.0.0:8888`
3.`./manage.py startapp 应用名称` 再去注册
4.`STATICFILES_DIRS=(BASE_DIR,'static')`
5.`return render(request,'模板名称',{})`

# 3.过滤器

{{变量|过滤器:参数}}
{{value|upper}} {{value|lower}} 转换值为大写/小写字符
{{value|truncatechars:n}} 截取字符串至n位字符

# 4.模板的继承

{% block 名称 %}
  父模板中的内容
{% endblock %}
{% extends '父模板的名称' %}

# 5.数据库准备

create database 数据库名 default charset utf8 collate utf8_general_ci;
链接MySQL
  ENGINE NAME USER PASSWORD HOST PORT
在`__init__`中添加
  import pymysql
  pymysql.install_as_MySQLdb()
./manage.py makemigrations
./manage.py migrate

# 6.模型类

from django.db import models

# 7.在视图层执行CRUD

from django.db.models import F,Q
F('列名') Q(表达式)|Q(表达式)
1.增加数据
  Entry(**dic).save()
2.查询操作
  Entry.objects.all()
  Entry.objects.all()[:n] 相当于limit n
  Entry.objects.values('列1','列2')
  Entry.objects.order_by('列')
  Entry.objects.exclude(条件)
  Entry.objects.filter(参数)
  Entry.objects.get(查询条件/谓词)
3.修改操作
  au = Author.objects.get(id=1)
  au.name = '王宝强' au.age = 35  au.save()
  Author.objects.all().update(属性=值,属性=值)
4.删除数据
  Author.objects.get(id=1).delete()
  Author.objects.all().delete()
5.原生数据库操作
  1.查
    Entry.objects.raw(sql)
  2.增删改
    with connection.cursor() as cursor:
        sql = 'delete from author where ...'
        cursor.execute(sql)

# 8.重定向

from django.http import HttpResponseRedirect
return HttpResponseRedirect('地址')

# 9.后台管理

1.`./manage.py createsuperuser`
2.admin.site.register(Entry1)
3.`def __str__(self):return self.name`
4.class Meta:
  1、db_table 更改表名
  2、verbose_name_plural
  3、ordering
5.class AuthorAdmin(admin.ModelAdmin):
  1.list_display
  2.list_display_links
  3.list_editable
  4.search_fields
  5.list_filter 过滤器 适用于类别 时间
  6.date_hierarchy
    作用：在列表页顶部增加时间选择器
    date_hierarchy='字段名'
  7.fields 详情页要显示的字段
  8.fieldsets = (
    ('分组名称',{'fields':('属性1','属性2'),'classes':('collapse',)}),
    )

# 10.关系映射 - Django中的连接查询

1.属性 = models.OneToOneField(Entry,null=True)
  反向查 默认会在另一个实体中增加 关联对象 属性
2.在 "多" 的实体中，增加：
  entry = models.ForeignKey(Entry)
  反向查 默认会在 1 的实体中增加 关联对象_set 属性
3.在 Entry2 的实体中增加
  entry1 = models.ManyToManyField(Entry1)
  正向查 entry2 = Entry2.objects.get(id=1)
        entry2.entry1.all()
  反向查 默认会在 Entry1 的实体中增加 entry2_set 属性
      entry1 = Entry1.objects.get(id=1)
      entry1.entry2_set.all()

# 11.自定义查询对象 - objects

class EntryManager(models.Manager):
    def 函数名(self,自定义参数列表):
        return ... ...
class Entry(models.Model):
    objects = EntryManager()

# 12.CSRF 跨站点攻击

目的：为了解决跨站点发送post请求
解决方案：
  1.settings.py中
    删除 CsrfViewMiddleWare 中间件
  2.在视图中增加 @csrf_protect
  3.在模板中 <form>下的第一行增加：
    {%csrf_token%}

# 13.HttpRequest

request.GET['名称']
request.POST['名称']
request.method

# 14.forms 模块

1.创建 forms.py 文件
2.from django import forms
3.创建 class，一个class对应一个表单
  该class必须继承自forms.Form
4.forms.CharField(label='标题',initial='初始数据')
5.解析
  视图中 form .forms import *
  form = RemarkForm()
  return render(request,'xx.html',locals())
  模板中 {{form.as_p}}
6.获取表单数据
  form = XXXForm(request.POST)
  if form.is_valid():
    cd = form.cleaned_data
7.forms高级
  在forms.py 创建class,继承自forms.ModelForm
  model fields
  labels = {'属性名':'label文本','属性名':'label文本'}

# 15.cookies

resp=HttpResponse('给客户端的一句话')
resp.set_cookie('key','value',expires)
return resp
获取 request.COOKIES

# 16.session

request.session['key'] = 值
request.session.set_expiry(time)
获取 request.session.get('key')
del request.session['key']
SESSION_COOKIE_AGE = 60*30
SESSION_EXPIRE_AT_BROWSER_CLOSE = True
