# Lab4: 简易vector

> 本实验需要提交代码源文件，以及一份简单的设计报告/或以完备的注释代替。

本实验需要实现一个简易的`Vector`（向量）数据结构，它是一个可以动态增长和缩小的数组，能够存放任意类型的数据。为了简化问题，我们只考虑存放整型数据的`Vector`。

本指南会提供可供参考的接口实现，当然，你可以选择自己定义合理的接口。

## Vector

vector数据结构可以用一个结构体来表示，它包含以下属性：

- elements: 一个指向动态分配的数组的指针，用于存放数据元素
- size: vector中当前元素的个数
- capacity: vector中可以容纳的最大元素个数

```C
typedef struct Vector {
    int *elements;    // 指向数组的指针
    size_t size;      // 当前元素个数
    size_t capacity;  // 最大容量
} Vector;
```

## 构造Vector

```C
Vector* Vector_constructor(size_t count, int val);
```

`Vector_constructor`函数将构造并返回一个根据参数`count`和`val`初始化的`Vector`。其元素个数为`count`，所有元素被初始化为`val`。

你需要实现`Vector_constructor`函数的功能，将`count`和`val`传入函数，并根据参数构造并返回一个`Vector`。其中元素个数为`count`，各个元素的值为`val`，你需要考虑`capacity`的值，一般你可以将它设置为2的倍数，你可以选择一个接近`count`并大于它的数将它设为`capacity`。

注意: 你应该使用动态分配的方式构造`Vector`，否则你可能返回一个局部变量，这将导致未定义行为的发生。

注意: 你应该根据`capacity`动态分配你的`elements`。

当`count`为零时，你需要考虑一个默认的容量大小`DEFAULT_CAPACITY`，一般你可以将它设置为2的倍数，例如: 8。

当你完成`Vector_constructor`函数后，应该及时进行单元测试，请编写简单的单元测试测试它。

## 释放Vector

```C
void Vector_destructor(Vector* v);
```

`Vector_destructor`函数将一个`Vector`释放掉，回收其占用的内存空间。

你需要实现`Vector_destructor`函数的功能，将一个`Vector*`指针作为参数传入，并释放其占用的内存空间。

注意: 你不仅需要释放`Vector`的元素`elements`，也需要释放`Vector`。

当你完成`Vector_destructor`函数后，应该及时进行单元测试，请编写简单的单元测试测试它。

## 打印Vector

```C
void Vector_print(Vector* v);
```

你需要实现`Vector_print`函数的功能，将一个`Vector*`指针作为参数传入，并以一定方式打印其中的所有元素。

当你完成`Vector_print`函数后，应该及时进行单元测试，请编写简单的单元测试测试它。

## 向Vector添加元素

```C
void Vector_push_back(Vector* v, int val);
```

`Vector_push_back`函数将一个新元素添加到`Vector`的末尾，并根据需要重新分配内存空间。

你需要实现`Vector_push_back`函数的功能，将一个`Vector`指针和一个新元素`val`作为参数传入，并将新元素添加到`Vector`中。如果`Vector`已满，则需要先扩大其容量（通常你可以选择扩大一倍容量），再添加新元素。

当你完成`Vector_push_back`函数后，应该及时进行单元测试，请编写简单的单元测试测试它。

## 从Vector删除元素

```C
int Vector_pop_back(Vector* v);
```

`Vector_pop_back`函数将`Vector`的最后一个元素删除，并返回该元素的值。

你需要实现`Vector_pop_back`函数的功能，将一个`Vector`指针作为参数传入，并删除其最后一个元素。如果`Vector`为空，则返回0。

当你完成`Vector_pop_back`函数后，应该及时进行单元测试，请编写简单的单元测试测试它。

## 获取Vector中指定位置的元素

```C
int Vector_at(Vector* v, size_t index);
```

`Vector_at`函数根据给定的索引值`index`，返回`Vector`中对应位置的元素值。

你需要实现`Vector_at`函数的功能，将一个`Vector`指针和一个索引值`index`作为参数传入，并返回该索引值对应的元素值。如果索引值超出范围，则返回0。

当你完成`Vector_at`函数后，应该及时进行单元测试，请编写简单的单元测试测试它。

## 修改Vector中指定位置的元素

```C
void Vector_set(Vector* v, size_t index, int val);
```

`Vector_set`函数根据给定的索引值和新元素值，修改`Vector`中对应位置的元素值。

你需要实现`Vector_set`函数的功能，将一个`Vector`指针，一个索引值`index`和一个新元素值`val`作为参数传入，并修改该索引值对应的元素值。如果索引值超出范围，则不做任何操作。

当你完成`Vector_set`函数后，应该及时进行单元测试，请编写简单的单元测试测试它。

## Vector元素访问

```C
int* Vector_data(Vector* v);
size_t Vector_size(Vector* v);
size_t Vector_capacity(Vector* v);
```

为统一接口，你需要以函数形式实现对`Vector`中元素的访问。

`Vector_data`返回`Vector->elements`。
`Vector_size`返回`Vector->size`。
`Vector_capacity`返回`Vector->capacity`。

## Vector大小修改

```C
void Vector_resize(vector* v, size_t new_size, int val);
```

`Vector_resize`函数调整`Vector`的大小，以包含`new_size`个元素，并根据需要重新分配内存空间。

你需要实现`Vector_resize`函数的功能，将一个`Vector`指针、一个新大小和一个默认元素值`val`作为参数传入，将`Vector`大小实现为`new_size`并根据需要在末尾添加默认元素值。

如果当前`size`大于`new_size`，则`Vector`将缩小到`new_size`个元素。

如果当前`size`小于`new_size`，根据需要重新分配容量，并添加值为`val`的元素至`Vector`末尾，直到大小匹配。

当你完成`Vector_resize`函数后，应该及时进行单元测试，请编写简单的单元测试测试它。

## 帮助函数

为了简化实现，你可以实现一些帮助函数，例如用于将`Vector`容量扩大一倍的函数等。

## 可选

实现一个泛型的`Vector`，使其可以成为任意类型的动态数组，所有元素为同一类型。
这是一个可供参考的实现:

```C
typedef struct Vector {
    void* elements;
    size_t size;
    size_t elem_size;
    size_t capacity;
} Vector;
```
