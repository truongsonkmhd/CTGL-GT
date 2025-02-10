#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;
string chuyenDoi1(int n){
	string s1;
	int i;
	while(n != 0){
		s1 += (char) (n % 2 + 48);
		n /= 2;
	}
	for(i=0; i<= s1.size()/2; i++){
		char t = s1[i];
		s1[i] = s1[s1.size() - 1 - i];
		s1[s1.size() - 1 - i] = t;
	}
	return s1;
}
string ChuyenDoi(double a){
	string s, s1, s2, s3;
	if(a < 0)	s = "1";
	else	s = "0";
	int n = a / 1;
	s1 = chuyenDoi1(abs(n));
	s3 = chuyenDoi1(127 + s1.size() - 1);
	long t = (a - n)*pow(2, 23);
	t = abs(t);
	int i = 22;
	while(i != 1){
		if(t - pow(2, i) > 0){
			s2 += "1";
			t -= pow(2, i);
		}else
			s2 += "0";
		i--;	
	}
	s += s3;
	for(i=1; i<s1.size(); i++)
		s += s1[i];
	cout << s2 << endl;
	s += s2;
	return s;
}
int main(){
	float m = -0.375;
//	int msv;
//	cin >> msv;
//	if(msv < 10)	msv += 20;
//	m += msv;
	cin >> m;
	cout << ChuyenDoi(m);
}
