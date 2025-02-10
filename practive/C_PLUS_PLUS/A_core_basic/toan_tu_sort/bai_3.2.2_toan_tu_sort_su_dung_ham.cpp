#include<bits/stdc++.h>
using namespace std;
// Đề bài1: Cho mảng a[] gồm N phần tử. Sắp xếp sao cho số nào có nhiều số lẻ hơn thì đứng trước,
// trong trường hợp nhiều số có cùng chữ số lẻ thì số nào nhỏ hơn sẽ đứng trước
// Đề bài_2: Cho mảng a[] gồm N phần tử. Sắp xếp sao cho số nào có nhiều snt hơn thì đứng trước,
// trong trường hợp nhiều số có cùng chữ snt thì số nào nhỏ hơn sẽ đứng trước
/*
-input: 
11
445 6 10493 23600 32757 6911 15236 14074 224358 32132 28596 15209
*/

#include<bits/stdc++.h>
using namespace std;

int le(int a) {
    int ans = 0;
    while (a) {
        if (a % 2 == 1) {
            ++ans;
        }
        a = a/10;
    }
    return ans;
}

int snt(int a){
    int ans = 0;
    while(a){
       int r = a % 10;
       if(r == 2 || r == 3 || r == 5|| r == 7)
        ++ans;
        a=a/10;
    }
    return ans;
}

bool cmp(int a, int b) {
    int cntA = le(a);
    int cntB = le(b);
    if (cntA != cntB) {
        return cntA < cntB; // Sắp xếp số lẻ nhiều hơn trước
    } else {
        return a < b; // Trường hợp số lẻ bằng nhau, sắp xếp theo thứ tự tăng dần
    }
}

int main() {
    int n; 
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // stable : ổn định ( giữ nguyên vị trí tương đối ban đầu)
    //stable_sort(a.begin() , a.end() , cmp); 
    sort(a.begin(), a.end(), cmp); // O(NlogN) = intro sort : quick sort + heap sort

    for (int num : a) {
        cout << num << " ";
    }
    return 0;
}