#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// mảng ngẫu nhiên sẽ được sắp xếp, nếu không tồn tại thì cho vị trí đó = -1
/*
2
10
-1 -1 6 1 9 3 2 -1 4 -1 => -1 1 2 3 4  -1 6  -1  -1 9 
6
0 -3 1 -2 4 -9 => 0 1  -1  -1 4  -1
*/
int main(){
    int t; cin>>t;
    while (t--)
    {
       int n ; cin >> n;
       map<ll,bool> mp;
       for(int i = 0 ; i < n ; i++){
            ll x; cin>>x;
            mp[x] = true;
       }
       for(int i = 0 ; i < n ; i++){
            if(mp[i]){
                cout<< i << " ";
            }
            else cout<<" -1 ";
       }
       cout<<endl;
    }
    
}