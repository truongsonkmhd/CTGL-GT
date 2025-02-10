#include <bits/stdc++.h>
using namespace std;

int n, k, ans;
vector<int> a, b;

void solve() {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i] * b[i];
    }
    if (sum == k) {
        ans++;
        for (int i = 0; i < n; ++i) {
            if (b[i]) cout << a[i] << " ";
        }
        cout << endl;
    }
}

void generateBinaryCombinations() {
    fill(b.begin(), b.end(), 0);
    bool last = false;
    while (!last) {
        solve();
        int index = n - 1;
        while (index >= 0 && b[index] == 1) {
            b[index] = 0;
            index--;
        }
        if (index >= 0) b[index] = 1;
        else last = true;
    }
}

void testCase() {
    cin >> n >> k;
    a.resize(n);
    b.resize(n);
    for (int &i : a) cin >> i;
    ans = 0;  // Reset the answer counter
    generateBinaryCombinations();
    cout << ans;
}

int main() {
    int T = 1;
    while (T--) {
        testCase();
        cout << "\n";
    }
    return 0;
}
