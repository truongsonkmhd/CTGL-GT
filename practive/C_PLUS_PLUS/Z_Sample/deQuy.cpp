/*
1:

#include <iostream>
#include <math.h>
using namespace std;

long fibonaci(int n){
    n--;
    return (pow((1.0 + sqrt(5.0)), n) - pow((1.0 - sqrt(5.0)), n)) / (pow(2.0, n) * sqrt(5.0));
}

int main(){
    int n;
    cin >> n;
    cout << fibonaci(n);
}

2:
#include <iostream>

using namespace std;
long gt(int n){
    if(n == 0)
        return 1;
    return n*gt(n-1);
}
int main(){
    int n;
    cin >> n;
    cout << gt(n);
}
3:
#include <iostream>

using namespace std;
long Pow(int a, int b){
    if(b == 0)  return 1;
    return a*Pow(a, b - 1);
}
int main(){
    int a, b;
    cin >> a >> b;
    cout << Pow(a, b);
}
4:
#include <iostream>

using namespace std;
long Pow(int a, int b){
    if(b == 0)  return 1;
    return a*Pow(a, b - 1);
}
int main(){
    int a, b;
    cin >> a >> b;
    cout << Pow(a, b);
}
5:
#include <iostream>

using namespace std;
int UCLN(int a, int b){
    if(a == b)  return a;
    if(b == 0) return a;
    if(a == 0) return b;
    if(a > b)   return UCLN(a%b, b);
    else        return UCLN(a, b%a);
}
int main(){
    int a, b;
    cin >> a >> b;
    cout << UCLN(a, b);
}
6:
#include <iostream>
#include <math.h>

using namespace std;

void NhiPhan(int n, int len){
    int c[10] = {0};
    int i = 0;
    while(n !=0){
        c[i] = n % 2;
        i++;
        n /= 2;
    }
    for(int j = len - 1; j>=0; j--)
        cout << c[j];
    cout << endl;
}
int main(){
    int n, i;
    cin >> n;
    int max = 0;
    for(i=1; i<n; i++)
        max += pow(2, i);
    for(i=0; i<=max + 1; i++)
        NhiPhan(i, n);
}
7:
#include <iostream>
#include <math.h>

using namespace std;

int NhiPhan(int n, int len, int m){
    int c[10] = {0}, j = 0;
    int i = 0;
    while(n !=0){
        c[i] = n % 2;
        if(c[i] == 1)
            j++;
        if(j > m)
            return 0;
        i++;
        n /= 2;
    }
    if(j < m)
        return 0;
    for(j = len - 1; j>=0; j--)
        cout << c[j];
    cout << endl;
}
int main(){
    int n, m, i;
    cin >> n >> m;
    int max = 0;
    for(i=0; i<m; i++)
        max += pow(2, m + n - i - 1);
    for(i=0; i<=max; i++)
        NhiPhan(i, n + m, m);
}
9:
#include <iostream>
#include <math.h>
#include <cstring>

using namespace std;

void ChuyenDoi(int n, string b, int x, int dodai){
    int a[100], i;
    for(i=0; i<dodai; i++)
        a[i] = b[0];
    i=0;
    while(n !=0){
        a[i] = b[n%x];
        n /= x;
        i++;
    }
    for(i=dodai-1; i>=0; i--)
        cout << (char) a[i];
    cout << endl;
}

int main(){
    string a;
    cin >> a;
    string b = a; 
    int i, j, count =0;
    
    b[b.size()] = b[0];
    for(i=0; i<b.size(); i++)
        if(b[i] != b[i+1])
            count ++;

    for(int k=1; k<=a.size(); k++){
        int sum = 0;
        for(i=0; i<k; i++)
       		sum += (count - 1)*pow(count, i);
        for(i=0; i<=sum; i++)
            ChuyenDoi(i, b, count, k);
    }
}

#include <iostream>

using namespace std;

int SoLuong(int a[][100], int y, int x, int *b, int m, int n){ // b[1] tren , b[2] duoi, b[3] trai, b[4] phai
    int SoDuong = 0;
    if(y > 0 && a[y - 1][x] == 0){
        b[1] = 1;
        SoDuong++;
    }
    if(x > 0 && a[y][x - 1] == 0){
        b[3] = 1;
        SoDuong++;
    }
    if(x < n - 1 && a[y][x + 1] == 0){
        b[4] = 1;
        SoDuong++;
    }
    if(y < m -1 && a[y + 1][x] == 0){
        b[2] = 1;
        SoDuong++;
    }
    return SoDuong;
}

int main(){
    int m, n, i, j, x = 0, y = 0;
    cin >> m >> n;
    int a[100][100];
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            cin >> a[i][j];
    int b[5];
    int Sl;
    do{
    	b[1] = 0;
    	b[2] = 0;
    	b[3] = 0;
    	b[4] = 0;
        Sl = SoLuong(a, y, x, b, m, n);
        if(Sl == 1){
        	a[y][x] = 2;
            if(b[1] == 1){
            	Sl = 0;
            	y--;
            	b[1] = 0;
			}
            if(b[2] == 1){
            	Sl --;	
            	y++;
            	b[2] = 0;
			}
            if(b[3] == 1){
            	Sl --;
            	x--;
            	b[3] = 0;
			}
           	if(b[4] == 1){
           		Sl--;
           		x++;
           		b[4] = 0;
			}
			a[y][x] = 2;
        }else{
        	if(b[4] == 1){
            	Sl = 1;
            	x++;
            	b[4] = 0;
			}
			a[y][x] = 2;
		}
		if(x == n - 1 && y == m - 1)
			break;
		Sl = SoLuong(a, y, x, b, m, n);	
	}while(1);
    for(i = 0; i<m; i++){
    	for(j = 0; j<n; j++)
    		cout << a[i][j] << " ";
    	cout << endl;
	}
}

#include <iostream>

using namespace std;

void Xuat(int *a, int n){
	for(int i=1; i<=n; i++)
		cout << a[i];
	cout << endl;
}
void Try(int i, int *check, int n, int *a){
	for(int j=1; j<=n; j++){
		if(check[j] == 0){
			check[j] = 1;
			a[i] = j;
			if(i == n)
				Xuat(a, n);
			else	Try(i+1, check, n, a);
			check[j] = 0;
		}
	}
}
int main(){
	int n;
	cin >> n;
	int *a = new int[n+1];
	int *check = new int[n];
	for(int i=1; i<=n; i++)
		check[i] = 0;
	Try(1, check, n, a);
}

8:
*/
#include <iostream>
#include <string.h>

using namespace std;
void Try(int i, int *check, string s, char *a){
	for(int j=0; j<s.size(); j++){
		if(check[j] == 0){
			check[j] = 1;
			a[i] = s[j];
			if(i == s.size() - 1)
				cout << a << endl;
			else	
				Try(i+1, check, s, a);
			check[j] = 0;
		}
	}
}
int main(){
	string s;
	char *a = new char;
	cin >> s;
	int *check = new int[s.size()];
	for(int i=0; i<s.size(); i++)
		check[i] = 0;
	Try(0, check, s, a);
}
