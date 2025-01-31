#include <iostream>
#include <vector>

int main() {
    // Declare a vector to store elements
    std::vector<int> dynamicArray;
    int numElements;

    // Prompt the user to enter the number of elements
    std::cout << "Enter the size of the array: ";
    std::cin >> numElements;

    // Input elements into the vector
    std::cout << "Enter the elements of the array: " << std::endl;
    for (int i = 0; i < numElements; ++i) {
        int value;
        std::cin >> value;
        dynamicArray.push_back(value);
    }

    // Input the number to search
    int searchElement;
    std::cout << "Enter the number to search: ";
    std::cin >> searchElement;

    // Perform Linear Search
    bool found = false;
    int index = -1;
    for (int i = 0; i < numElements; ++i) {
        if (dynamicArray[i] == searchElement) {
            found = true;
            index = i;
            break;
        }
    }

    // Display the result
    if (found) {
        std::cout << "Element found at index: " << index << std::endl;
    } else {
        std::cout << "Element not found in the array." << std::endl;
    }

    return 0;
}
