/*
#include <iostream>
#include <iomanip> // setw(5), lam tron

using namespace std;

int main(){
	int a, b;
	cin >> a >> b;
	cout << (float) a / b << endl; // endl = \n
	cout << fixed << setprecision(2) << setw(10) << left << (float) a / b << a / b;
}
1.1:

#include <iostream>
#include <iomanip> // setw(5), lam tron

using namespace std;

int main(){
	float r;
	cin >> r;
	cout << "Chu vi: " << 2*3.14*r << endl;
	cout << "Dien tich: " << 3.14*r*r << "\n";
}
1.2:

#include <iostream>
#include <iomanip> // setw(5), lam tron
#include <math.h>
using namespace std;

int main(){
	int x1, y1, x2, y2;
	cout << "Nhap diem diem A: "; cin >> x1 >> y1;
	cout << "Nhap diem diem B: "; cin >> x2 >> y2;
	float AB = sqrt( (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) );
	cout << AB << endl;
	AB = sqrt( pow(x1 - x2, 2) + pow(y1 - y2, 2) );
	cout << AB << endl;
}
1.3:

#include <iostream>
#include <iomanip> // setw(5), lam tron

using namespace std;

int main(){
	int Tien;
	do{
		cin >> Tien;
	}while(Tien % 1000 != 0 || Tien < 0);
	cout << "Cac cach doi to tien " <<  Tien << "la:\n";
	for(int i=0; i <= Tien/1000; i++)
		for(int j=0; j<= Tien/2000; j++)
			for(int t=0; t<= Tien/5000; t++)
				if(i*1000 + j*2000 + t*5000 == Tien){
					cout << i << " x 1k + " << j << " x 2k + " << t << " x 5k \n"; 
				}
}
1.4

#include <iostream>
#include <math.h>

using namespace std;

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	// dk vo no
	if(a == 0 && b == 0 && c != 0){
		cout << "PT vo no";
		return 0;
	}
	// TH pt bac 1
	if(a == 0){
		cout << "PT co no: x = " << -1.0*c / b;
		return 0;
	}
	int denta = b*b - 4*a*c;
	if(denta == 0){
		cout << "No kep: x = " << -1.0*b/ (2*a);
	}else	if(denta > 0){
		cout << "x1 = " << 1.0*(-b - sqrt(denta)) / (2*a) << endl;
		cout << "x2 = " << 1.0*(-b + sqrt(denta)) / (2*a) << endl;
	}else{
		cout << "PT vo no";
	}
}
1.5

#include <iostream>

using namespace std;

int main(){
	for(int i = 'A'; i<= 'Z'; i++)
		cout << char (i + 32) << endl;
}

1.6

#include <iostream>
#include <math.h>
using namespace std;
long GT(int n){
	long  kq = 1;
	for(int i=2; i<=n; i++)
		kq *= i;
	return kq;
}
int main(){
	// lan can diem khong?
	float x;
	cin >> x;
	float Cos = 1;
	float denta = 1;
	int n = 1;
	do{
		denta = pow(-1.0, n)*pow(x, 2*n)/(GT(2*n));
		Cos += denta;
		n++;
	}while(abs(denta) > 0.00000001);
	cout << Cos << endl;
	cout << cos(x);
	
//	float Tu = 1;
//	long Mau = 1;
//	int dau = -1, i = 1;
//	float denta = 1;
//	float Cos  = 1;
//	do{
//		Tu *= x*x;
//		Mau *= i*(i+1);
//		denta = 1.0*dau*Tu/Mau;
//		Cos += denta;
//	//	cout << denta << endl;
//		i+=2;
//		dau *= - 1;
//	}while(abs(denta) > 0.000001);
//	cout << Cos << endl;
//	cout << cos(x);
}
1.7

#include <iostream>

using namespace std;

int main(){
	int n, i = 0;
	cin >> n;
	int a[n];
	while(n != 0){
		a[i] = n % 2;
		i++;
		n /= 2;
	}
	i--;
	for(;i >= 0; i--){
		cout << a[i];
	}
}
1.8

#include <iostream>

using namespace std;

int main(){
	int n, m, i = 0;
	cin >> n >> m;
	int a[n];
	while(n != 0){
		a[i] = n % m;
		if(a[i] >= 10){ // a[i] == 11 -> B 765 -> 7 , 65
 			a[i] = a[i] - 10 + 'A';
		}else{
			a[i] = a[i] + '0';
		}
		i++;
		n /= m;
	}
	i--;
	for(;i >= 0; i--){
		cout << (char) a[i];
	}
}
2.1

#include <iostream>

using namespace std;
int Tong(int a, int b){
	int c;
	c = a + b;
	return c;
}
void Tong2(int a, int b, int &c){ // nho ng khac di sua nha: dua anh ngoi nha
	c = a + b;
}
int main(){
	int a, b, c;
	cin >> a >> b;
	cout << Tong(a, b) << endl;
	Tong2(a, b, c);
	cout << c;
}
2.2

#include <iostream>
#include <string.h>

using namespace std;
void ChuyenDoi(int n, int m, char *a){
	int i=0;
	while(n != 0){
		a[i] = n % m;
		if(a[i] >= 10){ // a[i] == 11 -> B 765 -> 7 , 65
 			a[i] = a[i] - 10 + 'A';
		}else{
			a[i] = a[i] + '0';
		}
		i++;
		n /= m;
	}
	strrev(a);
}
char * ChuyenDoi(int n, int m){
	int i=0;
	char *a = new char;
	while(n != 0){
		a[i] = n % m;
		if(a[i] >= 10){ // a[i] == 11 -> B 765 -> 7 , 65
 			a[i] = a[i] - 10 + 'A';
		}else{
			a[i] = a[i] + '0';
		}
		i++;
		n /= m;
	}
	a[i] = '\0';
	strrev(a);
	return a;
}
int main(){
	int n, m;
	cin >> n >> m;
	char a[n];
	ChuyenDoi(n, m, a);
	for(int i=0; i<strlen(a); i++)
		cout << a[i];
	char *b = ChuyenDoi(n, m);
	cout << endl;
	for(int i=0; i<strlen(b); i++)
		cout << b[i];
}

#include <iostream>
#include <math.h>

using namespace std;
int KT(int n){
	if(n < 2)	return 0; // k phai nt
	for(int i = 2; i<= sqrt(n); i++)
		if(n % i == 0) 
			return 0;
	return 1;
}
int KT2(int n){
	for(int i = 2; i<= sqrt(n); i++)
		if(n % i == 0) 
			return 0;
	return n >= 2; // n < 2
}
int TimNT(int n){
	int i = 2, count = 0;
	while(1){
		if(KT(i) == 1){
			count++;
			if(count == n)
				return i;
		}
		i++;
	}
//	2 3 5 7 11 13
// 6: 1 2 3 6
// 4: 1 2 4
}
int KTSHH(int n){
	int sum = 0;
	for(int i = 1; i<= n/2; i++)
		if(n % i == 0 && n/i >= i){
			if(i*i != n)
				sum += i + n/i;
			else
				sum += i;
		}
	if(sum - n == n)	return 1;
	return 0;
}
int fbnc(int n){
	int a[n];
	a[0] = 1;
	a[1] = 1;
	for(int i=2; i<=n; i++)
		a[i] = a[i-1] + a[i-2];
	return a[n];
}
int fbnc2(int n){
	if(n == 0 || n == 1)	return 1;
	return fbnc2(n-1) + fbnc2(n-2);
}
long GT(int n){
	if(n == 0 || n == 1) return 1;
	return n*GT(n-1);
}
int main(){
	int n;
	cin >> n;
//	if(KT(n) == 1){
//		cout << "La so nt\n"; 
//	}else
//		cout << "Khong la nt\n";
//	if(KT2(n) == 1){
//		cout << "La so nt\n"; 
//	}else
//		cout << "Khong la nt\n";
//	cout << "So nt thu " << n << " la: " << TimNT(n) << endl;
	
//	if(KTSHH(n) == 1){
//		cout << "La so hh\n"; 
//	}else
//		cout << "Khong la hh\n";

//	cout << "C1: " << fbnc(n) << endl;
//	cout << "C2: " << fbnc2(n) << endl;
	cout << n << "! = " << GT(n);
}

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;
int* Doc(int n){
	int *a = new int[n];
	for(int i=0; i<n; i++)
		cin >> a[i];
	return a;
}
int* Docs(int n){
	int *a = new int[n];
	for(int i=0; i<n; i++)
		a[i] = rand() %(15 - 5) + 5;
	return a;
}
void Xuat(int *a, int n){
	for(int i=0; i<n; i++)
		cout << a[i] << " ";
	cout << endl;
}
int KT2(int n){
	for(int i = 2; i<= sqrt(n); i++)
		if(n % i == 0) 
			return 0;
	return n >= 2; // n < 2
}
void Delete(int *a, int &n, int x){
	n--;
	for(int i=x; i<n; i++)
		a[i] = a[i+1];
}
void Add(int *a, int &n, int x, int y){
	n++;
	for(int i = n-1; i>x; i--)
		a[i] = a[i-1];
	a[x] = y;
}
void Sort(int *a, int n){
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(a[i] < a[j]){
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
}
int main(){
	int n;
	cin >> n;
	srand(time(0));
	int *a = Docs(n);
	Xuat(a, n);
	cout << "Xuat so nt: ";
	for(int i=0; i<n; i++)
		if(KT2(a[i]) == 1)
			cout << a[i] << " ";
	cout << "\nXoa: ";
	Delete(a, n, 2);
	Xuat(a, n);
	cout << "\nThem: ";
	Add(a, n, 2, 100);
	Xuat(a, n);
	cout << "\nSap xep: ";
	Sort(a, n);
	Xuat(a, n);
}


#include <iostream>
#include <stdlib.h>

using namespace std;
int** Doc(int m, int n){
	int** a = new int*[m];
	for(int i=0; i<m; i++)
		a[i] = new int[n];
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			cin >> a[i][j];
	return a;
}
int** Doc2(int m, int n){
	int** a = new int*[m];
	for(int i=0; i<m; i++)
		a[i] = new int[n];
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			a[i][j] = rand()%100;
	return a;
}
void Xuat(int **a, int m, int n){
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++)	// xuat cua 1 dong
			cout << a[i][j] << " ";
		cout << endl;
	}
}
void Sort(int *a, int n){
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(a[i] < a[j]){
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
}
void Sort2(int **a, int m, int n){
	int *b = new int[m*n];
	int t = 0;
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++){
			b[t] = a[i][j];
			t++;
		}
	t = 0;
	Sort(b, m*n);
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++){
			a[i][j] = b[t];
			t++;
		}
}
int **Tong(int **a, int **b, int m, int n){
	int** c = new int*[m];
	for(int i=0; i<m; i++)
		c[i] = new int[n];
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			c[i][j] = a[i][j] + b[i][j];
	return c;
}
int** Hieu(int **a, int **b, int m, int n){
	int** c = new int*[m];
	for(int i=0; i<m; i++)
		c[i] = new int[n];
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			c[i][j] = a[i][j] - b[i][j];
	return c;
}
int** Hieu(int **a, int **b, int m, int n, int p, int q){
	int** c = new int*[m];
	for(int i=0; i<m; i++)
		c[i] = new int[q];
	for(int i=0; i<m; i++)
		for(int j=0; j<q; j++){
			c[i][j] = 0;
			for(int k = 0; k<n; k++)
				c[i][j] += a[i][k]*b[k][j];
		}
	return c;
}
int main(){
	int m, n;
	cin >> m >> n;
	int **a = Doc2(m, n);
	cout << endl;
	Xuat(a, m, n);
	cout << endl;
//	Sort2(a, m, n);
//	Xuat(a, m, n);
	int** b = Doc2(m, n);
	Xuat(b, m, n);
	cout << endl;
	int** c = Tong(a, b, m, n);
	Xuat(c, m, n);
	cout << endl;
	c = Hieu(a, a, m, n, n, m);
	Xuat(c, m, m);
	cout << endl;
}
4.1
*/
#include <iostream>
#include <string.h>

using namespace std;
void ChuanHoa1(char *a){
	while(a[0] == 32){
		strcpy(a + 0, a + 0 + 1);
	}
	for(int i=0; i<strlen(a); i++)
		if(a[i] == a[i+1] && a[i] == 32){
			strcpy(a + i, a + i + 1);
			i--;
		}
}
// Nguyen   Van A
void ChuanHoa(char *a){
	ChuanHoa1(a);
	if(a[strlen(a) - 1] == '\n')
		a[strlen(a) - 1] = '\0';
	if(a[0] >= 'a' && a[0] <= 'z')
		a[0] -= 32;
	for(int i=1; i<strlen(a); i++)
		if(a[i-1] == 32 && a[i] >= 'a' && a[i] <= 'z')
			a[i] -= 32;
		else	if(a[i-1] != 32 && a[i] >= 'A' && a[i] <= 'Z')
			a[i] += 32;
}
void Tach(char *a){
	int k = 0, t = 0;
	ChuanHoa(a);
	a[strlen(a)] = 32;
	char b[100][100];
	
	for(int i=0; i<strlen(a); i++)
		if(a[i+1] == 32){
			strncpy(b[t], a + k, i - k + 1);
			k = i + 2;
			t++;
		}
	for(int i=0; i<t; i++)
		cout << b[i] << endl;
}
// hi_cau_ _ _minh_la_
// k
void DoiXau(char *a, char *x, char *y){
	char *p = strstr(a, x);
	while(p != NULL){
		char b[100];
		strcpy(b, p + strlen(x));
		strcpy(p, y);
		strcat(p + strlen(y), b);
		p = strstr(p, x);
	}
}
int main(){
	char a[100];
	cin.getline(a, 99);
	// NGuyen vAn a\n
	char c[] = "ngoc";
	char d[] = "Ngoc anh";
	DoiXau(a, c, d);
	cout << a;
	
	
}
