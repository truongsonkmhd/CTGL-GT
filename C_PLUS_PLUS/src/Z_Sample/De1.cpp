/*
2. 	a) i = 6 s = 12
	b) i = 3 s = 10
3.
dong 7 bi loi do chua koi tao gtri i
dong 9 bi loi do chua dung dk so sanh i%2 

sua:
int i = 0, s = 0;
	while(i < 10){
		if(i%2 == 0 && i %3 == 0)
			s+= i;
		else
			s/= i;
		i++;
	}
	
4.
#include <iostream>

using namespace std;

int main(){
	int n, i;
	double S = 0;
	cin >> n;
	for(i=1; i<=n; i++)
		S += 1.0*(i+1)/i;
	cout << S;
		
}
5.
*/
#include <iostream>

using namespace std;

int tongCacChuSo(int n){
	int sum = 0;
	while(n != 0){
		sum += n % 10;
		n /= 10;
	}
	return sum;
}
int main(){
	int n;
	cin >> n;
	cout << tongCacChuSo(n);
}
