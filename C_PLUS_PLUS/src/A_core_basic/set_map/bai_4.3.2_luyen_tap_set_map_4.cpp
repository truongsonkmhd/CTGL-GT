#include <bits/stdc++.h>
using namespace std;
//Đề bài: Xâu được gọi là pangra, nếu nó có đủ các chữ cái từ a tới z không phân biệt hoa thường,
// kiểm tra một xâu nhập vào có phải là pangram hay không?
/*
Input:
 1
 ThequickbrownfoxjumpsoverthelazyDOG -> output: YES;
 andrewneiMan                        -> output: NO;
*/
int main(){
    int t; cin>>t;
    cin.ignore();
    while (t--)
    {
        string s;
        getline(cin,s);
        set<char> se;
        for(char x : se){
            se.insert(tolower(x));
        }
        cout<< se.size() <<endl;
        if(se.size() == 26) cout<<"YES\n";
        else cout<<"No";
    }
    
}