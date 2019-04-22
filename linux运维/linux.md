# linux command 
1. ps 
```shell
ps -e 
ps -f 
ps -l 
```
2. vmstat 
```shell
vmstat 1
```
3. less is more
4. od 
```shell 
od -t x1 file.dat	//16进制
od -c file		//char by char
echo abcde | od -t x1	//show ascll code use 16 bytes
```
5. wc 
```shell
wc -l			//show the line number
```
6. sort 
```shell
sort -n 		//Numberic
```
7. tr
```shell
tr '[a-z]''[A-Z]'
tr % '\012'
```
8. uniq(筛选文件中的重复行)
```shell
uniq -u             //只筛选出没有重复的行
uniq -d             //只筛选出重复的行
uniq                //筛选出所有行
uniq -c             //显示重复的行
```