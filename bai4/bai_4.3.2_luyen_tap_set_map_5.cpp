#include <bits/stdc++.h>
using namespace std;
//Đề bài: Đếm số lượng tử khác nhau trong câu
/*
input:
2
Python C++ java php Python python ->5
son neiman son son son ->3
*/
using ll = long long;
int main(){
    int t; cin>>t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin,s);
        //set<string> se;
        map<string,bool> mp;
        stringstream ss(s);
        string word;
        while (ss >> word)
        {
           // se.insert(word);
           mp[word] = true;
        }
       // cout<< se.size() << endl;
       cout<< mp.size() << endl;

       string res;  int fre = 0;
       for(auto it: mp){
        if(it.second > fre){
            fre = it.second;
            res = it.first;
        }

        cout<<res<<" "<<fre;
        
       }

    }
}