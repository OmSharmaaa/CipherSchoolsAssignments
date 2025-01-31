#include <iostream>
#include <vector>
#include <algorithm>

// Function to perform counting sort based on a specific character index
void countingSort(std::vector<std::string>& arr, int index) {
    int n = arr.size();
    std::vector<std::string> output(n);
    std::vector<int> count(26, 0);

    // Count occurrences of each character at the given index
    for (int i = 0; i < n; i++) {
        count[arr[i][index] - 'a']++;
    }

    // Compute cumulative count
    for (int i = 1; i < 26; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i][index] - 'a'] - 1] = arr[i];
        count[arr[i][index] - 'a']--;
    }

    // Copy sorted values back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Function to perform Radix Sort
void radixSort(std::vector<std::string>& arr, int length) {
    for (int i = length - 1; i >= 0; i--) {
        countingSort(arr, i);
    }
}

int main() {
    int numElements;
    std::cout << "Enter the number of elements: ";
    std::cin >> numElements;

    std::vector<std::string> arr(numElements);
    std::cout << "Enter the strings: ";
    for (int i = 0; i < numElements; ++i) {
        std::cin >> arr[i];
    }

    int strLength = arr[0].size();
    radixSort(arr, strLength);

    std::cout << "Sorted strings: ";
    for (const std::string& str : arr) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    return 0;
}
