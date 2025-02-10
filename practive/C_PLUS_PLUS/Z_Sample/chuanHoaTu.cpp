
/*#include <iostream>

using namespace std;

long fbnc(int n){
    if(n == 0)  return 0;
    if(n == 1)  return 1;
    return fbnc(n-1) + fbnc(n-2);
}
int main(){
    char c;
    int n;
    do{
        cout << "Nhap n: "; cin >> n;
        if(n < 0 )
            cout << "Nhap sai! So n phai khong am.\n";
        else
            cout << "So fibonaci thu " << n << " la: " << fbnc(n) << endl;
        cout << "Ban muon nhap tiep khong(y/n)? "; cin >> c;
    }while(c != 'n');
}

*/
#include <iostream>
#include <string.h>

using namespace std;
void XoaDauCach(char *a){
    int i;
    while(a[0] == 32)
        strcpy(a, a+1);
    for(i=0; i<strlen(a); i++){
        if((a[i] == 32 && a[i+1] == 32)){
            strcpy(a + i, a + i + 1);
            i--;
        }
    }
    if(a[strlen(a)- 1] == 32)
        a[strlen(a) - 1] = '\0';
}
void ChuanHoa(char *a){
    int i;
    XoaDauCach(a);
    for(i=0; i<strlen(a); i++){
        if( a[i] >= 'A' && a[i] <= 'Z')
            a[i] += 32;
        if((i == 0 && a[i] >= 'a' && a[i] <= 'z') || (a[i - 1] == 32 && a[i] >= 'a' && a[i] <= 'z' )) 
            a[i] -= 32;
    }
}
int main(){
    char a[100];
    cin.getline(a, 99);
    ChuanHoa(a);
    cout << a;
   
}
/*
#include <iostream>
#include <string.h>

using namespace std;
int main(){
	int i, j, max = -1, min = 10;
	string a;
	cin >> a;
	if(a[0] != '-' && a[0] != '0'){
		for(i=0; i<a.size(); i++){
			max = (max < a[i] - 48) ? a[i] - 48 : max;
			min = (min > a[i] - 48) ? a[i] - 48 : min;
		}
		cout << max + min;
	}
}
*/

sum = 0;
for(int i=n-1; i>0; i--)
	sum += a[i][n-i];

