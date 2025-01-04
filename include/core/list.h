#pragma once
#include <iostream>
#include <initializer_list>
#include <stdexcept> 

template <typename T> class List {
public:
    List();
    List(const List& toCopy);
    List(List&& toMove);
    List(std::initializer_list<T> init);
    ~List();
    void Add(const T& element);
    void Pop();
    void RemoveAt(size_t index);
    size_t Size() const;
    void Display() const;
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    bool operator==(const List&) const;
    bool operator!=(const List&) const;
    List& operator=(const List&);
    List& operator=(List&&);
private:
    size_t _capacity;
    size_t _size;
    T* _values;
    void Resize();
};

#include "src/core/list.cpp"
