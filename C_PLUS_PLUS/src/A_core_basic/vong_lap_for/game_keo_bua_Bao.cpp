/*#include <iostream>
#include <cstdlib> //dung cho "rand()" and "srand()"
#include <ctime> // dung cho "time()"
using namespace std;
int main(){
	long long may, Nguoi;
	int luachoncuanguoi;
	srand(time(NULL));// khoi tao mot day so ngau nhien 
	//co "n" lua chon, voi n= so max, m= so min =>  co cong thuc la 
	//Computer = rand()%n+m
	//vd: 1->3
	may = rand()%3+1; // rand viet tat cua: random
	cout<<"1.Bua"<<endl;
	cout<<"2.Keo"<<endl;
	cout<<"3.Bao"<<endl;
	cout<<"Moi ban nhap lua chon  :";
	cin>>luachoncuanguoi;
	switch(luachoncuanguoi){
		case 1:
			cout<<"May ra :"<<may<<endl;
			if(may==1) {
				cout<<"hoa nhau";
				}
			else if(may==2) {
			cout<<"Nguoi lose";
			}
			else cout<<"Nguoi win";
			break;
		case 2:
			cout<<"May ra :"<<may<<endl;
			if(may==1) { 
			cout<<"Nguoi win";
			}
			else if(may==2) {
			cout<<"hoa nhau";
			}
			else cout<<"Nguoi lose";
			break;
		case 3:
			cout<<"May ra :"<<may<<endl;
			if(may==1) {
			cout<<"Nguoi win";
			}
			else if(may==2) {
			cout<<"Nguoi lose";
			}
			else cout<<"hoa nhau";
			break;
	default:
		cout<<"Vui long nhap lai!!!!";
	}
	return 0;
}
*/
#include <bits/stdc++.h>
#include <vector>
using namespace std;

void doitien(int t, vector<int> menh_gia){
int SoToTien;
for(int i=0; i<menh_gia.size(); i++){
SoToTien = t / menh_gia[i];
if(SoToTien != 0){
cout << "Co " << SoToTien << " to " << menh_gia[i] << endl;
}
t = t - SoToTien * menh_gia[i];
}
}

int main(){
int t;
cout << "Nhap so can doi tien: ";
cin >> t;
if(t >= 1000){
vector<int> menh_gia = {10000, 5000, 2000, 1000};
doitien(t, menh_gia);
}else {
cout << "So tien ban vua nhap ho hon muc quy dinh!!! Vui long xem lai." << endl;
}
return 0;
}
