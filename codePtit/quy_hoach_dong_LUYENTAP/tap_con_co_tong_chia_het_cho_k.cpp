#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Bảng động dp[i][v] đại diện cho số lượng phần tử lớn nhất của dãy con từ A[1] đến A[i]
    // mà tổng các phần tử có phần dư là v khi chia cho k.
    vector<vector<int>> dp(n + 1, vector<int>(k, -1));//Khởi tạo -1 có nghĩa là ban đầu, chưa có dãy con nào được xem xét, 
                                                      //và do đó, giá trị -1 đại diện cho trạng thái không hợp lệ hoặc chưa được cập nhật.
    dp[0][0] = 0; // khởi tạo dp[0][0] = 0, các vị trí còn lại khởi tạo -1 vì chưa có giá trị hợp lệ

    for (int i = 1; i <= n; i++) {
        int mod = a[i - 1] % k;
        for (int v = 0; v < k; v++) {
            // Giữ nguyên giá trị từ dãy con không bao gồm a[i]
            dp[i][v] = max(dp[i][v], dp[i - 1][v]);
            // Cập nhật giá trị nếu bao gồm a[i]
            int prev = (v - mod + k) % k;
            if (dp[i - 1][prev] != -1) {
                dp[i][v] = max(dp[i][v], dp[i - 1][prev] + 1);
            }
        }
    }

    // Kết quả là số lượng phần tử lớn nhất của dãy con mà tổng chia hết cho k
    int result = dp[n][0];
    cout << result << endl;

    return 0;
}
