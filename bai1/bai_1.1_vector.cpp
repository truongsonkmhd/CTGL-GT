#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n; 
    vector<int> v;
    while(n--){
        int x;
        cin>>x;
        if( x == 1 ){
            int y; cin>>y;
            v.push_back(y);
        } else if( v.empty() == false ){
            v.pop_back();
        }
    }
    if(v.empty()) cout<<"EMPTY\n";
    else{
         for(int &x : v){
            cout<< x << " ";
        }
    }   
    return 0;
}