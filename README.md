# matrix_library_demo
# Matrix类库
一个用 C++ 实现的矩阵运算库，提供完整的矩阵操作功能，包括矩阵创建、基本运算、安全访问和异常处理。

## 功能特性
* 多种构造函数
* 矩阵加法和乘法运算
* 安全边界检查访问
* 维度查询和验证工具
* 自定义异常处理

## 使用示例
**矩阵加法运算**
```
#include "matrix.h"
#include <iostream>

int main() {
    // 创建矩阵
    Matrix m1(2, 3, 1.0); // 2x3 矩阵，所有元素为 1.0
    Matrix m2(2, 3, 2.0); // 2x3 矩阵，所有元素为 2.0
    
    // 矩阵加法
    Matrix m3 = m1 + m2;
    
    // 输出矩阵
    std::cout << "Matrix m3:" << std::endl;
    std::cout << m3 << std::endl;
    
    return 0;
}
```
**测试维度不匹配的加法**
```
#include "matrix.h"
#include <iostream>

int main() {
    Matrix m1(2, 2, 1.0);
    Matrix m2(3, 3, 2.0);
    
    try {
        Matrix m3 = m1 + m2;
    } catch (const MatrixException& e) {
        std::cout << "错误: " << e.what() << endl;
    }

    return 0;
}
```
## 项目结构
```
matrix_library_demo/
├── CMakeLists.txt 
├── include/
│   └── matrix.h
├── src/
│   ├── main.cpp 
│   └── matrix.cpp 
└── README.md
```
## API参考
### 构造函数系列
```
    Matrix(); //默认构造函数，创建一个0x0的矩阵
    Matrix(size_t rows, size_t cols); //给定行和列，创建一个全0矩阵
    Matrix(size_t rows, size_t cols, double value); //给定行、列和初始值，创建矩阵
    Matrix(const std::vector<std::vector<double>>& vec); //用给定的二维向量初始化矩阵
    Matrix(const Matrix& other); //拷贝构造函数
```
### 运算符重载
* `operator+ //矩阵加法`
* `operator* //矩阵乘法`
* `operator= //矩阵赋值`
* `operator<< //输出流操作符`

### 成员函数
* `at(i, j) //安全访问矩阵元素（带边界检查）`
* `getRows() //获取矩阵行数`
* `getCols() //获取矩阵列数`
* `isSameDimension(other) //检查两个矩阵是否同维度`
* `canMultiply(other) //检查两个矩阵是否可以相乘`

## 异常处理
库提供自定义异常类`MatrixException`，继承自`std::exception`，包含详细的错误信息：
* 测试维度不匹配的运算
* 测试越界访问