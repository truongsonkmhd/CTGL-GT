/*
//1:

#include <iostream>

using namespace std;

long GT(int n){
	if(n <= 1)	return 1;	// dieu kien dung
	return n*GT(n-1);	// cong thuc de quy
}

int main(){
	int n;
	cin >> n;
	if(n < 0)	return 0;	// neu n am thi k thuc hien
	cout << GT(n);
	return 0;
}

// 2:
#include <iostream>

using namespace std; 

void Buble_Sort(int n, int A[]){
	for(int i=0; i<n - 1; i++){
		int d = 1; // bien kiem tra xem da sap xep giam dan chua
		for(int j = 0; j< n - i - 1; j++)
			if(A[j] > A[j+1]){
				int t = A[j];
				A[j] = A[j+1];
				A[j+1] = t;
				d = 0;
			}
		if(d == 1)	// Da sap xep thi dung chuong trinh
			break;
	}
}
int main(){
	int n;	cin >> n;
	int A[n];
	for(int i=0; i<n; i++)
		cin >> A[i];
	Buble_Sort(n, A);
	for(int i=0; i<n; i++)
		cout << A[i] << " ";
	return 0;
}


//3:
#include <iostream>

using namespace std;

typedef struct Node{
	int value;
	Node* next;
}Node;

Node *ChenDau(Node *&head, int x){
	Node *p = new Node;
	p->value = x;
	p->next = head;
	return p;
}
Node* TimKiem(Node *head, Node *q){
	Node *i = head;
	while(i != NULL){
		if(i == q)	return i;	// tra ve node can tim trong list
		i = i->next;
	}
	return NULL; //  neu khong co not q
}
void Chen2(Node *&head, Node *p, Node *q){
	Node *i = head;
	while(i != NULL){
		if(i->next == q) { // chen vao trc node q
			p->next = q;
			i->next = p;
			return;
		}
		i = i->next;
	}
}
void Xuat(Node *head){
	Node *p = head;
	while(p != NULL){
		cout << p->value << " ";
		p = p->next;
	}
}
int main(){
	int n;
	cout << "Nhap n: "; cin >> n;
	Node *head = NULL;
	int x;	
	for(int i=0; i<n; i++){
		cin >> x;
		head = ChenDau(head, x);
	}
	Xuat(head);	cout << endl;
	cout << "Nhap vi tri node q: "; cin >> x;
	Node *i = head;
	while(x > 1){
		i=i->next;
		x--;
	}
	Node *q = i;
	cout << "Nhap gtri can chen: "; cin >> x;
	Node *p = new Node;
	p->value = x;
	Chen2(head, p, q);
	Xuat(head);
}
*/
// them/ lay
// 4:

#include <iostream>

using namespace std;

typedef struct Node{
	int data;
	Node *next;
}node;

struct Queue{
	Node *dau;
	Node *cuoi;
};
int Rong(Queue q){
	if(q.dau == NULL)
		return 1;
	return 0;
}
void Them(Queue &q, int x){
	Node *p = new Node;
	p->data = x;
	p->next = NULL;
	if(Rong(q) == 1){
		q.dau = p;
		q.cuoi = p;
		return;
	}
	q.cuoi->next = p;
	q.cuoi = p;
}
int Lay(Queue &q){
	if(Rong(q) == 1){
		return 0;
	}
	Node *p = q.dau;
	int datas = p->data;
	q.dau = p->next;
	delete p;
	if(q.dau == NULL)
		q.cuoi = NULL;
	return datas;	
}
void Xuat(Queue q){	
	Node *i = q.dau;
	while(i != q.cuoi->next){
		cout << i->data << " ";
		i = i->next;
	}
}
int main(){
	int n; cin >> n;
	int x;
	Queue q;
	q.dau = NULL;
	q.cuoi = NULL;
	for(int i=0; i<n; i++){
		cin >> x;
		Them(q, x);
	}
	Xuat(q);
	Lay(q);
	cout << endl;
	Xuat(q);
}

