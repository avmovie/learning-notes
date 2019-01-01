# questions

1. `const`所修饰的变量是不是全局变量,如果不是,其作用域是什么?

   ```c++
   # include<stdio.h>
   void function();
   int main()
   {
       printf("%d\n",i);			
       printf("%d\n",m);
       //error: i ,m undeclared
   }
   void function()
   {
       static int i = 0;
       const  int m = 9;
       printf("%d\n",i);
       printf("%d\n",m);
   }
   ```

   > 通过上面的例子就可以说明,`const`所修饰的变量并非绝对全局变量,其作用域无法脱离其所在的函数.
   >
   > 教科书中所表达的全局变量应该是指在`main`函数中所声明的`const`变量,这样的变量可以在其他文件中被访问,所以被称为全局变量.

   > 对`const`变量的分析:
   >
   > 1. 分配空间:编译器通常不会为`const`变量分配存储空间,而是将他们保存在符号表中

2. 如何更加深入的了解一个变量的性质?

> 1. 分配空间
> 2. 作用域
> 3. 生存周期

3. 字符串

> C语言中的字符串(数组字符串,char*字符串)
>
> C++中的字符串

4.  