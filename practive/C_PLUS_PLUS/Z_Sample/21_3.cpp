/*
3:
Tinh dien tich, chu vi khi biet ban kinh
Tinh ban kinh khi biet dien tich;


#include <iostream> 
#include <math.h>

using namespace std;

int main(){
	float r , s, c;
	cout << "Nhap ban kinh: "; cin >> r;
	cout << "Dien tich hinh tron co ban kinh " << r << " la: " << 3.14*r*r << " chu vi la: "<< 2*3.14*r<< endl;
	cout << "Nhap dien tich: "; cin >> s;
	cout << "Ban kinh hinh tron co dien tich " << s << " la: "<< sqrt(s/3.14); 
}


4:
	Nhap vao day lon, day nho, chieu cao xuat ra dien tich
	

#include <iostream> 

using namespace std;

int main(){
	float a, b, h, s;
	cout << "Nhap do dai day lon: "; cin >> a;
	cout << "Nhap do dai day nho: "; cin >> b;
	cout << "Nhap chieu cao: "; cin >> h;
	s = (a + b)*h/2;
	cout << "Dien tich la: " << s;
	
}


7:
	Nhap tt cua 1 sinh vien: MSV, fullName, address, yearOfBirth, Mark
	xuat tt;



#include <iostream> 
#include <string.h>

using namespace std;

int main(){
	char MSV[10];
	cout << "Nhap MSV: "; cin >> MSV;
	char fullName[50];
	cout << "Nhap ho va ten: ";	cin.ignore(); cin.getline(fullName, 49);
	char Address[100];
	cout << "Nhap que quan: ";	 cin.getline(Address, 99);
	int yearOfBirth;
	cout << "Nhap nam sinh: "; cin >> yearOfBirth;
	float Mark;
	cout << "Nhap diem: "; cin >> Mark;
	cout <<"\tSinh vien: " << fullName <<", MSV: " << MSV << ". Sinh nam " << yearOfBirth << ". Que quan " << Address << " co diem trung binh: "<< Mark;
	
}

8:
	Nhap vao 3 canh cua tam giac va in ra dien tich


#include <iostream> 
#include <math.h>

using namespace std;

int main(){
	float a, b, c, s;
	cout << "Nhap do dai 3 canh: "; cin >> a >> b >> c;
	if(a + b <= c || a + c <= b || b + c <= a)
		cout << "Do dai khong phu hop.";
	else{
		float p = (a + b + c)/2;
		s = sqrt(p*(p-a)*(p-b)*(p-c));
		cout << "Dien tich la: " << s;
	}
}


9:
	Nhap toa do 2 diem A, B xuat toa do trung diem I



#include <iostream> 

using namespace std;

int main(){
	float x1, x2, y1, y2;
	cout << "Nhap toa do diem A: "; cin >> x1 >> y1;
	cout << "Nhap toa do diem B: "; cin >> x2 >> y2;
	cout << "Toa do trung diem A va B la: I(" << (x1 + x2)/2 <<";" <<(y1 + y2)/2 << ")\n";
}

10:
	Nhap toa do 3 dinh A, B, C xuat toa do trong tam
	
#include <iostream> 

using namespace std;

int main(){
	float x1, x2, x3, y1, y2, y3;
	cout << "Nhap toa do diem A: "; cin >> x1 >> y1;
	cout << "Nhap toa do diem B: "; cin >> x2 >> y2;
	cout << "Nhap toa do diem C: "; cin >> x3 >> y3;
	cout << "Toa do trong tam la: G(" << (x1 + x2 + x3)/3 <<";" <<(y1 + y2 + y3)/3 << ")\n";
}

11:
	Nhap he so a, b, c, x cua tam thuc bac 2 va tinh gtri
	


#include <iostream> 

using namespace std;

int main(){
	float a, b, c, x;
	cout << "Nhap he so a, b, c: "; cin >> a >> b >> c;
	cout << "Nhap gia tri x: "; cin >> x;
	cout << "f(" << x <<") = " << a*x*x+b*x + c;
}

12:

	
#include <iostream> 

using namespace std;

int main(){
	float i = 1, j = 3, d;
	d = (i=j)++;
	cout << d << endl;
	d = i+j++;
	cout << d << endl;
//	d = ++(i+j);	sai
//	cout << d << endl;
//	d = ++i+++j;	sai
//	cout << d << endl;
}


13:
	kiem tra so chan, le


#include <iostream>

using namespace std;

int main(){
	int n;
	cout << "Nhap so can kiem tra: "; cin >> n;
	if(n % 2 == 0)
		cout << n << " la so chan.";
	else
		cout << n << " la so le.";
}

14:
	Tim so lon nhat cua 2 so

#include <iostream>

using namespace std;

int main(){
	int num1, num2;
	cout << "Nhap 2 so: "; cin >> num1 >> num2;
	if(num1 == num2)
		cout << "Khong ton tai max";
	else	if(num1 > num2)
		cout << "max = " << num1;
	else
		cout << "max = " << num2;
}

15:
	B, O, K xuat ra nguoi thang, hoa


#include <iostream>

using namespace std;

int main(){
	char A, B;
	cout << "Nhap lua chon cua 2 nguoi: "; cin >> A >> B;
	if(A == B)
		cout << "Hoa.";
	else	if((A == 'B' && B == 'K') || (A == 'O' && B == 'B') || (A == 'K' && B == 'O'))
		cout << "A thang.";
	else
		cout << "B thang.";
}

19:
	Tim so lon nhat, nho nhat trong 3 so

#include <iostream>

using namespace std;

int main(){
	float a, b, c;
	cout << "Nhap 3 so: "; cin >> a >> b >> c;
	float max, min;
	max = (a > b) ? a : b;
	max = (max > c) ? max : c;
	cout << "Max = " << max;
	
	min = (a < b) ? a : b;
	min = (min < c) ? min : c;
	cout << "\nMin = " << min;
}	



20:
	Tim max, min cua 4 so.


#include <iostream>

using namespace std;

int main(){
	float a, b, c, d;
	cout << "Nhap 4 so: "; cin >> a >> b >> c >> d;
	float max, min;
	max = (a > b) ? a : b;
	max = (max > c) ? max : c;
	max = (max > d) ? max : d;
	cout << "Max = " << max;
	
	min = (a < b) ? a : b;
	min = (min < c) ? min : c;
	min = (min < d) ? min : d;
	cout << "\nMin = " << min;
}

21:
	Viet chuong trinh xep loai hoc sinh
	

#include <iostream>

using namespace std;

int main(){
	float	mark;
	cout << "Nhap diem: "; cin >> mark;
	if(mark >= 9)
		cout << "Gioi.";
	else 	if(mark >= 8)
		cout << "Kha.";
	else	if(mark >= 6)
		cout << "Trung binh";
	else	if(mark >= 5)
		cout << "Yeu.";
	else
		cout << "Kem.";
}


22:
	Giai pt ax + b > 0;

#include <iostream>

using namespace std;

int main(){
	int a, b;
	float x;
	cout << "Nhap he so a, b: "; cin >> a >> b;
	if(a > 0)
		cout << "x > " << -1.0*b/a;
	else	if(a < 0)
		cout << "x > " << -1.0*b/a;
	else
		cout << b << " > 0";
	
}

23:



#include <iostream>

using namespace std;

int UCLN(int a, int b){
	while(b != 0){
		int t  = b;
		b = a % b;
		a = t;
	}
	return a;
}

int main(){
	int tu1, mau1, tu2, mau2;
	
	cout << "Nhap tu phan so 1: "; cin >> tu1;
	do{
		cout << "Nhap mau phan so 1(khac 0): "; 
		cin >> mau1;
	}while(mau1 == 0);
	
	cout << "\nNhap tu phan so 2: "; cin >> tu2;
	do{
		cout << "Nhap mau phan so 2(khac 0): "; 
		cin >> mau2;
	}while(mau2 == 0);
	
	int ucln = UCLN(mau1, mau2);
	int maSoChung = mau1*mau2/ucln;
	cout << tu1 << " / " << mau1 << " + " << tu2 << " / " << mau2 << " = " << (maSoChung/mau1)*tu1 + maSoChung/mau2*tu2 << " / " << maSoChung << endl;
	cout << tu1 << " / " << mau1 << " - " << tu2 << " / " << mau2 << " = " << (maSoChung/mau1)*tu1 - maSoChung/mau2*tu2 << " / " << maSoChung << endl;
	cout << tu1 << " / " << mau1 << " * " << tu2 << " / " << mau2 << " = " << tu1*tu2/UCLN(tu1*tu2, mau1*mau2) << " / " << mau1*mau2/UCLN(tu1*tu2, mau1*mau2)  << endl;
	cout << tu1 << " / " << mau1 << " : " << tu2 << " / " << mau2 << " = " << tu1*mau2/UCLN(tu1*mau2, mau1*tu2) << " / " << mau1*tu2/UCLN(tu1*mau2, mau1*tu2)  << endl;

}	


24:


#include <iostream>

using namespace std;

int main(){
	char c;
	cout << "Nhap ki tu: "; cin >> c;
	if(c <='z' && c >= 'a')
		cout << "Chu in thuong.";
	else	if(c <= 'Z' && c >= 'A')
		cout << "Chu in hoa.";
	else	if(c <='9' && c >= '0')
		cout << "Ki tu so.";
	else
		cout << "Ki tu dac biet.";
	
}

25:


#include <iostream>

using namespace std;

int main(){
	int n, giatien;
	cout << "Nhap so dien: "; cin >> n;
	if(n <= 100)
		cout << "So tien phai tra: " << n*550*1.1 << " VND.";
	else if(n <= 150)	
		cout <<"So tien phai tra: " << (100*550 + (n-100)*900)*1.1 << " VND.";
	else if(n <= 200)
		cout <<"So tien phai tra: " << (100*550 + 50*900 + (n - 150)*1250)*1.1 << " VND.";
	else if(n <= 300)
		cout <<"So tien phai tra: " << (100*550 + 50*900 + 50*1250 + (n - 200)*1450)*1.1 << " VND.";
	else 
		cout <<"So tien phai tra: " << (100*550 + 50*900 + 50*1250 + 100*1450 + (n - 300)*1700)*1.1 << " VND.";
}

26:

#include <iostream>

using namespace std;

int main(){
	long MS, X, Y, Z, N, S;
	cout << "Nhap ma so: "; cin >> MS;
	switch(MS){
		case 1:{
			cout << "Nhap khoan luong co dinh X(theo tuan): ";
			cin >> X;
			cout << "So tien cong nhan nhan duoc trong tuan la: " << X;
			break;
		}
		case 2:{
			int h;
			cout << "Nhap khoan luong co ban Y: ";
			cin >> Y;
			cout << "Nhap thoi gian cong nhan lam(tinh theo gio): ";
			cin >> h;
			cout << "So tien cong nhan nhan duoc trong tuan la: " << Y + (h - 40)*Y/40*1.5;
			break;
		}
		case 3:{
			cout << "Nhap tri gia doanh thuZ: ";
			cin >> Z;
			cout << "So tien cong nhan nhan duoc trong tuan la: " << 500000 + Z*1.07;
			break;
		}
		case 4:{
			cout << "Nhap so san pham N: ";
			cin >> N;
			cout << "Nhap gia tien S cua 1 san pham: ";
			cin >> S;
			cout << "So tien cong nhan nhan duoc trong tuan la: " << N*S;
			break;
		}
	}
	
}

27:



#include <iostream>
#include <string.h>

using namespace std;

int main(){
	char a[100];
	cout << "Nhap so a: "; cin >> a;
	if(strlen(a) > 1)
		switch (a[strlen(a) - 2] - 48){
			case 1:{
				cout << " muoi";
				if(a[strlen(a) -1] == 48)
					return 0;
				break;
			}
			case 3:{
				cout << " ba muoi";
				if(a[strlen(a) -1] == 48)
					return 0;
				break;
			}
			case 4:{
				cout << " bon muoi";
				if(a[strlen(a) -1] == 48)
					return 0;
				break;
			}
			case 5:{
				cout << " nam muoi";
				if(a[strlen(a) -1] == 48)
					return 0;
				break;
			}
			
			case 6:{
				cout << " sau muoi";
				if(a[strlen(a) -1] == 48)
					return 0;
				break;
			}
			case 7:{
				cout << " bay muoi";
				if(a[strlen(a) -1] == 48)
					return 0;
				break;
			}
			case 8:{
				cout << " tam muoi";
				if(a[strlen(a) -1] == 48)
					return 0;
				break;
			}
			case 9:{
				cout << " chin muoi";
				if(a[strlen(a) -1] == 48)
					return 0;
				break;
			}
		}
	switch (a[strlen(a) - 1] - 48){
		case 0 :{
			cout << " khong.";
			break;
		}
		case 1 :{
			cout << " mot.";
			break;
		}
		case 2 :{
			cout << " hai.";
			break;
		}
		case 3 :{
			cout << " ba.";
			break;
		}
		case 4 :{
			cout << " bon.";
			break;
		}
		case 5 :{
			cout << " lam.";
			break;
		}case 6 :{
			cout << " sau.";
			break;
		}
		case 7 :{
			cout << " bay.";
			break;
		}
		case 8 :{
			cout << " tam.";
			break;
		}
		case 9 :{
			cout << " chin.";
			break;
		}
	}
}


28:



#include <iostream>
#include <string.h>

using namespace std;

int main(){
	char a[100];
	cout << "Nhap so a: "; cin >> a;
	switch (a[0] - 48){
			case 1:{
				cout << " mot tram";
				break;
			}
			case 2:{
				cout << " hai tram";
				break;
			}
			case 3:{
				cout << " ba tram";
				break;
			}
			case 4:{
				cout << " bon tram";
				break;
			}
			case 5:{
				cout << " nam tram";
				break;
			}
			
			case 6:{
				cout << " sau tram";
				break;
			}
			case 7:{
				cout << " bay tram";
				break;
			}
			case 8:{
				cout << " tam tram";
				break;
			}
			case 9:{
				cout << " chin tram";
				break;
			}
		}
	switch (a[1] - 48){
			case 1:{
				cout << " muoi";
				break;
			}
			case 2:{
				cout << " hai muoi";
				break;
			}
			case 3:{
				cout << " ba muoi";
				break;
			}
			case 4:{
				cout << " bon muoi";
				break;
			}
			case 5:{
				cout << " nam muoi";
				break;
			}
			
			case 6:{
				cout << " sau muoi";
				break;
			}
			case 7:{
				cout << " bay muoi";
				break;
			}
			case 8:{
				cout << " tam muoi";
				break;
			}
			case 9:{
				cout << " chin muoi";
				break;
			}
			case 0:{
				if(a[2 != 48])
					cout << " linh";
				break;
			}
		}
	if(a[2] == 48)
		return 0;
	switch (a[strlen(a) - 1] - 48){
		case 0 :{
			cout << " khong.";
			break;
		}
		case 1 :{
			cout << " mot.";
			break;
		}
		case 2 :{
			cout << " hai.";
			break;
		}
		case 3 :{
			cout << " ba.";
			break;
		}
		case 4 :{
			cout << " bon.";
			break;
		}
		case 5 :{
			cout << " lam.";
			break;
		}case 6 :{
			cout << " sau.";
			break;
		}
		case 7 :{
			cout << " bay.";
			break;
		}
		case 8 :{
			cout << " tam.";
			break;
		}
		case 9 :{
			cout << " chin.";
			break;
		}
	}
}



29:



#include <iostream>

using namespace std;

int main(){
	int n;
	long kq = 1;
	cout << "Nhap n: "; cin >> n;
	if(n % 2 == 0){
		for(int i = 2; i <= n; i+=2)
			kq *= i;
		cout << n <<"!! = " << kq;
	}else{
		for(int i = 1; i <= n; i+=2)
			kq *= i;
		cout << n <<"!! = " << kq;
	}		
	
}


30:



#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int n;
	long s1 = 0, s2 = 0, s3 = 1;
	float s4  = 0;
	cout << "Nhap n: "; cin >> n;
	for(int i = 1; i<= n; i++){
		s1 += i;
		s2 += 2*i + 1;
		s3 *= i;
		if(i>=2)
			s4 += 1.0/(i*i + i);
	}
	cout << "S1 = " << s1 << endl;
	cout << "S2 = " << s2 << endl;
	cout << "S3 = " << s3 << endl;
	cout << "S4 = " << fixed << setprecision(2) << s4 << endl;
	
}

31:


#include <iostream>

using namespace std;

int main(){
	int i, dem = 0;
		for(i=3; i<=100; i++)
			if(i%3 == 0 || i % 7 == 0)
				dem++;
		cout << "Tu 1 -> 100 co " << dem << " so thoa man.";
	
}
32:

#include <iostream>
#include <math.h>

using namespace std;

int main(){
	int n, i;
	cout << "Nhap so can kiem tra: "; cin >> n;
	
	if(n < 2){
		cout << n << " khong phai so nguyen to.";
			return 0;
	}
	
	for(i=2; i<=sqrt(n); i++)
		if(n % i == 0){
			cout << n << " khong phai so nguyen to.";
			return 0;
		}
	cout << n << " la so nguyen to.";
}

33:

#include <iostream>

using namespace std;

int main(){
	int n, i = 2;
	cout << "Nhap so can phan tich: "; cin >> n;
	cout << "\n" << n << " = ";
	while(n != 1){
		if(n % i == 0){
			if(n == i)
				cout << i;
			else
				cout << i << " x ";
			n /= i;
		}
		else
			i++;
	}
	
}


34:



#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	float a, sum = 0;
	int n = 0;
	char c;
	do{
		cout << "\nNhap diem: "; cin >> a;
		sum += a;
		cout << "Ban co muon nhap tiep(y/n)? "; cin >> c;
		n++;
	}while(c == 'y');
	cout << "Diem trung binh cua " << n << " sinh vien la: " << fixed << setprecision(2) << sum/n;
	
}

35:

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	float a, sum = 0;
	int n = 0;
	do{
		cout << "\nNhap so: "; cin >> a;
		if(a == 9999)
			break;
		sum += a;
		n++;
	}while(1);
	cout << "Diem trung binh cua " << n << " so la: " << fixed << setprecision(2) << sum/n;
	
}


36:


#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int i, j;
	for(i=1; i<=10; i++){
		for(j=1; j<10; j++)
			cout << setw(2) <<  i << " x"<< setw(2) << j << " =" << setw(2) << i*j << "  ";
		cout << endl;
	}
}
	
37:

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
	float x = 0;
	while(x != 180 + 5){
	cout << "sin(" << (int) x <<") = " << fixed << setprecision(2) << sin(x*3.14/180) << "\t\tcos(" << (int) x << ") = " << fixed << setprecision(2) << cos(x*3.14/180);
	if(x != 90)
		cout << "\t\ttan(" << (int) x <<") = " << fixed << setprecision(2) << tan(x*3.14/180);
	else
		cout << "\t\ttan(" << (int) x << ") khong xac dinh.";
	x+= 5;
	cout << endl; 
	}
	
}


38:


#include <iostream>

using namespace std;

int main(){
	int m, n;
	cout <<"Nhap 2 so M, N: " ; cin >> m >> n;
	int BCNN = m*n;
	while (m !=0){
		int t = m;
		m = n % m;
		n = t;
	}
	cout << "UCLN = " << n;
	cout << "\nBCNN = " << BCNN/n; 
	
}

39:
*//*
3:
Tinh dien tich, chu vi khi biet ban kinh
Tinh ban kinh khi biet dien tich;


#include <iostream> 
#include <math.h>

using namespace std;

int main(){
	float r , s, c;
	cout << "Nhap ban kinh: "; cin >> r;
	cout << "Dien tich hinh tron co ban kinh " << r << " la: " << 3.14*r*r << " chu vi la: "<< 2*3.14*r<< endl;
	cout << "Nhap dien tich: "; cin >> s;
	cout << "Ban kinh hinh tron co dien tich " << s << " la: "<< sqrt(s/3.14); 
}


4:
	Nhap vao day lon, day nho, chieu cao xuat ra dien tich
	

#include <iostream> 

using namespace std;

int main(){
	float a, b, h, s;
	cout << "Nhap do dai day lon: "; cin >> a;
	cout << "Nhap do dai day nho: "; cin >> b;
	cout << "Nhap chieu cao: "; cin >> h;
	s = (a + b)*h/2;
	cout << "Dien tich la: " << s;
	
}


7:
	Nhap tt cua 1 sinh vien: MSV, fullName, address, yearOfBirth, Mark
	xuat tt;



#include <iostream> 
#include <string.h>

using namespace std;

int main(){
	char MSV[10];
	cout << "Nhap MSV: "; cin >> MSV;
	char fullName[50];
	cout << "Nhap ho va ten: ";	cin.ignore(); cin.getline(fullName, 49);
	char Address[100];
	cout << "Nhap que quan: ";	 cin.getline(Address, 99);
	int yearOfBirth;
	cout << "Nhap nam sinh: "; cin >> yearOfBirth;
	float Mark;
	cout << "Nhap diem: "; cin >> Mark;
	cout <<"\tSinh vien: " << fullName <<", MSV: " << MSV << ". Sinh nam " << yearOfBirth << ". Que quan " << Address << " co diem trung binh: "<< Mark;
	
}

8:
	Nhap vao 3 canh cua tam giac va in ra dien tich


#include <iostream> 
#include <math.h>

using namespace std;

int main(){
	float a, b, c, s;
	cout << "Nhap do dai 3 canh: "; cin >> a >> b >> c;
	if(a + b <= c || a + c <= b || b + c <= a)
		cout << "Do dai khong phu hop.";
	else{
		float p = (a + b + c)/2;
		s = sqrt(p*(p-a)*(p-b)*(p-c));
		cout << "Dien tich la: " << s;
	}
}


9:
	Nhap toa do 2 diem A, B xuat toa do trung diem I



#include <iostream> 

using namespace std;

int main(){
	float x1, x2, y1, y2;
	cout << "Nhap toa do diem A: "; cin >> x1 >> y1;
	cout << "Nhap toa do diem B: "; cin >> x2 >> y2;
	cout << "Toa do trung diem A va B la: I(" << (x1 + x2)/2 <<";" <<(y1 + y2)/2 << ")\n";
}

10:
	Nhap toa do 3 dinh A, B, C xuat toa do trong tam
	
#include <iostream> 

using namespace std;

int main(){
	float x1, x2, x3, y1, y2, y3;
	cout << "Nhap toa do diem A: "; cin >> x1 >> y1;
	cout << "Nhap toa do diem B: "; cin >> x2 >> y2;
	cout << "Nhap toa do diem C: "; cin >> x3 >> y3;
	cout << "Toa do trong tam la: G(" << (x1 + x2 + x3)/3 <<";" <<(y1 + y2 + y3)/3 << ")\n";
}

11:
	Nhap he so a, b, c, x cua tam thuc bac 2 va tinh gtri
	


#include <iostream> 

using namespace std;

int main(){
	float a, b, c, x;
	cout << "Nhap he so a, b, c: "; cin >> a >> b >> c;
	cout << "Nhap gia tri x: "; cin >> x;
	cout << "f(" << x <<") = " << a*x*x+b*x + c;
}

12:

	
#include <iostream> 

using namespace std;

int main(){
	float i = 1, j = 3, d;
	d = (i=j)++;
	cout << d << endl;
	d = i+j++;
	cout << d << endl;
//	d = ++(i+j);	sai
//	cout << d << endl;
//	d = ++i+++j;	sai
//	cout << d << endl;
}


13:
	kiem tra so chan, le


#include <iostream>

using namespace std;

int main(){
	int n;
	cout << "Nhap so can kiem tra: "; cin >> n;
	if(n % 2 == 0)
		cout << n << " la so chan.";
	else
		cout << n << " la so le.";
}

14:
	Tim so lon nhat cua 2 so

#include <iostream>

using namespace std;

int main(){
	int num1, num2;
	cout << "Nhap 2 so: "; cin >> num1 >> num2;
	if(num1 == num2)
		cout << "Khong ton tai max";
	else	if(num1 > num2)
		cout << "max = " << num1;
	else
		cout << "max = " << num2;
}

15:
	B, O, K xuat ra nguoi thang, hoa


#include <iostream>

using namespace std;

int main(){
	char A, B;
	cout << "Nhap lua chon cua 2 nguoi: "; cin >> A >> B;
	if(A == B)
		cout << "Hoa.";
	else	if((A == 'B' && B == 'K') || (A == 'O' && B == 'B') || (A == 'K' && B == 'O'))
		cout << "A thang.";
	else
		cout << "B thang.";
}

19:
	Tim so lon nhat, nho nhat trong 3 so

#include <iostream>

using namespace std;

int main(){
	float a, b, c;
	cout << "Nhap 3 so: "; cin >> a >> b >> c;
	float max, min;
	max = (a > b) ? a : b;
	max = (max > c) ? max : c;
	cout << "Max = " << max;
	
	min = (a < b) ? a : b;
	min = (min < c) ? min : c;
	cout << "\nMin = " << min;
}	



20:
	Tim max, min cua 4 so.


#include <iostream>

using namespace std;

int main(){
	float a, b, c, d;
	cout << "Nhap 4 so: "; cin >> a >> b >> c >> d;
	float max, min;
	max = (a > b) ? a : b;
	max = (max > c) ? max : c;
	max = (max > d) ? max : d;
	cout << "Max = " << max;
	
	min = (a < b) ? a : b;
	min = (min < c) ? min : c;
	min = (min < d) ? min : d;
	cout << "\nMin = " << min;
}

21:
	Viet chuong trinh xep loai hoc sinh
	

#include <iostream>

using namespace std;

int main(){
	float	mark;
	cout << "Nhap diem: "; cin >> mark;
	if(mark >= 9)
		cout << "Gioi.";
	else 	if(mark >= 8)
		cout << "Kha.";
	else	if(mark >= 6)
		cout << "Trung binh";
	else	if(mark >= 5)
		cout << "Yeu.";
	else
		cout << "Kem.";
}


22:
	Giai pt ax + b > 0;

#include <iostream>

using namespace std;

int main(){
	int a, b;
	float x;
	cout << "Nhap he so a, b: "; cin >> a >> b;
	if(a > 0)
		cout << "x > " << -1.0*b/a;
	else	if(a < 0)
		cout << "x > " << -1.0*b/a;
	else
		cout << b << " > 0";
	
}

23:



#include <iostream>

using namespace std;

int UCLN(int a, int b){
	while(b != 0){
		int t  = b;
		b = a % b;
		a = t;
	}
	return a;
}

int main(){
	int tu1, mau1, tu2, mau2;
	
	cout << "Nhap tu phan so 1: "; cin >> tu1;
	do{
		cout << "Nhap mau phan so 1(khac 0): "; 
		cin >> mau1;
	}while(mau1 == 0);
	
	cout << "\nNhap tu phan so 2: "; cin >> tu2;
	do{
		cout << "Nhap mau phan so 2(khac 0): "; 
		cin >> mau2;
	}while(mau2 == 0);
	
	int ucln = UCLN(mau1, mau2);
	int maSoChung = mau1*mau2/ucln;
	cout << tu1 << " / " << mau1 << " + " << tu2 << " / " << mau2 << " = " << (maSoChung/mau1)*tu1 + maSoChung/mau2*tu2 << " / " << maSoChung << endl;
	cout << tu1 << " / " << mau1 << " - " << tu2 << " / " << mau2 << " = " << (maSoChung/mau1)*tu1 - maSoChung/mau2*tu2 << " / " << maSoChung << endl;
	cout << tu1 << " / " << mau1 << " * " << tu2 << " / " << mau2 << " = " << tu1*tu2/UCLN(tu1*tu2, mau1*mau2) << " / " << mau1*mau2/UCLN(tu1*tu2, mau1*mau2)  << endl;
	cout << tu1 << " / " << mau1 << " : " << tu2 << " / " << mau2 << " = " << tu1*mau2/UCLN(tu1*mau2, mau1*tu2) << " / " << mau1*tu2/UCLN(tu1*mau2, mau1*tu2)  << endl;

}	


24:


#include <iostream>

using namespace std;

int main(){
	char c;
	cout << "Nhap ki tu: "; cin >> c;
	if(c <='z' && c >= 'a')
		cout << "Chu in thuong.";
	else	if(c <= 'Z' && c >= 'A')
		cout << "Chu in hoa.";
	else	if(c <='9' && c >= '0')
		cout << "Ki tu so.";
	else
		cout << "Ki tu dac biet.";
	
}

25:


#include <iostream>

using namespace std;

int main(){
	int n, giatien;
	cout << "Nhap so dien: "; cin >> n;
	if(n <= 100)
		cout << "So tien phai tra: " << n*550*1.1 << " VND.";
	else if(n <= 150)	
		cout <<"So tien phai tra: " << (100*550 + (n-100)*900)*1.1 << " VND.";
	else if(n <= 200)
		cout <<"So tien phai tra: " << (100*550 + 50*900 + (n - 150)*1250)*1.1 << " VND.";
	else if(n <= 300)
		cout <<"So tien phai tra: " << (100*550 + 50*900 + 50*1250 + (n - 200)*1450)*1.1 << " VND.";
	else 
		cout <<"So tien phai tra: " << (100*550 + 50*900 + 50*1250 + 100*1450 + (n - 300)*1700)*1.1 << " VND.";
}

26:

#include <iostream>

using namespace std;

int main(){
	long MS, X, Y, Z, N, S;
	cout << "Nhap ma so: "; cin >> MS;
	switch(MS){
		case 1:{
			cout << "Nhap khoan luong co dinh X(theo tuan): ";
			cin >> X;
			cout << "So tien cong nhan nhan duoc trong tuan la: " << X;
			break;
		}
		case 2:{
			int h;
			cout << "Nhap khoan luong co ban Y: ";
			cin >> Y;
			cout << "Nhap thoi gian cong nhan lam(tinh theo gio): ";
			cin >> h;
			cout << "So tien cong nhan nhan duoc trong tuan la: " << Y + (h - 40)*Y/40*1.5;
			break;
		}
		case 3:{
			cout << "Nhap tri gia doanh thuZ: ";
			cin >> Z;
			cout << "So tien cong nhan nhan duoc trong tuan la: " << 500000 + Z*1.07;
			break;
		}
		case 4:{
			cout << "Nhap so san pham N: ";
			cin >> N;
			cout << "Nhap gia tien S cua 1 san pham: ";
			cin >> S;
			cout << "So tien cong nhan nhan duoc trong tuan la: " << N*S;
			break;
		}
	}
	
}

27:



#include <iostream>
#include <string.h>

using namespace std;

int main(){
	char a[100];
	cout << "Nhap so a: "; cin >> a;
	if(strlen(a) > 1)
		switch (a[strlen(a) - 2] - 48){
			case 1:{
				cout << " muoi";
				if(a[strlen(a) -1] == 48)
					return 0;
				break;
			}
			case 3:{
				cout << " ba muoi";
				if(a[strlen(a) -1] == 48)
					return 0;
				break;
			}
			case 4:{
				cout << " bon muoi";
				if(a[strlen(a) -1] == 48)
					return 0;
				break;
			}
			case 5:{
				cout << " nam muoi";
				if(a[strlen(a) -1] == 48)
					return 0;
				break;
			}
			
			case 6:{
				cout << " sau muoi";
				if(a[strlen(a) -1] == 48)
					return 0;
				break;
			}
			case 7:{
				cout << " bay muoi";
				if(a[strlen(a) -1] == 48)
					return 0;
				break;
			}
			case 8:{
				cout << " tam muoi";
				if(a[strlen(a) -1] == 48)
					return 0;
				break;
			}
			case 9:{
				cout << " chin muoi";
				if(a[strlen(a) -1] == 48)
					return 0;
				break;
			}
		}
	switch (a[strlen(a) - 1] - 48){
		case 0 :{
			cout << " khong.";
			break;
		}
		case 1 :{
			cout << " mot.";
			break;
		}
		case 2 :{
			cout << " hai.";
			break;
		}
		case 3 :{
			cout << " ba.";
			break;
		}
		case 4 :{
			cout << " bon.";
			break;
		}
		case 5 :{
			cout << " lam.";
			break;
		}case 6 :{
			cout << " sau.";
			break;
		}
		case 7 :{
			cout << " bay.";
			break;
		}
		case 8 :{
			cout << " tam.";
			break;
		}
		case 9 :{
			cout << " chin.";
			break;
		}
	}
}


28:



#include <iostream>
#include <string.h>

using namespace std;

int main(){
	char a[100];
	cout << "Nhap so a: "; cin >> a;
	switch (a[0] - 48){
			case 1:{
				cout << " mot tram";
				break;
			}
			case 2:{
				cout << " hai tram";
				break;
			}
			case 3:{
				cout << " ba tram";
				break;
			}
			case 4:{
				cout << " bon tram";
				break;
			}
			case 5:{
				cout << " nam tram";
				break;
			}
			
			case 6:{
				cout << " sau tram";
				break;
			}
			case 7:{
				cout << " bay tram";
				break;
			}
			case 8:{
				cout << " tam tram";
				break;
			}
			case 9:{
				cout << " chin tram";
				break;
			}
		}
	switch (a[1] - 48){
			case 1:{
				cout << " muoi";
				break;
			}
			case 2:{
				cout << " hai muoi";
				break;
			}
			case 3:{
				cout << " ba muoi";
				break;
			}
			case 4:{
				cout << " bon muoi";
				break;
			}
			case 5:{
				cout << " nam muoi";
				break;
			}
			
			case 6:{
				cout << " sau muoi";
				break;
			}
			case 7:{
				cout << " bay muoi";
				break;
			}
			case 8:{
				cout << " tam muoi";
				break;
			}
			case 9:{
				cout << " chin muoi";
				break;
			}
			case 0:{
				if(a[2 != 48])
					cout << " linh";
				break;
			}
		}
	if(a[2] == 48)
		return 0;
	switch (a[strlen(a) - 1] - 48){
		case 0 :{
			cout << " khong.";
			break;
		}
		case 1 :{
			cout << " mot.";
			break;
		}
		case 2 :{
			cout << " hai.";
			break;
		}
		case 3 :{
			cout << " ba.";
			break;
		}
		case 4 :{
			cout << " bon.";
			break;
		}
		case 5 :{
			cout << " lam.";
			break;
		}case 6 :{
			cout << " sau.";
			break;
		}
		case 7 :{
			cout << " bay.";
			break;
		}
		case 8 :{
			cout << " tam.";
			break;
		}
		case 9 :{
			cout << " chin.";
			break;
		}
	}
}



29:



#include <iostream>

using namespace std;

int main(){
	int n;
	long kq = 1;
	cout << "Nhap n: "; cin >> n;
	if(n % 2 == 0){
		for(int i = 2; i <= n; i+=2)
			kq *= i;
		cout << n <<"!! = " << kq;
	}else{
		for(int i = 1; i <= n; i+=2)
			kq *= i;
		cout << n <<"!! = " << kq;
	}		
	
}


30:



#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int n;
	long s1 = 0, s2 = 0, s3 = 1;
	float s4  = 0;
	cout << "Nhap n: "; cin >> n;
	for(int i = 1; i<= n; i++){
		s1 += i;
		s2 += 2*i + 1;
		s3 *= i;
		if(i>=2)
			s4 += 1.0/(i*i + i);
	}
	cout << "S1 = " << s1 << endl;
	cout << "S2 = " << s2 << endl;
	cout << "S3 = " << s3 << endl;
	cout << "S4 = " << fixed << setprecision(2) << s4 << endl;
	
}

31:


#include <iostream>

using namespace std;

int main(){
	int i, dem = 0;
		for(i=3; i<=100; i++)
			if(i%3 == 0 || i % 7 == 0)
				dem++;
		cout << "Tu 1 -> 100 co " << dem << " so thoa man.";
	
}
32:

#include <iostream>
#include <math.h>

using namespace std;

int main(){
	int n, i;
	cout << "Nhap so can kiem tra: "; cin >> n;
	
	if(n < 2){
		cout << n << " khong phai so nguyen to.";
			return 0;
	}
	
	for(i=2; i<=sqrt(n); i++)
		if(n % i == 0){
			cout << n << " khong phai so nguyen to.";
			return 0;
		}
	cout << n << " la so nguyen to.";
}

33:

#include <iostream>

using namespace std;

int main(){
	int n, i = 2;
	cout << "Nhap so can phan tich: "; cin >> n;
	cout << "\n" << n << " = ";
	while(n != 1){
		if(n % i == 0){
			if(n == i)
				cout << i;
			else
				cout << i << " x ";
			n /= i;
		}
		else
			i++;
	}
	
}


34:



#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	float a, sum = 0;
	int n = 0;
	char c;
	do{
		cout << "\nNhap diem: "; cin >> a;
		sum += a;
		cout << "Ban co muon nhap tiep(y/n)? "; cin >> c;
		n++;
	}while(c == 'y');
	cout << "Diem trung binh cua " << n << " sinh vien la: " << fixed << setprecision(2) << sum/n;
	
}

35:

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	float a, sum = 0;
	int n = 0;
	do{
		cout << "\nNhap so: "; cin >> a;
		if(a == 9999)
			break;
		sum += a;
		n++;
	}while(1);
	cout << "Diem trung binh cua " << n << " so la: " << fixed << setprecision(2) << sum/n;
	
}


36:


#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int i, j;
	for(i=1; i<=10; i++){
		for(j=1; j<10; j++)
			cout << setw(2) <<  i << " x"<< setw(2) << j << " =" << setw(2) << i*j << "  ";
		cout << endl;
	}
}
	
37:

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
	float x = 0;
	while(x != 180 + 5){
	cout << "sin(" << (int) x <<") = " << fixed << setprecision(2) << sin(x*3.14/180) << "\t\tcos(" << (int) x << ") = " << fixed << setprecision(2) << cos(x*3.14/180);
	if(x != 90)
		cout << "\t\ttan(" << (int) x <<") = " << fixed << setprecision(2) << tan(x*3.14/180);
	else
		cout << "\t\ttan(" << (int) x << ") khong xac dinh.";
	x+= 5;
	cout << endl; 
	}
	
}


38:


#include <iostream>

using namespace std;

int main(){
	int m, n;
	cout <<"Nhap 2 so M, N: " ; cin >> m >> n;
	int BCNN = m*n;
	while (m !=0){
		int t = m;
		m = n % m;
		n = t;
	}
	cout << "UCLN = " << n;
	cout << "\nBCNN = " << BCNN/n; 
	
}

39:
*/
#include <iostream>

using namespace std;

void QuyDoi(int *b, int n, int *a, int gtri, int Loai){
	int i = n - 1;
	while(gtri >0){
		if(gtri < a[i] || i == Loai)
			i--;
		if(gtri >= a[i] && i != Loai){
			b[i] ++;
			gtri -= a[i];
		}
	}
}

int main(){
	int gtri = 1000, m;
	do{
		if(gtri % 1000 != 0)
			cout << "Gia tri nhap k hop le!\nVui long nhap lai: ";
		else
		cout << "Nhap gia tri can doi: ";
		cin >> gtri;
	}while(gtri % 1000 != 0);
	
	m = gtri;
	int a[4] ={1000, 2000, 5000, 10000}, i = 3, cach = 1;
	int n = 0;
	
	while(a[0] * n != gtri){
		int b[4] ={0};
		cout << "Cach" << cach << ":\n";
		QuyDoi(b, 4 - cach + 1, a, gtri, 10);
		for(i=0; i<4; i++)
		if(b[i] != 0)
			cout << b[i] << " to menh gia " << a[i] << endl;
		cach ++;
		n = b[0];
	}
}
