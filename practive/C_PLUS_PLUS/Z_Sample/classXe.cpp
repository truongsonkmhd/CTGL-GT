#include <iostream>
#include <string.h>

using namespace std;

class XeMay{
	public:
	float giaXe;
	string nhaSanXuat;
	printlnFo(){
		cout << "Gia xe: " << giaXe << endl;
		cout << "Nha san xuat: " << nhaSanXuat << endl;
	}
};
class HangHoa{
	public:
	XeMay Xe;
	string maH;
	string tenH;
	int soluongH;
	printlnFo(){
		cout << "\nMa: " << maH << endl;
		cout << "Ten: " << tenH << endl;
		cout << "So luong: " << soluongH << endl;
		Xe.printlnFo();
	}
};
HangHoa Nhap(){
	HangHoa a;
	string s;
	cout << "\nNhap ma: ";cin >> a.maH;
	getline(cin, s); 
	cout << "Nhap ten: ";getline(cin, a.tenH);
	cout << "Nhap so luong: "; cin >> a.soluongH;
	cout << "Nhap gia: "; cin >> a.Xe.giaXe;
	getline(cin, s);
	cout << "Nhap nha san xuat: "; cin >> a.Xe.nhaSanXuat;
	return a;
}

int main(){
	int k;
	int n;
	HangHoa *a;
	do{
		cout << "\n1. Nhap n mat hang";
		cout << "\n2. Hien thi xe gia < 25tr";
		cout << "\n3. So luong, doanh thu cua hang Honda";
		cout << "\n4. Ten xe co gia thap nhat";
		cout << "\n0. Thoat";
		cout << "\n\tChuc nang: ";
		cin >> k;
		switch(k){
			case 1:{
				cin >> n;
				a = new HangHoa[n];
				for(int i=0; i<n; i++)
				a[i] = Nhap();
				break;
			}
			case 2:{
				cout << "Danh sach xe co gia nho hon 25 trieu la:\n ";
				for(int i=0; i<n; i++)
					if(a[i].Xe.giaXe < 25)	
						a[i].printlnFo();
				break;
			}
			case 3:{
				int count = 0, tien = 0;
				for(int i=0; i<n; i++)
					if(a[i].Xe.nhaSanXuat == "Honda"){
						count++;
						tien += a[i].Xe.giaXe;
					}
				cout << "\nso luong: " << count;
				cout << "\nTong tien: " << tien;
				break;
			}
			case 4:{
				float min = a[0].Xe.giaXe;
				string s = a[0].tenH;
				for(int i=1; i<n; i++)
					if(a[i].Xe.giaXe < min){
						min = a[i].Xe.giaXe;
						s = a[i].tenH;
					}
				cout << s;
				break;
			}
			
		}
	}while(k != 0);
		
}
