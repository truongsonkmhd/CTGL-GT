#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

struct Sach{
	char name[201];
	char ISBN[11];
	char Tg[41];
	char NN[30];
	int year;
	float gia;
	int sl;
};
void XoaEnter(char *s){
	if(s[strlen(s) - 1] == '\n')
		s[strlen(s) - 1] = '\0';
}
Sach Nhap(){
	Sach a;
	cout << "\nNhap ten sach: "; cin.ignore(); cin.getline(a.name, 200);	XoaEnter(a.name);
	cout << "Nhap ISBN: "; cin >> a.ISBN;
	cout << "Nhap ten tac gia: "; cin.ignore(); cin.getline(a.Tg, 40); XoaEnter(a.Tg);
	cout << "Nhap ngon ngu sach: "; cin.getline(a.NN, 30); XoaEnter(a.NN);
	cout << "Nhap nam xuat ban: "; cin >> a.year;
	cout << "Nhap gia(USD): "; cin >> a.gia;
	cout << "Nhap so luong: "; cin >> a.sl;
	return a;
}
void XuatSach(Sach a){
	cout << setw(30) << left << a.name << setw(12) << a.ISBN << setw(30) << a.Tg << setw(20) << a.NN << setw(10) << a.year << setw(10) << fixed << setprecision(2) << a.gia << setw(10) << a.sl << endl;
}
struct Node{
	Sach data;
	Node* next;
};
struct List{
	Node* Dau;
	Node* Cuoi;
};
void KhoiTao(List &L){
	L.Dau = NULL;
	L.Cuoi = NULL;
}
Node* TaoNode(Sach x){
	Node *p = new Node;
	p->data = x;
	p->next = NULL;
	return p;
}
void Add(List &l, Node* p){
	if(l.Dau == NULL){
		l.Dau = p;
		l.Cuoi = p;
	}else{
		l.Cuoi->next = p;
		l.Cuoi = p;
		p->next = NULL;
	}
}
void XuatList(List l){
	cout << setw(30) << left << "Ten sach" << setw(12) << "ISBN" << setw(30) << "Tac gia" << setw(20) << "Ngon ngu" << setw(10) << "Nam" << setw(10) << "Gia(USD)" << setw(10) << "So luong" << endl;
	Node *p = l.Dau;
	while(p != 0 ){
		XuatSach(p->data);
		p = p->next;
	}
}
void ChucNang2(List &l, Sach x, int n){
	Node *p = l.Dau;
	while(p != NULL){
		if(strcmp(p->data.ISBN, x.ISBN) == 0){
			p->data.sl += x.sl;
			return;
		}
		p = p->next;
	}
	Add(l, TaoNode(x));
	n++;
}
void ChucNang3(List &l, char *s){
	Node *p = l.Dau;
	while(p != NULL){
		if(strcmp(p->data.ISBN, s) == 0){
			if(p->data.sl == 0){
				cout << "\n\tHet hang!";
				return;
			}
			cout << "\n\tThong tin sach: ";
			cout << "\t" << p->data.name << " gia: " << p->data.gia << "USD\n";
			p->data.sl--;
			return; 
		}
		p = p->next;
	}
	cout << "\n\tSach khong co trong kho!";
}
void ChucNang4(List l, char *s){
	Node *p = l.Dau;
	while(p != NULL){
		if(strcmp(p->data.name, s) == 0)	XuatSach(p->data);
		p = p->next;
	}
}
void ChucNang5(List &l, int k){
	Node* p = l.Dau;
	Node* prev;
	while(p != NULL){
		if(p->data.sl < k){
			prev->next = p->next;
			if(prev == NULL)
				break;
			p = prev->next;
		}else{
			prev = p;
			p = p->next;	
		}
	}
}
void Menu(){
	cout << "\n\n================MENU===============";
	cout << "\n1. Khoi tao kho.";
	cout << "\n2. Nhap sach.";
	cout << "\n3. Ban sach.";
	cout << "\n4. Tim thong tin sach.";
	cout << "\n5. Loai bo sach it hon k quyen.";
	cout << "\n6. Xuat sach trong kho.";
	cout << "\n0. Thoat.";
	cout << "\n\tChuc nang: ";
}
int main(){
	int luaChon, n = -1;
	List list;
	do{
		Menu();
		cin >> luaChon;
		switch(luaChon){
			case 1:{
				KhoiTao(list);
				n = 0;
				cout << "\n\tDa khoi tao kho sach!";
				break;
			}
			case 2:{
				Sach x;
				x = Nhap();
				ChucNang2(list, x, n);
				break;
			}
			case 3:{
				char isbn[11];
				cout << "\nNhap ISBN sach muon mua: "; cin >> isbn;
				ChucNang3(list, isbn);
				break;
			}
			case 4:{
				char ten[100];
				cout << "\nNhap ten sach: "; cin.ignore(); cin.getline(ten, 99);	XoaEnter(ten);
				ChucNang4(list, ten);
				break;
			}
			case 5:{
				int k;
				cout << "Nhap nguong: "; cin >> k;
				ChucNang5(list, k);
				break;
			}
			case 6:{
				XuatList(list);
				break;
			}
			case 0:{
				cout << "\n=============Ket thuc=============";
				break;
			}
		}
	}while(luaChon != 0);
}
