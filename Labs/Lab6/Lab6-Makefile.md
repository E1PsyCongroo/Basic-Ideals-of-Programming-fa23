# Lab6-Makefile

> 本实验取自 [CMU 15-213 CSAPP](https://www.cs.cmu.edu/~213/index.html)

## 获取实验文件

要解压tar文件，请键入: `tar -xf lab6-Makefile.tar`

### 查阅更多关于tar的使用

```bash
man tar
tldr tar
```

## 第一部分：编译步骤演练

浏览 lab6.c 和 lab6_helper.c 中的代码。

1. 使用 -E 标志编译 lab6.c。将内容放入 .txt 文件中
   - `gcc -E lab6.c > pre_processor.txt`
   - 记下 lab6.c 的实际代码如何变化（滚动到文本文件的底部以查看代码！）

2. 使用 -S 标志分别编译 lab6.c 和 lab6_helper.c
   - `gcc -S lab6.c`
   - `gcc -S lab6_helper.c`
   - 查看生成的程序集文件。不需要理解代码的含义。
3. 使用 -c 标志分别编译 lab6.s 和 lab6_helper.s。
   - `gcc -c lab6.s`
   - `gcc -c lab6_helper.s`
   - 使用 `xxd [file].o | less` 查看新生成的 .o 文件的代码。你能读一下吗？
   - 查看实际的机器码并将内容放在.txt文件中查看，使用`objdump -s lab6.o > objdumplab6.txt`
     - 你还可以通过以下方式查看汇编代码的机器代码: `objdump -sdr lab6.o`
4. 使用 -o 标志将 lab6.o 和 lab6_helper.o 一起编译，将输出文件重命名为 lab6。
   - `gcc -o lab6 lab6.o lab6_helper.o`
   - 查看新生成的可执行文件的代码，然后运行它看看会发生什么！
5. 使用 -o 标志将 lab6.c 和 lab6_helper.c 一起编译，将输出文件重命名为 lab6。
   - `gcc -o lab6 lab6.c lab6_helper.c`
   - 并不总是需要分步编译代码！

## 可视化优化级别

现在，让我们尝试了解优化标志之间的差异：-O0、-O1、-O2、-O3 和 -Os。优化级别将向你显示不同的结果，并且代码的某些部分将发生变化，但你现在不必了解发生了什么。使用每个标志编译 lab6.c 和 lab6_helper.c。按照下面的命令格式创建不同的可执行文件将很有帮助。

### 任务1

接下来，使用 `objdump -d [NameOfExecutable]` 查看可执行文件的汇编代码。将 objdump 的输出放入 .txt 文件可能是最简单的方法。请注意有关程序集文件差异的总体观察结果。如果你愿意，你可以使用： `diff [file1] [file2]` 在控制台中打印两个文件之间的差异。如果你有时间，请随意尝试假设差异的原因。你不需要了解汇编代码在做什么。例如，按以下顺序运行这些命令：

```bash
gcc -O0 lab6.c lab6_helper.c -o optimization0
objdump -d optimization0 > optimization0.txt
```

请记住对 -O1、-O2、-O3、-Os 标志重复这些步骤！

### 任务2

利用字数统计来比较所有优化文件之间的差异: `wc optimizationX.txt`
输出应是如下格式: `LineCount WordCount Bytes Filename`

运行不同优化等级的可执行文件。
可执行文件输出的最后两行包含以下信息：

```bash
Clock ticks: [NUM]
Time in seconds taken by CPU: [NUM]
```

该信息代表不同形式的执行时间。对于不同优化级别的时间安排，你注意到什么？

## 第二部分：修改Makefile

正如讲座中提到的，Makefile 只是一个规则集，其中包含计算机执行的步骤列表。第 2 部分的目标是修改 Makefile。阅读并完成文件中的 // TODO。完成后，运行 `make`。如果你尝试运行特定目标，可以键入 `make [NameOfTarget]`。

此 Makefile 的目的是了解如何使用 Makefile 来遵循编译可执行文件所执行的相同步骤。有一些注释描述了每条规则的作用。通常，你不会在 Makefile 中包含所有编译步骤，而只需包含将所有内容编译在一起的最后一个目标！
