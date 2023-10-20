# Lab3: Calculator

> 本实验不需要进行提交

本实验仅需要修改`calculator.c`文件

## Token

```C
typedef struct Token {
    char kind;        // what kind of token
    double value;     // for numbers: a value
} Token;
```

结构体`Token`定义了表达式中最小不可分的组成元素：数和符号。

- `kind`用于存储计算符号
- `value`仅当`kind`的符号表示为数字时，才被使用。

## Token_Buffer

```C
typedef struct Token_Buffer {
    Token token;
    bool full;
} Token_Buffer;
void put_back(Token_Buffer* tb, Token t);
Token get_token(Token_Buffer* tb);
```

结构体`Token_Buffer`用作`Token`的缓存区，用于处理表达式`Token`的读入。

- 函数`put_back`用于将`Token`写回缓存区
- 函数`get_token`用于从缓存区或标准输入中读取`Token`
- 变量`full`标识了缓存区是否存有`Token`

你需要实现`put_back`和`get_token`函数

## Calculate

```text
Grammar:
    Expression:
        Term
        Term "+"|"-" Term ...
    Term:
        Primary
        Primary "*"|"/" Primary ...
    Primary:
        Number
        "(" Expression ")"
    Number:
        floating-point-literal

```

根据提供的文法以及函数抽象思维，实现`expression`、`term`、`primary`函数。

## Test

当你完成上述所有任务后可运行程序，输入`test.txt`中的测试表达式，比较结果。

## 拓展

- 可以通过拓展文法的方式，实现可编程的计算器，以下是一个可供参考的例子：

```text
Grammar:
    Calculation:
        Statement
        Print
        Quit
        Calculation Statement
    Statement:
        Declaration
        Name "=" Calculation Statement
    Declaration:
        "let" Name "=" Calculation Statement
    Print:
        ";"
    Quit:
        "q"
    Calculation Statement:
        Expression:
            Term
            Term "+"|"-" Term ...
        Term:
            Primary
            Primary "*"|"/"|"%" Primary ...
        Primary:
            Number
            Name
            Name "=" Expreesion
            Function(Primary)
            "(" Expression ")"
            "-" Primary
            "+" Primary
        Function:
            sqrt
        Number:
            floating-point-literal
```

- 可以编写异常处理，处理程序运行中的错误后继续运行程序，而不是直接退出。
