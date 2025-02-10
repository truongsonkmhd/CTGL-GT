#include<bits/stdc++.h>
#include <map> // khong cho phep luu nhieu key giong nhau // co thu tu
#include<unordered_map> // cho phep luu nhieu key giong nhau // co thu tu
#include <string>
using namespace std;
//(key ,value)
//insert
//count
//fint
//erase
//orsered // tự sắp xếp

int main(){
	//========================map================================
	//cong dung: so lan xuat hien cua tung phan tu dc dem bang cach su dung mot bo
	//dem(map) duoc luu tru trong bien "mp"
	map<int, int> mp;
	mp[1]=200;
	mp[2]=300;
	mp.insert({3, 400});
	mp.insert({4,500});
	
	for(pair<int,int> x : mp){
	cout<<x.first << " "<<x.second << endl;
	}
	cout<<"============================"<<endl;
	
	mp.erase(100);
	for(auto it : mp){
	cout << it.first << " "<<it.second<<endl;
	}
	
	for(map<int,int>::iterator it = mp.begin(); it != mp.end() ; it++){
		cout<<(*it).first << " " << (*it).second << endl;
	}
	if(mp.find(100)!=mp.end()){ // O(log(n))
	// hoac
	//if(mp.count(100)!=0()){
	cout<<"Found"<<endl;
	} else {
	cout<<"not Found"<<endl;
	}
	
//8 
//1 1 2 1 3 4 1 -4
//output
//1 4
//2 1
//3 1
//5 1
//-4 1

    /*
    map<int, int> mp;
	cout<<"Nhap so phan tu mang: ";
	int n; cin>>n;
	for(int i = 0; i < n; i++){
		int x; cin>>x;
		mp[x]++;
	}
	for(auto it : mp){ // dung de duyet cac phan tu cua map
					   //bien 'it' duoc khai bao tu dong va se luu tru mot phan tu 'mp' o moi lan lap
		cout<<"So lan xuat hien cua: "<<it.first << " la " <<it.second <<endl;
		//it.first tra ve gia tri cua key trong phan tu hien tai và it.second tra ve gia tri cua value tuong ?ng.
	}
    */

	//=>>>>>key cua map mac dinh sap xep
	
	//cach khong sap xep key
	
	map<int, int> mp;
	cout<<"Nhap so phan tu mang: ";
	int n; cin>>n;
	int a[1000];
	for(int i = 0; i < n; i++){
		cin>>a[i];
		mp[a[i]]++;
	}
	for(int i = 0; i < n; i++){
		if(mp[a[i]] !=0){
			cout << a[i] << " " <<mp[a[i]] << endl;
			mp[a[i]] = 0;
		}
	}

	//su dung map trong "String" (in theo thu tu a,b,c,d bang chu cai theo thu tu tang dan
//9
//python
//java
//string 
//java
//python
//c++
//sql
//java
//python 

/*
// demo nhap xuat
map<string, int> mp;
cout<<"Moi ban nhap so ptu cua mang: ";
int n; cin>>n;
for(int i = 0; i<n ; i++){
string s; cin>>s;
mp[s]++;
}
cout<<"==================================";
for(auto it : mp){
	cout<<it.first << " " <<it.second <<endl;
}*/
//demo tim ptu co tan suat nhieu nhat trong mang

    /*map<string, int> mp;
    int n;
    cin >> n;
    if (n < 1) {
        cout << "Nhap vao khong hop le!!!!!" << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        mp[s]++;
    }
    cout << "==================================" << endl;
    int max_fre = 0;
    string res;
    for (auto it : mp) {
        if (it.second > max_fre) {
            max_fre = it.second;
            res = it.first;
        }
    }
    cout << res << " " << max_fre << endl;

    // tim kiem phan tu co cung tan so xuat hien
    for (auto it : mp) {
        if (it.second == max_fre && it.first != res) {
            cout << it.first << " " << max_fre << endl;
        }
    }*/
    
    
    //=============multimap=====================
/*    multimap<int, int> mp;
    mp.insert({1,100});
    mp.insert({2,200});
    mp.insert({1,200});
    for(auto it  :mp){
	cout<< it.first << " "<< it.second << endl;
	}
	cout<<mp.count(1)<<endl;
	*/
    return 0;
}
