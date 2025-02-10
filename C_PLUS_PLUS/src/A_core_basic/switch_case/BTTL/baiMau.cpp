#include <iostream>
#include <math.h>
using namespace std;
int main()
{
char toantu;
float so1, so2, ketQua;
bool kt = true;
cout<<"Nhap toan hang thu nhat: "; cin >> so1;
cout<<"Nhap toan tu: "; cin >> toantu;
cout<<"Nhap toan hang thu hai: "; cin >> so2;
switch (toantu)
{
case '+':
ketQua = so1 + so2;
break;
case '-':
ketQua = so1 - so2;
break;
case '*':
ketQua = so1 * so2;
break;
case '/':
if (so2 != 0)
ketQua = so1 / so2;
else
kt = false;
break;
default:
cout<<"Toan tu khong hop le!";
}
cout << "---------------------------------" << endl;
if (kt)
cout<<so1<<" "<<toantu<<" "<<so2<<" = "<<ketQua;
else
cout<<"Khong the thuc hien phep chia cho 0"<<
endl;
return 0;
}
