#include <iostream>
#include <string.h>

using namespace std;

typedef struct Nut{
	int mahang;
	int kl;
	int dongia;
	string ten;
	struct Nut *next;
}DSTC;

void Add(DSTC *& head, int mahang, int kl, int dg, string ten){
	Nut *p = new Nut;
	Nut->mahang = mahang;
	Nut->kl = kl;
	Nut->dongia = dongia;
	Nut->ten = ten;
	Nut->next = head;
	head = Nut;
}
void Bill(DSTC *head, int mahang){
	Nut *p = head;
	while(p != NULL){
		if(p->mahang == mahang){
			cout << p->kl*p->dongia << endl;
			return;
		}
	abc_	
	}
}
int main(){
	
}
