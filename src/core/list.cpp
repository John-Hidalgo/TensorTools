#include "include/core/list.h"

template<typename T> List<T>::List():
    _capacity(1), _size(0), _values(new T[1])
{}
template<typename T> List<T>::List(const List& toCopy): 
    _capacity(toCopy._capacity), _size(toCopy._size), _values(nullptr)
{
    this->_values = new T[toCopy._capacity];
    for (size_t i = 0; i < toCopy._size; ++i)
    {
        this->_values[i] = toCopy._values[i];
    }
}
template<typename T> List<T>::List(List&& toMove):
    _capacity(toMove._capacity), _size(toMove._size), _values(toMove._values)
{
    toMove._capacity = 0;
    toMove._size = 0;
    toMove._values = nullptr;
}
template<typename T> List<T>::List(std::initializer_list<T> init): 
    _capacity(init.size()),
    _size(init.size()),
    _values(new T[_capacity])
{        
    std::copy(init.begin(), init.end(), _values);
}
template<typename T> inline List<T>::~List(){
    if (this->_values) 
    {
        delete[] this->_values;
        this->_values = nullptr;
    }
}
template<typename T> void List<T>::Add(const T& element){
    if(this->_size == this->_capacity){
        Resize();
    }
    this->_values[_size] = element;
    this->_size++;
}
template<typename T> void List<T>::Pop(){
    --this->_size;
}
template<typename T> void List<T>::RemoveAt(size_t index){
    if (index < 0 || index >= _size) {
            throw std::out_of_range("Index is out of range of list");
        }
    for(size_t i = index ;i < this->_size - 1 ;++i){
        this->_values[index] = this->_values[index + 1];
    }
    --this->_size;
}
template<typename T> size_t List<T>::Size() const{
    return this->_size;
}
template<typename T> void List<T>::Display() const {
    if (this->_size == 0) {
        std::cout << "[]" << "\n";
    } else {
        std::cout << "[";
        for (size_t i = 0; i < this->_size - 1; ++i) {
            std::cout << this->_values[i] << ", ";
        }
        std::cout << this->_values[this->_size - 1] << "]" << "\n";
    }
}
template<typename T> T& List<T>::operator[](const size_t index){
    if (index < 0 || index >= _size) {
        throw std::out_of_range("Index is out of range of list size");
    }
    return this->_values[index];
}
template<typename T> const T& List<T>::operator[](const size_t index) const{
    if (index < 0 || index >= _size) {
        throw std::out_of_range("Index is out of range of list size");
    }
    return this->_values[index];
}
template<typename T> bool List<T>::operator==(const List<T>& list) const {
    if (this->_size != list._size) {
        return false;
        for (size_t i = 0; i < this->_size; ++i) {
            if (this->_values[i] != list._values[i]) {
                return false; 
            }
        }
    }
    return true;
}
template<typename T> bool List<T>::operator!=(const List<T>& list) const {
    return !(*this == list);
}
template<typename T> List<T>& List<T>::operator=(const List& toCopy){
    if (this != &toCopy) {
        delete[] this->_values;
        this->_capacity = toCopy._capacity;
        this->_size = toCopy._size;
        this->_values = new T[this->_capacity];
        for (size_t i = 0; i < this->_size; ++i) {
            this->_values[i] = toCopy._values[i];
        }
    }
    return *this;
}
template<typename T> List<T>& List<T>::operator=(List&& toMove){
    this->_size = toMove._size;
    if (this->_values)
    {
        delete[] this->_values;
    }
    this->_values = toMove._values;
    toMove._values = nullptr;
    toMove._capacity = 0;
    toMove._size = 0;
    return *this;
}
template<typename T> void List<T>::Resize(){
    this->_capacity *= 2;
    T* newValues = new T[this->_capacity];
    for(size_t i = 0; i < this->_size;++i){
        newValues[i] = this->_values[i];
    }
    delete[] this->_values;
    this->_values = newValues;
}