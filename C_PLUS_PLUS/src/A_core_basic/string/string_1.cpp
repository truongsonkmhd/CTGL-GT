/*#include <iostream>
#include <string.h>
using namespace std;
int main() {*/
//================ nhap xuat chuoi===================
/*	int n;
	cin >> n; // van con phim enter
	cin.ignore(); // vi du nhap 1 gtri no ko dung lai nua nop se doi minh nhap mot cai xau
	string s;
	getline(cin, s);
	cout<< s << endl;
	return 0;
	}*/
//============= truy cap ki tu cua xau thong qua chi so=======
/*	string s= "python"; //co 6 ptu o dang chuoi
	 // cách 1:
	for(int i = 0; i < s.length(); i++){
		cout<< s[i]<<endl;
	}
	// cách 2
	for(char x : s) // duuyet qua cac phan tu co kieu char trong chuoi s
{
	cout << x << endl;
}*/
/*giai thich: cung giong nhu mang
int a[100]; // co 100 phan tu
for(int x : a); //  duyet qua cac phan tu co kieu int trong mang a[]*/


//========== noi 2 xau =============
/*	string a = "python";
	string b = "java";
	string c = a  + b;
	cout<< c <<endl;
 
	return 0;
	}*/
// =============== compare trong xau=================
/*	string a = "abc";
	string b = "def";
	if(a  >  b){
		cout<<"a lon hon b"<<endl;
	}	
	else if( a == b){
		cout << " a giong b "<<endl;
		}
	else{
		cout<<"a nho hon b"<<endl;
	} */
	//== dung ham co san trong c++===
	// a < b: -1
	// a == b: 0
	// a > b: 1
	/*string a = "z";
	string b = "def";
	cout<<a.compare(b)<<endl;*/
	
	
	
	// === cat chuoi ====
	/*	string a = " abcdef ";
		string b = a.substr(2,4); // chay tu "0" cat tu 2 den 4
		cout<< b << endl;
	*/
	
	
	// ======chuyen chuoi ki tu thanh so=====
	// so be kieu int: stoi()
	// so lon kieu long, long long: stoll
//	string a = "123321312"; // xau
//	int x = stoi(a);
/*	string a = " 38247238423489832";
	long long x = stoll(a);
	cout << x << endl;*/
	//====== chuyuen tu so sang string=======
	/*int n = 123345; // ="123345"
	string s = to_string(n);
	cout<< s <<endl;*/
	//====== xuat ra 1 chu trong string====
	/*string s = "java python  php lap  trinh ";
	stringstream ss(s);
	string tmp;
	int cnt = 0;
	while(ss > tmp){
	++cnt;
	}
	cout<< cnt << endl;*/
	
	//bai1:
	// ============ chuoi dao nguoc  cua mot chuoi ===========
 

//int main() {
  /*  string blogName = "java2blog";
    string reverse = "";
    
    for(int i = blogName.length()-1; i >= 0; i--) { 
        reverse = reverse + blogName[i];
    }
    
    cout << "Reverse of java2blog is: " << reverse << endl;  // reverse:  dao nguoc
   */
/*#include <iostream>
#include <string>
using namespace std;

string recursiveReverse(string orig);

string recursiveReverse(string orig) { // ham de quy
    if (orig.length() == 1) {
        return orig;
    } else {
        return orig[orig.length() - 1] + recursiveReverse(orig.substr(0, orig.length() - 1));
    }
}

int main() {
    string blogName = "java2blog";
    string reverse = recursiveReverse(blogName);
    cout << "Reverse of java2blog is: " << reverse << endl;
    return 0;
}
*/
//=========================bai 2==================================(ko hieu lam)
/*#include <iostream>
#include <cstring>
using namespace std;

bool isAnagram(string str1, string str2) {
if (str1.length() != str2.length()) {
return false;
}
int count[256] = {0};
for (int i = 0; i < str1.length(); i++) {
count[(int)str1[i]]++;
count[(int)str2[i]]--;
}
for (int i = 0; i < 256; i++) {
if (count[i] != 0) {
return false;
}
	}
return true;
}

int main() {
bool isAnagramResult = isAnagram("e", "Angle");
cout << "Are Angle and Angel anagrams: " << isAnagramResult << endl;
return 0;
}
*/
	
// bai 3
/*#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

bool hasAllUniqueChars(string word) {
    unordered_set<char> alphaSet;

    for(int index = 0; index < word.length(); index++) {
        char c = word[index];

        // If unordered_set's insert method returns false, that means it is already present in the set
        if(!alphaSet.insert(c).second)
            return false;
    }

    return true;
}

int main() {
    cout << "java2blog has all unique chars: " << hasAllUniqueChars("java2blog") << endl;
    cout << "Apple has all unique chars: " << hasAllUniqueChars("apple") << endl;
    cout << "index has all unique chars: " << hasAllUniqueChars("index") << endl;
    cout << "world has all unique chars: " << hasAllUniqueChars("world") << endl;

    return 0;
}*/

	
	
// ============= tach tu trong xau bang stringstream========
/*#include <bits/stdc++.h>

// yeu cau:
// input: python   java   php   C++
// output: 4
// dung vecto de in ra cac tu tach dc tu xau
// input: python   java   php   C++
// output: python 
//         java
//         php
//		   C++
using namespace std;
int main(){
	string s;
	getline(cin, s);
	stringstream ss(s);
	string word;
	
	
	int cnt = 0;// khoi tao bien dem cac tu rieng biet
	while(ss >> word){ // doc tutu doi tuong ss va luu nó vao word
	++cnt;
	}
	cout<< cnt << endl;
	
	
	// luu lai cac tu 
//	vector<string> v;
//	while(ss >> word){
//		v.push_back(word); // moi lan tach ra dc 1 tu ta lai luu vao tr?ng word
//	}
//	for(string x : v){
//		cout << x << endl;
//	}
return 0;
}
	
	*/
	// =============xoa tu trong xau========
/*#include <iostream>
#include <sstream>
#include <string>

using namespace std;
//input:pham truong son
//cout: nhap tu can xoa: (son)
//output:pham truong
int main() {
    string s;
    getline(cin, s);
    string word;// nhap so ptu can xoa
    cin >> word;
    stringstream ss(s);
    string token;
    while (ss >> token) { // doc tutu doi tuong ss va luu nó vao token
        if (token != word) {
            cout << token << " ";
        }
    }
    return 0;
}
*/
	

	
	
	
	
	
	
