/*
2:
#include <iostream>

using namespace std;

int main(){
	int a, b, k;
	do{
		cout << "\n\n\t\t\tMENU\n";
		cout <<"\t1. Tinh tong 2 so.\n";
		cout <<"\t2. Tinh hieu 2 so.\n";
		cout <<"\t3. Tinh tich 2 so.\n";
		cout <<"\t4. Tinh thuong 2 so.\n";
		cout <<"\t0. Thoat.\n";
		cout <<"\tSu dung chuc nang: ";  cin >> k;
		switch(k){
			case 1:{
				cout << "Nhap a, b: "; cin >> a >> b;
				cout <<"Tong " << a << " + " << b << " = " << a + b;
				break;
			}
			case 2:{
				cout << "Nhap a, b: "; cin >> a >> b;
				cout <<"Hieu " << a << " - " << b << " = " << a - b;
				break;
			}
			case 3:{
				cout << "Nhap a, b: "; cin >> a >> b;
				cout <<"Tich " << a << " * " << b << " = " << a * b;
				break;
			}
			case 4:{
				cout << "Nhap a, b: "; cin >> a >> b;
				if(b != 0)
					cout <<"Thuong " << a << " / " << b << " = " << a / b;
				else
					cout << "Loi khong thuc hien do b = 0.";
				break;
			}
			case 0:{
				cout << "Hen gap lai.";
				break;
			}
		}
		
	}while(k != 0);
}

3:
Kiem tra 1 so co la boi cua 3 va 5 khong?


#include <iostream>

using namespace std;

int main(){
	int n;
	cout << "Nhap so can kiem tra: "; cin >> n;
	if(n % 3 == 0 && n % 5 == 0)
		cout << n << " la boi so cua 3 va 5.";
	else
		cout << n << " khong phai boi so cua 3 va 5.";
}

4:
Tinh tien

#include <iostream>

using namespace std;

int main(){
	float n;
	cout << "Nhap so km da di: "; cin >> n;
	if(n <=1)
		cout << "So tien phai tra la: " << n*15000;
	else if(n <=30)
		cout << "So tien phai tra la: " << 15000 + (n-1)*16500;
	else
		cout << "So tien phai tra la: " << 15000 + 29*16500 + (n - 30)*16000;
}


bai lam them 
1:


#include <iostream>

using namespace std;

int main(){
	int a, b, c;
	cout << "Nhap do dai 3 canh cua tam giac: "; cin >> a >> b >> c;
	if(a + b <= c || a + c <= b || b + c <= a)
		cout << "Do dai khong phu hop.";
	else{
		if(a == b && b == c){
			cout << "Tam giac thuong.";
			return 0;
		}
		if((a*a + b*b == c*c && a == b) || (c*c + b*b == a*a && c == b) || (a*a + c*c == b*b && a == c))
			cout << "Tam giac vuong can.";
		else if(a*a + b*b == c*c || a*a + c*c == b*b || c*c + b*b == a*a)
			cout << "Tam giac vuong.";
		else	if(a == b || a == c || b == c)
			cout << "Tam giac can.";
		else
			cout << "Tam giac thuong";
	}
}

2:

#include <iostream>
#include <math.h>

using namespace std;

int main(){
	int n, a;
	cout << "Nhap so can kiem tra: "; cin >> n;
	a = sqrt(n);
	if(a*a == n)
		cout << n << " la so chinh phuong.";
	else
		cout << n << " khong phai so chinh phuong.";
}

III Thuc hanh
1:


#include <iostream>
#include <math.h>

using namespace std;

int main(){
	int n, sum = 0;
	cout << "Nhap so n: "; cin >> n;
	if(n>0){
		for(int i=1; i<=n; i++)
			sum += i;
		cout << sum;
	}
}
2.a:


#include <iostream>
#include <math.h>

using namespace std;

int main(){
	int n, sum = 0;
	cout << "Nhap so n: "; cin >> n;
	if(n>0)
		for(int i=1; i<=n; i++)
			sum += i*(i+1);
	cout << sum;
}

2.b
*/

#include <iostream>
#include <math.h>

using namespace std;

int main(){
	int n, sum = 0, a[100], i = 0;
	do{
		cout << "Nhap so: "; cin >> n;
		if(n % 3 == 0 && n % 7 == 0){
			a[i] = n;
			i++;
			sum += n;
		}
	}while(n != -999);
	for(int j=0; j<i; j++)
		cout << a[j] << " ";
		cout << "\nTong = " << sum;
}
