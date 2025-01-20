#include <iostream>
#include <vector>

int main() {
    // Step 1: Prompt the user to enter the number of elements
    int numElements;
    std::cout << "Enter the number of elements you want to store in the dynamic array: ";
    std::cin >> numElements;

    // Step 2: Declare a std::vector
    std::vector<int> dynamicArray;

    // Step 3: Input elements into the vector
    std::cout << "Enter " << numElements << " elements: \n";
    for (int i = 0; i < numElements; ++i) {
        int element;
        std::cin >> element;
        dynamicArray.push_back(element);
    }

    // Step 4: Display the elements of the vector
    std::cout << "Elements in the dynamic array: ";
    for (int elem : dynamicArray) {
        std::cout << elem << " ";
    }
    std::cout << "\n";

    // Step 5: Add a new element to the vector
    int newElement;
    std::cout << "Enter a new element to add to the dynamic array: ";
    std::cin >> newElement;
    dynamicArray.push_back(newElement);

    // Step 6: Display the updated vector
    std::cout << "Updated elements in the dynamic array: ";
    for (int elem : dynamicArray) {
        std::cout << elem << " ";
    }
    std::cout << "\n";

    return 0;
}
