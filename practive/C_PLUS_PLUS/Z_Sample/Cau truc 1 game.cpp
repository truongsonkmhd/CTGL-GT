#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <unistd.h>
#include <vector>
#include "console.h"

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

void Nhap(vector<int> &a, int &n){
	int x;
	n = 0;
	do{
		cin >> x;
		if(x == -1)	break;
		a.push_back(x);
		n++;
	}while(1);
}
float* XuLyDuLieu(vector<int> &a, int n){
	float *b = new float[11];
	for(int i=0; i<11; i++)
		b[i] = 0;
	for(int i=0; i<n; i++)
		b[a[i]]++;
	for(int i=0; i<11; i++)
		b[i] *= (100.0/n);
	return b;
}
void VeDoThi(float *b){
	int i, j;
	TextColor(14);
	for(i=0; i<12; i++){
		gotoXY(i, 5); cout << char (124);
	}
	for(i=0; i<=30; i++){
		gotoXY(12, i); cout << char (95);
	}
}
int main(){
	int n;
	vector<int> a;
	Nhap(a, n);
	float *b = new float[11];
	b = XuLyDuLieu(a, n);
//	VeDoThi(b);
	int i, j;
	TextColor(11);
	cout << "Hello";
//	for(i=0; i<12; i++){
//		gotoXY(5, i); cout << char (124);
//	}
//	for(i=5; i<=35; i++){
//		gotoXY(i, 12); cout << char (95);
//	}
}
	
	
	
	
	
	
