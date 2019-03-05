# 1.增

1.db.collection_name.insert()
2.db.collection_name.insert([{},{},{}....])
3.db.collection_name.save()

# 2.改

1.db.collection_name.renameCollection('newname')
2.db.collection_name.update(query,update,upsert,multi)
3.db.collection_name.update(query,{$set:{'域名':'值'}})
4.db.collection_name.update(query,{$unset:{'域名':1}}
5.db.collection_name.update(query,{$rename:{旧域名:'新域名'}})
6.db.collection_name.update(query,{$set:{域名:'值'},$setOnInsert:{域名1:'值1',域名2:'值2'}},true)
7.db.collection_name.update(query,{$inc:{域名:1}})
8.db.collection_name.update(query,{$mul:{域名:2}})
9.db.collection_name.update(query,{$min:{域名:16}})
10.db.collection_name.update(query,{$max:{域名:16}})
11.db.collection_name.update(query,{$push:{数组名:'文档名'}})
12.db.collection_name.update(query,{$pushAll:{数组名1:'文档名1',数组名2:'文档名2',数组名3:'文档名3'}})
13.db.collection_name.update(query,{$push:{数组名:{$each:['文档名1','文档名2','文档名3','文档名4']}}})
14.db.collection_name.update(query,{$push:{数组名:{$each:['文档名1','文档名2','文档名3'],$position:1}}})
15.db.collection_name.update(query,{$push:{数组名:{$each:['文档名1','文档名2','文档名3'],$sort:1}}})
16.db.collection_name.update(query,{$pull:{数组名:'文档名'}})
17.db.collection_name.update(query,{$pullAll:{数组名1:'文档名1',数组名2:'文档名2',数组名3:'文档名3'}})
18.db.collection_name.update(query,{$pop:{数组名:1}})
19.db.collection_name.update(query,{$addToSet:{数组名:'文档名'}})

# 3.查

1.db.collection_name.find(query,field)
2.db.collection_name.findOne()
3.db.collection_name.find({数组名:'文档名'},{_id:0})
4.db.collection_name.find({数组名:{$all:['文档名1','文档名2']}},{})
5.db.collection_name.find({数组名:{$size:2}},{_id:0})
6.db.collection_name.find({域名:{$exists:true}},{_id:0})
7.db.collection_name.find({域名:{$mod:[商,余数]}},{_id:0})
8.db.collection_name.find({域名:{$type:1}},{_id:0})
9.db.collection_name.distinct(['域名1','域名2'])
10.db.collection_name.find().pretty()
11.db.collection_name.find().limit(3)
12.db.collection_name.find().skip(2)
13.db.collection_name.find().count()
14.db.collection_name.find().sort({'域名1':1,'域名2':0})
15.db.collection_name.find().explain()

# 4.删

1.db.collection_name.remove(query,justOne)
2.db.dropDatabase()
3.db.collection_name.drop()

# 5.杂

1.$eq $ne $lt $lte $gt $gte $in $nin
2.use databasename
3.show  dbs
4.mongodump  -h  dbhost -d dbname  -o  dbdir
5.mongorestore  -h  <hostname>:<port> -d dbname <path>
6.db.getCollection('collection_name')
7.db.createCollection(collection_name)
8.show collections    show tables
9.$and $or $not $nor 
10.new Date() ISODate() Date() ISODate().valueOf()
11.null
12.db.createCollection(collection_name,{capped:true,size:10000,max:1000})
13.var cursor = db.class0.find()
14..cursor.hasNext()
15..cursor.next()

# 6.索引

1.db.collection_name.ensureIndex({'域名':1})
2.db.collection_name.ensureIndex({域名:1},{'unique':true})
3.db.collection_name.ensureIndex({域名:1},{sparse:true})
4.db.collection_name.ensureIndex({msg:'text',description:'text'})
5.db.collection_name.getIndexes()
6.db.collection_name.dropIndex({域名:1})
7.db.collection_name.find({域名1:'文档'},{_id:0,域名1:1})
8.db.collection_name.find({$text:{$search:"单词 -big"}},{_id:0})
9.db.collection_name.find({$text:{$search:"\"多个单词\""}},{_id:0})
10.db.collection_name.find({$text:{$search:"多个单词"}},{_id:0}

# 6.聚合

1.db.collection_name.aggregate([{},{},{}...])
2.db.collection_name.aggregate({$group:{_id:'$域名', num:{$sum:1}}})
3.db.collection_name.aggregate({$group:{_id:'$域名1',num:{$sum:'$域名2'}}})
4.db.collection_name.aggregate({$group:{_id:'$域名1',num:{$avg:'$域名2'}}})
5.db.collection_name.aggregate({$group:{_id:'$域名1',num:{$min:'$域名2'}}})
6.db.collection_name.aggregate({$group:{_id:'$域名1',num:{$max:'$域名2'}}})
7.db.collection_name.aggregate({$group:{_id:'$域名1',域名2:{$first:'$域名2'}}})
8.db.collection_name.aggregate({$group:{_id:'$域名1',域名2:{$last:'$域名2'}}})
9.db.collection_name.aggregate({$project:{_id:0,新域名1:'$旧域名1',新域名2:'$旧域名2'}})
10.db.collection_name.aggregate({$match:{域名:{$lt:20}}})
11.db.collection_name.aggregate({$limit:3})
12.db.collection_name.aggregate({$skip:2})
13.db.collection_name.aggregate({$sort:{域名:1}})

# 7.GridFS

1.fs.files
2.fs.chunks
3.db.fs.files.find()
4.db.fs.chunks.find({files_id:ObjectId("xxxxx")})
5.mongofiles -d   dbname  put filename
6.mongofiles -d   dbname  get filename

# 8.python操作

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
