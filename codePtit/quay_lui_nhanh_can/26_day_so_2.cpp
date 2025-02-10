// #include <bits/stdc++.h>
// using namespace std;

// int n;
// vector<int> a;
// vector<vector<int>> res;

// void Try(int i) {
//     res.push_back(a);
//     if (i == 1) return;
//     for (int j = 0; j < i - 1; ++j) {
//         a[j] = a[j] + a[j + 1];
//     }
//     a.resize(i - 1); // thu nhỏ kích thước mảng a
//     Try(i - 1);
// }

// void testCase() {
//     cin >> n;
//     a.resize(n);//// Cấp phát đủ bộ nhớ cho vector a để lưu trữ n phần tử
//     res.clear();
//     for (int &i : a) cin >> i;
//     Try(n);
//     reverse(res.begin(), res.end()); // đảo ngược mảng
//     for (auto x : res) {
//         cout << "[";
//         for (int j = 0; j <= x.size() - 1; ++j) {
//             cout << x[j]; 
//             if (j != x.size() - 1) cout << " ";
//         }
//         cout << "]";
//         cout<<endl;
//     }
// }

// int main() {
//     int T = 0; cin >> T;
//     while (T--) {
//         testCase();
//         cout << "\n";
//     }
//     return 0;
// }


#include <bits/stdc++.h>
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
        reverse(res.begin(), res.end()); // đảo ngược mảng
        disPlay();
    }
    return 0;
}
