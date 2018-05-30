# tar 的用法

1. 创建归档文件

> tar -cvf archive.tar

记忆方法：

c --create file 

v--verbose file

f--file

-cvf 代表的就是创建冗余(啰嗦)文件

2. 追加文件到归档

> tar -rvf archive.tar

记忆方法：

r --append file追加归档至文件结尾

3. 解开归档

> tar -xvf archive.tar

记忆方法：

x--extract 解压文件

# 压缩和解压

## gzip and bzip2

压缩文件：

> gzip archive.tar
>
> bzip2 archive.tar

解压文件：

> gunzip archive.tar.gz
>
> bunzip2 archive.tar.bz2

同时归档压缩

> tar -zcvf archive.tar.gz archive/
>
> tar -jcvf archive.tar.bz2 archive/

* `archive`是一个文件目录
* z--通过gzip过滤归档
* j--通过bzip2过滤归档

同时提取解压

> tar -zxvf archive.tar.gz
>
> tar -jxvf archive.tar.bz2

* 相比于压缩命令，只是将-c（create）换成了-x（extract）

直接显示归档压缩的文件：

> zcat archive.tar.gz
>
> zmore archive.tar.gz
>
> zless archive.tar.gz

以上命令可以直接显示用gzip压缩的文件的内容

## .zip/.rar解压

> unzip archive.zip
>
> unrar e archive.rar

需要注意的是参数`e`前面并没有`-`。

## zip/rar的压缩

> zip -r archive.zip archive/

注意：

1. **`rar的解压软件是免费的，但是其压缩软件是收费的`**
2. -r  英文单词recurse，代表递归

## .zip/.rar的预览

> unzip -l archive.zip
>
> unrar l archive.rar

注意：

1. **`-l 参数代表的是list files`**
2. unrar 参数没有**`-`**

