#include <iostream>

using namespace std;

long long GiaiThua(int n){
	if(n <=1)
		return 1;
	return n*GiaiThua(n-1);
}
int main(){
	int n;
	cout << "Nhap n: "; cin >> n;
	cout << n << "! = " << GiaiThua(n);
}
