# 事件

1.事件

```flow
st=>start: 事件发生
op1=>operation: 创建事件对象
op2=>operation: 传递给QObject的event()函数
op3=>operation: envnt()按照事件对象的类型分配给特定的事件处理函数
ed=>end: 相应的事件处理函数
st->op1->op2->op3->ed
```

2. 所有的时间处理函数都是`protected virtual`类型的,也就是说,他们都已经在基类被实现,但是可以在子类被重新实现.
3. 