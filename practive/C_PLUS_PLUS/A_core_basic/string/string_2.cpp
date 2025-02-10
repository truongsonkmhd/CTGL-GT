//#include <bits/stdc++.h>
//using  namespace std;
//input: Pham TrUong SoN
//output:  sonpt@gmail.com 
/*int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        for (int i = 0; i < s.length(); i++) {
            s[i] = tolower(s[i]);
        }
        vector<string> v;
        stringstream ss(s);
        string tmp;
        while (ss >> tmp) {
            v.push_back(tmp);
        }
        cout << v[v.size() - 1]; // in ra tu cuoi cung trong cac tu da nhap vao
        for (int i = 0; i < v.size() - 1; i++) {
            cout << v[i][0]; // in ra ky tu dau cua cac tu nhap vao
        }
        cout <<"@gmail.com"<< endl;
    }
    return 0;
}*/
/*
//<<<<<<<<<<<<<< bai nay khooooooo >>>>>>>>>>>>>>..
//3 -> input
//pham van son -> input
//sonpv@gmail.com- out
//pham vu son
//sonpv2@gmail.com
//pham vinh son
//sonpv3@gmail.com
int main() {
    int t;
    cin >> t;
    cin.ignore();
    map<string, int> mp;
        while (t--) {
        string s;
        getline(cin, s);
        for (int i = 0; i < s.length(); i++) {
            s[i] = tolower(s[i]);
        }
        vector<string> v;
        stringstream ss(s);
        string tmp;
        string res = "";
        while (ss >> tmp)     v.push_back(tmp); 
        res+=v[v.size()-1];
        for (int i = 0; i < v.size() - 1; i++) {
        res+= v[i][0];   
        }
        if(mp[res] == 0){
			cout<< res <<"@gmail.com"<< endl;
		}
		else{
			cout<<res<<mp[res] + 1<<"@gmail.com"<< endl;
		}
    }
    return 0;
}*/




/*
// ===== Chuan hoa ten 1==========
// input : 
// nhap vao so ten muon chuyen doi(int)
// vd:
// Pham tRuoNg sOn -> out put: Pham Truong. SON
#include<bits/stdc++.h>
using namespace std;
void vietHoa(string &s){
	for(int i = 0; i<=s.length(); i++){
	s[i] = toupper(s[i]); //touper: ham viet hoa
		}
	}
void chuanHoa(string &S){
	s[0] = toupper(s[0]); // chu cai dau phai viet hoa
    for(int i = 1; i < s.length(); i++){
        s[i] = tolower(s[i]); // tolower: ham bien chu hoa thanh chu thuong 
    }
}
int main(){
	int t; cin>> t;
	cin.ignore();
	while(t--){
	string s;
	getline(cin, s);
	vector<string> v;
	stringstream ss(s);
	string tmp;
	while(ss >> tmp) v.push_back(tmp); // de luu cai tu minh nhap vao trong vector
	for(int i = 0; i<=v.size()-1; i++){
		chuanHoa(v[i]);
		cout<<v[i];
		if(i == v.size()- 2){// v.size()- 2: la tu ben canh phia bnen trai tu cuoi cùng
			cout<<", ";
		}else{
			cout<<" ";// dau cach giua cac tu dau tiên
		}
		vietHoa(v[v.size() - 1]);// viet hoa tu cuoi cung nhap vao tuong ung voi name
		cout<< v[v.size() - 1]; 
		cout<<endl;
	}
}
return 0 ;
}*/
// ========= chuan hoa ten 2=======
// input: 2
//		  NguyenN VaN  Manh
// output: Manh, Nguyen 
/*#include<bits/stdc++.h>
using namespace std;
void vietHoa(string &s){
	for(int i = 0; i<=s.length(); i++){
	s[i] = toupper(s[i]); //touper: ham viet hoa
		}
	}
void chuanHoa(string &S){
	s[0] = toupper(s[0]); // chu cai dau phai viet hoa
    for(int i = 1; i < s.length(); i++){
        s[i] = tolower(s[i]); // tolower: ham bien chu hoa thanh chu thuong 
    }
}
int main(){
	int t; cin>> t;
	cin.ignore();
	while(t--){
	string s;
	getline(cin, s);
	vector<string> v;
	stringstream ss(s);
	string tmp;
	while(ss >> tmp) v.push_back(tmp); // de luu cai tu minh nhap vao trong vector
		chuanHoa(v[v.size() - 1]);
		cout<<v[v.size() - 1]<<", ";
		for(int i = 0; i<=v.size()-1; i++){
		chuanHoa(v[i]); cout<<v[i];
		if(i != v.size()-2) cout<<" ";
		}
		cout<<endl;
}
return 0 ;
}*/
// ============= xau pangram <<<<< kho chua lam >> ==============


// ================= dem tu trong xau ===================
/*#include<bits/stdc++.h>
using namespace std;
int main(){
int t; cin>>t;
cin.ignore();
while(t--){
	string s;
	getline(cin,s);
	string tmp;
	stringstream ss(s);
	int count = 0;
	while(ss >> tmp){
		count++;
		}
		cout<<count;
	}
	cout<<endl;
return 0;
}*/
// ========= dem xau con trong xau co ki tu dau va cuoi khac nhau <<< bai kho chua lam>> =========

// ================= in ra cac ki tu khong lap khac  nhau trong 1 xau ==========================
// input: ABCDEAABC 
//        ABC
//output: DE
//		  ABC
/*#include<bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	cin.ignore();
	while(t--){
	string s;
	getline(cin, s);
	map<char,int> mp;
	for(char x : s){// luu gtri cua string(s) cho bien x
		mp[x]++;
	}
	for(char x : s){
		if(mp[x]==1)
		cout<< x;
	}
}
	return 0;
	}*/
#include <iostream>
#include <map>
using namespace std;
bool hasUniqueChars(const string& str) {
    map<char, int> charCounts;
    for (char c : str) {
        charCounts[c]++;
    }
    for (const auto& pair : charCounts) {
        if (pair.second != 1) {
            return false;
        }
    }
    return true;
}
int main(){
	string s;
	cout<<"enter a string: ";
	cin>>s;
	if(hasUniqueChars(s)){
	cout<<"The string contains all unique characters."<<endl;
	}else{
		cout<<"The string does not contain all unique character."<<endl;
	}
return 0;
}
