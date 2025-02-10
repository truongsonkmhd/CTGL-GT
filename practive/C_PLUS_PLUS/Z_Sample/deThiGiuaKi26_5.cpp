/*#include <iostream>

using namespace std;

struct Node{
	int value;
	Node* next;
};
Node* add(Node *head, int x){
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
Node *addNode(Node* head, int v, int k){
	Node *i = head;
	while(i != NULL){
		if(i->value == k){
			Node *p = new Node;
			p->value = v;
			p->next = i->next;
			i->next = p;
		}
		i = i->next;
	}
	return head;
}

void Xuat(Node*head){
	Node* i = head;
	while(i != NULL){
		cout << i->value << " ";
		 i = i->next;
	}
}
Node* deleteNode(Node *head){
	Node *i = head;
	while(i->next != NULL){
		if(i->next->value - i->value != 5){
			i->next = i->next->next;
		}
		i = i->next;
	}
	return head;
}
int main(){
	int n;
	cin >> n;
	Node *head = NULL;
	for(int  i=0; i<n; i++){
		int x; cin >> x;
		head = add(head, x);
	}
	deleteNode(head);
	Xuat(head);
}

#include <iostream>
#include <math.h>

using namespace std;

int main(){
	int m, n;
	cin >> m >> n;
	int sum = 0;
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++){
			cin >> x;
			int d = sqrt(x);
			if(d*d == x) sum+= x;
		}
	cout << sum;
}

#include <iostream>
#include <string>

using namespace std;
struct sinhvien{
    string tensinhvien;
    float gpa;
};
int main(){
    int a;
    cin >> a;
    string tmp;
    sinhvien sv[a];
    for(int i=0;i<a;i++){
        getline(cin, tmp);
        getline(cin,sv[i].tensinhvien);
        cin >> sv[i].gpa;
    }
    for(int i=0;i<a-1;i++){
        for(int j=i+1;j<a;j++){
            if(sv[i].gpa<sv[j].gpa){
                sinhvien TMP=sv[j];
                sv[i]=sv[j];
                sv[j]=TMP;
            }
        }
    }
    float m;
    cin >> m;
    for(int i=0;i<3;i++){
        if(sv[i].gpa>=m){
            cout << sv[i].tensinhvien << endl;
        }else
        	break;
    }
    return 0;
}
*/
#include <iostream>
#include <string.h>

using namespace std;

int main(){
	char s[1000];
	char w[100];
	cin.getline(s, 999);
	cin.getline(w, 99);
	for(int i=0; i<strlen(s); i++)
		if((s[i] == w[0] || s[i] + 32 == w[0] || s[i] - 32 == w[0])){
			int d = 1;
			for(int j=1; j<strlen(w); j++){
			if(!(s[i+j] == w[j] || s[i+j] + 32 == w[j] || s[i+j] - 32 == w[j])){
				d = 0;
				break;
			}
			if(d == 1)
				strcpy(s + i, s + i + strlen(w));
			}
		}
	cout << s << endl;
}
