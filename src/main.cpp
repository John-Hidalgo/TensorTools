#include <iostream>
#include "include/core/list.h"
#include "tests/listTests.cpp"

int main() {
    // // Test default constructor and Add method
    // std::cout << "Test 1: Default Constructor and Add\n";
    // List<int> list1;
    // list1.Add(10);
    // list1.Add(20);
    // list1.Add(30);
    // list1.Display(); // Expected: 10 20 30

    // // Test copy constructor
    // std::cout << "\nTest 2: Copy Constructor\n";
    // List<int> list2 = list1;
    // list2.Display(); // Expected: 10 20 30

    // // Modify list2 to ensure deep copy
    // list2.Add(40);
    // std::cout << "Original list (list1): ";
    // list1.Display(); // Expected: 10 20 30
    // std::cout << "Copied list (list2): ";
    // list2.Display(); // Expected: 10 20 30 40

    // // Test copy assignment operator
    // std::cout << "\nTest 3: Copy Assignment Operator\n";
    // List<int> list3;
    // list3 = list2;
    // list3.Display(); // Expected: 10 20 30 40

    // // Modify list3 to ensure deep copy
    // list3.RemoveAt(2);
    // std::cout << "Original list (list2): ";
    // list2.Display(); // Expected: 10 20 30 40
    // std::cout << "Modified list (list3): ";
    // list3.Display(); // Expected: 10 20 40

    // // Test move constructor
    // std::cout << "\nTest 4: Move Constructor\n";
    // List<int> list4 = std::move(list1);
    // std::cout << "Moved list (list4): ";
    // list4.Display(); // Expected: 10 20 30
    // std::cout << "Original list (list1, now empty): ";
    // list1.Display(); // Expected: Empty

    // // Test move assignment operator
    // std::cout << "\nTest 5: Move Assignment Operator\n";
    // List<int> list5;
    // list5 = std::move(list2);
    // std::cout << "Moved list (list5): ";
    // list5.Display(); // Expected: 10 20 30 40
    // std::cout << "Original list (list2, now empty): ";
    // list2.Display(); // Expected: Empty

    // // Test operator[] overload
    // std::cout << "\nTest 6: Operator[]\n";
    // std::cout << "Element at index 1 in list5: " << list5[1] << "\n"; // Expected: 20
    // list5[1] = 25;
    // std::cout << "Modified list5: ";
    // list5.Display(); // Expected: 10 25 30 40

    // // Test initializer list constructor
    // std::cout << "\nTest 7: Initializer List Constructor\n";
    // List<int> list6 = {5, 10, 15, 20};
    // list6.Display(); // Expected: 5 10 15 20

    // // Test Pop method
    // std::cout << "\nTest 8: Pop Method\n";
    // list6.Pop();
    // list6.Display(); // Expected: 5 10 15

    // // Test RemoveAt method
    // std::cout << "\nTest 9: RemoveAt Method\n";
    // list6.RemoveAt(1);
    // list6.Display(); // Expected: 5 15

    // // Test out-of-bounds access
    // std::cout << "\nTest 10: Out-of-Bounds Access\n";
    // try {
    //     std::cout << "Attempting to access index 10 in list6...\n";
    //     std::cout << list6[10] << "\n";
    // } catch (const std::out_of_range& e) {
    //     std::cout << "Caught exception: " << e.what() << "\n"; // Expected: Exception
    // }
    testList();
    std::cout << "\nAll tests completed successfully.\n";
    return 0;
}
