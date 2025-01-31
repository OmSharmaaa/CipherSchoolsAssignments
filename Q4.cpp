#include <iostream>
#include <vector>

int main() {
    // Declare a vector to store elements
    std::vector<int> dynamicArray;
    int numElements;

    // Prompt the user to enter the number of elements
    std::cout << "Enter the number of elements: ";
    std::cin >> numElements;

    // Input elements into the vector
    std::cout << "Enter " << numElements << " elements:" << std::endl;
    for (int i = 0; i < numElements; ++i) {
        int value;
        std::cin >> value;
        dynamicArray.push_back(value);
    }

    // Display the elements of the vector
    std::cout << "Elements in the vector: ";
    for (int val : dynamicArray) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Add a new element to the vector
    int newElement;
    std::cout << "Enter a new element to add: ";
    std::cin >> newElement;
    dynamicArray.push_back(newElement);

    // Display the updated vector
    std::cout << "Updated vector: ";
    for (int val : dynamicArray) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
