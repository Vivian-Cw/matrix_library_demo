#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>//用于输入输出操作
#include <vector>//使用向量容器存储矩阵数据
#include <stdexcept>//提供标准异常类

//自定义异常类，自定义异常类MatrixException，继承自标准异常类std::exception
class MatrixException : public std::exception {
private:
    std::string message;//包含一个私有成员message用于存储错误信息
public:
    MatrixException(const std::string& msg) : message(msg) {}
    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};

class Matrix {
private:
    size_t rows;
    size_t cols;
    std::vector<std::vector<double>> data;//存储矩阵数据的二维向量data

public:
    // 构造函数系列
    Matrix();//默认构造函数，创建一个0x0的矩阵
    Matrix(size_t rows, size_t cols);//给定行和列，创建一个全0矩阵
    Matrix(size_t rows, size_t cols, double value);//给定行、列和初始值，创建矩阵
    Matrix(const std::vector<std::vector<double>>& vec);//用给定的二维向量初始化矩阵
    Matrix(const Matrix& other);//拷贝构造函数
    
    // 运算符重载
    Matrix operator+(const Matrix& other) const;//矩阵加法，返回一个新的矩阵
    Matrix operator*(const Matrix& other) const;//矩阵乘法，返回一个新的矩阵
    Matrix& operator=(const Matrix& other);//赋值运算符，将另一个矩阵赋值给当前矩阵
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);//输出运算符，用于打印矩阵
    
    // 安全访问：两个重载版本，一个返回可修改的引用，一个返回常量引用。它们会进行边界检查，如果越界则抛出异常。
    double& at(size_t i, size_t j);
    const double& at(size_t i, size_t j) const;
    
    // 维度查询
    size_t getRows() const;//返回行数
    size_t getCols() const;//返回列数
    
    // 工具函数
    bool isSameDimension(const Matrix& other) const;//检查两个矩阵是否维度相同
    bool canMultiply(const Matrix& other) const;//检查两个矩阵是否可以相乘（第一个矩阵的列数等于第二个矩阵的行数）
};

#endif // MATRIX_H，结束头文件保护宏