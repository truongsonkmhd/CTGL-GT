#include <bits/stdc++.h>
using namespace std;

string s;
int a[100];
bool chuaXet[100]; // mang danh dau (value default = false)

void Try(int i) {
    for (int j = 0; j < s.size(); j++) {
        if (!chuaXet[j]) {
            a[i] = j;
            chuaXet[j] = true; // Đánh dấu ký tự tại vị trí j đã được xét.
            if (i == s.size() - 1) {
                for (int l = 0; l < s.size(); l++)
                    cout << s[a[l]];
                cout << " ";
            } else {
                Try(i + 1);
            }
            chuaXet[j] = false;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> s;
        memset(chuaXet, false, sizeof(chuaXet));
        sort(s.begin(), s.end());
        Try(0); // Bắt đầu từ 0 thay vì 1
        cout << endl;
    }
    return 0;
}

//input:
/*
2
AB
ABC
*/
