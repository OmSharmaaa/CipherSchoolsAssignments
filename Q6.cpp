#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& arr, int& totalSwaps, int& totalPasses) {
    int n = arr.size();
    totalSwaps = 0;
    totalPasses = 0;
    bool swapped;

    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
                totalSwaps++;
            }
        }
        totalPasses++;
        if (!swapped) break;
    }
}

int main() {
    int numElements;
    std::cout << "Enter the number of elements: ";
    std::cin >> numElements;

    std::vector<int> arr(numElements);
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < numElements; ++i) {
        std::cin >> arr[i];
    }

    int totalSwaps, totalPasses;
    bubbleSort(arr, totalSwaps, totalPasses);

    std::cout << "Sorted Array: ";
    for (int val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Total Swaps: " << totalSwaps << std::endl;
    std::cout << "Total Passes: " << totalPasses << std::endl;

    return 0;
}
