#include <iostream>
#include "thuVienCuaToi.h"
#include <iomanip>

#define maxX  100
#define minX  10
#define maxY  30
#define minY  2

using namespace std;

void Chu(int d, int x, int y){
	TextColor(13);
	switch(d){
		case 1:{
			gotoXY(x+0, y-1);	cout << ">Game moi<";
			TextColor(14);
			gotoXY(x+1, y-1);	cout << " Tiep tuc ";
			gotoXY(x+2, y-1);	cout << " Bang diem ";
			gotoXY(x+3, y-1);	cout << " Thoat ";
			break;
		}
		case 2:{
			gotoXY(x+1, y-1);	cout << ">Tiep tuc<";
			TextColor(14);
			gotoXY(x+0, y-1);	cout << " Game moi ";
			gotoXY(x+2, y-1);	cout << " Bang diem ";
			gotoXY(x+3, y-1);	cout << " Thoat ";
			break;
		}
		case 3:{
			gotoXY(x+2, y-1);	cout << ">Bang diem<";
			TextColor(14);
			gotoXY(x+0, y-1);	cout << " Game moi ";
			gotoXY(x+1, y-1);	cout << " Tiep tuc ";
			gotoXY(x+3, y-1);	cout << " Thoat ";
			break;
		}
		case 4:{
			gotoXY(x+3, y-1);	cout << ">Thoat<";
			TextColor(14);
			gotoXY(x+0, y-1);	cout << " Game moi ";
			gotoXY(x+1, y-1);	cout << " Tiep tuc ";
			gotoXY(x+2, y-1);	cout << " Bang diem ";
			break;
		}
	}
}
void XuatChu(char dk, int x, int y, int &d){
	switch(dk){
		case 'w':{
			d--;
			break;
		}
		case 'x':{
			d++;
			break;
		}
	}
	if(d == 0)
		d = 4;
	if(d == 5)
		d = 1;
	Chu(d, x, y);
}
void KhungGiaoDien(int x, int y){
	TextColor(11);
	gotoXY(x+0, y); cout << "	                     , ---. , ---.";
	gotoXY(x+1, y); cout << "                    / / ''`. \\ .-- '' ''--./, '' \\ \\";
	gotoXY(x+2, y); cout << "                    \\ \\ _ _ / /";
	gotoXY(x+3, y); cout << "                     `./ / __ __ \\ \\, '";
	gotoXY(x+4, y); cout << "                      / / _O) _ (_ O \\ \\";
	gotoXY(x+5, y); cout << "                      | .- '___ `-. |";
	gotoXY(x+6, y); cout << "                   .-- | \\ _ / | -.";
	gotoXY(x+7, y); cout << "                 , '\\ \\ | / / `.";
	gotoXY(x+8, y); cout << "                / '. `- ^ - ',' \\";
	gotoXY(x+9, y); cout << "             .- '' '' '-.` --.___.-- '.- '' '' ''-.";
	gotoXY(x+10, y); cout <<".----------- / \\ ------------------ / \\ --------------.";
	gotoXY(x+11, y); cout <<"| .--------- \\ / ----------------- \\ / ------------. |";
	gotoXY(x+12, y); cout <<"| | `-` - `-- '' --' -'- '| |";
	gotoXY(x+13, y); cout <<"| | | |";
	gotoXY(x+14, y); cout <<"| | | |";
	gotoXY(x+15, y); cout <<"| | | |";
	gotoXY(x+16, y); cout <<"| | | |";
	gotoXY(x+17, y); cout <<"| | | |";
	gotoXY(x+18, y); cout <<"| | | |";
	gotoXY(x+19, y); cout <<"| | | |";
	gotoXY(x+20, y); cout <<"| | | |";
	gotoXY(x+21, y); cout <<"| | | |";
	gotoXY(x+22, y); cout <<"| | | |";
	gotoXY(x+23, y); cout <<"| | | |";
	gotoXY(x+24, y); cout <<"| | | |";
	gotoXY(x+25, y); cout <<"| | _____________________________________________________________ | |";
	gotoXY(x+26, y); cout <<"| _________________________________________________________________ |";
	gotoXY(x+27, y); cout <<"                   ) __________ | __ | __________ (";
	gotoXY(x+28, y); cout <<"                  | || |";
	gotoXY(x+29, y); cout <<"                  | ____________ || ____________ |";
	gotoXY(x+30, y); cout <<"                    ), -----. (), -----. (";
	gotoXY(x+31, y); cout <<"                  , '==. \\ /. == `.";
	gotoXY(x+32, y); cout <<"                 /) (\\";
	gotoXY(x+33, y); cout <<"                 `=========== '' =========== 'hjw";
}
void VeDongVat(int x, int y){
	TextColor(11);
	gotoXY(x-5, y); cout << "           ((`\\";
	gotoXY(x-4, y); cout << "        ___ \\\\ '--._      " << char (14) << " " << char (14);
	gotoXY(x-3, y); cout << "     .'`   `'    o  )";
	gotoXY(x-2, y); cout << "    /    \\   '. __.";
	gotoXY(x-1, y); cout << "   _|    /_  \\ \\_\\";
	gotoXY(x-0, y); cout << "  {_\\______\\-'\\__\\_\\";
}
void Load(int x, int y){
	int i;
	TextColor(15);
	for(i=0; i<=40; i++){
		Sleep(100);
		VeDongVat(x, y + 2*i - 10);
		gotoXY(x+1, y + 2*i); cout << char (178) << char (178);
		gotoXY(x+2, y + 40); cout << "Loading: " << fixed << setprecision(2) <<  2.5*i << "%";
		gotoXY(x+3, y+40); TextColor(i/7 + 7); cout << "-----Nhom 7 - K66-DACLC2 - UET";
	}
	Sleep(200);
}

void GiaoDien(int x, int y){
	Load(x + 20, y);
	clrscr();
	KhungGiaoDien(2, 10);
	Chu(1, 2 + 17, 10 + 28);
}
