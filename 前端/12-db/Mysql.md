# mysql

## 1.增

1.create database 库名 default charset=utf8;
2.create table 表名(字段名 数据类型,字段名 数据类型,... ...);
3.insert into 表名(字段名列表) values(值 1,...值 N);
4.alter table 表名 add 字段名 数据类型 first | after 字段名;
5.字段名 数据类型 default 默认值 字段名 数据类型 not null;
6.create table 表名 select 查询命令; 表复制;
7.create table 表名 select 查询命令 where false; 只复制表结构

## 2.删

1.drop database 库名;
2.drop table 表名;
3.alter table 表名 drop 字段名;
4.delete from 表名 where 条件;
5.select 字段名列表 from 表 1
inner join 表 2 on 条件 inner join 表 3 on 条件;
6.select 字段名列表 from 表名列表 where 条件;
等同于 内连接 inner join

## 3.改

1.alter table 表名 modify 字段名 新数据类型;
2.alter table 表名 change 旧名 新名 数据类型;
3.alter table 表名 rename 新表名;
4.update 表名 set 字段名 1=值 1,字段名 2=值 2,... where 条件;

## 4.查

1.show databases;
2.show create database 库名;
3.select database();
4.show tables;
5.show create table 表名;
6.desc 表名;
7.select 字段 1,字段名 2,...,字段名 N from 表名;
8.select 聚合函数(distinct...) from 表名 where group by having order by limit
where
group by
聚合函数 avg sum max min count (字段名)
having
order by 字段名 排序方式 ASC(默认):升序 DESC:降序
limit m,n 9.嵌套查询(子查询)
10.select 字段名列表 from 表 1
left/right outer join 表 2 on 条件;
11.select 字段名列表 from 表名列表; ## 笛卡尔积

## 5.索引

### 1.普通索引

1.KEY 标志为 MUL 2.创表时 index(id)  
3.create index 索引名 on 表名(字段名);

### 2.唯一索引

1.KEY 标志是 UNI 2.创表时 unique(字段名)
3.create unique index 索引名 on 表名(字段名);

### 3.主键索引

1.KEY 标志是 PRI 2.字段名 数据类型 primary key auto_increment
3.id int auto_increment,
...
primary key(id))auto_increment=10000;
4.alter table 表名 add primary key(字段名);
5.alter table 表名 modify id int;
6.alter table 表名 drop primary key;

### 4.外键索引

1.foreign key(参考字段名) references 被参考表名(被参考字段名)
on delete 级联动作 on update 级联动作
2.cascade ：数据级联更新
当主表删除记录 或者 更新被参考字段的值时,从表会级联更新
3.restrict 默认
当删除主表记录时,如果从表中有相关联记录则不允许主表删除 更新同理
4.set null
当主表删除记录时,从表中相关联记录的参考字段值自动设置为 NULL 更新同理
5.no action 立即检查外键限制
6.alter table 表名 drop foreign key 外键名;
7.alter table 表名 add foreign key(参考字段名)
references 被参考表名(被参考字段名)
on delete 级联动作
on update 级联动作;

### 5.删除索引

drop index 索引名 on 表名;

### 6.查看索引

show index from 表名\G;

## 6.杂

### 1.linux 下操作

1.sudo apt-get install mysql-server
2.sudo apt-get install mysql-client
3.sudo /etc/init.d/mysql status
4.sudo /etc/init.d/mysql stop | start | restart
5.mysql -hlocalhost -uroot -p123456
6.sudo -i
cd /etc/mysql/mysql.conf.d
vi mysqld.cnf [mysqld] character_set_server = utf8 保存退出
/etc/init.d/mysql restart | reload
7.mysqldump -uroot -p 源库名 > 路径/xxx.sql
8.mysql -u 用户名 -p 目标库名 < 路径/xxx.sql
9.mysql -u 用户名 -p --one-database 目标库名 < all_mysql.sql
10.show create table 表名; ## engine=...
11.create table 表名(...)engine=myisam;
12.mysql> show engines;
13.INNODB Myisam
14.cd /etc/mysql/mysql.conf.d/
vi mysqld.cnf
[mysqld]
defalut-storage-engine = myisam

### 2.数值类型

1.整型
int 大整型(4 个字节)
tinyint 微小整型(1 个字节)
1、有符号(signed 默认): -128 ~ 127
2、无符号(unsigned): 0 ~ 255
smallint 小整型(2 个字节)
bigint 极大整型(8 个字节) 2.浮点型
float(4 个字节,最多显示 7 个有效位)
double(8 个字节,最多显示 15 个有效位)
decimal(M+2 个字节,最多显示 28 个有效位) 3.字符类型
char(定长) 1 ~ 255 不给定宽度默认为 1
varchar(变长) 1 ~ 65535 没有默认宽度
char 浪费存储空间,但是性能高
varchar 节省存储空间,但是性能低 4.枚举类型
单选 字段名 enum(值 1,值 2,...,值 N)
多选 字段名 set(值 1,值 2,...,值 N) "Python,boy,Mysql" 5.日期时间类型
year ：年 YYYY
date ：日期 YYYYMMDD
time ：时间 HHMMSS
datetime ：日期时间 YYYYMMDDHHMMSS 不给值默认返回 NULL
timestamp ：日期时间 YYYYMMDDHHMMSS 不给值默认返回系统当前时间

### 3.运算符

1.=、!=、>、>=、<、<=
2.and or between 值 1 and 值 2 in not in is null is not null
3.where 字段名 like 表达式; where 字段名 regexp "正则表达式";

### 4.快速导入/导出数据

1.load data infile "文件名"
into table 表名
fields terminated by "分隔符"
lines terminated by "\n"
2.select ... from 表名
into outfile "文件名"
fields terminated by "分隔符"
lines terminated by "\n";

### 5.权限

1.cd /etc/mysql/mysql.conf.d/
vi mysqld.cnf ##bind-address = 127.0.0.1
2.create user "用户名"@"IP 地址" identified by "密码";
3.grant 权限列表 on 库.表 to "用户名"@"IP 地址" with grant option;
权限列表：select,update,delete,insert,alter,drop,create,...
all privileges

## 7.pymysql

1.对象名 = pymysql.connect("主机地址","用户名","密码","库名",charset="utf8")
2.db cursor() commit() rollback() close
3.cur execute fetchone() fetchall() fetchmany(n) close()
