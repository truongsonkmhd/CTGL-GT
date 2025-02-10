/*#include <iostream>

using namespace std;

typedef struct Node{
	int value;
	Node* next;
}Node;
Node* Search(Node *head, int q){
	Node *i = head;
	int x = 0;
	while(i != NULL){
		if(x == q)	return i;
		i = i->next;
		x++;
	}
	return NULL;
}
Node *Add(Node *head, int x){
	Node *p = new Node;
	p->value = x;
	p->next = NULL;
	if(head == NULL)	return p;
	Node *i = head;
	while(i->next != NULL)
		i = i->next;
	i->next = p;
	return head;
}
void XuatList(Node *head){
	Node *p = head;
	while(p != NULL){
		cout << p->value << " ";
		p = p->next;
	}
}
Node* deleteDuplicates(Node* head){ // Xoa cac phan tu trung lap
    Node *i = head;
    while(i != NULL){
        Node *j = i->next;
        Node *t = i;
        while(j != NULL){
            if(i->value == j->value)
            	t->next = j->next;
			else{
				t = t->next;
			}
			j = j->next;	
        }
        i = i->next;
    }
    return head;
}

void Delete2(Node *head, int q){
	Node *i = head;
	int x = 0;
	while(i != NULL){
		if(x == q) i->next = i->next->next;
		i = i->next;
	}
}
Node* convert(Node* head){ // Noi a1 a2 b1 b2 -> a1 b1 a2 b2
	int dem = 0;
	Node *i = head;
	while(i != NULL){
		i=i->next;
		dem++;
	}
	dem /= 2;
	i = head;
	while(dem > 1){
		i = i->next;
		dem--;
	}
	Node *pb = i->next;
	Node *pa = head;
	while(pb->next != NULL){
		i->next = pb->next;
		pb->next = pa->next;
		pa->next = pb;
		pa = pa->next->next;
		pb = i->next;
	}
    return head;
}
Node* insert(Node* head, int value){ // Chen ma khong thay doi trat tu
	Node *p = new Node;
	p->value = value;
	p->next = NULL;
	if(head == NULL) return p;
	
	int d = -1; // Giam
	if(head->value < head->next->value)	d = 1;
	
	Node *i = head;
	if(i->value*d > value*d){
		p->next = head;
		return p;
	}
	while(i->next != NULL){
		if(i->next->value*d > value*d){
			p->next = i->next;
			i->next = p;
			return head;
		}
		i = i->next;
	}
	if(i->value*d > value*d)
		i->next = p;
		return head;
}
void rotate(Node* &head, int k){
    if(k == 0)  return;
    Node *i = head;
    Node *j = head;
    while(i->next != NULL){
        k--;
        if(k == 0){
        	head = i->next;
			i->next = NULL;
			i = head;	
		}
		i=i->next;
    }
    i->next = j; 
}*/
#include <iostream>
#include <string.h>

using namespace std;

typedef struct Node{
	int valude;
	Node* next;
}Node;

Node *AddFirstD(Node *&head, int x){
	Node *p = new Node;
	p->valude = x;
	p->next = head;
	return p;
}
Node* SearchD(Node *&head, Node *&q){
	Node *i = head;
	while(i != NULL){
		if(i == q)	return i;
		i = i->next;
	}
	return NULL;
}
void DeleteD(Node *&head, Node *&q){
	Node *i = head;
	while(i != NULL){
		if(i == q) i->next = i->next->next;
		i = i->next;
	}
}
void XuatListD(Node *&head){
	Node *p = head;
	while(p != NULL){
		cout << p->valude << " ";
		p = p->next;
	}
}
int main(){
	int n;
	cout << "Nhap sl: "; cin >> n;
	Node *p = NULL;
	for(int i=0; i<n; i++){
		int x;	cin >> x;
		p = AddFirstD(p, x);
	}
//	rotate(p, 3);
	XuatListD(p);
}
