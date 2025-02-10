
#include <iostream>

using namespace std;

struct Node{
    int value;
    Node *next;
};
Node* Add(Node *head, int x){
    Node *p = new Node;
    p->value = x;
    p->next = p;
    if(head == NULL) return p;
    
    Node *i = head;
    while(i->next != head){
        i = i->next;
    }
    i->next = p;
    p->next = head;
    return head;
}
void Xuat(Node*head){
    Node *p = head;
    do{
        cout << p->value << " ";
        p = p->next;
    }while(p != head);
}
int main()
{
   int n;
   cin >> n;
   Node *head = NULL;
   int sl = n;
   for(int i=1; i<=n; i++){
       head = Add(head, i);
   }
   Node *p = head;
   Node *q = head->next;
  do{
       head->next= head ->next->next;
       head = head ->next;
        sl--;
  }while(sl != 1);
  Xuat(head);
// cout << head -> value;
    
}
