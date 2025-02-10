#include <iostream>
#include <string.h>

using namespace std;

void ChuyenDoi(char *a, int n){
	if(n < 0)
		n *= - 1;
	int i = 0, j;
	while(n != 0){
		a[i] = n % 2 + 48;
		n /= 2;
		if(a[i] == '1')
			a[i] = 48;
		else
			a[i] = 49;
		i++;
	}
	if(i % 4 != 0)
		for(j=0; j<i%4; j++)
			a[i+j] = 49;
	for(i=0; i<strlen(a); i++)
		if(a[i] == 48){
			a[i] = 49;
			break;
		}else{
			a[i] = 48;
		}
	strrev(a);
}
int main(){
	int n;
	char *a = new char[1000];
	cin >> n;
	ChuyenDoi(a, n);
	cout << a;
}
