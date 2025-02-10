//BTTL

//Bai 5:
/*#include <iostream>
#include <math.h>
using namespace std;
int main(){
	int n,s=0;
	cout<<"Nhap n:"<<endl; cin>>n;
	for(int i=1; i<=n; i=i+2){
		s=s+i;
		}
		cout<<s;
	return 0;
	} */
//Bai 6:
/*
#include <iostream>
#include <math.h>
using namespace std;
int main(){
	int n;
	double s=0.0;
	cout<<"Nhap n:"<<endl; cin>>n;
	for(int i=1; i<=n; i++){
		s=s+(1.0/i);
	}
	cout<<s<<endl;
	return 0;
}
*/
//bai 7:
/* cach1:
include <iostream>
using namespace std;

int main() {
    int n, a, b, c, d;
    cout << "nhap n: ";
    cin >> n;

    for (int i = 1000; i < 9999; i++) {
        a = i / 1000;
        b = (i / 100) % 10;
        c = (i / 10) % 10;
        d = i % 10;
        if (a + b == c + d) {
            cout << i << endl;
        }
    }
    return 0;
}
	*/
/* //cach2:
#include <iostream>
using namespace std;

int main() {
    for (int a = 1; a <= 9; a++) {
        for (int b = 0; b <= 9; b++) {
            for (int c = 1; c <= 9; c++) {
                for (int d = 0; d <= 9; d++) {
                    if (a + b == c + d) {
                        cout << a << b << c << d << endl;
                    }
                }
            }
        }
    }
    return 0;
} /*
/
/* //Bai8
#include <iostream>
using namespace std;

int main() {
    int rows, columns;

    cout << "Nhap so cot: ";
    cin >> rows;

    cout << "nhap so hang: ";
    cin >> columns;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
*/


//BTVN

/* //bai9
#include <iostream>
#include <math.h>
using namespace std;
int main(){
	int n,tich=0;
	cout<<"Nhap n:"<<endl; cin>>n;
	for(int i=2; i<=n; i=i+2){
		tich=tich*i;
		}
		cout<<tich;
	return 0;
	*/
/* //Bai 10
#include <iostream>
#include <math.h>
using namespace std;
int main(){
	int n,binhph=0;
	cout<<"Nhap n:"<<endl; cin>>n;
	for(int i=1; i<=n; i++){
		binhph=binhph+pow(i,2);
		}
		cout<<binhph;
	return 0;
	*/
/* //bai11:
#include<iostream> 
using namespace std; 
bool Check_Per(int n){  
	long long int sum = 0;
	if(n < 6){ 
		return false;
	}  
	for(long long int i = 1; i <= n; i++){ 
		sum += i; 
		if(sum == n){ 
			return true;
		}
	}
	return false;
}
int main(){ 
//trong pham vi m nhe
	long long int m; 
	cin >> m;
	for(int n;n<=m;n++){
	if(Check_Per(n)){ 
		cout<<n<<" la "<<"so hoan hao";
	}else{ 
		cout<<n<<"  "<<"Khong la so hoan hao";
	}
		cout<<endl;
}
	
//	if (condition)    // neu condition là true
//    statement;    // thuc thi câu lenh này
//    else
//   statement2;    // n?u condition là false, th?c thi câu l?nh này
    
return 0;
} */
// bai 12
/*#include <bits/stdc++.h>
#include <vector>
using namespace std;

void doitien(int t, vector<int> menh_gia){
int SoToTien;
for(int i=0; i<menh_gia.size(); i++){
SoToTien = t / menh_gia[i];
if(SoToTien != 0){
cout << "Co " << SoToTien << " to " << menh_gia[i] << endl;
}
t = t - SoToTien * menh_gia[i];
			}
	}

int main(){
int t;
vector<int> menh_gia = {10000, 5000, 2000, 1000};
cout << "Nhap so can doi tien: ";
cin >> t;
if(t >= 1000){
doitien(t, menh_gia);
}else {
cout << "So tien ban vua nhap ho hon muc quy dinh!!! Vui long xem lai." << endl;
}
return 0;
}*/
 //bai 13
#include<iostream> 
using namespace std; 
bool Check_Per(int n){  
	int demuoc = 0;
	if(n <= 1){ 
		return false;
	}  
	for(int i = 2; i <= n/2; i++){ 
		if(n%i == 0){ 
			return false;
		}
	}
	return true;
}
int main(){ 
	int m; 
	cin >> m;
	for(int n = 2; n <= m; n++){
		if(Check_Per(n)){ 
			cout << n << " la " << "so nguyen to" << endl;
		}else{ 
			cout << n << "  " << "Khong la so nguyen to " << endl;
		}
	}
	return 0;
}

/*//cach 1
#include<iostream> 
using namespace std; 
int main(){
	int n;9
	cout<<"Nhap n="; cin>>n;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n+1-i; j++){
			cout<<"*";
			}
		cout<<endl;
		}
	return 0;
}*/
/*//cách 2
#include<iostream> 
using namespace std; 
int main(){
	int n;
	cout<<"Nhap n="; cin>>n;
	for(int i=n; i>=1; i--){
		for(int j=1; j<=i; j++){
			cout<<"*";
			}
		cout<<endl;
		}
	return 0;
}*/
/*//cach 3
#include<iostream> 
using namespace std; 
int main(){
	cout<<"*******"<<endl;
	cout<<"******"<<endl;
	cout<<"*****"<<endl;
	cout<<"****"<<endl;
	cout<<"***"<<endl;
	cout<<"**"<<endl;
	cout<<"*"<<endl;
	return 0;
}*/
/*// bai 14
#include <iostream>
using namespace std;

int main() {
  for (int i = 2; i <= 9; i++) {
    cout << "bang nhan cua " << i << ":" << endl;
    for (int j = 1; j <= 10; j++) {
      cout << i << " x " << j << " = " << i * j << endl;
    }
    cout << endl;
  }
  return 0;
}
*/
