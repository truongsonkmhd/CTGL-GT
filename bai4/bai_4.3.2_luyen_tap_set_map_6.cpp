#include <bits/stdc++.h>
using namespace std;
// Tìm từ được lặp lại đầu tiên trong câu:
/*
input:
    2
       abc abc abc zzz zzz cd -> abc
       ngon ngu lap lap ngu ngon -> lap
*/
int main(){
int t; cin>>t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin,s);
        vector<string> vt;
        map<string,bool> mp;
        stringstream ss(s); // để tách từ sau mỗi dấu cách của 1 string
        string word;
        while (ss >> word){
            vt.push_back(word);
        }

        for(string x : vt){
            if(mp.find(x) != mp.end()){
                 cout<< x <<endl; break;
            } 
            mp[x] = true;
        }
    }
}