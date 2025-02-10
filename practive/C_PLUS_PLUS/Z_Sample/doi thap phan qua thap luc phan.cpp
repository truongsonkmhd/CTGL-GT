#include <iostream>
#include <string.h>

using namespace std;

int main(){
	char a[100];
	int n, du, i =0;
	cout << "Nhap n: "; cin >> n;
	int x; cin >> x;
	while(n !=0){
		du = n % x;
		if(du > 9)
			a[i] = du - 10 + 'A';
		else
			a[i] = du + 48;
		i++;
		n /= x;
	}
	strrev(a);
	cout << a;
}
