#《知识点笔记》

## 第一章
>int c = getchar()
从文本流中读入下一个输入字节，并将其作为结果值返回。

>putchar(c) 
打印一个字符。

[如何修改头文件](https://www.oschina.net/question/179541_26961)

## 第二章
C语言只提供了4中基本数据类型:

- char
- int:  通常反映了所用机器中整数的自然长度。
- float
- double

4中基本数据类型前面可以增加一些限定符:

- short 和 long 用于限定数值类型
    - short int sh;
    - long int counter;
    - 这种类型的声明中,关键字 int 可以省略。
    - 还可以这样: long double;
- signed 与 unsigned 类型限定符:
    - 可用于限定 char 或 任何整数型。
    - signed char, 取值范围 -128~127
    - unsigned char, 取值范围 0~255

长度定义的符号常量,以及与机器和编译器有关的属性可以在 <limits.h> 与 <float.h> 中找到。

### 2.3 常量

- 字符串常量就是字符数组。
- C语言对字符串长度没限制,但必须得遍历一遍才知道字符串长度。
- 长度不包括末尾的'\0'

标准头文件<string.h> 声明了 strlen 和其他字符串函数。

字符常量 与 只有一个字符的字符串的区别:

- 'x' 与 "x" 是不同的。
- 前者是一个整数, 后者是一个包含 'x' 和 一个结束字符 '\0' 的数组。