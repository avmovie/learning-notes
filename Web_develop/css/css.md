# cascading style sheet 层叠样式表

## css引入

* 行间样式

* 页面级css

  ```html
  <style type="text/css">
  
  </style>
  ```

* 外部引入css

## css选择器

**id 选择器**

```html
<div id="first">
   	JIANGHUIWEN	
</div>
```

```html
#first
{

}
```

**class 选择器**

```html
<div class="demo">
    jianghuiwen
</div>
```

```html
.demo
{

}
```

> class选择器与id选择器的关系：
>
> id选择器是一一对应的
>
> class选择器是多对多的
>
> 也就是说一个class可以对应多个div
>
> 而多个div也可以是使用多个class

```html
such as:
<div class="demo demo1">
    123
</div>
//将两个class同时应用于一个div
```

```html
同样的还有：
一个class
```

**标签选择器**

是对所选定的所有标签直接进行定义装修

**通配符选择器**

```html
*{

} //代表所有的标签
```

补充：

**属性选择器**

```html
[id]            //这里也可以直接添加具体的id值，比如:[id="123"]{}
{

}

[class]          //同上
{

}
```

```html
几种选择器同时修饰一个div，其优先级依次是？
行间样式>id选择器>class选择器|属性选择器（两者的优先级相同，在css表中的定义，谁的顺序在后面就制定谁）>标签选择器>通配符选择器
```

注意：

```html
<div style="background-color="red">
    
</div>
```

此时再定义一个样式表：

```html
div{
background-color:green!important
}
```

> 格式：属性+!important,该优先级大于所有优先级。

**父子选择器/派生选择器**

```html
div span                
{

}
```

注意：父子选择器不在意标签或者是id选择器，其着重点在于是否满足派生关系。

父子选择器指的是该选择器下面的所有该类型的选择器，并非是直接的选择器。

**直接子元素选择器**

> 指的是只对当前选择器下面的直接选择器起作用。

```html
such as：
div > em {
//该标签表示只对div下面的直接em标签起作用
}
```

