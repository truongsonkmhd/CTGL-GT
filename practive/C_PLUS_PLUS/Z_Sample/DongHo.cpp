#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

typedef struct {
    int h;
    int p;
    int s;
}Time;
void ChuanHoaTime(Time &a){
    if(a.s > 60){
        a.p += a.s/60;
        a.s %= 60;
    }
    if(a.s < 0){
        a.p += a.s/60 - 1;
        a.s = a.s%60 + 60;
    }
    
    if(a.p > 60){
        a.h += a.p/60;
        a.p %= 60;
    }
    if(a.p < 0){
        a.h += a.p/60 - 1;
        a.p = a.p%60 + 60;
    }
    if(a.h > 24)
        a.h %= 24;
    if(a.h < 0)
        a.h = a.p%24 + 24;    
}
int ChuyenXauSangSo(char *s){
    int n = 0;
    int mu = 0, i;
    for(i=strlen(s) - 1; i>=0; i--){
        n += (s[i] - 48)*pow(10, mu);
        mu++;
    }
    return n;
}
int PhanTich(char c, char *s){
    if(s[0] == '+')
        return 1;
    if(s[0] == '-')
        return -1;
    int n = ChuyenXauSangSo(s);
    if(c == '+')
        return n;
    return -n;
}
int main(){
    Time a;
    cin >> a.h >> a.p >> a.s;
    int n;
    cin >> n;
    int denta  =0;
    for(int k=0; k<n; k++){
        char c;
        char *s = new char[100];
        cin >> c >> s;
        denta += PhanTich(c, s);
        delete s;
    }
    a.s += denta;
    ChuanHoaTime(a);
    cout << a.h << " " << a.p << " " << a.s;
}
