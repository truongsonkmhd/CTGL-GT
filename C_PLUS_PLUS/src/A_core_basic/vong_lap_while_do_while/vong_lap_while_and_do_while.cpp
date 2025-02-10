/* //
#include <iostream>
using namespace std;
int main()
{
int n;
cout<<"Nhap so n: "; cin >> n;
int i = 1; //chi so hang
while (i<=n)
{ int j = 1; //chi so cot
while (j <= i)
{
cout <<j;
j++;
}
cout<<endl;
i++;
}
return 0;
}
*/
//=======================BTTL====================================
/*//bai6
#include <iostream>
#include <math.h>
using namespace std;
int main(){
	int n,i,s=0;
	cout<<"Nhap n="; cin>>n;
	while(i<=n){
		s=s+i;
		i=i+2;
		}
		cout<<"gia tri cua s="<<s;
		return 0;
	}*/
//bai7
/*#include <iostream>
#include <math.h>
using namespace std;
int main()
{
  float a;
  do
  {
    cout<<"Nhap so thuc a: "; cin>>a;
    if (a<=1 || a>=2)
      cout<<"\nNhap lai so a!"<<endl;
  } while (a<=1 || a>=2);
  
  int i = 1;
  float S = 0;
  do
  {
    S = S + (float) 1/i;
    i++;
  } while (S<a);
  cout<<"So n nho nhat la: "<<i-1<<endl;
  cout<<"Tong la: "<<S<<endl;
  return 0;
}
*/
/*#include<iostream> 
using namespace std; 
bool Check_Per(int n){
	int i = 2;  
	int demuoc = 0;
	if(n <= 1){ 
		return false;
	}  
	while( i <= n/2 ){ 
		if(n%i == 0){ 
			return false;
		}
		i++;
	}
	return true;
}
int main(){ 
	int n; 
	cin >> n;
		if(Check_Per(n)){ 
			cout << n << " la " << "so nguyen to" << endl;
		}else{ 
			cout << n << "  " << "Khong la so nguyen to " << endl;
		}
	
	return 0;
}
*/
//bai9
/*#include <iostream>
using namespace std;
int main(){
	float n, tbc = 0;
	int dem1 = 0, dem2 = 0;
	cout<<"Moi ban nhap vao so thuc ="; cin>>n;
	while(n != 0){
		if(n == 0) dem1++;
		else if(n < 0) dem2++;
		else tbc += n;
		cin >> n;
	} 
	if (dem1 + dem2 > 0)
		tbc /= (dem1 + dem2);
	else 
		tbc = 0;
	cout<<"Trung binh cong cac phan tu da nhap la:"<<tbc<<endl;
	cout<<"Dem so phan tu da nhap ko ke 0:"<<dem1<<endl;
	cout<<"Dem so phan tu am:"<<dem2<<endl;
	return 0;
}*/
/*#include <iostream>
using namespace std;
int main(){
    float n, tong = 0;
    int dem = 0, demam = 0;
    cout << "Nhap so thuc, den 0 stop: ";
    cin >> n;
    while (n != 0) {
        tong += n;
        dem++;
        if (n < 0) demam++;
        cin >> n;
    }
    if (dem > 0) {
        cout << "Dem do pha tu da nhap ko ke 0: " << dem << endl;
        cout << "tbc cac phan tu da nhap: " << tong / dem << endl;
        cout << "Dem phan tu am: " << demam << endl;
    } else {
        cout << "ko co ptu nao dc nhap" << endl;
    }
    return 0;
}*/
/*//BTVN
// Bai10
#include <iostream>
using namespace std;
int main()
{
int n,p=0;
cout<<"Nhap so n: "; cin >> n;
int i = 2;
while (i<=n)
{
 p=p+i;
 i=i+2;
}
cout<<"Tich la:"<<p;
return 0;
}*/
// bai11
/*#include <iostream>
#include <math.h>
using namespace std;
int main()
{
int n,s=0;
cout<<"Nhap so n: "; cin >> n;
int i = 1;
while (i<=n)
{
 s=s+pow(i,2);
 i=i+1;
}
cout<<"Tong la:"<<s;
return 0;
}
*/
/*//bai 12
#include <iostream>
using namespace std;
int main()
{
int n,p=0;
cout<<"Nhap so n: "; cin >> n;
int i = 1;
while (i<=n)
{
 p=p+i*(i+1);
 i++;
}
cout<<"Tong la:"<<p;
return 0;
}*/
/*#include <iostream>
#include <math.h>
using namespace std;
int main()
{
int n;
float p=0;
cout<<"Nhap so n: "; cin >> n;
int i = 1;
while (i<=n)
{
 p=p+1/pow(i,2);
 i=i+2;
}
cout<<"Tong la:"<<p;
return 0;
}*/
//Bai13
#include <iostream>
using namespace std;
int gcd(int p, int q) {
    while (q != 0) {
        int r = p % q;
        p = q;
        q = r;
    }
    return p;
}

int main() {
    int p, q;
    cout << "Nhap vao lan luot 2 so: ";
    cin >> p >> q;
    int hcf = gcd(p, q);
    cout << "GCD of " << p << " and " << q << " is " << hcf << endl;
    int lcm = p * q / hcf;
    cout << "LCM of " << p << " and " << q << " is " << lcm << endl;
    return 0;
}

