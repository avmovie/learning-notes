# 事件

1. 事件处理的过程

```flow
st=>start: 事件发生
op1=>operation: 创建事件对象
op2=>operation: 传递给QObject的event()函数
op3=>operation: envnt()按照事件对象的类型分配给特定的事件处理函数
ed=>end: 相应的事件处理函数
st->op1->op2->op3->ed
```

2. 事件的接受和忽略

> 事件接受后,不会继续向下传递该事件
>
> 事件忽略后,需要注意的是,需要继续向下传递该事件
>
>  

