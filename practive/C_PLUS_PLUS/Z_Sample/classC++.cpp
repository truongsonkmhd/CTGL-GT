#include <iostream>

using namespace std;

class SV{
private: 
	int a;
	int b;

public:
	void Show(){
		cout << a << " " << b;
	}
	SV(int _a, int _b){
		a = _a;
		b = _b;
	}
	int Denta(){
		return a - b;
	}
	SV Tong(SV x){
		return SV(a + x.a, b + x.b);
	}
};

int main(){
	SV a(5, 6);
	SV x(1, 2);
	a.Tong(x).Show();
	return 0;
}
