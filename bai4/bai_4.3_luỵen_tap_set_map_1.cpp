#include <bits/stdc++.h>
using namespace std;
// input: // đếm số phần tử không trùng nhau trong mảng 
//2
//5
//1 2 2 3
//4
//1 2 3 4
// output:   2 
//           4
/*
// c1
int main(){
    int t ; cin>>t;
    while(t--){
        int n ; cin >> n;
        set<int> s;
        for(int  i = 0; i < n; i++){
            int x; cin>>x;
            s.insert(x);
        }
        cout<< s.size() << endl;
    }
    
}
*/
// c2:
// làm theo cach dung map:
/*
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        map<int,bool > m;
        for(int  i = 0; i < n; i++){
            int x; cin >> x;
            m[x] = true;
         }
         cout<<m.size()<<endl;
    }
    
}
*/

// c3: làm theo kiểu sắp xếp
/*
int main(){
    int t; cin>>t;
    while (t--)
    {
        int n ; cin>>n;
    int a[n];
    for(int &x : a) cin>>x;
    sort(a, a+n);
    int dem  = 1;
     for(int  i = 1; i < n; i++){
         if(a[i] != a[i-1]) dem++;
         }
    cout<<dem<<endl;
    }
    
}
*/

//tìm kiếm một phần tử có trong mảng 
//c1
/*
int main(){
    int t ; cin >> t;
    while(t--){
        int n; cin>> n;
        set<int> se;
        //map<int,bool> mp;
        for(int  i = 0; i < n; i++){
            int x; cin>>x;
            se.insert(x);
        // mp[x] = true;
        
    }
    int q; cin>> q;
    while (q--)
    {
        int x; cin>>x;
        if(se.count(x) == 1){
      //if(mp.count(x) == 1){
            cout<< " YES \n";
        } else cout<< "NO \n";
    }
}
*/
//c2
int main(){
    int t ; cin >> t;
    while(t--){
        int n; cin>> n;
        map<int,bool> mp;
        for(int  i = 0; i < n; i++){
            int x; cin>>x;
         mp[x] = true;
        
    }
    int q; cin>> q;
    while (q--)
    {
        int x; cin>>x;
        if(mp.count(x) == 1){
            cout<< " YES \n";
        } else cout<< "NO \n";
    }
}