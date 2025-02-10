#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[100];

void testCase(){
    cin >> n >> k;
    for(int i = 1; i <= k; i++) a[i] = i;
    bool last = false;
    while(last == false) {
        // In cấu hình hiện tại
        for(int i = 1; i <= k; i++) cout << a[i] << " ";
        cout << "  ";

        int index = k;
        // Tìm phần tử chưa đạt max
        while(index >= 1 && a[index] == (n - k + index)) {
            index--;
        }

        // Đã tìm được phần tử chưa đạt max bên phải ngoài cùng
        if(index >= 1) {
            a[index]++;
            for(int j = index + 1; j <= k; j++) {
                a[j] = a[j - 1] + 1;
            }
        } else {
            last = true;
        }
    }
}

int main(){
    int t = 1; cin >> t;
    while(t--){
        testCase();
        cout << endl;
    }
    return 0;
}
