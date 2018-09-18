# Linux下的TCP通信进程

```flow
st=>start: Start
ed=>end: end :> https://baidu.com
op1=>operation: socket
sub1=>subroutine: My Subroutine 
cond=>condition: Yes or No?
io=>inputoutput: catching something...
st->op1->cond
cond(yes)->ed
cond(no)->sub1(right)->op1
```

upd文本发送

> 发送过程:
>
> ```flow
> st=>start: 创建套接字(updsocke t)
> op1=>operation: 绑定套接字(bind)
> op2=>operation: 对方发送数据过来
> op3=>operation: 自动触发ReadRead函数
> op4=>operation: 读取对方发送的内容(readdatagram)
> 
> st->op1->op2->op3->op4
> 
> 
> 
> ```
>
>
>
>

