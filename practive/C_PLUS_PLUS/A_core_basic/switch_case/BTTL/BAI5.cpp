#include <iostream>
#include <math.h>
using namespace std;
int main(){
int a,b,c;
int luachon,tong=0,tich=0;
long long x;
cout<<"Nhap vao lan luot gia tri a,b,c  "<<endl; cin>>a>>b>>c;
cout<<"1. Tinh tong a+b+c"<<endl;
cout<<"2. Tinh tich a*b*c"<<endl;
cout<<"3. Giai pt ax+b=c"<<endl;
cout<<"0. Thoat"<<endl;
cout<<"Moi ban nhap lua chon:"; cin>>luachon;
switch(luachon){
case 1:
	tong=a+b+c;
	cout<<"tong 3 so la:"<<tong;
	break;
case 2:
	tich=a*b*c;
	cout<<"tich 3 so la:"<<tich;
	break;
case 3:
	if(a == 0){
		cout<<"PT vo ngiem"<<endl;
		}
	else
	{
		x=(c-b)/a;
		cout<<"PT co 1 nghiem duy nhat ="<<x<<endl;
		}
		break;
default :
	cout<<"Thoat chuong trinh thanh cong";
}
	return 0;
		}
