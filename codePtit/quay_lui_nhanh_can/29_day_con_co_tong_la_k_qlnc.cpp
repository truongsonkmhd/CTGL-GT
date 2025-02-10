#include <bits/stdc++.h>
using namespace std;
// quay lui nhánh cận
int n, k;
int a[100], v[100];
vector<vector<int>> res;

void init(){
    res.clear();
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    sort(v + 1, v + n + 1);

/*
-v + 1 là con trỏ tới phần tử đầu tiên của mảng v (tức v[1]).
-v + n + 1 là con trỏ tới phần tử ngay sau phần tử cuối cùng của mảng v cần sắp xếp (tức v[n]).

v = [0, 4, 1, 3, 2, 5] (phần tử v[0] không sử dụng).
Khi gọi sort(v + 1, v + n + 1);, tức sort(v + 1, v + 6);, các phần tử từ v[1] đến v[5] sẽ được sắp xếp lại:
*/
}

void Try(int i) {
    for(int j = 0; j <= 1; j++) {
        a[i] = j; // mang a dung de luu vtri cua v[i]
        if(i == n) {
            int s = 0;
            for(int l = 1; l <= n; l++)
                if(a[l]) s += v[l]; //a[l] = 0 => ko đc chọn, a[l] = 1 => đc chọn
            if(s == k) {
                vector<int> x;
                for(int l = 1; l <= n; l++)
                    if(a[l]) x.push_back(v[l]);
                res.push_back(x);
            }
        } else {
            Try(i + 1);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        init();
        Try(1);
        if(res.size() == 0) {
            cout << -1 << endl;
        } else {
            sort(res.begin(), res.end());// sort các mảng
            /*
           ví dụ: [1,2,3] < [2,3], [4] > [2,3,4,5]
            */
            for(auto& r : res) {
                cout << "[";
                for(int j = 0; j < r.size(); j++) {
                    cout << r[j];
                    if(j < r.size() - 1) cout << " ";
                }
                cout << "] ";
            }
            cout << endl;
        }
    }
    return 0;
}
