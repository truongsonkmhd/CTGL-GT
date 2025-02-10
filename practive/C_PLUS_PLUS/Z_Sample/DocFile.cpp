#include <iostream>
#include <fstream>

using namespace std;

int KT(int n){
	int m = n;
	for(int i=1; i<n; i++)
		if(n % i == 0)
			m -= i;	
	if(m == 0)
		return 1;
	return 0;
}
int* Doc(int &n, char *s){
	ifstream fileIn;
	fileIn.open(s);
	fileIn >> n;
	int *a = new int[n];
	for(int i=0; i<n; i++)
		fileIn >> a[i];
	return a;	
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
	int *a;
	a = Doc(n, "D:\\C++\\fileOut.txt");
	
	ofstream fileOut("D:\\C++\\Text.txt");
	for(int i=0; i<n; i++)
		if(KT(a[i]) == 1)
			fileOut << a[i] << " ";
	fileOut << endl;
	Sort(a, n);
	for(int i=0; i<n; i++)
		fileOut << a[i] << " ";
	return 0;
}
