# Html标签

## <a>标签

> 功能：
>
> (1)超链接
>
> ```html
> <a href="baidu.com"
> ```
>
> 
>
> (2)锚点
>
> (3)打电话
>
> ```html
> <a href="tel:156928200983" style="font-size:12rem";></a>
> <a href="mailto:156928200983@163.com" style="font-size:12rem";></a>
> ```
>
> (4)协议限定符
>
> ```html
> <a href="javascript:while(1){alert}"></a>
> ```

## <form>标签

> ```html
> <form method="get" action="http://www.baidu.com/123.html">    //action 代表数据接受的地址
>     <p>
>         username :<input type="text">
>     </p>
>     <p>
>     password :<input type="password">        
>     </p>
>     <p>
>     <input type="submit" value="login">      
>     </p>
> </form>
> ```
>
> * 发送数据需要注意两点：
>
>   (1)数据的主题(数据名称)
>
>   (2)数据的内容(数据的值)
>
>   ```html
>   such as:
>   <input type="text" name="username">
>   <input type="password" name="password">
>   <input type="radio">                          //单选框
>   	指定同样的name可以实现单选框
>   such as:
>   你们所喜欢的男生：
>   1. 贝克汉姆<input type="radio" name="select" value="xiaobei">
>   2. 来昂那多<input type="radio" name="select" value="xiaolai">
>   3. 姜绘文<input type="radio" name="select" value="jianghu">
>   单选框的要点：
>   必须要指定相同的名字
>   
>   再就是复选框的问题：
>   你们所喜欢的男生：
>   1. 贝克汉姆<input type="checkbox" name="select" value="xiaobei" checked="checked"> 
>   // 以上也就是实现了默认选项
>   2. 来昂那多<input type="checkbox" name="select" value="xiaolai">
>   3. 姜绘文<input type="checkbox" name="select" value="jianghu">
>   
>   
>   slelcet组件：
>   <h1>
>       选择你所在的城市：
>       <select name="city">
>           <option value="beijing">beijing</option>
>           <option>shanghai</option>
>           <option>guangzhou</option>
>           <option>chengdu</option>
>           <option>shenzhen</option>           //最终值以value值为标准
>       </select>
>      <input type="submit">
>   </h1>
>   其中，name指定了数据名。
>   什么时候代表数据发送成功了？
>   网址栏出现了数据名和数据内容
>   ```

一个简单的小例子：实现搜索框的功能

```html
<p>
    username:<input type="text" name="username"
              style="clor:#999"
              value="请输入用户名"
              onfocus="if(this.value=="请输入用户名")
        {
        this.value='';
        this.style.color='#424242'
        }"
                    onblur="if(this.value=='')
        {
        this.value='请输入用户名';
        this.style.color='#999'
        }">
    password:<input type="password" name="password">
    		<input type="submit">
</p>
```

