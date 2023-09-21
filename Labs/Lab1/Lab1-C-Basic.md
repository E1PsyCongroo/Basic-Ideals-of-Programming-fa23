# Lab1: C Basic

> 所有任务分为vs版和非vs版
> 本实验不需要进行提交

## Exercise1: Debug

在本任务中你需要通过调试猜中一个随机数(guess)。

请注意：你不能修改代码源文件

## Exercise2: grep commend

grep是一个常用的命令行工具，用于在文本文件中搜索指定的模式。它可以根据正则表达式匹配文本，并输出匹配到的行。

再本练习中，你将实现一个简单的grep。

### 输入|输出

- getchar: <https://zh.cppreference.com/w/c/io/getchar>
  - getchar()从输入区域读入一个字符并返回
  - 你可以通过判断'\n'换行符，判断行末
- printf: <https://zh.cppreference.com/w/c/io/fprintf>
  - printf通过格式指示符实现格式化输出（对不同长度的二进制串做不同解释）
- scanf: <https://zh.cppreference.com/w/c/io/fscanf>
  - scanf通过格式指示符实现格式化读入（将输入解释为不同长度的二进制串）
- puts: <https://zh.cppreference.com/w/c/io/puts>
  - 你可以理解为printf("%s\n", var);

### 数组

数组是一种固定长度的元素集合，可以容纳一个或多个相同类型的元素。其中每个元素都有一个唯一的索引，可以通过索引来访问和操作数组中的元素。

### 任务

- 实现getline，该函数读入一行字符串（包括换行符），并且返回读入到的字符个数
- 实现strindex，该函数返回字符串s在字符串t中第一次出现的位置（注意从索引0开始），如果s不存在于t中则返回-1
- 实现grep，该函数打印所有输入中匹配字符串pattern的行，并返回匹配行的个数。
