# 递归

- 经典递归例子

  ```C
  #include <stdio.h>
  int fibonacci(int n) {
      if (n < 1) {
          return -1;
      }
      if (n == 1 || n == 2) {
          return 1;
      }
      else {
          return fibonacci(n - 1) + fibonacci(n - 2);
      }
  }
  
  int main(void)
  {
      int a;
      while (scanf("%d", &a) != EOF) {
          printf("Fibonacci数列第%d项为:%d\n", a, fibonacci(a));
      }
      return 0;
  }
  ```

- 理解递归的重要方式
  - Base Case：递归主体以一个基本情况开始，通常它是这个条件语句，定义了函数对最简单的输入的行为，并通常被用作递归结束的出口。
  - Recursive Calls：在Base Case之后，是一个或多个递归调用。递归调用总是有一个特点：它们简化了原来的问题。
  - 数学归纳法理解：
    1. 验证递归函数`F(X)`取Base Case时成立.
    2. 假设X = n时成立，那么可以推导出在X = n+1时递归函数`F(X)`做出正确的行为。
    3. 最后一步总结表述。

- 数字拆分

  - 正整数n的拆分（以m大小的拆分）是n可以按递增顺序表示为m以下的正整数部分之和的方式的数目。举个例子——正整数6以4拆分的个数为：

    1. `6 = 2 + 4`

    2. `6 = 1 + 1 + 4`

    3. `6 = 3 + 3`

    4. `6 = 1 + 2 + 3`

    5. `6 = 1 + 1 + 1 + 3`

    6. `6 = 2 + 2 + 2`

    7. `6 = 1 + 1 + 2 + 2`

    8. `6 = 1 + 1 + 1 + 1 + 2`

    9. `6 = 1 + 1 + 1 + 1 + 1 + 1`

  - 实现一个递归函数`int count_partitions(int n, int m)`打印n使用m拆分的个数。

  - 该函数有一个简单的解决方案作为树递归函数，基于以下观察：

    使用不超过 m 的整数划分 n 的方法个数等于：

    - 使用m划分n-m的方法个数，以及
    - 使用m-1划分n的方法个数。

- 完成文件`main.c`中的`count_partitions`函数编写。