#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <unistd.h>
#include "console.h"
#include <math.h>

using namespace std;

void TextColor (int color){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , color);
}
void clrscr(){
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;                  
	HANDLE	hConsoleOut;
	COORD	Home = {0,0};
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut,' ',csbiInfo.dwSize.X * csbiInfo.dwSize.Y,Home,&dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut,csbiInfo.dwCursorPosition);
}
void gotoXY (int column, int line){
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void Sleep(int n){
	for(int i =0; i< 100*n; i++)
		for(int j=0; j<1000; j++);
}
int KiemTraTrai(int **a, int y){
	for(int i=1; i<5; i++)
		if(a[y][i] == 0 && a[y][i+1] != 0)
			return 0;
	return 1;
}
int KiemTraPhai(int **a, int y){
	for(int i=4; i>=1; i--)
		if(a[y][i] == 0 && a[y][i-1] != 0)
			return 0;
	return 1;
}
int KiemTraTren(int **a, int y){
	for(int i=1; i<=4; i++)
		if(a[i][y] == 0 && a[i+1][y] != 0)
			return 0;
	return 1;
}
int KiemTraDuoi(int **a, int y){
	for(int i=4; i>=1; i--)
		if(a[i][y] == 0 && a[i-1][y] != 0)
			return 0;
	return 1;
}
void SangTrai(int **a){
	int i, j;
	for(i=1; i<5; i++){
		while(KiemTraTrai(a, i) == 0)
			for(j=1; j<5; j++)
				if(a[i][j] == 0){
					a[i][j] += a[i][j+1];
					a[i][j+1] = 0;
				}
		for(j=1; j<5; j++)
			if(a[i][j] == a[i][j+1]){
				a[i][j] += a[i][j+1];
				a[i][j+1] = 0;
			}
		while(KiemTraTrai(a, i) == 0)
			for(j=1; j<5; j++)
				if(a[i][j] == 0){
					a[i][j] += a[i][j+1];
					a[i][j+1] = 0;
				}
	}
}
void SangPhai(int **a){
	int i, j;
	for(i=1; i<5; i++){
		while(KiemTraPhai(a, i) == 0)
			for(j=4; j>=1; j--)
				if(a[i][j] == 0){
					a[i][j] += a[i][j-1];
					a[i][j-1] = 0;
				}
		for(j=4; j>=1; j--)
			if(a[i][j] == a[i][j-1]){
				a[i][j] += a[i][j-1];
				a[i][j-1] = 0;
			}
		while(KiemTraPhai(a, i) == 0)
			for(j=4; j>=1; j--)
				if(a[i][j] == 0){
					a[i][j] += a[i][j-1];
					a[i][j-1] = 0;
				}
	}
}
void LenTren(int **a){
	int i, j;
	for(j=1; j<5; j++){
		while(KiemTraTren(a, j) == 0)
			for(i=1; i<5; i++)
				if(a[i][j] == 0){
					a[i][j] += a[i+1][j];
					a[i+1][j] = 0;
				}
		for(i=1; i<5; i++)
				if(a[i][j] == a[i+1][j]){
					a[i][j] += a[i+1][j];
					a[i+1][j] = 0;
				}
		while(KiemTraTren(a, j) == 0)
			for(i=1; i<5; i++)
				if(a[i][j] == 0){
					a[i][j] += a[i+1][j];
					a[i+1][j] = 0;
				}
	}
}
void XuongDuoi(int **a){
	int i, j;
	for(j=1; j<5; j++){
		while(KiemTraDuoi(a, j) == 0)
			for(i=4; i>=1; i--)
				if(a[i][j] == 0){
					a[i][j] += a[i-1][j];
					a[i-1][j] = 0;
			}
		for(i=4; i>=1; i--)
				if(a[i][j] == a[i-1][j]){
					a[i][j] += a[i-1][j];
					a[i-1][j] = 0;
			}
		while(KiemTraDuoi(a, j) == 0)
			for(i=4; i>=1; i--)
				if(a[i][j] == 0){
					a[i][j] += a[i-1][j];
					a[i-1][j] = 0;
			}
	}
}
void XuatDiem(int x){
	int color;
	if(x == 0)
		color = 15;
	else
		color = 15 - log(x)/log(2) - 1;
	TextColor(color);
	cout << x;
}
void TaoDiem(int **a){
	int x, y;
	do{
		x = rand() %4 + 1;
		y = rand() %4 + 1;
	}while(a[x][y] != 0);
	int d = rand() %20;
	if(d == 13)
		a[x][y] = 4;
	else
		a[x][y] = 2;
}
int diemChoi(int **a){
	int diem = 0;
	for(int i=1; i<5; i++)
		for(int j=1; j<5; j++)
			if(a[i][j] != 0)
			diem += (a[i][j] - 1)*10;
	return diem - 30;
}
int End(int **a){
	int i, j;
	for(i=1; i <5; i++)
		for(j=1; j<5; j++)
			if(a[i][j] == 0 || a[i][j] == a[i][j+1] || a[i][j] == a[i][j-1] || a[i][j] == a[i-1][j] || a[i][j] == a[i+1][j]) 
				return 1;
	return 0;
}
void oChoi(int x, int y, int diem){
	TextColor(14);
	gotoXY(x, y + 0); cout << " + - - + - - + - - + - - +";
	gotoXY(x, y + 1); cout << " |     |     |     |     |";
	gotoXY(x, y + 2); cout << " + - - + - - + - - + - - +";
	gotoXY(x, y + 3); cout << " |     |     |     |     |";
	gotoXY(x, y + 4); cout << " + - - + - - + - - + - - +";
	gotoXY(x, y + 5); cout << " |     |     |     |     |";
	gotoXY(x, y + 6); cout << " + - - + - - + - - + - - +";
	gotoXY(x, y + 7); cout << " |     |     |     |     |";
	gotoXY(x, y + 8); cout << " + - - + - - + - - + - - +";
}
void Xuat(int **a){
	int i, j;
	for(i=1; i<5; i++){
		for(j=1; j<5; j++){
			gotoXY(48 + 6*j - a[i][j]/100, i*2 + 9); XuatDiem(a[i][j]);	
		}
	}
}
void DK(int **a, char dk){
	switch(dk){
		case 'w':{
			LenTren(a);
			break;
		}
		case 'a':{
			SangTrai(a);
			break;
		}
		case 'd':{
			SangPhai(a);
			break;
		}
		case 'x':{
			XuongDuoi(a);
			break;
		}
	}
	TaoDiem(a);
}
void Khung(int x, int y, char dk){
	TextColor(7);
	gotoXY(x+3, y-1); cout << char (94); // tren
	gotoXY(x+0, y); cout << char (60); // trai
	gotoXY(x+6, y); cout << char (62); // phai
	gotoXY(x+3, y+1); cout << char (118); // duoi
	switch(dk){
		case 'w':{
			TextColor(10);
			gotoXY(x+3, y-1); cout << char (94); // tren
			break;
		}
		case 'a':{
			TextColor(11);
			gotoXY(x+0, y); cout << char (60); // trai
			break;
		}
		case 'd':{
			TextColor(12);
			gotoXY(x+6, y); cout << char (62); // phai
			break;
		}
		case 'x':{
			TextColor(13);
			gotoXY(x+3, y+1); cout << char (118); // duoi
			break;
		}
	}
	TextColor(7);
}
int main(){
	int **a = new int*[6];
	char dk;
	for(int i=0; i<6; i++)
		a[i] = new int[6];
	for(int i=0; i<6; i++)
		for(int j=0; j<6; j++)
			a[i][j] = 0;
	// moi choi cho 2 o
	TaoDiem(a);
	TaoDiem(a);
	TaoDiem(a);
	TaoDiem(a);
	getch();
	oChoi(50, 10, 10);
	Xuat(a);
	TextColor(14);
	gotoXY(80, 10); cout << " Diem:";
	gotoXY(81, 11); cout << diemChoi(a);
	while(1){
		if(kbhit()){
			TextColor(14);
			gotoXY(80, 10); cout << " Diem:";
			gotoXY(81, 11); cout << diemChoi(a);
			TextColor(7);
			dk = getch();
			DK(a, dk);
			oChoi(50, 10, 10);
			Xuat(a);
			Khung(80, 15, dk);
		}
		if(End(a) == 0){
			gotoXY(60, 15); cout << "GAME OVER";
			getch();
			break;
		}
	}
}
/*
2 2 4 4
0 0 0 0 
0 0 0 0 
0 0 0 0
*/
