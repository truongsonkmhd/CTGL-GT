#include<bits/stdc++.h>
using namespace std;
// sort(a, a + n) : dùng với List => [0 , n-1] 
// sort(a+x, a+y+1) : dùng với list (nhưng được tuỳ chọn vị trí)
// sort(a.begin(), a.end()) : dùng với vector [duyệt toàn bộ list]
// sort(a.begin() + x, a.end() + y + 1) : dùng vector với vị trí tuỳ chọn 

// comparision function 

using ll = long long;

int main(){
    int n; cin >> n;
    vector<pair<int,int>> a(n);
    for(int i = 0; i < n ; i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    for(auto it : a){
        cout<<it.first<< ' '<< it.second<<endl;
    }
}

// string 
/*
int main(){
    int n ; cin >> n;
    vector<string> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }

    sort(a.begin(), a.end());
    for(string it : a){
        cout<<it<<endl;
    }
}

*/
