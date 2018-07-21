# git的基本操作

配置用户信息：

> git config --global user.name "yourname"
>
> git config --global user.email "youremail@xxx.com"

git的四种对象：

> 1. blob
> 2. tree
> 3. commit 
> 4. tag

git仓库的获取

> 1. git init 
>
>    `git init --bare `创建一个裸仓库
>
> 2. git cone 

git仓库

1. 工作区域

> * working directory  （工作区）
> * staging area (缓存区)
> * history repository （历史仓库）

2. git的基本命令

> 1. git add
>
>    > git add .或者 git add -A 表示将整个工作区添加到缓存区中
>
>    > **git ignore 文件的编写**
>    >
>    > `git ignore 文件中保存的是被git所忽略的文件，也就是不被提交到git缓存区中的文件`
>    >
>    > such as：
>    >
>    > ```
>    > *.[oa]				//忽略以.a/.o 结尾的文件
>    > *.pyc
>    > ！test.pyc		    //忽略除test.pyc 以外的所有以.pyc结尾的文件
>    > /!text.py			//将以！开头的test.py 文件添加到列表中
>    > foo/ 				//将foo目录添加到列表中
>    > **/ 				//代表匹配零个或者多个目录
>    > **/res 				//当前目录下的res目录以及其他目录中的res目录也能够匹配到
>    > ```
>    >
>
> 2. git commit 
>
> 3. git status
>
> 4. git rm （同时删除git 缓存区中的文件引用以及git工作区中的文件）
>
> 5. git rm --cached filename (只删除缓存区中文件，但是不删除工作区中的文件)
>
> 6. git mv （通常用来实现文件的重命名和移动，本质是一系列操作的组合）
>
> 7. git ignore 



