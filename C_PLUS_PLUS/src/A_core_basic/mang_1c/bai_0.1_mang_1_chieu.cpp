#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int cnt[10000002];

/*
input: 1<t<100; 10^(-6)<=A[i]<=10^6
2
5
1 2 3 4 5 ->6
5 
0 -10 1 3 -20
*/

int main(){
    int t; cin>>t;
    while (t--)
    {
        int n; cin>>n;
        memset(cnt, 0 , sizeof(cnt)); // reset lại mảng cnt (vì dùng lại lần 2 cho mảng sau)
        for(int i = 0; i < n; i++){
            int x; cin>>x;
            if(x>0) cnt[x] = 1;
        }
        for(int i = 1; i < 1000001; i++){
            if(cnt[i] == 0){
                cout << i << endl;
                break;
            }
        }
    }
}
