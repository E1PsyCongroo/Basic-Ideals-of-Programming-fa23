# Lab6-Debug

> 本实验取自 [UCB-CS61C Lab2](https://cs61c.org/fa23/)

## 获取实验文件

要解压tar文件，请键入: `tar -xf lab6-Debug.tar`

### 查阅更多关于tar的使用

```bash
man tar
tldr tar
```

## 练习 1：编译器警告和错误

生成编译器警告是为了帮助你查找代码中的潜在错误。请确保在尝试运行代码之前修复所有编译器警告。这将为你节省大量调试时间，因为修复编译器警告比尝试自己查找错误要快得多。

1. **仔细阅读** 中的代码 `ex1_compiler_warnings.c`

2. 使用 `gcc -o ex1_compiler_warnings ex1_compiler_warnings.c` **编译程序**你应该会看到 3 条警告。

3. **阅读**第一个警告的第一行。该行以 `ex1_compiler_warnings.c:13:22` 开头，它告诉你警告是由 `ex1_compiler_warnings.c` 的第 13 行引起的。该警告表明程序正在尝试将 `char` 分配给 `char *` 。

4. **打开** `ex1_compiler_warnings.c` 并导航到导致警告的行。它试图将 `char` 分配给 `char *` 。编译器指出这是一个潜在的错误，因为我们不应该将 `char` 分配给 `char *` 。

5. **修复**此编译器警告。

6. **重新编译**代码。现在，你可以看到此警告不再出现，并且还剩下 2 个警告。

7. **修复** `ex1_compiler_warnings.c` 中的其余编译器警告。

## 什么是GDB？

以下是[GDB网站](https://www.gnu.org/software/gdb/)的摘录：

GDB，GNU工程调试器 (GNU Project debugger)，允许你看到另一个程序在执行时“内部”发生了什么，或者另一个程序在崩溃的那一刻在做什么。

GDB 可以做四种主要的事情（以及支持这些事情的其他事情）来帮助你捕获行为中的错误：

- 启动程序，指定可能影响其行为的任何内容。
- 使程序在指定条件下停止。
- 检查程序停止时发生了什么。
- 更改程序中的内容，以便你可以尝试纠正一个错误的影响，并继续了解另一个错误。

在本实验中，我们将使用 [CGDB](https://cgdb.github.io/)，它为 gdb 提供了一个轻量级接口，使其更易于使用。CGDB 已安装在此服务器上，因此无需安装。

这是一张 [GDB 参考卡](https://inst.eecS.berkeley.edu/%7Ecs61c/resources/gdb5-refcard.pdf)。

如果遇到 GDB 的任何问题，请参阅[下面的“常见 GDB 错误”部分](#常见的-gdb-错误)

## 练习 2：GDB 简介

在本节中，你将学习 GDB 命令 `start`、`step`、`next`、`finish`、`print`、`quit` 。本节将解决一路上的错误。在继续之前，请确保修复代码中的错误。

下表是上述命令的摘要

|命令|缩写|描述|
|---|---|---|
|start|无|开始运行程序并在 `main` 的第 1 行停止|
|step|s|执行当前代码行（此命令将单步执行函数）|
|next|n|执行当前代码行（此命令不会单步执行函数）|
|finish|fin|执行当前函数的其余部分并返回到调用函数|
|print|p|打印参数的值|
|quit|q|退出 GDB|

你应该用相应的命令填写 `ex2_commands.txt` 。请仅使用上表中的命令。为了确保正确性，我们将根据所需的输出检查 `ex2_commands.txt` 的输出。我们建议打开两个窗口，以便你可以同时拥有命令文件和 cgdb 会话。

1. 使用 `-g` 标志编译你的程序。这将包括 CGDB 所需的可执行文件中的附加调试信息。

    ```bash
    gcc -g -o pwd_checker test_pwd_checker.c pwd_checker.c
    ```

2. 开始 cgdb 。请注意，你应该使用可执行文件 ( `pwd_checker` ) 作为参数，而不是源文件 ( `pwd_checker.c` )。

    ```bash
    cgdb pwd_checker
    ```

    现在应该看到 CGDB 已打开。顶部窗口显示我们的代码，底部窗口显示控制台。

对于以下每个步骤，将你执行的 CGDB 命令添加到 `ex2_commands.txt` 。每个命令都应该独占一行。下面的每一步都需要一个或多个 CGDB 命令。

1. 从 `main` 中的第一行**启动**程序。提示：此命令应在第 1 行设置断点并开始运行程序。

2. `main` 中的第一行是对 printf 的调用。我们不想进入这个函数。**越过**程序中的这一行。

3. **单步执行**，直到程序处于 `check_password` 调用状态。请注意，旁边带有箭头的行是我们当前所在的行，但尚未执行。

4. **步入** `check_password`。

5. **步入** `check_lower`。

6. **打印** `password` 的值（ `password` 是一个字符串）。

7. **结束** `check_lower` 。在函数返回之前不要单步执行。

8. **步入** `check_length`。

9. **单步执行**到函数的最后一行。

10. **打印**函数的返回值。返回值应为 `false`。

11. **打印** `length` 的值。看起来 `length` 是正确的，所以第24行肯定有一些逻辑问题。

12. **退出** CGDB。 CGDB 可能会询问是否要退出，请输入 y （但不要将 y 添加到 `ex2_commands.txt` ）。

此时，你的 `ex2_commands.txt` 应包含上述步骤中的命令列表。你无需将以下步骤中的任何内容添加到你的 `ex2_commands.txt` 中。

1. **修复**第 24 行的 bug。

2. **编译**并**运行**代码。

3. 程序仍然有误。再次打开并单步执行 cgdb ，你应该看到 `check_number` 现在失败。我们将在下一个练习中解决这个问题。

## 练习 3：更多 GDB

在本节中，你将学习 gdb 命令 `break` 、 `conditional break` 、 `run` 和 `continue` 。本节将解决一路上的错误。在继续之前，请确保修复代码中的错误。

下表是上述命令的摘要

|命令|缩写|描述|
|---|---|---|
|break [line num or function name]|b|在指定位置设置断点，使用 `filename.c:linenum` 在特定文件中设置断点|
|conditional break (ex: break 3 if n==4)|(ex: b 3 if n==4)|仅当满足给定条件时，才在指定位置设置断点|
|run|r|执行程序，直到终止或到达断点|
|continue|c|继续执行已暂停的程序|

你应该用相应的命令填写 `ex3_commands.txt` 。请仅使用上表和练习 2 中的表中的命令。为了确保正确性，我们将根据所需的输出检查 `ex3_commands.txt` 的输出。我们建议打开两个窗口，以便你可以同时拥有命令文件和 cgdb 会话。

1. **重新编译并运行**代码。你应该看到断言`number`失败

2. **启动** cgdb

    ```bash
    cgdb pwd_checker
    ```

对于以下每个步骤，将你执行的 CGDB 命令添加到 `ex3_commands.txt` 。每个命令都应该独占一行。下面的每一步都需要一个或多个 CGDB 命令。

1. 在我们的代码中**设置一个断点**以直接跳转到函数 `check_number` 。你的断点不应位于 `check_password` 中。

2. **运行**程序。你的代码应该运行直到到达我们刚刚设置的断点。

3. **步入** `check_range`。

4. 请记住，这些数字直到稍后才出现在密码中。我们可以直接跳转到代码中使用条件断点比较数字的位置，而不是单步执行密码开头的所有非数字字符。条件断点只会根据给定条件停止程序。密码中的第一个数字 `0` ，因此我们可以在 `letter` 为 `'0'` 时设置断点。**如果 `letter` 是 `'0'` ，则在第 31 行中断**。
    我们使用单引号，因为`0`是一个字符。

5. 在断点处停止后**继续执行**代码。。

6. 代码已在条件断点处停止。要验证这一点，请**打印** `letter`。
    它应该打印 `48`。

7. 我们看一下 `check_range` 的返回值。打印 `is_in_range` 。结果是 `false` 。真奇怪。 `'0'` 应该在范围内。

8. 让我们看看范围的上限和下限。**打印** `lower` 。

9. **打印** `upper`。

10. 啊啊！ `lower` 的 ASCII 表示为 `\000` （空终止符）， `upper` 的 ASCII 表示为 `\t` 。看起来我们传入了数字 0 和 9 而不是字符 '0' 和 '9' ！

11. 退出 CGDB。 CGDB 可能会询问你是否要退出，请输入 y （但不要将 y 添加到 `ex3_commands.txt` ）。

此时，你的 `ex3_commands.txt` 应包含上述步骤中的命令列表。你无需将以下步骤中的任何内容添加到你的 `ex3_commands.txt` 中。

1. **修复** bug。

2. **编译**并**运行**代码。还有一个错误，你将在[练习 4](#练习-4调试) 中找到该错误。

## 练习 4：调试

1. 使用你刚刚学到的命令自行调试 `check_upper` 。即使有大写字母，该函数似乎也会返回 `false` 。提示：错误本身可能不在 `check_upper` 本身中。

## Valgrind

即使使用调试器，我们也可能无法捕获所有错误。有些错误就是我们所说的“bohrbug”，这意味着它们在明确定义但可能未知的条件下可靠地表现出来。其他错误就是我们所说的“heisenbug”，它们不是决定性的，而是在人们试图研究它们时消失或改变其行为。我们可以使用调试器检测第一种类型，但第二种类型可能会被我们忽视，因为它们（至少在 C 语言中）通常是由于内存管理不当造成的。请记住，与其他编程语言不同，C 要求你（程序员）手动管理内存。

我们可以使用一个叫Valgrind的工具来帮助捕获“heisenbugs”和“bohrbugs”。 Valgrind 是一个模拟 CPU 并跟踪内存访问的程序。这会减慢你正在运行的进程的速度（例如，这就是为什么我们不总是在 Valgrind 内运行所有可执行文件的原因），但也可能会暴露一些错误，这些错误可能是仅在一组独特的情况下可见的不正确行为。

我们来看看 `bork` 翻译程序吧！博克语是一种与英语非常相似的古老语言。要将单词翻译为 Bork，你需要获取英语单词并在单词中的每个元音后面添加“f”。

让我们看看我们是否能理解一些Bork。使用以下命令编译并运行 `bork` 。

```bash
gcc -g -o bork bork.c
./bork hello
```

下面提供了一个示例输出。请注意，你的输出可能看起来会有所不同。

```txt
Input string: "hello"
Length of translated string: 21
Translate to Bork: "hefl2?^?Ul2?^?Uof?^?U"
```

嗯，Bork 是一种古老的语言，但不应该有这些奇怪的字符。看来古人在他们的程序中留下了一些bug！我们要踏上消灭bug并发现Bork真正美丽的旅程。

如果我们快速浏览一下 `main` ，我们可以看到我们正在获取一个输入字符串 ( `src_str` ) 并将其转换为 Bork ( `dest_str` )。如果我们滚动到顶部，我们可以看到我们有一个函数（ `alloc_str` ）来为堆中的字符串分配空间，这是一个包含字符串及其长度的 `Str` 结构体，一个 `make_str` 函数，它将创建一个 `Str` 结构体并初始化其 `data` 和 `len` 字段，以及一个用于释放结构体数据的函数。还有一个将两个字符串连接在一起的函数和另一个将字母翻译为 Bork 的函数。这是一个需要调试的相当长的程序。

如果有一个工具可以为我们提供一个良好的第一查看位置，那不是很好吗？

事实证明，valgrind 就是其中之一！

让我们使用以下命令在我们的程序上运行 `valgrind`。

```bash
valgrind ./bork hello
```

```bash
==10170== Memcheck, a memory error detector
==10170== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==10170== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==10170== Command: ./bork hello
==10170==
==10170== Invalid read of size 1
==10170==    at 0x4C34D04: strlen (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==10170==    by 0x10879F: make_Str (bork.c:22)
==10170==    by 0x108978: translate_to_bork (bork.c:56)
==10170==    by 0x1089F2: main (bork.c:68)
==10170==  Address 0x522f041 is 0 bytes after a block of size 1 alloc'd
==10170==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==10170==    by 0x108781: alloc_str (bork.c:10)
==10170==    by 0x10895E: translate_to_bork (bork.c:54)
==10170==    by 0x1089F2: main (bork.c:68)
==10170==
==10170== Invalid read of size 1
==10170==    at 0x4C34D04: strlen (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==10170==    by 0x10879F: make_Str (bork.c:22)
==10170==    by 0x108952: translate_to_bork (bork.c:51)
==10170==    by 0x1089F2: main (bork.c:68)
==10170==  Address 0x522f0e2 is 0 bytes after a block of size 2 alloc'd
==10170==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==10170==    by 0x108781: alloc_str (bork.c:10)
==10170==    by 0x10892D: translate_to_bork (bork.c:48)
==10170==    by 0x1089F2: main (bork.c:68)
==10170==
Input string: "hello"
Length of translated string: 7
==10170== Invalid read of size 1
==10170==    at 0x4C34D04: strlen (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==10170==    by 0x4E9B4A2: vfprintf (vfprintf.c:1643)
==10170==    by 0x4EA2EE5: printf (printf.c:33)
==10170==    by 0x108A6F: main (bork.c:74)
==10170==  Address 0x522f317 is 0 bytes after a block of size 7 alloc'd
==10170==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==10170==    by 0x108781: alloc_str (bork.c:10)
==10170==    by 0x108833: concat (bork.c:32)
==10170==    by 0x108A15: main (bork.c:69)
==10170==
Translate to Bork: "hefllof"
==10170==
==10170== HEAP SUMMARY:
==10170==     in use at exit: 7 bytes in 1 blocks
==10170==   total heap usage: 11 allocs, 10 frees, 1,051 bytes allocated
==10170==
==10170== LEAK SUMMARY:
==10170==    definitely lost: 7 bytes in 1 blocks
==10170==    indirectly lost: 0 bytes in 0 blocks
==10170==      possibly lost: 0 bytes in 0 blocks
==10170==    still reachable: 0 bytes in 0 blocks
==10170==         suppressed: 0 bytes in 0 blocks
==10170== Rerun with --leak-check=full to see details of leaked memory
==10170==
==10170== For counts of detected and suppressed errors, rerun with: -v
==10170== ERROR SUMMARY: 6 errors from 3 contexts (suppressed: 0 from 0)
```

（有趣的旁注：当我们查看这个 valgrind 日志中的正常程序输出时，我们看到正常行为（即它打印“hefllof”）。这是因为 valgrind 运行我们的程序的方式与我们的程序“自然”运行的方式不同（又名“裸机”）。我们现在不打算讨论这个问题。）

但回到调试：解析大型错误日志时要遵循的一个很好的一般经验法则是只考虑第一条错误消息（并忽略其余的），因此让我们这样做：

```txt
==10170== Invalid read of size 1
==10170==    at 0x4C34D04: strlen (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==10170==    by 0x10879F: make_Str (bork.c:22)
==10170==    by 0x108978: translate_to_bork (bork.c:56)
==10170==    by 0x1089F2: main (bork.c:68)
```

错误消息指出我们正在执行大小为 1 的无效读取。这是什么意思？无效读取意味着你的程序正在不应该读取的位置读取内存（这可能会导致段错误，但并非总是如此）。 Size 1 意味着我们试图读取 1 个字节。

因为我们不熟悉这个古老的代码库，并且我们不想阅读所有代码来查找错误，所以遵循的一个好的流程是从高级细节开始，然后逐步深入（所以基本上我们的方式是通过valgrind 提供的调用堆栈）。

让我们看看 `bork.c` 中在 `main` 第 68 行（堆栈的底部）：

```c
Str bork_substr = translate_to_bork(src_str.data[i]);
```

这里发生了什么奇怪的事情吗？看起来我们只是将一个字符传递给 `translate_to_bork` 。到目前为止看起来还不错。

让我们进一步深入调用堆栈并查看 `bork.c` 中的 `translate_to_bork` 第 56 行：

```c
return make_Str(res);
```

我们只是在这里调用 `make_Str` 。我们应该更深入。让我们看一下 `bork.c` 第 22 行。

```c
return (Str){.data=str,.len=strlen(str)};
```

在这里，我们创建一个新的 `Str` 结构并设置其 `data` 和 `len` 参数。这看起来也很正常啊！

但是 valgrind 说 `strlen` 正在执行无效读取？

好吧，我们正在向它传递一个字符串，对吗？ `strlen` 又做了什么？它通过迭代每个字符直到到达空终止符来确定字符串的长度。也许没有空终止符，因此 `strlen` 不断超出字符串的末尾（这意味着它超出了我们为字符串分配的区域）。

让我们通过检查创建字符串的位置来确保字符串具有空终止符。

早些时候，我们在 `translate_to_bork` 第 56 行看到了这一点。

```c
return make_Str(res);
```

如果我们向上查看两行（第 54 行），我们可以看到我们正在通过调用 `alloc_str` 为字符串分配空间。我们来看看这个函数。

```c
char *alloc_str(int len) {
    return malloc(len*sizeof(char));
}
```

嗯。看起来 `alloc_str` 给了我们一些只有 `len` 大的内存，这意味着当我们写入 `translate_to_bork` 中的字符串时，我们没有足够的空间对于空终止符！

让我们进行以下更改来解决问题：

```diff
10c10,12
<     return malloc(len*sizeof(char));
---
>     char *data = malloc((len+1)*sizeof(char));
>     data[len] = '\0';
>     return data;
```

让我们运行我们的程序，看看我们是否解决了问题

```bash
./bork hello
```

```txt
Input string: "hello"
Length of translated string: 7
Translate to Bork: "hefllof"
```

一切看起来都工作正常。但是，可能存在我们看不到的隐藏错误，因此让我们通过 valgrind 运行我们的代码，以确保没有潜在的问题。

```bash
valgrind ./bork hello
```

```txt
==29797== Memcheck, a memory error detector
==29797== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==29797== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==29797== Command: ./bork hello
==29797==
Input string: "hello"
Length of translated string: 7
Translate to Bork: "hefllof"
==29797==
==29797== HEAP SUMMARY:
==29797==     in use at exit: 8 bytes in 1 blocks
==29797==   total heap usage: 11 allocs, 10 frees, 1,061 bytes allocated
==29797==
==29797== LEAK SUMMARY:
==29797==    definitely lost: 8 bytes in 1 blocks
==29797==    indirectly lost: 0 bytes in 0 blocks
==29797==      possibly lost: 0 bytes in 0 blocks
==29797==    still reachable: 0 bytes in 0 blocks
==29797==         suppressed: 0 bytes in 0 blocks
==29797== Rerun with --leak-check=full to see details of leaked memory
==29797==
==29797== For counts of detected and suppressed errors, rerun with: -v
==29797== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

让我们看一下下面的堆摘要。它告诉我们在退出时分配了 1 个块中的 8 个字节。这意味着堆中未释放的内存源自一次分配调用，并且大小为 8 个字节。

接下来，我们可以看到堆摘要，该摘要显示我们在程序的生命周期内进行了 11 次分配调用和 10 次释放。

```txt
==29797== HEAP SUMMARY:
==29797==     in use at exit: 8 bytes in 1 blocks
==29797==   total heap usage: 11 allocs, 10 frees, 1,061 bytes allocated
```

现在让我们看一下下面的泄漏摘要。这只是表明我们在 1 个块中丢失了 8 个字节。

```txt
==29797== LEAK SUMMARY:
==29797==    definitely lost: 8 bytes in 1 blocks
==29797==    indirectly lost: 0 bytes in 0 blocks
==29797==      possibly lost: 0 bytes in 0 blocks
==29797==    still reachable: 0 bytes in 0 blocks
==29797==         suppressed: 0 bytes in 0 blocks
==29797== Rerun with --leak-check=full to see details of leaked memory
```

它告诉我们“使用 `--leak-check=full` 重新运行以查看泄漏内存的详细信息”，所以让我们这样做。

```bash
valgrind --leak-check=full ./bork hello
```

```txt
==32334== Memcheck, a memory error detector
==32334== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==32334== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==32334== Command: ./bork hello
==32334==
Input string: "hello"
Length of translated string: 7
Translate to Bork: "hefllof"
==32334==
==32334== HEAP SUMMARY:
==32334==     in use at exit: 8 bytes in 1 blocks
==32334==   total heap usage: 11 allocs, 10 frees, 1,061 bytes allocated
==32334==
==32334== 8 bytes in 1 blocks are definitely lost in loss record 1 of 1
==32334==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==32334==    by 0x108784: alloc_str (in /home/cc/cs61c/fa22/staff/cs61c-tac/bork)
==32334==    by 0x10884E: concat (in /home/cc/cs61c/fa22/staff/cs61c-tac/bork)
==32334==    by 0x108A30: main (in /home/cc/cs61c/fa22/staff/cs61c-tac/bork)
==32334==
==32334== LEAK SUMMARY:
==32334==    definitely lost: 8 bytes in 1 blocks
==32334==    indirectly lost: 0 bytes in 0 blocks
==32334==      possibly lost: 0 bytes in 0 blocks
==32334==    still reachable: 0 bytes in 0 blocks
==32334==         suppressed: 0 bytes in 0 blocks
==32334==
==32334== For counts of detected and suppressed errors, rerun with: -v
==32334== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```

现在 Valgrind 告诉我们未释放块最初分配的位置。下面我们就来看看这个。如果我们跟踪调用堆栈，我们可以看到 `malloc` 被 `alloc_str` 调用，而 `alloc_str` 又被 `main` 中的 `concat` 调用。

```txt
==32334== 8 bytes in 1 blocks are definitely lost in loss record 1 of 1
==32334==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==32334==    by 0x108784: alloc_str (in /home/cc/cs61c/fa22/staff/cs61c-tac/bork)
==32334==    by 0x10884E: concat (in /home/cc/cs61c/fa22/staff/cs61c-tac/bork)
==32334==    by 0x108A30: main (in /home/cc/cs61c/fa22/staff/cs61c-tac/bork)
```

如果我们查看 `main` ，我们可以看到我们通过调用 `concat` 为 `dest_str` 分配了空间，但我们从未释放它。我们需要 `dest_str` 直到程序结束，所以让我们在从 `main` 返回之前释放它。该结构体已在 `main` ( `Str dest_str={};` ) 中的栈上分配，因此我们不需要释放该结构体本身。但是，结构体指向的数据是在堆中分配的。因此，我们只需要释放结构体的这一部分。如果你查看程序顶部附近，我们已经提供了一个函数 `free_Str` 来释放结构体的已分配部分。让我们在程序末尾调用这个函数。

```diff
76a77
>     free_Str(dest_str);
```

你可能想知道为什么我们不释放 `src_str` 。如果我们看一下构建 `src_str` ( `Str src_str = make_Str(argv[1]);` ) 的位置，我们可以看到它是使用 `make_str` 创建的，它不会进行任何分配空间在堆上的调用。我们用来制作 `src_str` 的字符串来自 `argv[1]` 。调用 `main` 的程序负责设置 `argv[1]` ，所以我们不必担心它。

一旦我们修复了错误，valgrind 输出应该如下所示。堆摘要显示我们退出时没有分配任何块。底部的错误摘要向我们表明没有需要报告的错误。

```bash
valgrind ./bork hello
```

```txt
==10835== Memcheck, a memory error detector
==10835== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==10835== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==10835== Command: ./bork hello
==10835==
Input string: "hello"
Length of translated string: 7
Translate to Bork: "hefllof"
==10835==
==10835== HEAP SUMMARY:
==10835==     in use at exit: 0 bytes in 0 blocks
==10835==   total heap usage: 11 allocs, 11 frees, 1,061 bytes allocated
==10835==
==10835== All heap blocks were freed -- no leaks are possible
==10835==
==10835== For counts of detected and suppressed errors, rerun with: -v
==10835== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

## 练习 5：使用 Valgrind 查找段错误

`ex5_valgrind` 中有一个错误，让我们看看如何使用 valgrind 检测它。

1. **编译** `ex5_valgrind.c` 。请注意，没有编译器错误或警告，并且我们使用 -g 标志，以防将来需要调试该程序。

    ```bash
    gcc -g -o ex5_valgrind ex5_valgrind.c
    ```

2. **运行** `ex5_valgrind` 。请注意，该程序不会引发任何错误。

3. 在 `valgrind` 上运行 `ex5_valgrind` 。你应该看到有 2 个错误。

4. 仔细**阅读** valgrind 输出。在 `ex5_answers.txt` 中，回答以下问题。请不要更改文件的格式。对于问题 1 到 7，我们指的是第一个 valgrind 错误（无效写入错误）。

    1. 无效写入有多少字节？（答案应该是一个没有任何单位的数字）
    2. 哪个函数导致了无效写入？（答案应该是函数的名称）
    3. 哪个函数调用了问题 2 的答案？（答案应该是函数的名称）
    4. 调用发生在哪个文件中？（答案应该是文件的名称）
    5. 呼叫发生在哪条线路上？（答案应该是一个数字）
    6. 实际分配了多少字节？（答案应该是一个没有任何单位的数字）
    7. 应该分配多少字节？请随意阅读代码。（答案应该是一个没有任何单位的数字）
    8. 是否有任何内存泄漏？（答案应为“是”或“否”）
    9. 泄露了多少字节？如果没有内存泄漏，则写入 0。（答案应该是一个没有任何单位的数字）

## 练习 6：内存管理

本练习使用 `ex6_vector.h` 、 `ex6_test_vector.c` 和 `ex6_vector.c` ，我们为你提供了一个用于实现可变长度数组的框架。本练习旨在帮助你熟悉 C 结构和 C 中的内存管理。

1. 尝试**解释**为什么 `bad_vector_new()` 不好。我们在这里提供了原因，以便验证你的理解

    > bad_vector_new（）
    > 向量是在栈上创建的，而不是在堆上。一旦该函数完成运行，存储在栈上的所有内存都会被释放，因此当函数返回时，我们会丢失我们构造的向量。

2. 在 `ex6_vector.c` 中填写函数 `vector_new()` 、 `vector_get()` 、 `vector_delete()` 和 `vector_set()` ，以便我们的测试代码运行时没有任何内存管理错误。
    代码中的注释描述了函数应该如何工作。查看我们填写的函数，了解应如何使用数据结构。为了保持一致性，除非用户设置，否则假设向量中的所有条目均为 0。请记住这一点，因为 `malloc()` 不会将其分配的内存清零。如果传入的索引大于数组的大小， `vector_set` 应调整数组的大小。

3. **测试** `vector_new()` 、 `vector_get()` 、 `vector_delete()` 和 `vector_set()` 的实现是否正确。

    ```bash
    gcc -g -o ex6_vector ex6_vector.c ex6_test_vector.c
    ./ex6_vector
    ```

4. **测试**内存管理的 `vector_new()` 、 `vector_get()` 、 `vector_delete()` 和 `vector_set()` 的实现。

    ```bash
    valgrind ./ex6_vector
    ```

任何数量的禁止显示的错误都可以;它们不会影响我们。

你也可以随意使用 CGDB 来调试代码。

## 常见的 GDB 错误

### GDB is skipping over lines of code

这可能意味着你的源文件比可执行文件更新。退出 GDB，使用 `-g` 标志重新编译代码，然后重新启动 gdb。

### GDB isn't loading my file

你可能会看到类似这样的错误“not in executable format: file format not recognized”或“No symbol table loaded. Use the "file" command.”

这意味着你在源文件（以 `.c` 结尾的文件）而不是可执行文件上调用了 gdb。退出 GDB 并确保使用可执行文件调用它。

### 如何在代码窗口和控制台之间切换？

CGDB 提供了一个类似 vim 的导航界面：按键盘上的按钮`i`可从代码窗口切换到控制台。按下`ESC`可从控制台切换到代码窗口。

GDB 提供了一个类似 readline/emacs 的导航界面：按 `ctrl + x` 然后在窗口之间切换。

### 我被困在代码窗口中

按键盘上的`i`。这应该会让你返回控制台。

### 文本 UI 出现乱码

按 `ctrl + l` 刷新 GDB 文本 UI。

---

## 其他有用的 GDB 命令（推荐）

### 命令：`info locals`

打印当前堆栈帧中所有局部变量的值

### 命令：`command`

每次到达断点时执行命令列表。例如：

设置断点：

```txt
b 73
```

键入后跟断点编号：`commands`

```txt
commands 1
```

键入要执行的命令列表，并用新行分隔。在命令列表后，输入 `end` 并按下 `Enter` 。

```txt
p var1
p var2
end
```
