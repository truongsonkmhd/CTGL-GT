#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//Đề bài: Cho mảng A[] gồm n số chưa được sắp xếp. Hãy tìm Min(A[i] - A[j]) (không âm) : i!=j và
//i,j = 0,1,2,...n-1. Ví dụ với A[]={1,5,3,19,18,25} ta có kết quả là 1 = 19-18
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        int res = INT_MAX;
        for (int i = 1; i < n; i++) {
            res = min(res, a[i] - a[i - 1]);
        }
        cout << res << endl;
    }

}