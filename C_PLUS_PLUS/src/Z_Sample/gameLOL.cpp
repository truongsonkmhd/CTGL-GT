#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct{
    int Tuong;
    int m;
}TT;

int main() {
    int n, i, j = 0, k;
    cin >> n;
    TT x[n];
    int a[3];
    a[1] = 1;
    a[2] = 1;
    while(j < n){
        cin >> x[j].Tuong;
        cin >> x[j].m;
        j++;
    }
    cin >> k;
    for(i=0; i<n; i++){
        switch(x[i].Tuong){
            case 1:{
                cout << "Malphite - Sat thuong duoc giam: " << x[i].m*10 + k*10 + (a[x[i].Tuong] - 1)*10<< endl;
                break;
            }
            case 2:{
                cout << "Cho'Gath - Sat thuong duoc giam: " << x[i].m*5 + k*10 + (a[x[i].Tuong] - 1)*10 << endl;
                break;
            }
        }
        a[x[i].Tuong]++;
    }
    return 0;
}

