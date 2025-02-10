#include <iostream>
#include <string.h>

using namespace std;

void DaoNguocXau(string &s);
int SoSanh(string a, string b);
string Cong2SoDuong(string a, string b);
string Hieu2SoDuong(string a, string b);
string TichVoi1SoDuong(string a, char x, int n);
string Tich2SoDuong(string a, string b);
string Chia2SoDuong(string a, string b);
string Tong(string a, string b);
string Hieu(string a, string b);
string Tich(string a, string b);
string Thuong(string a, string b);
int main(){
	string a, b, c;
	cin >> a >> b;
//	c = Hieu2SoDuong("11725", "1242");
//	c = TichVoi1SoDuong(a, '0', 0);
	c = Thuong(a, b);
	cout << c;
}
/*
241452321
1242
*/
void DaoNguocXau(string &s){ // dao nguoc xau
	int len = s.size();
	for(long i=0; i<len/2; i++){ // dao vi tri cua cac so o vi tri doi xung
		char c = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = c;
	}
}
int SoSanh(string a, string b){
	if(a.size() == b.size())	return a.compare(b);
	if(a.size() > b.size())		return 1;
	return -1;
}
string Cong2SoDuong(string a, string b){
	string kq;
	long len1 = a.size(); // lay do dai cua so thu 1
	long len2 = b.size();     // lay do dai cua so thu 2
	long len = len1 > len2 ? len1 : len2; // toan tu 3 ngoi neu so sanh dung thi len = len1 nguoc lai len = len2
	int d = 0; // phan thua
	DaoNguocXau(a);
	DaoNguocXau(b);
	
	for(long i = 0; i < len + 1; i++){
		char c = (i < len1)*(a[i] - 48) + (i < len2)*(b[i] - 48) + d; // tinh gia tri o hang i
		d = c / 10;
		c %= 10;
		c += 48;
		kq.push_back(c); // them vao cuoi
	}
	DaoNguocXau(kq);
	while(kq[0] == 48 && kq.size() > 1)
		kq.erase(0, 1); // xoa ki tu dau
	return kq;
}
string Hieu2SoDuong(string a, string b){
	string kq;
	long len1 = a.size(); // lay do dai cua so thu 1
	long len2 = b.size();     // lay do dai cua so thu 2
	long len = len1 > len2 ? len1 : len2;
	int d = 0; // phan thua
	DaoNguocXau(a);
	DaoNguocXau(b);
	
	for(long i = 0; i < len1; i++){
		char c = (a[i] - 48) - (i < len2)*(b[i] - 48) - d; 
		if(c < 0){ // neu chu so o so tru lon chu so o so bi tru thi tang them 10 va phan bu = 1
			c += 10;
			d = 1;
		}else
			d = 0;
		c += 48;
		kq.push_back(c);
	}
	DaoNguocXau(kq);
	while(kq[0] == 48 && kq.size() > 1)
		kq.erase(0, 1);
	return kq;
}
string TichVoi1SoDuong(string a, char x, int n){
	string kq;
	for(long i=0; i<n; i++) // chen them n so 0
		kq.push_back('0');
	long len1 = a.size(); // lay do dai cua so thu 1
	int d = 0; // phan thua
	DaoNguocXau(a);
	for(long i = 0; i < len1 + 1; i++){
		char c = (i < len1)*(a[i] - 48)*(x - 48) + d;
		d = c / 10; // phan thua 
		c %= 10; //
		c += 48; 
		kq.push_back(c);
	}
	DaoNguocXau(kq);
	while(kq[0] == 48 && kq.size() > 1)
		kq.erase(0, 1);
	return kq;
}
string Tich2SoDuong(string a, string b){
	string kq;
	for(long i=b.size() - 1; i>=0; i--){ // nhan so a voi cac chu so cua b tu duoi len
		kq = Cong2SoDuong(kq, TichVoi1SoDuong(a, b[i],b.size() - 1 - i)); // cong vao ket qua a*b[i]
	}
	return kq;
}
string Chia2SoDuong(string a, string b){
	int n = a.size() - b.size();
	if(n < 0)	return "0";
	string kq;
	string du = a.substr(0, b.size());
	for(int i=0; i<=n; i++){
		char c = '0';
		string tam = "0";
		while(SoSanh(tam, du) == -1 || SoSanh(tam, du) == 0){
			c++;
			tam = TichVoi1SoDuong(b, c, 0);
		}
		c--;
		tam = TichVoi1SoDuong(b, c, 0);
		du = Hieu2SoDuong(du, tam);
		if(du == "0")
			du.erase(0,1);
		kq.push_back(c);
		du.push_back(a[b.size() + i]);
	}
	while(kq[0] == 48 && kq.size() > 1)
		kq.erase(0, 1);
	return kq;
}
string Tong(string a, string b){
	if(a[0] == '-' && b[0] == '-'){ // tong 2 so am
		a.erase(0, 1);
		b.erase(0, 1);
		return "-" + Cong2SoDuong(a, b);  
	}
	if(a[0] == '-'){
		a.erase(0, 1);
		return Hieu(b, a); // lay b - a;
	}
	if(b[0] == '-'){
		b.erase(0, 1);
		return Hieu(a, b); // lay a - b;
	}
	return Cong2SoDuong(a, b);// tong 2 so duong
}
string Hieu(string a, string b){
	if(a[0] == '-' && b[0] == '-'){ // hieu -1 - (-2) = 2 - 1
		a.erase(0, 1);
		b.erase(0, 1);
		return Hieu(b, a);  
	}
	if(a[0] == '-'){ // -1 - 2 = -1 + (-2)
		b = "-" + b; 
		return Tong(a, b);
	}
	if(b[0] == '-'){
		b.erase(0, 1);
		return Tong(a, b); // lay a + -b;
	}
	if(SoSanh(a, b) == -1)
		return "-" + Hieu(b, a); // 5 - 6 = - (6 - 5)
	if(SoSanh(a, b) == 0)	return "0";
	return Hieu2SoDuong(a, b);// a - b
}
string Tich(string a, string b){
	if(a == "0" || b == "0")
		return "0";
	if(a[0] == '-' && b[0] == '-'){ // hieu -1 * (-2) = 1*2
		a.erase(0, 1);
		b.erase(0, 1);
		return Tich2SoDuong(a, b);  
	}
	if(a[0] == '-'){ // -1 * 2 = - (1*2)
		a.erase(0, 1);
		return "-" + Tich2SoDuong(a, b);  
	}
	if(b[0] == '-'){ // 1 * (-2) = - (1*2)
		b.erase(0, 1);
		return "-" + Tich2SoDuong(a, b);
	}
	return Tich2SoDuong(a, b);
}
string Thuong(string a, string b){
	if(a == "0")	return "0";
	if(b == "0")	return "Phep tinh khong hop le!";
	if(a[0] == '-' && b[0] == '-'){ // hieu -1 / (-2) = 1 / 2
		a.erase(0, 1);
		b.erase(0, 1);
		return Chia2SoDuong(a, b);  
	}
	if(a[0] == '-'){ // -1 * 2 = - (1*2)
		a.erase(0, 1);
		return Chia2SoDuong(a, b) == "0" ? "0" : "-" + Chia2SoDuong(a, b);  
	}
	if(b[0] == '-'){ // 1 * (-2) = - (1*2)
		b.erase(0, 1);
		return Chia2SoDuong(a, b) == "0" ? "0" : "-" + Chia2SoDuong(a, b); 
	}
	return Chia2SoDuong(a, b);
}
