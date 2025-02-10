#include <iostream>
#include <string.h>

using namespace std;

// struct thong tin cua thu cung
typedef struct ThongTin{
	char Ma[11];
	char Name[101];
	float Kl;
	unsigned int Age;
	char Color[20];
}ThuCung;

void NhapTC(ThuCung &a){
	cout << "\nNhap ma: "; cin >> a.Ma;
	cout << "Nhap ten: "; cin.ignore(); cin.getline(a.Name, 99);
	cout << "Nhap khoi luong: "; cin >> a.Kl;
	cout << "Nhap tuoi: "; cin >> a.Age;
	cout << "Nhap mau sac: "; cin.ignore(); cin.getline(a.Color, 19);
}
void XuatTC(ThuCung a){
	cout << a.Ma << "\t" << a.Name << "\t\t" << a.Kl << "\t" << a.Age << "\t" << a.Color << endl;
}

// struct node
typedef struct Node{
	ThuCung data;
	Node* next;
}Node;
typedef struct Node* node;

// struct list
typedef struct List{
	node pHead;
	node pTail;
}L;

void KhoiTao(List &L){
	L.pHead = NULL;
	L.pTail = NULL;
}

bool KTMa(List l, ThuCung x){
	node p = l.pHead;
	while(p != NULL){
		if(strcmp(p->data.Ma, x.Ma) == 0)
			return false;
		p = p->next;
	}
	return true;
}
node TaoNode(ThuCung x){
	node p = new Node;
	p->data = x;
	p->next = NULL;
	return p;
}
void Them(List &l, node p){
	if (l.pHead == NULL){
		l.pHead = p;
		l.pTail = p;
	}else{
		l.pTail->next = p;
		l.pTail = p;
		p->next = NULL;
	}
}
void XuatList(List l){
	node p = l.pHead;
	while(p != NULL){
		XuatTC(p->data);
		p = p->next;
	}
}
int SearchAndDelete(List l, char *ma){
	node p = l.pHead, prev;
	int d = 0;
	while(p != NULL && strcmp(p->data.Ma, ma) != 0){
		prev = p;
		p = p->next;
		}
	if(prev == NULL || p == NULL){
		cout << "\n\tKhong the tim thay thu cung co ma vua nhap!\n";
		return 0;
	}
	cout << "\n\tThong tin:";
	cout << "\nTen:" << p->data.Name;
	cout << "\nTrong luong:" << p->data.Kl;
	cout << "\nTuoi:" << p->data.Age;
	cout << "\nGia:" << 100 + p->data.Kl*2 - p->data.Age << " (USD)";
	prev->next = p->next;
	delete p;
	return 1;
}
void Search(List l, int age, char *s){
	node p = l.pHead;
	int count = 0;
	cout<<"\n\t\tDANH SACH THU CUNG THEO YEU CAU\n";
	while(p != NULL){
		if(p->data.Age == age && strcmp(p->data.Color, s) == 0){
			XuatTC(p->data);
			count++;
		}
		p = p->next;
	}
	if(count == 0)
		cout << "\n\tKhong co thu cung hop le!";
}
void Delete(List l, int k){
	node p = l.pHead, prev;
	while(p != NULL){
		if(p->data.Kl > k){
			prev->next = p->next;
			if(prev == NULL)
				break;
			p = prev->next;
		}else{
			prev = p;
			p = p->next;	
		}
	}
	p = l.pHead;
	while(p != NULL){
		XuatTC(p->data);
		p = p->next;
	}
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

int main(){
	List list;
	int luachon, n;
	
	do{
		Menu();
		cin >> luachon;
		switch(luachon){
			case 1:{
				KhoiTao(list);
				cout << "\n\tDa khoi tao cua hang!\n";
				n = 0;
				break;
			}
			case 2:{
				cout << "\n\tNhap thong tin cua thu cung:\n";
				ThuCung a;
				NhapTC(a);
				if(KTMa(list, a) == true){
					node p = TaoNode(a);
					Them(list, p);
				}else
					cout << "\n\tVui long kiem tra lai ma!\n";
				break;
			}
			case 3:{
				cout << "\n\tBan thu cung: \n";
				char ma[100];
				cout << "Nhap ma: "; cin >> ma;
				SearchAndDelete(list, ma);
				break;
			}
			case 4:{
				cout << "\n\tTim danh sach thu cung qua tuoi va mau sac.\n";
				int age;
				char color[100];
				cout << "Nhap tuoi: "; cin >> age;
				cout << "Nhap mau sac: "; cin.ignore(); cin.getline(color, 99);
				Search(list, age, color);
				break;
			}
			case 5:{
				cout << "\n\tXoa thu cung co trong luong hon gtri k.";
				float k;
				cout << "\nNhap khoi luong can loai: "; cin >> k;
				Delete(list, k);
				break;
			}
			case 0:{
				cout << "\n\t\tHen gap lai!\n";
				break;
			}
		}
	}while(luachon != 0);
}
