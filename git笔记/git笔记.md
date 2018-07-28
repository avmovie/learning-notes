# git笔记

1. 初始化及相关配置

   > ```bash
   > git config --global user.name "Name"
   > git config --global user.email "Email@XX.com"
   > ```
   >
   > 仓库的初始化
   >
   > ```bash
   > mkdir DirectName  
   > git init 
   > ```
   >
   > ssh秘钥的配置
   >
   > ```bash
   > ssh-keygen -t rsa -C "youremail@xx.com"				//一路回车
   > cd .ssh
   > 	id_rsa				私钥
   > 	id_rsa.pub			公钥，在GitHub粘贴该公钥密码
   > ```

unix 平台的diff的格式

历史记录

```bash
git log							//显示git的历史提交
git log --pretty=oneline 		  //排成一行
```

回退到上一个版本

> HEAD 指向当前版本，也就是最新的提交
>
> HEAD^ 						上一个版本
>
> HEAD^						上上个版本
>
> HEAD~100					往上100个版本

```bash
git reset --hard HEAD^				返回上一版本
git reset --hard commit id			返回指定版本号的提交
```

> git版本回退原理：
>
> HEAD指针的移动

```bash
git reflog						查看git的历史提交记录，其显示的信息中有历史提交版本号
```

工作区、版本库、暂存区

> .git目录是git的版本库，其中:index或stage是暂存区，head是指针
>
> `git add`				将文件添加到暂存区
>
> `git commit`			将暂存区的所有内容添加到当前分支
>
> `git commit` 就是往master分支上提交更改

git的优点：

> git管理的是修改不是文件
>
> 具体流程如下所示：
>
> modify gitfile (1)
>
> `git add `
>
> modify gitfile (2)
>
> `git commit `
>
> ```bash
> git diff HEAD -- gitfile(filename)			//比较工作区和版本库文件之间的差异
> ```
>
> `git status `
>
> `modified :gitfile`

git文件的恢复(恢复到暂存区保存的文件内容)

> **跟暂存区的内容保持一致**(未添加到暂存区)
>
> ```bash
> git checkout -- gitfile(filename)			//discard changes in working directory now 
> ```
>
> **跟暂存区之前的内容保持一致**（已经添加到暂存区）
>
> ```bash
> git reset HEAD gitname(filename)			//HEAD表示已经提交的最新的版本
> ```

git中删除文件

> ```bash
> touch filename 
> git add filename 
> git commit filename -m "create filename"
> rm filename
> > deleted :filename			工作区和版本库中的文件就不一样了，如何解决?
> ```
>
> 两种情况:
>
> 1. 确实删除
>
>    ```bash
>    git rm filename 
>    git commit filename -m "remove filename"		//remove and commit 
>    ```
>
> 2. 恢复文件
>
>    ```bash
>    git checkout -- filename			
>    //if you misdeleted your file ->filename ,you can restore it use command like this .
>    ```
>
> 3. 命令辨析：
>
> ```bash
> git checkout -- filename				//抛弃工作区修改还没有提交的文件的文件的改动
> git reset -- hard HEAD					//恢复到最新的版本库的状态
> ```
>
> ```bash
> rm 								//删除了工作区的文件，但没有删除暂存区文件，文件的删除不可追踪
> git rm 							//同时删除工作区和暂存区文件，文件的删除是可追踪的
> ```

git远程仓库

```bash
git clone git@github.com:avmovie/learing-notes.git //从远程仓库克隆到本地
```

2. git的分支管理

> ```bash
> git checkout -b dev					//switched to a new branch
> 	1. git branch dev				//create new branch 
> 	2. git checkout dev				//switch branch dev 
> git branch							//查看当前分支
> git checkout master					//switch to branch master 
> git merge							//merge branch dev and master 
> 	tips:
> 	Fast-forward :该合并是快进模式，直接将master指向dev的当前提交
> git branch -d dev 					//delete current branch 
> 
> 因为git创建，合并，删除分支的速度非常快，利用分支的提交方式更加安全，所以Git鼓励用户使用分支。
> git log								//可以看到分支的合并情况
> git log --graph --pretty=oneline --abbrev-commit //可以更加直观的查看
> ```
>

3. 分支管理策略

> ```bash
> git merge dev --no-ff -m "merge with no-ff"				//表示禁用Fast forward
> ```
>
> ```bash
> --no-ff 表示禁用Fast-forwatd模式，可以在删除分支之后保存之前的分支历史，能够更好地查看merge历史，以及branch状态。
> ```

4. bug分支





5. feature 分支



6. 多人协作

> git本地master分支----->git远程master分支（origin）
>
> ```bash
> git remote					//查看git远程库的信息
> git remote -v 				//查看更加详细的信息
> ```
>
> 推送分支
>
> ```bash
> git push origin master		// 推送本地master分支
> git push origin dev			//推送本地Dev分支
> ```
>
> 从远程库克隆，默认情况下，只能看到本地的master 分支，如何创建远程的Dev分支到本地？
>
> ```bash
> git checkout -b dev origin/dev 
> //then you can modify in this branch and push it to remote resposity 
> modify somefile ,then...
> git add filename
> git commit filename -m "xxxxx"
> git push origin dev
> ```
>
> Meanwhile ,your partner modified a same file as you modified ,and he push it to remote before than you ,then you push your modifies ,you will find an error ,how to figure that ?
>
> ```bash
> git branch --set-upstream-to=origin/dev dev 	//为本地dev和远程dev创建连接
> git pull								//将最新的提交从origin/dev中拉下来
> ```
>
> git pull的过程中，分支会自动进行合并，如果发生了冲突，需要先解决冲突，然后再次提交