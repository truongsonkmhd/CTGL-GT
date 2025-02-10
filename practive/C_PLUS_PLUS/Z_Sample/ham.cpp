#include <iostream>
#include <math.h>
using namespace std;

double Can2(double n){
	double m = n;
	int mu = 1, dodai = 0;
	while(1){
		m /= 10;
		mu *= 10;
		dodai++;
		if(m < 100 && dodai % 2 == 0)
			break;
	}
	double x1, x2;
	x1 = m*pow(10, dodai/2);
	x2 = (x1 + n/x1)/2;
	do{
		x1 = x2; 
		x2 = (x1 + n/x1)/2;
	}while(abs(x1 - x2) > 0.00001);
	return x1;
}
int main(){
	int n;
	cin >> n;
	cout << Can2(n);
	return 0;
}
