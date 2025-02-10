#include <iostream>
#include <math.h>

using namespace std;

int** Nhap(int m, int n){
	int** a = new int*[m];
	for(int i=0; i<m; i++)
		a[i] = new int[n];
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			cin >> a[i][j];
	return a;
}
void Xuat(int **a, int m, int n){
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}
void YC_3(int **a, int m, int n){
	int max = 0, x = -1;
	for(int i=0; i<m; i++){
		int sl = 0;
		for(int j=0; j<n; j++)
			if(a[i][j] < 0)
				sl++;
		if(sl > max){
			max = sl;
			x = i;
		}
	}
	for(int i=0; i<n; i++)
		cout << a[x][i] << " ";
}
bool KT(int x){
	if(x < 0)	return false;
	int d = sqrt(x);
	if(d*d == x)
		return true;
	return false;
}
void YC_4(int **a, int m, int n){
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			if(KT(a[i][j]))
				cout << "(" << i << "," << j << "), ";
}
int YC_5(int **a, int m, int n){
	int sl = -1;
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			if(a[i][j] == a[0][0])
				sl++;
	return sl;
}
int main(){
	int m, n;
	cout << "Nhap m, n: ";
	cin >> m >> n;
	cout << "Nhap ma tran:\n";
	int **a = Nhap(m, n);
	cout << "\nMa tran vua nhap:\n";
	Xuat(a, m, n);
	cout << "\nHang co so phan tu am nhieu nhat: ";
	YC_3(a, m, n);
	cout << "\nCac vi tri so chinh phuong: ";
	YC_4(a, m, n);
	cout << "\nSo luong cac phan tu bang phan tu tai vi tri (0,0) la: " << YC_5(a, m, n);
}


