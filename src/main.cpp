#include "Matrix.h"
#include <iostream>
#include <iomanip>

using namespace std;

void testMatrixCreation() {
    cout << "=== 测试矩阵创建 ===" << endl;
    
    // 创建全1矩阵
    Matrix m1(2, 3, 1.0);
    cout << "m1 (2x3, 全1):" << endl;
    cout << "矩阵 " << m1.getRows() << "x" << m1.getCols() << ":" << endl;
    cout << m1 << endl;
    
    // 创建全2矩阵
    Matrix m2(2, 3, 2.0);
    cout << "m2 (2x3, 全2):" << endl;
    cout << "矩阵 " << m2.getRows() << "x" << m2.getCols() << ":" << endl;
    cout << m2 << endl;

}

void testMatrixOperations() {
    cout << "=== 测试矩阵运算 ===" << endl;
    
    // 测试加法
    Matrix m1(2, 2, 1.0);
    Matrix m2(2, 2, 2.0);
    
    cout << "m1:" << endl;
    cout << "矩阵 " << m1.getRows() << "x" << m1.getCols() << ":" << endl;
    cout << m1 << endl;
    
    cout << "m2:" << endl;
    cout << "矩阵 " << m2.getRows() << "x" << m2.getCols() << ":" << endl;
    cout << m2 << endl;
    
    Matrix m3 = m1 + m2;
    cout << "m1 + m2:" << endl;
    cout << "矩阵 " << m3.getRows() << "x" << m3.getCols() << ":" << endl;
    cout << m3 << endl;

}

void testErrorHandling() {
    cout << "=== 测试错误处理 ===" << endl;
    
    // 测试维度不匹配的加法
    Matrix m1(2, 2, 1.0);
    Matrix m2(3, 3, 2.0);
    
    cout << "尝试 m1 + m2 (维度不匹配):" << endl;
    try {
        Matrix m3 = m1 + m2;
    } catch (const MatrixException& e) {
        cout << "错误: " << e.what() << endl;
    }
    
}

int main() {
    // 设置输出格式，保留两位小数
    cout << fixed << setprecision(2);
    
    testMatrixCreation();
    cout << endl;
    
    testMatrixOperations();
    cout << endl;
    
    testErrorHandling();
    
    return 0;
}

