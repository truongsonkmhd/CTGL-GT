#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
using namespace std;
struct Phim{
	char Ten[100];
	int Tong;
	int SoLuot;
	float danhGia;
};
int main(){
	int n, i, j;
	ifstream FileIn;
	FileIn.open("D:\\C++\\AItest.txt");
	FileIn >> n;
	char s[100][100];
	int x[n];
	
	for(i=0; i<n; i++){
		FileIn.ignore();
		FileIn.getline(s[i], 99);
		FileIn >> x[i];
		if(s[i][strlen(s[i]) - 1] == '\n')
			s[i][strlen(s[i]) - 1] = '\0';
	}
	
	Phim a[100];
	int sl  = 0;
	for(i=0; i<n; i++){
		int d = x[i];
		int k = 1; // chua xuat hien
		for(j=0; j<sl; j++)
			if(strcmp(a[j].Ten, s[i]) == 0){
				k = 0;
				a[j].Tong += d;
				a[j].SoLuot++;
				break;
			}
		if(k == 1){
			strcpy(a[sl].Ten, s[i]);
			a[sl].SoLuot = 1;
			a[sl].Tong = d;
			sl++;
		}
	}
	for(i=0; i<sl; i++){
		a[i].danhGia = a[i].Tong*1.0/a[i].SoLuot;
		cout << a[i].Ten << "\t" << a[i].SoLuot << " view\t" << fixed << setprecision(1) << a[i].danhGia << "/5" << endl;
	}
}
