#include <iostream>
#include <vector>
#include <algorithm> // Thêm thư viện này để sử dụng hàm reverse

using namespace std;

// cách 1 : Dùng theo mảng tĩnh
// int n, a[15] = {};

// void disPlay(int n) {
//     cout << "[";
//     for(int i = 0; i < n; i++) {
//         cout << a[i];
//         if( i != n - 1) cout << " ";
//     }
//     cout << "]";
//     cout << endl;
// }

// void back_tracking(int n) {
//     disPlay(n);
//     if(n > 1) {
//         for(int i = 0; i < n - 1; i++) { // Chỉnh sửa ở đây để tránh truy cập ngoài phạm vi mảng
//             a[i] = a[i] + a[i + 1];
//         }
//         back_tracking(n - 1);
//     }
// }

// int main() {
//     int t = 0;
//     cin >> t;
//     while(t--) {
//         cin >> n;
//         for(int i = 0; i < n; i++) {
//             cin >> a[i];
//         }
//         back_tracking(n);
//     }
// }
// Cách 2: Dùng theo mảng động

#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> res;

void disPlay() {
    for (auto x : res) {
        cout << "[";
        for (int j = 0; j < x.size(); ++j) {
            cout << x[j];
            if (j != x.size() - 1) cout << " ";
        }
        cout << "]";
        cout << endl;
    }
}

void backTracking(vector<int> a) {
    res.push_back(a);
    if (a.size() == 1) return;
    vector<int> next_a(a.size() - 1);
    for (int j = 0; j < a.size() - 1; j++) {
        next_a[j] = a[j] + a[j + 1];
    }
    backTracking(next_a);
}

int main() {
    int t = 0;
    cin >> t;
    while (t--) {
        cin >> N;
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        res.clear();
        backTracking(a);
        disPlay();
    }
    return 0;
}
