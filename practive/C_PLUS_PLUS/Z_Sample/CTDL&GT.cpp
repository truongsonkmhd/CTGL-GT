#include <iostream>
#include <math.h>
using namespace std;
int KT(long n){
	long sum = 0;
	for(long i=1; i<n; i++)
		if(n % i == 0){
			sum += i;
		}
	if(sum == n)	return 1;
	return 0;
}
typedef struct Node{
	long data;
	Node* next;
}Node;
typedef struct {
	Node *Dau;
	Node *Cuoi;
}List;
void KhoiTao(List &L){
	L.Dau = NULL;
	L.Cuoi = NULL;
}
void Add(List &L, long datas){
	Node *p = new Node;
	p->data = datas;
	p->next = NULL;
	if(L.Dau == NULL){
		L.Dau = p;
		L.Cuoi = p;
	}else{
		L.Cuoi->next = p;
		L.Cuoi = p;
	}	
}

int main(){
	long n, x = -1;
	cin >> n;
	List L;
	KhoiTao(L);
	for(long i=0; i<n; i++){
		cin >> x;
		Add(L, x);
	}
	int d = 0;
	Node *i = L.Dau;
	while(i != NULL){
		if(KT(i->data) == 1){
			if(d == 0){
				cout << i->data << " ";
				d = 1;
			}
			x = i->data;
		}
		i=i->next;
	}
	if(d == 0)	cout << -1;
	else	cout << x;
}
