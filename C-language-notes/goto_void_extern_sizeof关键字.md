# goto,void,extern,sizeof关键字

1. goto 副作用分析

```c
#include <stdio.h>

void func(int n)
{
    int* p = NULL;

    if(  n < 0 )
    {
        goto STATUS;
    }
    
    p = malloc(sizeof(int) * n);
    
STATUS:
    p[0] = n;    
}

int main()
{  
    f(1);
    f(-1);
    
    return 0;
}
```

2. void 关键字-修饰函数的返回值和参数

   1. C语言没有定义void究竟是多大内存的别名,没有void的标尺
   2. void 指针的意义

   > 1. 只有相同类型的指针可以相互赋值
   > 2. void*指针作为左值可以接受任意类型的指针
   > 3. void* 指针作为右值赋值给其他指针是需要强制类型转换
   >
   > ```c
   > //malloc返回值为void
   > int *pI = (int *)malloc (sizeof(int));		
   > char *pC = (char *)malloc (sizeof(char));
   > void *p = NULL;
   > int * pi = NULL;
   > char * pc = NULL;
   > 
   > p = pI;		//OK
   > pi = p;		//fail
   > p = pc;		//OK
   > pc = p;		//fail
   > ```
   >
   > ```c
   > 1, memset()函数的实现
   > #include <stdio.h>
   > 
   > void *My_Memset(void *p,char v,int size)
   > {
   >     void *ret = p;
   >     char *dest = (char *) p;
   >     int i = 0;
   >     for(i;i<size;i++)
   >     {
   >         dest[i] = v;
   >     }
   > }
   > 
   > int main()
   > {
   >     int a[5] = {0,1,2,3,4,5};
   >     for(int i = 0;i<5,i++)
   >     {
   >         printf("%d\n",a[i]);
   >     }
   >     My_Memset(a,0,sizeof(a));
   >     for(int i = 0;i<5;i++)
   >     {
   >         printf("%d\n",a[i]);
   >     }
   >     return 0;
   > }
   > ```

   3. extern 中隐藏的意义

   > 用于声明外部定义的变量和函数
   >
   > 用于告诉编译器用标准c方式编译

   ```c
   // test.c
   #include <stdio.h>
   extern "C"			//使用标准c进行编译
   {
       int add(int a, int b)
       {
           return a + b;
       }
   }
   extern int g;
   extern int get_min(int a, int b);
   
   int main()
   {  
       return 0;
   }
   
   // test2.c
   int g = 100;
   
   int get_min(int a, int b)
   {
       return (a < b) ? a : b;
   }
   ```

   3. sizeof关键字

   > 1. sizeof是编译器的内置指示符,不是函数
   > 2. sizeof用于计算相应实体所占的内存大小
   > 3. sizeof的值在编译器就已经确定

   ```c
   #include <stdio.h>
   
   int main()
   {  
       int a;
       printf("%d\n", sizeof(a));
       printf("%d\n", sizeof a);
       printf("%d\n", sizeof(int));
       return 0;
   }
   ```


