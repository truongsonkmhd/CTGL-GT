#include <iostream>
#include <string.h>

using namespace std;

// struct thong tin cua thu cung
typedef struct ThongTin{
	char *Ma;
	char *Name;
	float Kl;
	unsigned int Age;
	char *Color;
}ThuCung;

int KiemTra(ThuCung *a, ThuCung x, int n){
	int i;
	for(i=0; i<n; i++)
		if(strcmp(a[i].Ma, x.Ma) == 0)
			return 0;
	return 1;
}
void NhapTC(ThuCung &a){
	char ma[100], name[100], color[100];

	cout << "\nNhap ma: "; cin >> ma;
	a.Ma = new char[strlen(ma) + 1];
	strcpy(a.Ma, ma);

	cout << "Nhap ten: "; cin.ignore(); cin.getline(name, 99);
	a.Name = new char[strlen(name) + 1];
	strcpy(a.Name, name);

	cout << "Nhap khoi luong: "; cin >> a.Kl;
	cout << "Nhap tuoi: "; cin >> a.Age;

	cout << "Nhap mau sac: "; cin.ignore(); cin.getline(color, 19);
	a.Color = new char[strlen(color) + 1];
	strcpy(a.Color, color);
}
void XuatTC(ThuCung a){
	cout << a.Ma << "\t" << a.Name << "\t\t" << a.Kl << "\t" << a.Age << "\t" << a.Color << endl;
}

void XuatCuaHang(ThuCung *a, int n){
	for(int i=0; i<n; i++)
		XuatTC(a[i]);
}
void XoaTC(ThuCung *a, int &n, int x){
	int i;
	n--;
	for(i=x; i<n; i++)
		a[i] = a[i+1];
}

void Menu(){
	cout << "\n\t\tMENU" << endl;
	cout << "1. Khoi tao cua hang." << endl;
	cout << "2. Nhap mot thu cung." << endl;
	cout << "3. Ban thu cung." << endl;
	cout << "4. Tim thu cung qua tuoi va mau sac." << endl;
	cout << "5. Xoa thu cung co thong tin trong luong hon gia tri." << endl;
	cout << "0. Thoat" << endl;
	cout << "\tChuc nang: ";
}

void NhapDS(ThuCung *a, int n){
	int i;
	ThuCung x;
	for(i=0; i<n; i++){
		cout << "\nNhap thu cung thu " << i << ":\n";
		NhapTC(x);
		if(KiemTra(a, x, i) == 1)
			a[i] = x;
		else{
			cout << "Vui long kiem tra lai ma thu cung!";
			i--;
		}
	}
}

void BanThu(ThuCung *a, char *ma, int &n){
	int i, d = 0;
	for(i=0; i<n; i++)
		if(strcmp(a[i].Ma, ma) == 0){
			d = 1;
			break;
		}
	if(d == 0)
		cout << "Ma thu cung ban nhap khong co trong cua hang.";
	else{
		cout << "\n\tThong tin:";
		cout << "\nTen:" << a[i].Name;
		cout << "\nTrong luong:" << a[i].Kl;
		cout << "\nTuoi:" << a[i].Age;
		cout << "\nGia:" << 100 + a[i].Kl*2 - a[i].Age << " (USD)";
		n--;
		for(; i<n; i++)
			a[i] = a[i+1];
	}
}

void Search(ThuCung *a, int n, char *ma, char *color){
	cout << "\n\tDanh sach thu cung theo yeu cau:\n";
	int i;
	for(i=0; i<n; i++)
		if(strcmp(a[i].Ma, ma) == 0 && strcmp(a[i].Color, color) == 0)
			XuatTC(a[i]);
}

void XoaTCK(ThuCung *a, int &n, float k){
	int i;
	for(i=0; i<n; i++)
		if(a[i].Kl >= k){
			XoaTC(a, n, i);
			i--;
		}
	cout << "\n\tDanh sach thu cung con lai\n";
	XuatCuaHang(a, n);	
}
int main(){
	ThuCung *a;
	a = new ThuCung;
	int n, k1, k2;
	do{
		Menu();
		cin >> k1;
		switch(k1){
			case 1:{
				a = new ThuCung;
				n = 0;
				cout << "\n\t\tDa khoi tao cua hang.\n";
				break;
			}
			case 2:{
				cout << "\n1. Nhap theo so luong.";
				cout << "\n2. Nhap lan luot.";
				cout << "\n\tChuc nang: ";	cin >> k2;
				switch (k2){
					case 1:{
						cout << "\nNhap so luong: "; cin >> n;
						a = new ThuCung[n-1];
						NhapDS(a, n);
						break;;
					}
					case 2:{
						ThuCung x;
						int i = 0;
						char c;
						do{
							NhapTC(x);
							if(KiemTra(a, x, i) == 1){
								a[i] = x;
								i++;
								a = new ThuCung;
							}else	
								cout << "Ma so vua nhap da xuat hien trong danh sach!\n\tVui long kiem tra lai.\n";
							cout << "Ban muon nhap tiep khong?(y/n) ";	cin >> c;
						}while(c != 'n');
						break;
					}
				}
				break;
			}
			case 3:{
				char ma[100];
				cout << "\nBan thu:\n";
				cout << "Nhap ma thu muon mua: "; cin >> ma;
				BanThu(a, ma, n);
				break;
			}
			case 4:{
				char ma[100], color[100];
				cout << "Nhap ma: ";	cin >> ma;
				cout << "Nhap mau sac: ";	cin.ignore();	cin.getline(color, 99);
				Search(a, n, ma, color);
				break;
			}
			case 5:{
				float kl;
				cout << "Nhap khoi luong: "; cin >> kl;
				XoaTCK(a, n, kl);
				break;
			}
			case 0:{
				cout << "\n\n\t\tHen gap lai!";
				break;
			}
		}
	}while(k1 != 0);
	return 0;
}
