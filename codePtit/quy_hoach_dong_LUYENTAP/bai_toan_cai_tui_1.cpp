#include <iostream>
#include <list>
#include <algorithm>

using namespace std;
// Bài toán balo 1 : mỗi gói chỉ chọn 1 hoặc không chọn
int knapsack(const list<int>& weights, const list<int>& values, int capacity) {
    int n = weights.size();
    
    // Tạo một mảng 2D để lưu trữ giá trị lớn nhất cho mỗi bài toán con
    int** dp = new int*[n + 1];
    for (int i = 0; i <= n; ++i) {
        dp[i] = new int[capacity + 1];
        for (int j = 0; j <= capacity; ++j) {
            dp[i][j] = 0;
        }
    }

    auto weightIt = weights.begin();
    auto valueIt = values.begin();

    for (int i = 1; i <= n; ++i, ++weightIt, ++valueIt) {
        for (int v = 0; v <= capacity; ++v) {
            if (*weightIt > v) {
                dp[i][v] = dp[i - 1][v]; // Nếu gói hàng thứ i không được chọn 
            } else {
                dp[i][v] = max(dp[i - 1][v], dp[i - 1][v - *weightIt] + *valueIt); // Nếu gói hàng thứ i được chọn
            }
        }
    }

    int maxValue = dp[n][capacity];

    // Giải phóng bộ nhớ đã cấp phát
    for (int i = 0; i <= n; ++i) {
        delete[] dp[i];
    }
    delete[] dp;

    return maxValue;
}

int main() {
    list<int> weights = {2, 3, 4, 5}; // Trọng lượng của các gói hàng
    list<int> values = {3, 4, 5, 6};  // Giá trị của các gói hàng
    int capacity = 9;                 // sức chưa max của cái túi

    int max_value = knapsack(weights, values, capacity);
    cout << "Gia tri lon nhat co the dat duoc la: " << max_value << endl;

    return 0;
}
