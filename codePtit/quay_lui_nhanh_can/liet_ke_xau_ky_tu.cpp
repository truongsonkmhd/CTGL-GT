// LIỆT KÊ XÂU KÝ TỰ
#include <bits/stdc++.h>
using namespace std;

char kyTuCuoi; // biến 'c'
int doDai; // biến 'k'
string xau; // biến 's'

// Hàm đệ quy để liệt kê các xâu ký tự
void thu(char kyTuBatDau) {
    for (char j = kyTuBatDau; j <= kyTuCuoi; ++j) {
        xau.push_back(j);
        if (xau.length() == doDai) cout << xau << endl;
        else thu(j);
        xau.pop_back(); //(cout<<xau; xong mới xoá) Xóa  ký tự cuối cùng khỏi xau để quay lui và thử ký tự tiếp theo trong vòng lặp.
    }
}

void testCase() {
    cin >> kyTuCuoi >> doDai;
    thu('A');
}

int main() {
    int soLuongBoTest = 1; // số lượng bộ test
    while (soLuongBoTest--) {
        testCase();
        cout << "\n";
    }
    return 0;
}
