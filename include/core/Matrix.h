#pragma once
#include <iostream>

template <typename T> class Matrix {
private:
    T** _data;
    int _rows;
    int _cols;
    void allocateMatrix(int rows, int cols);
    void deallocateMatrix();
    void copyMatrix(const Matrix<T>& other);
public:
    Matrix(int rows, int cols);
    Matrix(const Matrix<T>& other);
    Matrix(Matrix<T>&& other) noexcept;
    Matrix& operator=(const Matrix<T>& other);
    Matrix& operator=(Matrix<T>&& other) noexcept;
    ~Matrix();
    T& At(int row,int col);
    void setElement(int row, int col, const T& value);
    T getElement(int row, int col) const;
    void addRow(const T* rowData, int rowSize);
    void removeRow(int rowIndex);
    void resizeRow(int rowIndex, int newColCount);
    void resize(int newRows, int newCols);
    void display() const;
    int getRowCount() const;
    int getColCount() const;
};

#include "src/core/Matrix.cpp"