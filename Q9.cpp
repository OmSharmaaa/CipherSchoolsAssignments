#include <iostream>
#include <vector>
#include <cmath>

class SqrtDecomposition {
private:
    std::vector<int> arr, block;
    int blockSize;

public:
    SqrtDecomposition(std::vector<int>& input) {
        int n = input.size();
        blockSize = std::sqrt(n);
        arr = input;
        block.resize((n + blockSize - 1) / blockSize, 0);
        
        for (int i = 0; i < n; ++i) {
            block[i / blockSize] += arr[i];
        }
    }

    void update(int index, int value) {
        int blockIndex = index / blockSize;
        block[blockIndex] += value - arr[index];
        arr[index] = value;
    }

    int query(int L, int R) {
        int sum = 0;
        while (L <= R && L % blockSize != 0) {
            sum += arr[L++];
        }
        while (L + blockSize - 1 <= R) {
            sum += block[L / blockSize];
            L += blockSize;
        }
        while (L <= R) {
            sum += arr[L++];
        }
        return sum;
    }
};

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    SqrtDecomposition sqrtDecomp(arr);
    
    for (int i = 0; i < q; ++i) {
        std::string operation;
        std::cin >> operation;
        if (operation == "UPDATE") {
            int index, value;
            std::cin >> index >> value;
            sqrtDecomp.update(index - 1, value);
        } else if (operation == "QUERY") {
            int L, R;
            std::cin >> L >> R;
            std::cout << sqrtDecomp.query(L - 1, R - 1) << std::endl;
        }
    }
    return 0;
}
