#include<bits/stdc++.h>
using namespace std;

int main() {
    /*
    // c1 (khoi tao)
    pair<int , int> p = {10 ,20};
     // c2 (khoi tao) C++11 tro len 
    pair<int , int> p1 = make_pair(10,20);
    cout<<p1.first <<" "<<p1.second;
    */
    
    int n; cin>>n;
    pair<int,int> a[n];
    for(int i = 0 ; i < n ; i++){
        cin>>a[i].first>>a[i].second;
    } 
    
    vector<pair<int ,int>> p; // vector contain pair
    pair<int, pair<int,int>> p2;
    p2.first  = 10;
    p2.second.first = 20;
    p2.second.second = 12;
    pair<int , vector<int>> p;
    return 0 ;
}