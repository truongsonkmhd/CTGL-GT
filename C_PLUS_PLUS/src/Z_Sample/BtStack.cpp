/*#include <iostream>

using namespace std;

typedef struct{
	int *data;
	int top;
	int capacity;
}Stack;
void init(Stack *s, int x){
	s->data = new int[x];
	s->capacity = x;
	s->top = 0;
}
void push(Stack &s, int x){
	s.top++;
	s.data[s.top] = x;
}
int pop(Stack &s){
	int x = s.data[s.top];
	s.capacity--;
	s.top--;
	return x;
}
bool isEmpty(Stack s){
	if(s.top != 0)  return false;
	return true;
}
void blank(Stack &s){
	s.top = 0;
	s.data = NULL;
}
int size(Stack s){
	return s.capacity;
}
int main(){
	Stack a;
	push(a, 5);
	push(a, 10);
	cout << pop(a);
	cout << pop(a);
}
*/
#include <iostream>

using namespace std;

typedef struct Node{
	int data;
	Node *next;
}Node;

typedef struct{
	Node *head;
	int capacity;
}Stack;
void init(Stack &s, int capacity){
	s.head = NULL;
	s.capacity = capacity;
}
void push(Stack &s, int x){
	if(s.head == NULL){
		s.head = new Node;
		s.head->data = x;
		s.head->next = NULL;
		return;
	}
	Node *p = new Node;
	p->data = x;
	p->next = NULL;
	
	Node *i = s.head;
	while(i->next != NULL){
		i=i->next;
	}
	i->next = p;
	s.capacity++;
}
int pop(Stack &s){
	Node *p = s.head;
	Node *sau;
	while(p->next != NULL){
		sau = p;
		p=p->next;
	}
	sau->next = NULL;
	s.capacity--;
	return p->data;
}
bool isEmpty(Stack s){
	if(s.head == NULL) return true;
	return false;
}
void empty(Stack s){
	s.head = NULL;
	s.capacity = 0;
}
int size(Stack s){
	int n = 0;
	Node *p = s.head;
	while(p != NULL){
		n++;
		p=p->next;
	}
	return n;
}

int main(){
	Stack s;
	empty(s);
	push(s, 5);
	cout << pop(s);
}
