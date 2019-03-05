# 什么是VirtualEnv-虚拟环境

VirtualEnv，是Python的虚拟环境，在做Python应用开发时，如果不想在大的Python环境中安装各种各样的包的话，则可以虚拟出一个Python环境，可以让虚拟环境专门为某一个应用而存在。允许在虚拟环境中安装各种包不影响大的python环境

# 2.安装VirtualEnv

sudo pip3 install virtualenv

# 3.创建和使用虚拟环境

准备工作
  mkdir my_env
  mkdir testenv

创建虚拟环境
  virtualenv 虚拟环境名称
  virtualenv default
  virtualenv test

创建指定版本的虚拟环境
  virtualenv -p /usr/bin/python3.5 名称
  virtualenv -p /usr/bin/python3.5 py3.5
  virtualenv -p /usr/bin/python2.7 py2.7

启动虚拟环境
  注意：不能在bin的目录下启动虚拟环境
  source bin/activate
  退出虚拟环境
  deactivate

# 虚拟环境管理工具-VirtualenvWrapper

第三方的管理工具，能够快速，高效而且方便的管理虚拟环境

## 1.安装虚拟环境管理工具

sudo pip3 install virtualenvwrapper

## 2.配置virtualenvwrapper

在~目录下，有一个终端管理文件 .bashrc
配置.bashrc，以便在启动终端时，就自动启动虚拟环境管理工具
修改.bashrc: sudo vim .bashrc
在.bashrc底部增加以下内容：
export WORKON_HOME=~/my_env
将~/my_env 作为虚拟环境的管理目录，所有使用virtualenvwrapper创建的虚拟环境都默认保存于此
如果系统中包含多个python执行环境的话，则添加以下内容
export VIRTUALENVWRAPPER_PYTHON=/usr/bin/python3
source /usr/local/bin/virtualenvwrapper.sh
在~目录下，执行一遍  source .bashrc

## 3.使用虚拟环境管理工具

1.创建并进入到虚拟环境中
  mkvirtualenv 虚拟环境名称
  mkvirtualenv --python=/usr/bin/python3 虚拟环境名称
  mkvirtualenv --python=/usr/bin/python3 py3.5
  
2.查看当前所维护的所有虚拟环境
  workon
3.切换虚拟环境
  workon 虚拟环境名称
4.退出虚拟环境
  deactivate
5.删除虚拟环境
  rmvirtualenv 虚拟环境名称

# django配置中文app方法

https://jingyan.baidu.com/article/fa4125ac056fd428ac7092d3.html
  