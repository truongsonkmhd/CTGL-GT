#include <iostream>
using namespace std;

#define Max 100 

struct Stack {
    int a[Max];
    int top;
};

void init(Stack &s){
    s.top = -1;
}

void push(Stack &s, int x){
    s.a[++s.top] = x;
}

int pop(Stack &s){
    return s.a[s.top--];
}

bool isEmpty(Stack s){// is Empty: danh sách trong
//	if(s.top < 0)
//	return true;
//	
//return false;
return s.top < 0;
}
bool isFull(Stack s){
    return s.top == Max-1;
}
// kiem tra xem ngan xep da full hay chua
void output(Stack s){
    for(int i = 0; i <= s.top; i++){
        cout << s.a[i] << "\t";
    }
    cout << endl;
}
//Su dung cau truc stack, viet chuong trinh chuyen so nguyen duong trong he 
//thap phan sang he nhi phan
/*
//he so 2
void converDecimalToBinary(int n){
	Stack s;
	init(s);
	//push cac so du chia cho 2 vao stack
	while(n!=0){
//		int d = n % 2;
//		push(s,d);
		push(s, n%2);
		n/=2;
	}
	//pop all cac phan tu trong stack
	while(isEmpty(s) == false){
		cout << pop(s);
	}
}
*/
void converDecimalToBinary(int n,int radix){
	Stack s;
	init(s);
	//push cac so du chia cho radix vao stack
	while(n!=0){
//		int d = n % 2;
//		push(s,d);
		push(s, n%radix);
		n/=radix; //radix : co so 
	}
	//pop all cac phan tu trong stack
	while(isEmpty(s) == false){
		cout << pop(s);
	}
}
//he so 8, 16, ...........
int main() {
	//he so 1
	//converDecimalToBinary(224);
	//he so 2:
	converDecimalToBinary(214,16);
//    Stack s;
//    init(s);
//    
//    push(s, 10);
//    push(s, 15);
//    push(s, 20); 
//    
//    output(s);
//
//    cout << pop(s) << endl;
//
//    push(s, 25);
//
//    output(s);

    return 0;
}


