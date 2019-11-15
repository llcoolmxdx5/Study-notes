# mongo

## 1.增

```bash
db.collection_name.insert()
db.collection_name.insert([{},{},{}....])
db.collection_name.save()
# 如果不指定 _id 字段 save() 方法类似于 insert() 方法。如果指定 _id 字段，则会更新该 _id 的数据
```

## 2.改

```bash
db.collection_name.renameCollection('newname') # 改表名
db.collection_name.update(query,update,upsert,multi)
# upsert : 可选，这个参数的意思是，如果不存在update的记录，是否插入objNew,true为插入，默认是false，不插入。
# multi : 可选，mongodb 默认是false,只更新找到的第一条记录，如果这个参数为true,就把按条件查出来多条记录全部更新。
db.collection_name.update(query,{$set:{'域名':'值'}}) # $set 用来指定一个键并更新键值，若键不存在并创建。
db.collection_name.update(query,{$unset:{'域名':1}}# $unset 用来删除一个键。
db.collection_name.update(query,{$rename:{旧域名:'新域名'}}) # 修改字段名称
db.collection_name.update(query,{$set:{域名:'值'},$setOnInsert:{域名1:'值1',域名2:'值2'}},true)
db.collection_name.update(query,{$inc:{域名:1}}) # $inc对文档的某个值为数字型的键进行增减的操作
db.collection_name.update(query,{$mul:{域名:2}}) # 乘法 仅数字
db.collection_name.update(query,{$min:{域名:16}}) # $min操作符会在字段的值大于指定的值的时候更新字段的值为指定的值
db.collection_name.update(query,{$max:{域名:16}})
db.collection_name.update(query,{$push:{field:value}}) # 把value追加到field里面去，field一定要是数组类型才行，如果field不存在，会新增一个数组类型加进去。
db.collection_name.update(query,{$pushAll:{数组名1:'文档名1',数组名2:'文档名2',数组名3:'文档名3'}})# 同$push,只是一次可以追加多个值到一个数组字段内。
db.collection_name.update(query,{$push:{数组名:{$each:['文档名1','文档名2','文档名3','文档名4']}}})
db.collection_name.update(query,{$push:{数组名:{$each:['文档名1','文档名2','文档名3'],$position:1}}})
db.collection_name.update(query,{$push:{数组名:{$each:['文档名1','文档名2','文档名3'],$sort:1}}})
db.collection_name.update(query,{$pull:{数组名:'文档名'}}) # 从数组field内删除一个等于value值。
db.collection_name.update(query,{$pullAll:{数组名1:'文档名1',数组名2:'文档名2',数组名3:'文档名3'}})
db.collection_name.update(query,{$pop:{数组名:1}}) # 删除数组的第一个或最后一个元素
db.collection_name.update(query,{$addToSet:{数组名:'文档名'}})# 增加一个值到数组内，而且只有当这个值不在数组内才增加
```

## 3.查

```bash
db.collection_name.find(query,field)
db.collection_name.findOne()
db.collection_name.find({数组名:'文档名'},{_id:0}) # 不显示id
db.collection_name.find({数组名:{$all:['文档名1','文档名2']}},{})
db.collection_name.find({数组名:{$size:2}},{_id:0}) # $size查询一定元素的数量且是数组的字段
db.collection_name.find({域名:{$exists:true}},{_id:0}) # 当boolean为true,$exists匹配包含字段的文档，包括字段值为null的文档。当boolean为false,$exists返回不包含对应字段的文档
db.collection_name.find({域名:{$mod:[商,余数]}},{_id:0}) # 符合取模查询的结果
db.collection_name.find({域名:{$type:1}},{_id:0}) # $type基于BSON类型来检索集合中匹配的数据类型，并返回结果
db.collection_name.distinct(['域名1','域名2']) # 返回去重后的数据
db.collection_name.find().pretty() # 查询到的数据格式化显示
db.collection_name.find().limit(3) # 只显示三条
db.collection_name.find().skip(2) # 前2条不显示
db.collection_name.find().count() # 获取结果集的数量
db.collection_name.find().sort({'域名1':1,'域名2':0})
db.collection_name.find().explain() # 查询语句性能分析
```

![type](./src/mongo_type.png)

## 4.删

```bash
db.collection_name.remove(query,1) # 仅删除一条数据
db.collection_name.remove(query) # 全删
db.collection_name.deleteMany({}) # 全删 推荐使用这个方法取代remove
db.inventory.deleteOne(query) # 删除符合要求的第一条
db.dropDatabase() # 删除库
db.collection_name.drop() # 删除表
```

## 5.杂

```bash
$eq $ne $lt $lte $gt $gte $in $nin # 比较关键字
use databasename # 创建或选择库
show  dbs # 显示所有库
mongodump  -h  dbhost -d dbname  -o  dbdir
mongorestore  -h  <hostname>:<port> -d dbname <path>
db.getCollection('collection_name')
db.createCollection(collection_name) # 创建表
show collections    show tables # 显示所有表
$and $or $not $nor # 逻辑关键字
new Date() ISODate() Date() ISODate().valueOf() # 时间字段
null
db.createCollection(collection_name,{capped:true,size:10000,max:1000})
var cursor = db.class0.find()
.cursor.hasNext()
.cursor.next()
```

## 6.索引

```bash
db.collection.createIndex(keys, options) # 3.0后用createIndex取代ensureIndex
db.collection_name.ensureIndex({'域名':1})
db.collection_name.ensureIndex({域名:1},{'unique':true}) # 唯一索引
db.collection_name.ensureIndex({域名:1},{sparse:true}) # 对文档中不存在的字段数据不启用索引；
db.collection_name.ensureIndex({msg:'text',description:'text'})
db.collection_name.getIndexes() # 查看集合索引
db.collection_name.dropIndexes()# 删除集合所有索引
db.collection_name.dropIndex({域名:1}) # 删除集合指定索引
db.collection_name.find({域名1:'文档'},{_id:0,域名1:1})
db.collection_name.find({$text:{$search:"单词 -big"}},{_id:0})
db.collection_name.find({$text:{$search:"\"多个单词\""}},{_id:0})
db.collection_name.find({$text:{$search:"多个单词"}},{_id:0}
```

## 6.聚合

```bash
db.collection_name.aggregate([{},{},{}...])
db.collection_name.aggregate({$group:{_id:'$域名', num:{$sum:1}}})
db.collection_name.aggregate({$group:{_id:'$域名1',num:{$sum:'$域名2'}}})# $sum计算总和
db.collection_name.aggregate({$group:{_id:'$域名1',num:{$avg:'$域名2'}}})# $avg 计算平均值
db.collection_name.aggregate({$group:{_id:'$域名1',num:{$min:'$域名2'}}})# $min 获取集合中所有文档对应值得最小值。
db.collection_name.aggregate({$group:{_id:'$域名1',num:{$max:'$域名2'}}})
db.collection_name.aggregate({$group:{_id:'$域名1',域名2:{$first:'$域名2'}}})# $first 根据资源文档的排序获取第一个文档数据。
db.collection_name.aggregate({$group:{_id:'$域名1',域名2:{$last:'$域名2'}}})
db.collection_name.aggregate({$project:{_id:0,新域名1:'$旧域名1',新域名2:'$旧域名2'}})
db.collection_name.aggregate({$match:{域名:{$lt:20}}})
db.collection_name.aggregate({$limit:3})
db.collection_name.aggregate({$skip:2})
db.collection_name.aggregate({$sort:{域名:1}}) # 其中 1 为升序排列，而 -1 是用于降序排列。
```

## 7.GridFS

```bash
fs.files
fs.chunks
db.fs.files.find()
db.fs.chunks.find({files_id:ObjectId("xxxxx")})
mongofiles -d   dbname  put filename
mongofiles -d   dbname  get filename
```

## 8.python操作

```python
import pymongo
conn = pymongo.MongoClient('localhost',27017)
conn.close().db = conn.stu db = conn['stu']
my_set = db.class my_set = db['class']
my_set.insert
my_set.insert_one
my_set.insert_many
my_set.remove
cursor = my_set.find({},{'_id':0})
cursor.count()
my_set.find_one
my_set.update
my_set.update_one
my_set.update_many
my_set.ensure_index([('name',1),('King',1)])
index1 = pymongo.IndexModel([('name',1),('King',-1)])
my_set.create_indexes([index1,index2])
my_set.ensure_index('name',unique = True,sparse:True)
for i in my_set.list_indexes():print(i)
my_set.drop_index('name_1_King_-1')
my_set.drop_indexes()
my_set.aggregate()
```
