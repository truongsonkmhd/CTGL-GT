#include <iostream>
#include <math.h>

using namespace std;

int KT(int n){
	for(int i=2; i<=sqrt(n); i++){
		if(n % i == 0)	return 0;
	}
	return n >= 2;
}
int UCLN(int a, int b){
	while(b != 0){
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}
int TongU(int n){
	int sum = 0;
	for(int i=2; i<=sqrt(n); i++)
		if(n % i == 0){
			if(i*i == n)	sum += i;
			else			sum += i + n/i;
		}
	return sum + 1;	
}
int main(){
	int a, b;
	cout << "Nhap 2 so: "; cin >> a >> b;
	cout << "Cac so boi 5 trong khoang (" << a << ";" << b << ") la:\n";
	for(int i=a; i<b; i++)
		if(i % 5 == 0)
			cout << i << " ";
	cout << "\nCac so nguyen to trong khoang (" << a << ";" << b << ") la:\n";
	for(int i=a; i<b; i++)
		if(KT(i) == 1)
			cout << i << " ";
	if(UCLN(a, b) == 1){
		cout << a << " va " << b << " la cap nguyen to cung nhau\n";
	}else
		cout << a << " va " << b << " khong la cap nguyen to cung nhau\n";
	if(TongU(a) == b && TongU(b) == a)
		cout << "YES";
	else
		cout << "NO";
	cout << endl << TongU(220);
	cout << endl << TongU(284);
}
