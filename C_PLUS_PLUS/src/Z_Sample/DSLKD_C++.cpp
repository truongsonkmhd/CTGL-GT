#include <iostream>

using namespace std;

typedef struct Node{
	int value;
	Node *next;
}Node;
Node* Nhap(Node *head, int x){
	Node *p = new Node;
	p->value = x;
	p->next = NULL;
	if(head == NULL)	return p;
	
	Node *i = head;
	while(i->next != NULL){
		i = i->next;
	}
	i->next = p;
	return head;
}
void Xuat(Node *head){
	Node *p = head;
	while(p != NULL){
		cout << p->value << " ";
		p = p->next;
	}
	cout << endl;
}
Node* deleteSingle(Node* head){
    if(head->next == NULL)  return NULL;
    int d;
    while(head->value != head->next->value){
    	head = head->next;
	}
    Node *sau = head->next->next;
    Node *trc = head->next;
    Node *trcNua = head;
    while(sau != NULL){
			d = 1;
        if(trc->value != sau->value){
            if(sau->next == NULL){
                trc->next = NULL;
                return head;
            }
            if(trcNua->value != trc->value){
                trcNua->next = sau;
                trc = sau;
                sau = sau->next;
                d = 0;
			}
        }
        if(d == 1){
            trcNua = trc;
            trc = sau;
            sau = sau->next;
        }
        Xuat(head);
    }
    return head;
}
//Node* deleteSingle(Node* head){
//	Node* p = head;
//	Node* pp;
//	
//	int duyet=0;
//	while(p != NULL){
//		pp = p;
//		p = p->next;
//		if((duyet==0 && pp->value!=p->value) || (pp->value!=p->value && p->value!=p->next->value) || (p->next==NULL)){
//			break;
//		}
//		duyet += 1;
//	}
//	
//	if(duyet==0){
//		return p;
//	}else{
//		if(p->next == NULL){
//			delete p;
//			pp->next = NULL;
//		} 
//		else pp->next = p->next;
//		return head;
//	}
//	
//}
int main(){
	Node *a = NULL;
	int x;
	do{
		cin >> x;
		if(x == -1)	break;
		a = Nhap(a, x);
	}while(1);
	deleteSingle(a);
	Xuat(a);
}
