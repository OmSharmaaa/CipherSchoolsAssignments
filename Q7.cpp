#include <iostream>
#include <vector>

long long mergeAndCount(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> leftArr(n1), rightArr(n2);
    
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    long long inversions = 0;
    
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
            inversions += (n1 - i);
        }
    }
    
    while (i < n1)
        arr[k++] = leftArr[i++];
    while (j < n2)
        arr[k++] = rightArr[j++];
    
    return inversions;
}

long long mergeSortAndCount(std::vector<int>& arr, int left, int right) {
    long long inversions = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        inversions += mergeSortAndCount(arr, left, mid);
        inversions += mergeSortAndCount(arr, mid + 1, right);
        inversions += mergeAndCount(arr, left, mid, right);
    }
    return inversions;
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

    long long totalInversions = mergeSortAndCount(arr, 0, numElements - 1);
    
    std::cout << "Total Inversions: " << totalInversions << std::endl;

    return 0;
}
