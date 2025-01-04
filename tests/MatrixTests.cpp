#include <iostream>
#include <cassert>
#include "include/core/Matrix.h"

void TestConstructor() {
    // Create a matrix of size 2x3 (2 rows, 3 columns)
    Matrix<int> matrix(2, 3);
    // Access elements to ensure memory is allocated
    matrix.At(0, 0) = 1;
    matrix.At(0, 1) = 2;
    matrix.At(0, 2) = 3;
    matrix.At(1, 0) = 4;
    matrix.At(1, 1) = 5;
    matrix.At(1, 2) = 6;

    // Test that values are correctly set
    assert(matrix.At(0, 0) == 1);
    assert(matrix.At(0, 1) == 2);
    assert(matrix.At(0, 2) == 3);
    assert(matrix.At(1, 0) == 4);
    assert(matrix.At(1, 1) == 5);
    assert(matrix.At(1, 2) == 6);

    std::cout << "TestConstructor passed!\n";
}

void TestDestructor() {
    // Create a matrix and ensure it's deleted properly by checking memory allocation and deallocation
    {
        Matrix<int> matrix(2, 3);
        matrix.At(0, 0) = 10;
        matrix.At(0, 1) = 20;
        matrix.At(0, 2) = 30;
    } // The matrix goes out of scope here, triggering the destructor

    // Test whether memory was properly freed (we'll rely on RAII here for simplicity)
    std::cout << "TestDestructor passed!\n";
}
void TestCopyConstructor() {
    // Create a 2x3 matrix
    Matrix<int> original(2, 3);
    original.At(0, 0) = 1;
    original.At(0, 1) = 2;
    original.At(0, 2) = 3;
    original.At(1, 0) = 4;
    original.At(1, 1) = 5;
    original.At(1, 2) = 6;

    // Use the copy constructor
    Matrix<int> copy = original;

    // Verify the copy
    assert(copy.At(0, 0) == 1);
    assert(copy.At(0, 1) == 2);
    assert(copy.At(0, 2) == 3);
    assert(copy.At(1, 0) == 4);
    assert(copy.At(1, 1) == 5);
    assert(copy.At(1, 2) == 6);

    // Ensure deep copy
    copy.At(0, 0) = 42;
    assert(original.At(0, 0) != 42);

    std::cout << "TesTCopyConstructor passed!\n";
}
void TestMoveConstructor() {
    // Create a 2x2 matrix
    Matrix<int> original(2, 2);
    original.At(0, 0) = 1;
    original.At(0, 1) = 2;
    original.At(1, 0) = 3;
    original.At(1, 1) = 4;

    // Use the move constructor
    Matrix<int> moved = std::move(original);

    // Verify the contents of the moved matrix
    assert(moved.At(0, 0) == 1);
    assert(moved.At(0, 1) == 2);
    assert(moved.At(1, 0) == 3);
    assert(moved.At(1, 1) == 4);

    // Verify the state of the original matrix
    // assert(original._data == nullptr);
    // assert(original._rows == 0);
    // assert(original._cols == 0);

    std::cout << "TestMoveConstructor passed!\n";
}
void TestMoveAssignment() {
    // Create and initialize a matrix
    Matrix<int> a(2, 2);
    a.At(0, 0) = 1;
    a.At(0, 1) = 2;
    a.At(1, 0) = 3;
    a.At(1, 1) = 4;

    // Move the matrix
    Matrix<int> b(2, 2);
    b = std::move(a);

    // Verify b has the data
    assert(b.At(0, 0) == 1);
    assert(b.At(0, 1) == 2);
    assert(b.At(1, 0) == 3);
    assert(b.At(1, 1) == 4);

    // Verify a is empty
    try {
        a.At(0, 0); // Accessing an empty matrix should throw
        assert(false); // Should not reach this line
    } catch (const std::exception&) {
        std::cout << "Move assignment left source in a valid state.\n";
    }

    std::cout << "TestMoveAssignment passed!\n";
}