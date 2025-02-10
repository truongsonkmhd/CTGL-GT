#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

void TachTam(char *b, int &x, int &y){
    x = 0, y = 0;
	int j = 0;
    int i = strchr(b, ')') - b - 1;
    while(b[i] >= 48 && b[i] <= 57){
        y += (b[i] - 48)*pow(10, j);
        j++;
        i--;
    }
    i = strchr(b, ',') - b - 1;
    j = 0;
    while(b[i] >= 48 && b[i] <= 57){
    	x += (b[i] - 48)*pow(10, j);
    	j++;
    	i--;
	}
}
void TachBK(char *b, int &r){
	r = 0;
	int i, j = 0;
	i = strstr(b, "r = ") - b + 4;
	char c[100];
	while(b[i] >= 48 && b[i] <= 57){
		c[j] = b[i];
		i++;
		j++;	
	}
	j--;
	while(j >= 0){
		r += (c[j] - 48)*pow(10, strlen(c) - j - 1);
		j--;
	}
}
void TachMau(char *b, char *c){
	c[0] = '\0';
	int i = strstr(b, "mau") - b + 4, j = 0;
	while(b[i] == 32 || (b[i] <= 'z' && b[i] >= 'a')){
		c[j] = b[i];
		i++;
		j++;
	}
}
int chuyenMau(char *b){
    if(strcmp(b, "blue") == 0    || strcmp(b, "xanh da troi") == 0) return 1;
    if(strcmp(b, "green") == 0   || strcmp(b, "xanh la cay") == 0)  return 2;
    if(strcmp(b, "cyan") == 0    || strcmp(b, "xanh lo") == 0)      return 3;
    if(strcmp(b, "red") == 0     || strcmp(b, "do") == 0)           return 4;
    if(strcmp(b, "magenta") == 0 || strcmp(b, "tim") == 0)          return 5;
    if(strcmp(b, "brown") == 0   || strcmp(b, "nau") == 0)          return 6;
    if(strcmp(b, "lihgtgray") == 0 || strcmp(b, "xam nhat") == 0)   return 7;
    if(strcmp(b, "darkgray") == 0 || strcmp(b, "xam sam") == 0)     return 8;
    if(strcmp(b, "lightblue") == 0 || strcmp(b, "xanh da troi nhat") == 0)  return 9;
    if(strcmp(b, "lightgreen") == 0 || strcmp(b, "xanh la cay nhat") == 0)  return 10;
    if(strcmp(b, "lightcyan") == 0 || strcmp(b, "xanh lo nhat") == 0)  return 11;
    if(strcmp(b, "lightmagenta") == 0 || strcmp(b, "tim nhat") == 0)  return 13;
    if(strcmp(b, "lightred") == 0 || strcmp(b, "do nhat") == 0)  return 12;
    if(strcmp(b, "yellow") == 0 || strcmp(b, "bang") == 0)  return 14;

}
int main(){
	int x, y, r;
    char b[100], c[100];
    cin.getline(b, 99);
    TachTam(b, x, y);
    TachBK(b, r);
    TachMau(b, c);
    cout << x << " " << y << endl;
    cout << r << endl;
    cout << c << endl;
    cout << chuyenMau(c);
}
