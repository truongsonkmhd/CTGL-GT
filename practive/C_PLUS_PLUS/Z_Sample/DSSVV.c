// Thu vien
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct thongTin{
	unsigned int ID;
	unsigned int Diem;
	char hanhKiem[20];
	char fullName[50];
}TT;
void XoaDauXuongDong(char *a){
	if(a[strlen(a)-1] == '\n')
		a[strlen(a)-1] = '\0';
}
// 1 Nhap thong tin sinh vien
TT NhapTT(){
	TT a;
	printf("\tNhap ID: ");	scanf("%d", &a.ID);
	printf("\tNhap Diem: ");	scanf("%d", &a.Diem);
	printf("\tNhap ho va ten: "); fflush(stdin); fgets(a.fullName, sizeof(a.fullName), stdin);	XoaDauXuongDong(a.fullName);
	if(a.Diem >= 9){
			strcpy(a.hanhKiem,"A");
		}else
		if(a.Diem >=8){
			strcpy(a.hanhKiem,"B");
		}else
		if(a.Diem >=6){
			strcpy(a.hanhKiem,"C");
		}else
		if(a.Diem >=5){
			strcpy(a.hanhKiem,"D");
		}else
			strcpy(a.hanhKiem,"F");
	return a;
}
// 2 Xuat thong tin sinh vien
void XuatTT(TT a, int d){
	if(d==1)
		printf("\t%d\t|\t%d|\t%s\n", a.ID, a.Diem, a.fullName);
	else
		printf("\t%d\t|\t%d\t|\t%s\t%s|\n", a.ID, a.Diem, a.hanhKiem, a.fullName);
}
// 3 Tim diem cao nhat
int DiemMax(TT *a, int n){
	int diem = 0; // Do diem la so duong
	int i;
	for(i=0; i<n; i++)
		if(diem < a[i].Diem )
			diem = a[i].Diem;
	return diem;
}
// 4 Xuat thong tin sinh vien co diem cao nhat
void XuatDiemMax(TT *a, int n, int d){
	int i, diem = DiemMax(a, n);
	for(i=0; i<n; i++)
		if(a[i].Diem == diem)
			XuatTT(a[i], d);
}
// 5 Tim diem thap nhat
int DiemMin(TT *a, int n){
	int diem = DiemMax(a, n); // Do diem la so duong
	int i;
	for(i=0; i<n; i++)
		if(diem > a[i].Diem )
			diem = a[i].Diem;
	return diem;
}
// 6 Xuat thong tin sinh vien co diem thap nhat
void XuatDiemMin(TT *a, int n, int d){
	int i, diem = DiemMin(a, n);
	for(i=0; i<n; i++)
		if(a[i].Diem == diem)
			XuatTT(a[i], d);
}
// Kiem tra su co mat cua sinh vien trong danh sach
int KT(TT *a, int n, int x){
	int i;
	for(i=0; i<n; i++)
		if(a[i].ID == x)
			return 1;
	return 0;
}
int main(){
	int k1;	// Bien chon chuc nang cua MENU
	int n = -1; // So sinh vien;
	TT a[31] = {0, 0}; // danh sach sinh vien
	int d = 1; // Bien hien thi hoc luc.
	do{
		printf("\n\n\t\t\tMENU:\n\n");
		printf("\t\t1. Nhap so sinh vien.\n");
		printf("\t\t2. Nhap ID va diem.\n");
		printf("\t\t3. Hien thi danh sach sinh vien.\n");
		printf("\t\t4. Hien thi danh sach sinh vien co diem cao nhat.\n");
		printf("\t\t5. Hien thi danh sach sinh vien co diem thap nhat.\n");
		printf("\t\t6. Cap nhat hanh kiem.\n");
		printf("\t\t7. Hien thi diem cua toi.\n");
		printf("\t\t0. Thoat.\n");
		printf("\tChon chuc nang: "); scanf("%d", &k1);
		switch (k1){
			case 1:{
				int k2 =1; // Bien kiem tra so luong sinh vien nhap co dung khong - dung = 1, sai = 0
				do{ 
					if(k2 == 1)
						printf("\tNhap so luong sinh vien [3;30]: ");
					else
						printf("\n\tVui long nhap so luong trong khoang [3;30]!\n\a\t\tNhap so luong sinh vien: ");
					scanf("%d", &n);
					if(n < 3 || n > 30)
						k2 = 0;
					else
						k2 = 1;
				}while (k2 != 1);
				break;
			}
			case 2:{
				if(n == -1) // Chua nhap so luong;
					printf("\nVui long nhap so luong sinh vien (Chuc nang 1)!\n\a");
				else{
					int i = 0;
					do{	char c;
						printf("Sinh vien %d:\n", i + 1);
						a[i] = NhapTT();
						i++;
						if(i==n)
							break;
						printf("\t\tBan co muon nhap tiep khong (y/n)? "); fflush(stdin);  scanf("%c", &c); 
						if(c == 'n')
							break;
					}while(i != n );
				}
				break;
			}
			case 3:{
				if(n == -1) // chua nhap so luong;
					printf("\nVui long nhap so luong sinh vien (Chuc nang 1)!\n\a");
				else{
					int i;
					if(d == 1)
						printf("\n\t%s\t|\t%s|\t%s\n", "ID", "Diem", "Ho va ten");
					else
						printf("\n\t%s\t|\t%s\t|\t%s|\t%s\n", "ID", "Diem", "Hanh Kiem", "Ho va ten");
					for(i=0; i<n; i++)
						XuatTT(a[i], d);
				}
				break;
			}
			case 4:{
				if(n == -1) // chua nhap so luong;
					printf("\nVui long nhap so luong sinh vien (Chuc nang 1)!\n\a");
				else{
					printf("\n\tDanh sach sinh vien diem cao.");
					if(d == 1)
						printf("\n\t%s\t|\t%s|\t%s\n", "ID", "Diem", "Ho va ten");
					else
						printf("\n\t%s\t|\t%s\t|\t%s|\t%s\n", "ID", "Diem", "Hanh Kiem", "Ho va ten");
					XuatDiemMax(a, n, d);
				}
				break;
			}
			case 5:{
				if(n == -1) // chua nhap so luong;
					printf("\nVui long nhap so luong sinh vien (Chuc nang 1)!\n\a");
				else{
					printf("\n\tDanh sach sinh vien diem thap.");
					if(d == 1)
						printf("\n\t%s\t|\t%s|\t%s\n", "ID", "Diem", "Ho va ten");
					else
						printf("\n\t%s\t|\t%s\t|\t%s|\t%s\n", "ID", "Diem", "Hanh Kiem", "Ho va ten");
					XuatDiemMin(a, n, d);
				}
				break;
			}
			case 6:{
				if(n == -1) // chua nhap so luong;
					printf("\nVui long nhap so luong sinh vien (Chuc nang 1)!\n\a");
				else{
					d = 0;
				}
				break;
			}
			case 7:{
				if(n == -1) // chua nhap so luong;
					printf("\nVui long nhap so luong sinh vien (Chuc nang 1)!\n\a");
				else{
					int k3 = 1, id;
					do{
						if(k3 == 1)
							printf("\nNhap ID cua ban: ");
						else
							printf("\nID cua ban nhap khong co trong danh sach!\n\a\t\tVui long nhap lai id: "); 
						scanf("%d", &id);
						if(KT(a, n, id) == 1)
							k3 = 1;
						else
							k3 = 0;
					}while(k3 != 1);
					int i;
					for( i=0; i<n; i++)
						if(a[i].ID == id)
							if(d==1)
								printf("\t\tDiem cua %s la: %d", a[i].fullName, a[i].Diem);
							else
							printf("\t\tDiem cua %s la: %d - Hanh kiem: %s", a[i].fullName, a[i].Diem, a[i].hanhKiem);
				}
				break;
			}
		}
	}while (k1 != 0);
		printf("\n\n\n----------------------------------------------END-----------------------------------------\n\n\n");
}

