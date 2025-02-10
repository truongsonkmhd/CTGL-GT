/*
#include <iostream>

using namespace std;

struct Node{
	int data;
	Node* next;
};
Node* KhoiTao(int x){
	Node* p = new Node;
	p->data = x;
	p->next = NULL;
	return p;
}
Node* AddDau(Node *head, int x){
	Node* p = KhoiTao(x);
	p->next = head;
	return p;
}
Node* AddCuoi(Node *head, int x){
	Node* p = KhoiTao(x);
	if(head == NULL) return p;
	Node* i = head;
	while(i->next != NULL)
		i = i->next;// giong o for
	i->next = p;
	return head;
}
void Xuat(Node *head){
	Node *i = head;
	while(i != NULL){
		cout << i->data << " ";
		i = i->next;
	}
}
int Max(Node *head){
	int max = head->data;
	Node *i = head->next;
	while(i != NULL){
		if(i->data > max){
			max = i->data;
		}
		i = i->next;
	}
	return max;
}
int Min(Node *head){
	int max = head->data;
	Node *i = head->next;
	while(i != NULL){
		if(i->data < max){
			max = i->data;
		}
		i = i->next;
	}
	return max;
}
void Update(Node *head, int x){
	int j = 0;
	Node *i = head;
	while(i != NULL){
		j++;
		if(j == x){
			cin >> i->data;
			break;
		}
		i = i->next;
	}
}
Node* Chen(Node *head, int x, int y){
	int j = 0;
	Node *p = KhoiTao(y);
	Node *i = head;
	while(i != NULL){
		j++;
		if(j == x - 1){
			p->next = i->next;
			i->next = p;
			break;
		}
		i = i->next;
	}
	return head;
}
int main(){
	int n;
	cin >> n;
	Node *head = NULL;
	for(int i=0; i<n; i++){
		int x; cin >> x;
		head = AddDau(head, x);
	}
	Xuat(head);
	cout << "\n max = "<< Max(head);
	cout << "\n min = "<< Min(head) << endl;
	Update(head, 2);
	Xuat(head);	cout << endl;
	head = Chen(head, 2, 100);
	Xuat(head);
}
*/

#include <iostream>
#include <string.h>

using namespace std;

int main(){
	string s, s1, s2;
	s = "hello xin chao cac ban";
	cout << s.length() << endl;
	cout << s.size() << endl;
	s1 = s.substr(0, 5);
//	s1 = s.substr(6);
	cout << s1 << endl;
	cout << s.find("ko") <<  endl;
//	s.erase(0, 5);
//	cout << s << endl;
//	s.replace(0, 5, "Hello");
//	cout << s << endl;
//	s.replace(0, s.size(), "hello");
//	cout << s << endl;
}
