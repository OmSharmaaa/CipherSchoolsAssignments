#include <iostream>
#include <vector>
#include <stack>

std::vector<int> calculateStockSpan(const std::vector<int>& prices) {
    int n = prices.size();
    std::vector<int> span(n);
    std::stack<int> s;
    
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && prices[s.top()] <= prices[i]) {
            s.pop();
        }
        span[i] = (s.empty()) ? (i + 1) : (i - s.top());
        s.push(i);
    }
    return span;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> prices(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> prices[i];
    }
    
    std::vector<int> span = calculateStockSpan(prices);
    
    for (int val : span) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
