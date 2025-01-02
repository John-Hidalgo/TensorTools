#include <cassert>
#include <iostream>
#include "include/core/list.h"

void testList() {
    // Test Default Constructor
    List<int> list;
    assert(list.Size() == 0); // Ensure size is initially 0
    std::cout << "Test: Default Constructor test passed \n";

    // Test Add Method
    list.Add(10);
    list.Add(20);
    list.Add(30);
    assert(list.Size() == 3);
    assert(list[0] == 10);
    assert(list[1] == 20);
    assert(list[2] == 30);
    std::cout << "Test: Add method passed \n";

    // Test RemoveAt Method
    list.RemoveAt(1); // Remove the element at index 1 (20)
    assert(list.Size() == 2);
    assert(list[0] == 10);
    assert(list[1] == 30);
    std::cout << "Test: RemoveAt method passed \n";

    // Test Pop Method
    list.Pop();
    assert(list.Size() == 1);
    assert(list[0] == 10);
    std::cout << "Test: Pop method passed \n";

    // Test Copy Constructor
    List<int> copyList = list; // Create a copy
    assert(copyList.Size() == list.Size());
    assert(copyList[0] == 10);
    std::cout << "Test: Copy Constructor passed \n";

    // Test Move Constructor
    List<int> movedList = std::move(list); // Move list into movedList
    assert(movedList.Size() == 1);
    assert(movedList[0] == 10);
    // Ensure original list is empty after move
    assert(list.Size() == 0);
    std::cout << "Test: Move Constructor passed \n";

    // Test Assignment Operator
    List<int> assignedList;
    assignedList = movedList; // Copy assigned
    assert(assignedList.Size() == 1);
    assert(assignedList[0] == 10);
    std::cout << "Test: Assignment Operator passed \n";

    // Test Move Assignment Operator
    List<int> moveAssignedList;
    moveAssignedList = std::move(assignedList);
    assert(moveAssignedList.Size() == 1);
    assert(moveAssignedList[0] == 10);
    assert(assignedList.Size() == 0); // Ensure assignedList is empty
    std::cout << "Test: Move Assignment Operator passed \n";

    // Test Initializer List Constructor
    List<int> initList = {1, 2, 3, 4, 5};
    assert(initList.Size() == 5);
    assert(initList[0] == 1);
    assert(initList[4] == 5);

    // Test Resize by Adding Many Elements
    for (int i = 0; i < 100; ++i) {
        initList.Add(i);
    }
    assert(initList.Size() == 105); // 5 original + 100 new elements
    assert(initList[104] == 99);    // Last element added

    // Test Equality Operator
    List<int> anotherList = {1, 2, 3, 4, 5};
    assert(initList != anotherList); // Should not be equal

    anotherList.Add(6); // Modify anotherList
    assert(initList != anotherList); // Still not equal
    std::cout << "All test passed! \n";
}
