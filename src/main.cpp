#include <iostream>
#include "include/core/list.h"
#include "tests/listTests.cpp"
#include "tests/MatrixTests.cpp"

int main() {
    TestConstructor();
    TestDestructor();
    TestCopyConstructor();
    TestMoveConstructor();
     TestMoveAssignment();
    return 0;
}
