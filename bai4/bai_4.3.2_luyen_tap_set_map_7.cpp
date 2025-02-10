#include <bits/stdc++.h>
using namespace std;
// intput:
/*
4
an   ->an
binh ->binh
an   ->an1
binh ->binh1
*/
int main(){
    int t; cin>>t;
    map<string,int> mp;
    while(t--){
        string username;
        getline(cin,username);
        if(mp.find(username) == mp.end()){
            cout<<username<<endl;
        } else cout << username << mp[username] <<endl;
        mp[username]++;
    }
}