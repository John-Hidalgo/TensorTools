#include "include/core/Matrix.h"

template <typename T> Matrix<T>::Matrix(int rows,int cols):
    _data(nullptr),_rows(rows),_cols(cols)
{
    _data = new T*[rows];
    for (int i = 0; i < rows; ++i){
        *(_data + i) = new T[cols];
    }
}
template <typename T> Matrix<T>::~Matrix() {
    for (int i = 0; i < _rows; ++i) {
        delete[] _data[i];
    }
    delete[] _data;
}
template <typename T> Matrix<T>::Matrix(const Matrix<T>& toCopy):
    _data(nullptr),_rows(toCopy._rows),_cols(toCopy._cols)
{
    _data = new T*[_rows];
    for (int i = 0; i < _rows; ++i){
        *(_data + i) = new T[_cols];
    }
    for(int i = 0;i < _rows;++i){
        for(int j = 0;j < _cols;++j){
            *(*(_data + i) + j) = *(*(toCopy._data + i) + j);
        }
    }
}
template <typename T> Matrix<T>::Matrix(Matrix<T>&& toMove) noexcept:
    _data(toMove._data),_rows(toMove._rows),_cols(toMove._cols)
{
    toMove._data = nullptr;
    toMove._rows = 0;
    toMove._cols = 0;
}
template <typename T> Matrix<T>& Matrix<T>::operator=(const Matrix<T>& toCopy) {
    if (this != &toCopy) {
        for (int i = 0; i < _rows; ++i) {
            delete[] _data[i];
        }
        delete[] _data;
        _data = nullptr;
        _rows = toCopy._rows;
        _cols = toCopy._cols;
        _data = new T*[_rows];
        for (int i = 0; i < _rows; ++i) {
            _data[i] = new T[_cols];
        }
        for (int i = 0; i < _rows; ++i) {
            for (int j = 0; j < _cols; ++j) {
                _data[i][j] = toCopy._data[i][j];
            }
        }
    }
    return *this;
}
template <typename T> Matrix<T>& Matrix<T>::operator=(Matrix<T>&& toMove) noexcept {
    if (this != &toMove) {
        for (int i = 0; i < _rows; ++i) {
            delete[] _data[i];
        }
        delete[] _data;
        _data = toMove._data;
        _rows = toMove._rows;
        _cols = toMove._cols;
        toMove._data = nullptr;
        toMove._rows = 0;
        toMove._cols = 0;
    }
    return *this;
}

template <typename T> T& Matrix<T>::At(int row,int col) {
    if (row < 0 || row >= this->_rows || col < 0 || col >= this->_cols) {
        throw std::out_of_range("Index out of range");
    }
    return *(*(_data + row) + col); 
}