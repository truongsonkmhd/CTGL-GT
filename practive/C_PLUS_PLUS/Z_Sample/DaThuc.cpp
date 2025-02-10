#include <iostream>
#include <math.h>

using namespace std;

void NhapDaThuc(int n, int *b){
    int i;
    for(i=0; i<=n; i++)
        cin >> b[i];
}
void Xuat(int n, int *b){
    cout << b[0] << "x^0";
    for(int i=1; i<=n; i++)
        if(b[i] > 0)
            cout << "+" << b[i] << "x^" << i;
        else    if(b[i] < 0)
            cout << b[i] << "x^"<< i;
}
int main(){
    int m, n;
    int *a, *b;
    cin >> m;
    if(m < 0)	return 0;
    a = new int[m+1];
    NhapDaThuc(m, a);
    cin >> n;
    if(n < 0) return 0;
    b = new int[n+1];
    NhapDaThuc(n, b);
    int k;
    cin >> k;
    switch(k){
        case 1:{
            int max;
            int *c;
            if(m > n){
                max = m;
                c = new int[max+1];
                for(int i=0; i<=max; i++)
                    if(i <= n)
                        c[i] = a[i] + b[i];
                    else
                        c[i] = a[i];
            }else{
                max = n;
                c = new int[max+1];
                for(int i=0; i<=max; i++)
                    if(i <= m)
                        c[i] = a[i] + b[i];
                    else
                        c[i] = b[i];
            }
            Xuat(max, c);
            break;
        }
        case 2:{
            int max;
            int *c;
            if(m > n){
                max = m;
                c = new int[max+1];
                for(int i=0; i<=max; i++)
                    if(i <= n)
                        c[i] = a[i] - b[i];
                    else
                        c[i] = a[i];
            }else{
                max = n;
                c = new int[max+1];
                for(int i=0; i<=max; i++)
                    if(i <= m)
                        c[i] = a[i] - b[i];
                    else
                        c[i] = -b[i];
            }
            Xuat(max, c);
            break;
        }
        case 3:{
            int max = m + n;
            int *c = new int[m+n+2];
            for(int i=0; i<=m+n; i++)
                c[i] = 0;
            for(int i=0; i<=m; i++)
                for(int j=0; j<=n; j++)
                    c[i+j] += a[i]*b[j];
            Xuat(max, c);
            break;
        }
    }
	return 0;    
}
