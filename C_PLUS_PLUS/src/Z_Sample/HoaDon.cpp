#include <iostream>
#include <math.h>

using namespace std;

//long DeQuy(int n){
//	if(n == 1)	return 1;// diem dung khi n = 1
//	return pow(n, n)*DeQuy(n-1); // thuc hien lai goi ham
//}
//int main(){
//	int n;
//	cout << "Nhap n > 0: "; cin >> n;
//	if(n > 0){
//		cout << "Gia tri cua bieu thuc la: " << DeQuy(n);
//	}else
//		cout << "n <= 0";
//	return 0;
//}


//int main(){
//	int n;
//	cout << "Nhap so luong: "; cin >> n;
//	if(n > 0){ // kiem tra n > 0 thi thuc hien chuong trinh
//		int a[n];
//		int sum = 0;// tong
//		for(int i=0; i<n; i++){
//			cin >> a[i];// doc so
//			if(a[i] % 2 == 1)
//			sum += a[i];// neu la so le thi cong vao tong
//		}
//		cout << "Tong so le la: " << sum;
//	}else
//		cout << "Nhap n lon hon 0";
//	return 0;
//}

//int main(){
//	int n;
//	cout << "Nhap so luong: "; cin >> n;
//	if(n > 0){ // kiem tra n > 0 thi thuc hien chuong trinh
//		int a[n];
//		int sum = 0;// tong
//		int count = 0; // so luong so le
//		for(int i=0; i<n; i++){
//			cin >> a[i];// doc so
//			if(a[i] % 2 == 1)
//				count++; // neu la so le tang dem len 1
//			sum += a[i];// cong vao tong
//		}
//		cout << "TBC la: " << fixed << setprecision(2) << sum/n << endl;
//		cout << "So luong so le la: " << count;
//	}else
//		cout << "n <= 0";
//	return 0;
//}
//void ThucHien(char d){
//	string name;
//	int price;
//	int value;
//	cout << "\nNhap ten: "; getline(cin, name); // nhajap car khoang trang
//	cout << "Nhap don gia: "; cin >> price;
//	cout << "Nhap so luong: "; cin >> value;
//	cout << "Mat hang " << name << " tong tien: " << price*value << endl;
//	char c;
//	cout << "Ban muon nhap tiep khong(c/k)?";
//	cin >> c;
//	if(c == 'k' || c == 'K')
//		return;// ket thuc chuong trinh
//	cin.ignore(); // doc dau xuong dong
//	ThucHien(c);// thuc hien lai chuong trinh
//}
//int main(){
//	ThucHien('y');
//	return 0;
//}
