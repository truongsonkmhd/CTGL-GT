#include<bits/stdc++.h>
using namespace std;

void next(string s){
    int i = s.length() - 1;
    // c1:
    // while(i >= 0 && s[i] == '1'){
    //     s[i] = '0';
    //     --i;
    // }
    // if(i != -1){
    //     s[i] = '1';
    // }
    // c2:
    for(int i = s.length() - 1, i>=0;i++){
        if(s[i] == '1') s[i] = '0';
        else{
            s[i] = '1';
            break;
        }
    }
    cout<<s<<endl;
}

int main(){
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        next(s);
    }
    return 0;
}