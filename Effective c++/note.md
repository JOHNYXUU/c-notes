# 第一章 自己习惯c++

## 01、 视c++为一个语言联邦

**C**：区块（blocks）、语句（statements）、预处理器（preprocessor）、内置数据类型（built-in data type）、数组（arrays）、指针（points）来自C

**Object-Oriented C++**：classes（构造、析构函数）、封装、继承、多态、虚函数（动态绑定）

**Template C++**：泛型编程

**STL**：容器（containers）、迭代器（iterators）、算法（algorithms）、函数对象（function objects）

## 02、尽量以 const 、enum 、inline替换#define

字符串类型

```c++
//string 比 const char* 好
const std::string name("xxj");
```

class 内部专属常量

```cpp
class GamePlayer
{
	private:
    	static const int Num = 5; // 声明式
    	// 也可以写成 enum { Num = 5 }; 
    	// enum hack, 不想让别人获得整数常量的地址时，可以使用这种写法，可以防止不必要的内存分配
    	int scores[Num];		  // 使用
}
// 定义式 
// 需要取地址或者编译要求看到定义式  写在 实现文件，声明初值已设置(旧编译器可能不支持声明时给static成员赋初值，则需要在这里赋)
const int GamePlayer::Num;
```

**inline 获得宏的效率的同时，拥有一般函数的所有可预料行为和类型安全性**

```cpp
#define CALL_WITH_MAX(a,b) f((a) > (b) ? (a) : (b))
int a = 5, b = 0;
CALL_WITH_MAX(++a,b); // a 被累加 2 次
CALL_WITH_MAX(++a,b+10); // a 被累加 1 次

//改成inline就不会被这种痛苦折磨了
template<typename T>
inline void callWithMax(const T& a, const T& b)
{
	f(a > b ? a : b);
}
```

**总结**

常量用 const、enum替换

形似函数的宏用 inline替换

## 03、尽可能使用const

