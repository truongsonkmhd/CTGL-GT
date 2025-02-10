#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <unistd.h>
#include "console.h"

using namespace std;

int MaxX = 150, MaxY= 40;
/*
	30, 10					150, 10
	
	30, 40					150, 40
*/
struct ToaDo{
	int x;
	int y;
};
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

void TaoO(int x, int y, int n){
	int iy, ix;
	TextColor(14);
	for(iy = 0; iy < 2*n + 1; iy++){
		if(iy % 2 == 1){
			gotoXY(x + 0 , iy + y); cout << (char) 179; 
			gotoXY(x + 21, iy + y); cout << (char) 179;
		}
		if(iy % 2 == 0){
			if(iy == 0){
				gotoXY(x + 0 , iy + y); cout << (char) 218; 
				gotoXY(x + 21, iy + y); cout << (char) 191;
			}else
			if(iy == 2*n){
				gotoXY(x + 0 , iy + y); cout << (char) 192; 
				gotoXY(x + 21, iy + y); cout << (char) 217;
			}else{
				gotoXY(x + 0 , iy + y); cout << (char) 195; 
				gotoXY(x + 21, iy + y); cout << (char) 180;
			}
			for(ix = x+1; ix <= x+20; ix++){
				gotoXY(ix, iy + y);
				cout << (char) 196;
			}
		}
	}
}
void ThemChu(int x, int y, char a[][100], int n){
	TextColor(14);
	for(int i=0; i<n; i++){
		gotoXY(x + 10 - strlen(a[i])/2, y + 2*i); cout << a[i];
	}
	TextColor(7);
}

void DayMau(int *color){
	int i;
	int t = color[0];
	for(i=0; i<13; i++)
		color[i] = color[i+1];
	color[13] = t;
}
void Khung(int *color){
	int i, j = 0, n = 0;
	for(i=70; i<=100; i+=2){
		if(n == 15)
			n = 1;
		TextColor(color[n]);
		gotoXY(i, 8); cout << char (4);
			n++;
	}
	gotoXY(70, 9); cout << char (4);
	gotoXY(100, 9); cout << char (4);
	for(i=10; i<=MaxY; i++){
		if(n == 15)
			n = 1;
		TextColor(color[n]);
		gotoXY(30, i); cout << char (4);
		gotoXY(MaxX, i); cout << char (4);
			n++;
	}
	for(i=30; i<=MaxX; i+=2){
		if(n == 15)
			n = 1;
		TextColor(color[n]);
		gotoXY(i, 10); cout << char (4) ;
		gotoXY(i, MaxY); cout << char (4);
		n++;
	}
	TextColor(7);
}
int TaoQua(ToaDo a, int d){
	if(d == 1){ // qua doc
		TextColor(2);
		gotoXY(a.x, a.y); cout << char (2);
		TextColor(7);
		return -5;
	}else 
	if(d == 0){
		TextColor(4);
		gotoXY(a.x, a.y); cout << char(233);
		TextColor(7);
		return 3;
	}else{
		TextColor(12);
		gotoXY(a.x, a.y); cout << char (3);
		TextColor(7);
		return 1;	
	}
}
void VeRan(ToaDo *a, int n){
	TextColor(12);
	gotoXY(a[0].x, a[0].y); cout << char (254);
	TextColor(14);
	for(int i=1; i<n; i++){
		gotoXY(a[i].x, a[i].y);	cout << char (254);
		}
	TextColor(11);
	gotoXY(a[n].x, a[n].y); cout << " ";
	gotoXY(a[n+1].x, a[n+1].y); cout << " ";
	TextColor(7);
}
int AnQua(ToaDo *a, int n, ToaDo b){
	for(int i=0; i<n; i++)
		if(a[i].x == b.x && a[i].y == b.y)
			return 1;
	return 0;
}
void DiChuyen(ToaDo *a, int n){
	for(int i=n+1; i>0; i--)
		a[i] = a[i-1];
}
int HuongDi(ToaDo *a){
		if(a[0].x - 1 == a[1].x)
			return 1;  // ran dang di sang phai
		if(a[0].x + 1 == a[1].x)
			return 2; // ran dang di sang trai
		if(a[0].y - 1 == a[1].y)
			return 3; // ran dang di xuong
		return 4;	  // ran dang di len
}
void DK(ToaDo *a, char dk){
	switch(dk){
		case 'a':{
				a[0].x--;
			break;
		}
		case 'd':{
				a[0].x++;
			break;
		}
		case 'w':{
				a[0].y--;
			break;
		}
		case 'x':{
				a[0].y++;
			break;
		}
	}
}
void VeVat(ToaDo a ,int color){
	TextColor(color);
	if(a.y >= 11 && a.y <= MaxY){
		gotoXY(a.x + 1, a.y); cout << char(200) << char(233) << "  " << char(233) << char(188) ;
	}
	if(a.y >= 10 && a.y <= MaxY - 1){
		gotoXY(a.x, a.y + 1); cout << char(200) << char(205) << "(" << char(220) << char(220) << ")" << char(205) << char(188);
	}
	if(a.y >= 9 && a.y <= MaxY - 2){
		gotoXY(a.x, a.y + 2); cout << char(200) << char(205) << "(" << char(220) << char(220) << ")" << char(205) << char(188);
	}
	if(a.y >= 8 && a.y <= MaxY - 3){
		gotoXY(a.x, a.y + 3); cout << char(200) << char(205) << "(" << char(220) << char(220) << ")" << char(205) << char(188);	
	}
	if(a.y >= 7 && a.y <= MaxY - 4){
		gotoXY(a.x, a.y + 4); cout << char(200) << char(205) << "(" << char(220) << char(220) << ")" << char(205) << char(188);
	}
	if(a.y >= 6 && a.y <= MaxY - 5){
		gotoXY(a.x, a.y + 5); cout << char(200) << char(205) << "(" << char(220) << char(220) << ")" << char(205) << char(188);
	}
	if(a.y >= 5 && a.y <= MaxY - 6){
		gotoXY(a.x, a.y + 6); cout << char(200) << char(205) << "(" << char(220) << char(220) << ")" << char(205) << char(188);
	}
	if(a.y >=4 && a.y <= MaxY - 7){
		gotoXY(a.x, a.y + 7); cout << "            ";	
	}
}
int KiemTra(ToaDo *a, int doDai, ToaDo x, ToaDo Ret){
	int i;
	for(i=0; i<=doDai; i++)
		if(a[i].x == x.x && a[i].y == x.y)
			return 0;
	for(i=0; i<=8; i++)
		if(x.y == Ret.y + i && x.x >= Ret.x && x.x <= Ret.x + 6)
			return 0;
	return 1;
}
int main(){
	
	int k, k1, caidat = 2;
	char a[5][100];
	strcpy(a[0], "1. Choi moi");
	strcpy(a[1], "2. Tiep tuc");
	strcpy(a[2], "3. Cai dat");
	strcpy(a[3], "0. Thoat");
	strcpy(a[4], "Chuc nang:");
	do{	
		clrscr();
		TaoO(46,12,5);
		ThemChu(47, 13, a, 5);
		cin >> k;
		switch(k){
			case 1:{
				clrscr();
					int dodai = 2, diemThem, diemTo, tonTai = 0, timeGame = 0, TTQuaDoc = 0, timeDoc;
					int color[14] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
					ToaDo *a = new ToaDo;
					a[0].x = 100;
					a[0].y = 20;
					a[1].x = 99;
					a[1].y = 20;
					int Huong = HuongDi(a);
	
					ToaDo qua, quaTo, quaDoc;
					qua.x = 50;
					qua.y = 25;
	
					ToaDo Ret;
					Ret.x = 50;
					Ret.y = MaxY - 1; 
					char dk;
					getch();
					TextColor(14);
					gotoXY(83, 9); cout << "diem: " << dodai;
					TextColor(7);
					diemThem = TaoQua(qua, 2);
					VeRan(a, dodai);
					while(1){
						timeGame++;
						if(timeGame % 4 == 0){
							Khung(color);
							DayMau(color);
							VeVat(Ret, color[0]);
							Ret.y--;
							if(Ret.y == 3)
								Ret.y = MaxY - 1;
							int ranDom = rand() % 100;
							if(ranDom == 88){
								do{
									quaDoc.x = rand() %(110) + 32;
									quaDoc.y = rand() %(25) + 12;
								}while(KiemTra(a, dodai, quaDoc, Ret) == 0);
								TTQuaDoc = TaoQua(quaDoc, 1);
								timeDoc = 0;
							}
						}
					if(kbhit()){
						dk = getch();
						if((Huong == 1 && dk == 'a') || (Huong == 2 && dk == 'd') || (Huong == 3 && dk == 'w') || (Huong == 4 && dk == 'x'))
							goto X;
						DiChuyen(a, dodai);
						DK(a, dk);
						Huong = HuongDi(a);
					}
				X:
					if(TTQuaDoc == -5 ){
						timeDoc++;
						if(AnQua(a, dodai, quaDoc) == 1){
								dodai-=5;
								TTQuaDoc = 0;
						}
						if(timeDoc = 30){
							gotoXY(quaDoc.x, quaDoc.y); cout << " ";
							TTQuaDoc = 0;
						}
					}
					for(int ii=0; ii<=8; ii++)
						if(qua.y == Ret.y + ii && qua.x >= Ret.x && qua.x <= Ret.x + 6)
							goto Y;
					if(AnQua(a, dodai, qua) == 1 ){
						dodai ++;
						DiChuyen(a, dodai);
						switch(Huong){
							case 1:{
								a[0].x++;
								break;
							}
							case 2:{
								a[0].x--;
								break;
							}
							case 3:{
								a[0].y++;
								break;
							}
							case 4:{
								a[0].y--;
								break;
							}
						}
						Y:
						do{
							qua.x = rand() %(110) + 32;
							qua.y = rand() %(25) + 12;
						}while(KiemTra(a, dodai, qua, Ret) == 0);
						diemThem = TaoQua(qua, 2);
						TextColor(14);
						gotoXY(83, 9); cout << "diem: " << dodai;
						TextColor(7);
					}
					if(dodai %10 == 0 && tonTai != 5){
						do{
							quaTo.x = rand() %(100) + 40;
							quaTo.y = rand() %(MaxY - 23) + 17;
						}while(KiemTra(a, dodai, quaTo, Ret) == 0);
						diemTo = TaoQua(quaTo, 0);
						tonTai = 5;
					}
					if(tonTai == 5)
						if(AnQua(a, dodai, quaTo) == 1){
							for(int j=0; j<diemTo; j++){
								dodai ++;
								DiChuyen(a, dodai);
//								switch(Huong){
//									case 1:{
//										a[dodai].x = a[dodai-1];
//										break;
//									}
//									case 2:{
//										a[0].x--;
//										break;
//									}
//									case 3:{
//										a[0].y++;
//										break;
//									}
//									case 4:{
//										a[0].y--;
//										break;
//									}
//								}
							}
						TextColor(14);
						gotoXY(83, 9); cout << "diem: " << dodai;
						TextColor(7);
						}
					DiChuyen(a, dodai);
					switch(Huong){	
						case 1:{
							a[0].x++;
							break;
						}
						case 2:{
							a[0].x--;
							break;
						}
						case 3:{
							a[0].y++;
							break;
						}
						case 4:{
							a[0].y--;
							break;
						}
					}
				if(a[0].x>=MaxX || a[0].x<=30 || a[0].y<=10 || a[0].y>=MaxY){
					TextColor(4);
					gotoXY(70, 20); cout << "----GAME OVER----";
					TextColor(7);
					getch();
					break;
				}
				for(int ii=0; ii<dodai; ii++)
					if(a[ii].y == Ret.y && a[ii].x >= Ret.x && a[ii].x <= Ret.x + 6)
						dodai = ii;
				VeRan(a, dodai);
				gotoXY(a[0].x,a[0].y);
				Sleep(400);
				}
				break;
			}
			case 2:{
				clrscr();
				TaoO(46, 12, 1);
				char c[100] = {"Muc do: "};
				gotoXY(48,13);	cout << c;
				gotoXY(55,13); cin >> caidat;
				break;
			}
			case 0:{
				clrscr();
				gotoXY(50, 12);	cout << "GOOD BYE!";
				getch();
				break;
			}
		}
	}while(k != 0);
}
























