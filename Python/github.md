# 1.首次推文件

1. git init
2. git add .
3. git commit -m "这是注释内容"
4. 去github创建仓库
5. git remote add origin https://github.com/用户名/仓库名.git
6. git push -u origin master

# 2.更新文件到github

1. git add .
2. git commit -m "这是注释内容"
3. git pull origin master
4. git push -u origin master
5. 若进入vi就直接退

# 3.从github上下载源码到本地

git clone --recursive  https://github.com/用户名/仓库名.git
