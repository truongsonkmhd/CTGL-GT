/*
 22
 
#include <iostream>
#include <math.h>

using namespace std;

int Check(int n){
	int i, count =0;
	for(i=1; i<=sqrt(n); i++){
		if(n%i == 0 && n/i != i)
			count ++;
		if(count > 2)
			return 0;
	}
	if(count < 2)
		return 0;
	return 1;
}

void Sort(int *a, int n){
	int i, j;
	for(i=0; i<n-1; i++)
		for(j =i+1; j<n; j++)
			if(a[i] > a[j]){
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
}
int main(){
	int n;
	cout << "Enter quantity: "; cin >> n;
	int a[n], i;
	for(i=0; i<n; i++)
		cin >> a[i];
	cout << "The number devided by 7 and ending is 6: \n\t\t\t";
	for(i=0; i<n; i++)
		if(a[i] % 7 == 0 && a[i] % 10 == 6)
			cout << a[i] << " ";
	cout <<"\nThe number only 4 wishes are: \n\t\t\t";
	for(i=0; i<n; i++)
		if(Check(a[i]) == 1)
			cout << a[i] << " ";
	Sort(a, n);
	cout <<"\nThe number only 4 wishes are: \n\t\t\t";
	for(i=0; i<n; i++)
		cout << a[i] << " ";
}

23

#include <iostream>

using namespace std;

void Sort(int *a, int n){
	int i, j;
	for(i=0; i<n-1; i++)
		for(j=i+1; j<n; j++)
			if(a[i] > a[j]){
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
}
int KT(int *a, int n, int x){
	int dau = 0, cuoi = n-1, giua;
	while(dau <= cuoi){
		giua = (cuoi + dau)/2;
		if(a[giua] == x) return 1;
		if(a[giua] > x)	cuoi = giua - 1;
		else		dau = giua + 1;
	}
	if(a[dau] == x) return 1;
	return 0;
}
int main(){
	int n;
	cout << "Nhap sl: ";	cin >> n;
	int i, a[n+1], b[n];
	cout <<"Nhap day A:\n";
	for(i=0; i<n; i++)
		cin >> a[i];
	Sort(a, n);
	cout << "Nhap day B:\n";
	for(i=0; i<n; i++)
		cin >> b[i];
	cout <<"Cac so co mat trong ca A va B la: ";
	for(i=0; i<n - 1; i++)
		for(int j=i+1; j<n; j++)
			if(b[i] == b[j])
				b[j] = -1;
	for(i=0; i<n; i++)
		if(KT(a, n, b[i]) == 1)
			cout << b[i] << " ";
}

24


#include <iostream>

using namespace std;

int main(){
	long long denta =1, sum = 0;
	int n, i;
	cout <<"Nhap sl: "; cin >> n;
	int a[n];
	for(i=0; i<n; i++){
		cin >> a[i];
		denta *= a[i];
		sum += denta;
	}
	cout <<"Dap so: " << sum;
}

25




#include <iostream>

using namespace std;

void Nhap(int a[][100], int m, int n, int &sum){
	int i, j;
	for(i=0; i<m; i++)
		for(j=0; j<n; j++){
			cin >> a[i][j];
			if(i == j)
				sum += a[i][j];
		}
}
int main(){
	int m, n;
	cout << "Nhap kich thuoc: "; cin >> m >> n;
	int a[100][100], sum =0;
	Nhap(a, m, n, sum);
	cout << "Tong cac phan tu tren duong cheo chinh: " << sum ;
}



26


#include <iostream>

using namespace std;

void Nhap(int a[][100], int m, int n){
	int i, j;
	for(i=0; i<m; i++)
		for(j=0; j<n; j++){
			cin >> a[i][j];
		}
}
void MinMax(int a[][100], int m, int n, int &min, int &max){
	int i, j;
	min = a[0][0];
	max = a[0][0];
	for(i=0; i<m; i++)
		for(j=0; j<n; j++){
			min = (min > a[i][j]) ? a[i][j] : min;
			max = (max < a[i][j]) ? a[i][j] : max;
		}
}
void Search(int a[][100], int m, int n, int min){
	int i, j, count = 0;
	cout << "Vi tri cac so be nhat cua mang la:\n";
	for(i=0; i<m; i++)
		for(j=0; j<n; j++)
			if(a[i][j] == min){
				cout << "Dong: " << i + 1 << " - Cot: " << j + 1 << endl; 
				count ++;
			}
	cout <<"Vay co " << count << " so be nhat trong mang." << endl;
}
void Search2(int a[][100], int m, int n){
	int i, j, d;
	cout << "Cac phan tu co o dong 2 nhung k co o cot 4 la: \n";
	for(i=0; i<n; i++){
		d = 0;
		for(j=0; j<m; j++)
			if(a[1][i] == a[j][3]){
				d = 1;
				break;
			}
		if(d == 0)
			cout << a[1][i] << " ";
	}
	cout << endl;
}
void Sort1(int a[][100], int m, int n){
	int i, j;
	for(i=0; i<n-1; i++)
		for(j=i+1; j<n; j++)
			if(a[0][i] > a[0][j]){
				int t = a[0][i];
				a[0][i] = a[0][j];
				a[0][j] = t;
			}
}
void Xuat(int a[][100], int m, int n){
	int i, j;
	for(i=0; i<m; i++){
		for(j=0; j<n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}
int main(){
	int m, n;
	do{
		cout << "Nhap kich thuoc m x n(m>3, n > 4): "; cin >> m >> n;
	}while(m <3 || n < 4);

	int a[100][100], min, max;
	Nhap(a, m, n);
	MinMax(a, m, n, min, max);
	cout << "Phan tu lon nhat cua mang: " << max << endl;
	cout << "Phan tu nho nhat cua mang: " << min << endl;
	Search(a, m, n, min);
	Search2(a, m, n);
	Sort1(a, m , n);
	Xuat(a, m, n);
	
}


27

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

void KhoiTao(int a[][100]){
	int i, j;
	for(i=1; i<8; i++)
		for(j=1; j<7; j++)
			a[i][j] = i*i + j*j;
}
void Xuat(int a[][100], int m, int n){
	int i, j;
	for(i=1; i<m; i++){
		for(j=1; j<n; j++)
			cout << setw(3) << a[i][j] << " ";
		cout << endl;
	}
}
void ChinhPhuong(int a[][100], int m, int n){
	int i, j;
	for(i=1; i<m; i++)
		for(j=i; j<n; j++){
			int t = sqrt(a[i][j]);
			if(t*t == a[i][j])
				cout << t*t << " ";
		}
}
int main(){
	int a[8][100];
	KhoiTao(a);
	Xuat(a, 8, 7);
	cout << "\nCac so chinh phuong trong mang:\n";
	ChinhPhuong(a, 8, 7);
}



28

#include <iostream>
#include <string.h>

using namespace std;

int main(){
	char a[1000];
	cout << "Nhap xau a:\n";
	cin >> a;
	for(int i=strlen(a) - 1; i>=0; i--)
		cout << a[i];
}

29


#include <iostream>
#include <string.h>

using namespace std;

int main(){
	char a[1000];
	cout << "Nhap xau a:\n";
	cin.getline(a, 999);
	for(int i=0; i<=strlen(a) - 1; i++)
		if(a[i] != a[strlen(a) - 1 - i]){
			cout << "Xau khong doi xung.";
			return 0;
		}
	cout << "Xau doi xung.";
}


30


#include <iostream>
#include <string.h>

using namespace std;

void Xoa0(char *a){
	while(a[0] == 48)
		strcpy(a, a+1);
}
void Tang(char *c, int x){
	if(c[x] > 57){
		c[x+1] = 49;
		c[x] -= 10;
	}else{
		c[x+1] = 48;
	}
}
void Sum(char *a, char *b, char *c){
	char x[1000], y[1000];
	if(strlen(a) > strlen(b)){
		strcpy(x, strrev(a));
		strcpy(y, strrev(b));
	}else{
		strcpy(x, strrev(b));
		strcpy(y, strrev(a));
	}
	strrev(a); strrev(b);
	int i;
	c[0] = x[0] + y[0] - 48;
	Tang(c, 0);
	for(i=1; i<strlen(x); i++){
		if(i<strlen(y))
			c[i] += x[i] + y[i] - 48*2;
		else
			c[i] += x[i] -48;
		Tang(c, i);
	}
	strrev(c);
	Xoa0(c);
}
int main(){
	char a[1000], b[1000], c[1000];
	cout << "Nhap so a:\n";
	cin >> a;
	cout << "Nhap so b:\n";
	cin >> b;
	Sum(a, b, c);
	cout << a << " + " << b << " = " << c;
	
}


28



#include <iostream>
#include <string.h>

using namespace std;


int main(){
	char a[1000], b[1000], c[1000];
	cout << "Nhap chuoi a:\n";
	cin.getline(a, 999);
	cout << "Nhap chuoi b:\n";
	cin.getline(b, 999);
	if(strcmp(a, b) > 0)
		cout << "Chuoi a > chuoi b.\n";
	else
	if(strcmp(a, b) == 0)
		cout << "Chuoi a = chuoi b.\n";
	else
		cout << "Chuoi a < chuoi b.\n";
	cout << "Chuoi ban dau: " << a << endl;
	strcat(a, b);
	cout << "Chuoi sau khi noi: " << a << endl;
	int i, count =0;
	for(i=0; i<strlen(b); i++)
		if(b[i] == 32)
			count ++;
	cout << "Chuoi b co: " << count << " dau cach.";
}

1.

int maxThree(int a, int b, int c){
    int max;
    max = (a > b) ? a : b;
    max = (max > c) ? max : c;
    return max;
}

2.

void Swap(int &a, int &b){
    a *= b;
    b = a/b;
    a /= b;
}

3.

#include <iostream>

using namespace std;

void printArrow(int n, bool left){
    int i, j;
    if(left == true){
        for(i=n; i>0; i--){
            for(j=0; j<2*i - 1; j++)
            	if(j < i - 1)
            		cout << " ";
            	else
            		cout << "*";
            cout << endl;
        }
        for(i=2; i<=n; i++){
        	for(j=0; j<2*i - 1; j++)
            	if(j < i - 1)
            		cout << " ";
            	else
            		cout << "*";
            cout << endl;
		}
	}else{
        for(i=0; i<n; i++){
            for(j=0; j<n + i; j++)
            	if(j < 2*i)
            		cout << " ";
            	else
            		cout << "*";
            cout << endl;
        }
        for(i=n-2; i>=0; i--){
        	for(j=0; j<n + i; j++)
            	if(j < 2*i)
            		cout << " ";
            	else
            		cout << "*";
            cout << endl;
		}
    }
}

int main(){
	int n, left;
	cin >> n >> left;
	printArrow(n, left);
}



#include <iostream>

using namespace std;

int main(){
	int n;
	cout << "Nhap sl: "; cin >> n;
	int a[n], i, du = 1;
	int soCanChia;
	cin >> soCanChia;
	for(i=0; i<n; i++){
		cin >> a[i];
		du *= a[i]%soCanChia; 
	}
	cout << du%soCanChia << endl;
}





#include <iostream>
#include <string.h>

using namespace std;

string toLower (string a){
    string s = a;
    int i, n = s.length();
    for(i=0; i<n-1; i++)
        if(s[i] >= 65 && s[i] <= 'z')
            s[i] += 32;
      return s;     
}

int main(){
	string a;
	cin >> a;
	string s;
	s = toLower(a);
	cout << s;
}



*/

#include <stdio.h>
#include <string.h>

typedef struct Hedgehog {
	char ID[9];
	char Name[16];
	long donGia;
	int soLuong;
}Nhim;

Nhim Nhap(){
	Nhim a;
	printf("\nNhap ID: "); scanf("%s", a.ID);
	printf("Nhap ten: "); scanf("%s", a.Name);
	printf("Nhap don gia: "); scanf("%ld", &a.donGia);
	printf("Nhap so luong: "); scanf("%d", &a.soLuong);
	return a;
}
void Xuat(Nhim a, int Stt){
	printf("\t\t%-4d %8s %8s %16ld %12d\n", Stt, a.ID, a.Name, a.donGia, a.soLuong);
}
int Gia(Nhim *a, int n){
	long GiaMax = a[0].donGia;
	int i;
	for(i=1; i<n; i++)
		if(GiaMax < a[i].donGia)
			GiaMax = a[i].donGia;
	return GiaMax;
}
int main(){
	int k, i, n;
	char c;
	printf("Nhap so luong: "); scanf("%d", &n);
	Nhim HedArr[n];
	for(i=0; i < n; i++){
		HedArr[i] = Nhap();
	}
	long GiaMax = Gia(HedArr, n);
	printf("\n\t\tDanh sach nhim co gia cao\n");
	printf("\t\t%s \t%s \t%s \t\t%s \t%s\n", "STT", "ID", "Name", "Don gia", "So luong");
	for(i=0; i<n; i++)
		if(HedArr[i].donGia == GiaMax)
			Xuat(HedArr[i], i +1);
	char Yellow[10];
	strcpy(Yellow, "Yellow");
	printf("\n\n\t\tDanh sach nhim sau khi cap nhat\n");
	printf("\t\t%s \t%s \t%s \t\t%s \t%s\n", "STT", "ID", "Name", "Don gia", "So luong");
	for(i=0; i<n; i++){
		if(strcmp(HedArr[i].ID, Yellow) == 0)
			HedArr[i].donGia *= 1.5;
		Xuat(HedArr[i], i +1);
	}
}



















