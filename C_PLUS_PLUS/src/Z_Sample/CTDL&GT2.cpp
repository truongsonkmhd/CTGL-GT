/*
#include <iostream>
#include <string.h>
using namespace std; 

void Buble_Sort(int n, int A[]){
	int i, j;
	for(i=0; i<n; i++)
		for(j= i + 1; j< n - i; j++)
			if(A[j] > A[i]){
				int t = A[j];
				A[j] = A[i];
				A[i] = t;
			}
}
int main(){
	int n, i, d = 0;	cin >> n;
	int D[n];
	for(i=0; i<n; i++)
		cin >> D[i];
	Buble_Sort(n, D);
	for(int i=0; i<n; i++)
		cout << D[i] << " ";
	return 0;
}
*/
#include <iostream>
#include <string.h>
using namespace std;

typedef struct Node{
	int data;
	Node *left;
	Node *right;
}N;

void KhoiTao(Node *&Tree){
	Tree = NULL;
}
void Add(Node *&Tree, int &x){
	Node *p = new Node;
	p->data = x;
	p->left = NULL;
	p->right = NULL;
	if(Tree == NULL)	Tree = p;
	if(Tree->data > x)	Add(Tree->left, x);
	if(Tree->data < x) Add(Tree->right, x);
}
void Xuat(Node *&Tree){
	if(Tree != NULL){
		Xuat(Tree->right);
		cout << Tree->data << " ";
		Xuat(Tree->left);
	}
}

int main(){
	Node *Tree = NULL;
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		int x; cin >> x;
		Add(Tree, x);
	}
	Xuat(Tree);
}
*/
