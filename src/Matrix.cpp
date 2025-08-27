#include "Matrix.h"
#include <iostream>
#include <sstream>

using namespace std;

// 默认构造函数
Matrix::Matrix() : rows(0), cols(0) {}

// 维度构造函数
Matrix::Matrix(size_t rows, size_t cols) : rows(rows), cols(cols) {
    if (rows == 0 || cols == 0) {
        throw MatrixException("Invalid matrix dimensions: rows and cols must be positive");
    }
    data.resize(rows, vector<double>(cols, 0.0));
}

// 初始值构造函数
Matrix::Matrix(size_t rows, size_t cols, double value) : rows(rows), cols(cols) {
    if (rows == 0 || cols == 0) {
        throw MatrixException("Invalid matrix dimensions: rows and cols must be positive");
    }
    data.resize(rows, vector<double>(cols, value));
}

// 向量构造函数
Matrix::Matrix(const vector<vector<double>>& vec) {
    if (vec.empty() || vec[0].empty()) {
        rows = 0;
        cols = 0;
        return;
    }
    
    rows = vec.size();
    cols = vec[0].size();
    
    // 检查所有行是否有相同的列数
    for (const auto& row : vec) {
        if (row.size() != cols) {
            throw MatrixException("Invalid input vector: all rows must have the same number of columns");
        }
    }
    
    data = vec;
}

// 拷贝构造函数
Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols), data(other.data) {}

// 加法运算符重载
Matrix Matrix::operator+(const Matrix& other) const {
    if (!isSameDimension(other)) {
        throw MatrixException("Matrix addition failed: matrices have different dimensions");
    }
    
    Matrix result(rows, cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

// 乘法运算符重载
Matrix Matrix::operator*(const Matrix& other) const {
    if (!canMultiply(other)) {
        throw MatrixException("Matrix multiplication failed: number of columns in first matrix must equal number of rows in second matrix");
    }
    
    Matrix result(rows, other.cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < other.cols; ++j) {
            for (size_t k = 0; k < cols; ++k) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

// 赋值运算符重载
Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        rows = other.rows;
        cols = other.cols;
        data = other.data;
    }
    return *this;
}

// 输出运算符重载
ostream& operator<<(ostream& os, const Matrix& matrix) {
    for (size_t i = 0; i < matrix.rows; ++i) {
        os << "[";
        for (size_t j = 0; j < matrix.cols; ++j) {
            os << matrix.data[i][j];
            if (j < matrix.cols - 1) {
                os << ", ";
            }
        }
        os << "]";
        if (i < matrix.rows - 1) {
            os << "\n";
        }
    }
    return os;
}

// 安全访问（可修改）
double& Matrix::at(size_t i, size_t j) {
    if (i >= rows || j >= cols) {
        stringstream ss;
        ss << "Matrix index out of bounds: (" << i << ", " << j 
           << ") for matrix of size (" << rows << ", " << cols << ")";
        throw MatrixException(ss.str());
    }
    return data[i][j];
}

// 安全访问（只读）
const double& Matrix::at(size_t i, size_t j) const {
    if (i >= rows || j >= cols) {
        stringstream ss;
        ss << "Matrix index out of bounds: (" << i << ", " << j 
           << ") for matrix of size (" << rows << ", " << cols << ")";
        throw MatrixException(ss.str());
    }
    return data[i][j];
}

// 获取行数
size_t Matrix::getRows() const {
    return rows;
}

// 获取列数
size_t Matrix::getCols() const {
    return cols;
}

// 检查是否同维度
bool Matrix::isSameDimension(const Matrix& other) const {
    return rows == other.rows && cols == other.cols;
}

// 检查是否可以相乘
bool Matrix::canMultiply(const Matrix& other) const {
    return cols == other.rows;
}