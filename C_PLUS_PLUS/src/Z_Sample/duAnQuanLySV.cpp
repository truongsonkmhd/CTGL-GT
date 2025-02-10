#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>

using namespace std;

typedef struct Ngay{
    int day;
    int month;
    int year;
}ngaySinh;
void NhapNgay(ngaySinh &a);
void XuatNgay(ngaySinh a);

typedef struct Diem{
    float Toan;
    float Ktmt;
    float Anh;
    float DiemTB;
}diem;
typedef struct SinhVien{
    string MSV;
    string fullName;
    ngaySinh date; 
    string Class;
    string Phone;
    diem mark;
    char HocLuc;
}sinhVien;
void ChuanHoaTen(string &a);
void NhapSV(sinhVien &a);
void NhapDSSV(sinhVien *a, int n);
void XuatSV(sinhVien a, int d);
void XuatDSSV(sinhVien *a, int n, int d);
void Menu();
string Ten(string a);
void SortName(sinhVien *a, int n);
void SortMark(sinhVien *a, int n);
void XoaSinhVien(sinhVien *a, int &n, int x);
void XoaSinhVienMSV(sinhVien *a, int &n, string ma);
void XoaSinhVienClass(sinhVien *a, int &n, string maLop);
void DanhSachThiLai(sinhVien *a, int n);
void Doc(sinhVien *a, int &n);
void In(sinhVien *a, int n, int d);

int main(){
    sinhVien *a;
    a = new sinhVien[100];
    int n, k1, k2, d = 0;
    Doc(a, n);
    do{
        Menu();
        cin >> k1;
        switch (k1){
        case 1:{
            cout << "\n1. Nhap theo so luong.";
            cout << "\n2. Nhap lan luot.";
            cout << "\n\tChuc nang: "; cin >> k2;
            switch (k2){
                case 1:{
                	int m;
                    cout << "Nhap so luong: "; cin >> m;
                    NhapDSSV((a+n), m);
                    n += m;
                    break;
                }
                case 2:{
                    char c;
                    do{
                        NhapSV(a[n++]);
                        cout << "Ban co muon nhap tiep khong(y/n)?";
                        cin >> c;
                    }while(c != 'n');
                    break;
                }
            }
            break;
        }
        case 2:{
            XuatDSSV(a, n, d);
            break;
        }
        case 3:{
			In(a, n, d);
			cout << "\n\tDa xuat ra file danh sach sinh vien.txt";
			break;
		}
        case 4:{
            SortName(a, n);
            cout << "\nDa sap xep theo ten!\n\tDe xem vui long thuc hien chuc nang 2.\n";
            d = 1;
            break;
        }
        case 5:{
            SortMark(a, n);
            cout << "\nDa sap xep theo diem!\n\tDe xem vui long thuc hien chuc nang 2.\n";
            break;
        }
        case 6:{
            string ma;
            cout << "\nXoa sinh vien theo ma.\n\tVui long nhap MSV: ";  cin >> ma;
            XoaSinhVienMSV(a, n, ma);
            break;
        }
        case 7:{
            string maLop;
            cout << "\nXoa sinh vien theo ma lop.\n\tVui long nhap ma lop: "; cin >> maLop;
            XoaSinhVienClass(a, n, maLop);
            break;
        }
        case 8:{
        	cout << "\n\t\tDanh sach hoc sinh phai thi lai\n";
        	DanhSachThiLai(a, n);
			break;
		}
        }
    } while( k1 != 0);
    return 0;
}
void NhapNgay(ngaySinh &a){
    char c;
    cout << "Nhap ngay sinh(dd/mm/yyyy): ";
    cin >> a.day >> c >> a.month >> c >> a.year;
}
void XuatNgay(ngaySinh a){
    if(a.day < 10)
        cout << "0" << a.day;
    else
        cout << a.day;

    if(a.month < 10)
        cout << "/0" << a.month;
    else    
        cout << "/" << a.month;

    cout << "/" << a.year;
}


void ChuanHoaTen(string &a){
	int i;
	for(i=0; i<a.size(); i++){
		if((i == 0 || a[i-1] == 32 && a[i] != 32) && a[i] <='z' && a[i] >= 'a')	
			a[i] -= 32;
		if(a[i - 1] != 32 && i != 0 && a[i] >= 'A' && a[i] <= 'Z' )
			a[i] += 32;
	}
		
}
void NhapSV(sinhVien &a){
    cout << "Nhap MSV: "; 
    cin >> a.MSV;
    cout << "Nhap ten sinh vien: ";
    cin.ignore();    getline(cin ,a.fullName);	ChuanHoaTen(a.fullName);
	NhapNgay(a.date);
	cout << "Nhap ma lop: "; cin >> a.Class;
	cout << "Nhap SDT: "; 	cin >> a.Phone;
    cout << "Nhap diem thanh phan(T, L, A): "; cin >> a.mark.Toan >> a.mark.Ktmt >> a.mark.Anh;
    a.mark.DiemTB = (a.mark.Toan + a.mark.Anh + a.mark.Ktmt)/3;
    if(a.mark.DiemTB > 9)
    	a.HocLuc = 'A';
    else	if(a.mark.DiemTB > 8)
    	a.HocLuc = 'B';
    else	if(a.mark.DiemTB > 6)
    	a.HocLuc = 'C';
    else	if(a.mark.DiemTB > 4)
    	a.HocLuc = 'D';
    else
    	a.HocLuc = 'F';
}
void NhapDSSV(sinhVien *a, int n){
    int i;
    for(i=0; i<n; i++){
        cout << "\nNhap thong tin cua sinh vien thu " << i << ":\n";
        NhapSV(a[i]);
    }
}
void XuatSV(sinhVien a, int d){
	cout << left << setw(10) << a.MSV << setw(25) << a.fullName ; XuatNgay(a.date); 
	cout << "\t" << left << setw(10) << a.Class << setw(15)  << a.Phone 
	<< setw(8) << a.mark.Toan << setw(8) << a.mark.Ktmt << setw(8) << a.mark.Anh ;
	if(d >= 1)
		cout << left << setw(20) << fixed << setprecision(2) << a.mark.DiemTB << a.HocLuc;
	cout << endl;
}
void XuatDSSV(sinhVien *a, int n, int d){
	cout << left << setw(10) << "MSV" << setw(25) << "Ho ten" << setw(13) << "Ngay sinh" 
	<< setw(10) << "Lop" << setw(15)  << "SDT" << setw(8) << "Toan" << setw(8) << "Ktmt"
	<< setw(8) << "Anh" ;
	if(d >= 1)
		cout << left << setw(20) << "Trung binh" << setw(10) << "Hoc luc";
	cout << endl;
    for(int i=0; i<n; i++)
        XuatSV(a[i], d);
}
void Menu(){
	cout << "\n\t\tMENU\n";
	cout << "1. Nhap sinh vien.\n";
	cout << "2. Xuat danh sach sinh vien.\n";
    cout << "3. Xuat danh sach ra file.\n";
	cout << "4. Sap xep danh sach theo ten.\n";
	cout << "5. Sap xep theo diem trung binh.\n";
	cout << "6. Xoa sinh vien theo MSV.\n";
	cout << "7. Xoa sinh vien theo ma lop.\n";
	cout << "8. Danh sach hoc sinh phai thi lai.\n";
	cout << "0. Thoat.\n";
	cout << "\t\tChuc nang: ";
}
string Ten(string a){
    int i, k;
    string c;
    for(i= a.size() - 1; i>=0; i--){
        if(i==0){
        	c += a;
        } else
            if(a[i] == 32){
            	c += a.substr(i+1);
            	a.erase(i);
            	i = a.size();
            }
    }
    return c;
}
void SortName(sinhVien *a, int n){
    int i, j;
    for(i=0; i<n-1; i++)
        for(j=i+1; j<n; j++)
            if(Ten(a[i].fullName) > Ten(a[j].fullName)){
                sinhVien t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
}
void SortMark(sinhVien *a, int n){
    int i, j;
    for(i=0; i<n; i++)
        for(j=i+1; j<n; j++)
            if(a[i].mark.DiemTB < a[j].mark.DiemTB){
                sinhVien t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
}
void XoaSinhVien(sinhVien *a, int &n, int x){
    int i;
    n--;
    for(i=x; i<n; i++)
        a[i] = a[i+1];
}
void XoaSinhVienMSV(sinhVien *a, int &n, string ma){
    int i, d = 0;
    for(i=0; i<n; i++)
        if(a[i].MSV == ma){
            d = 1;
            break;
        }
    if(d == 0)
        cout << "\nTrong danh sach khong co sinh vien ma " << ma << ", vui long kiem tra lai!\n";
    else    {
        XoaSinhVien(a, n, i);
        cout << "\nDa xoa sinh vien ma " << ma << " khoi danh sach!Dung chuc nang 2 de xem danh sach.";
    }
}
void XoaSinhVienClass(sinhVien *a, int &n, string maLop){
    int i, d = 0;
    for(i=0; i<n; i++)
        if(a[i].Class == maLop){
            d = 1;
            XoaSinhVien(a, n, i);
            i--;
        }
    if(d == 0)
        cout << "\nTrong danh sach khong co ma lop " << maLop << ", vui long kiem tra lai!\n";
    else    
        cout << "\nDa xoa sinh vien co ma lop " << maLop << " khoi danh sach!Dung chuc nang 2 de xem danh sach.";
}
void DanhSachThiLai(sinhVien *a, int n){
	int i, d = 0;
	cout << "\n\t\t\tDANH SACH THI LAI\n";
	cout << left << setw(10) << "MSV" << setw(20) << "Ho ten" << setw(10) << "Ngay sinh" 
		<< setw(10) << "Lop" << setw(15)  << "SDT" << setw(8) << "Toan" << setw(8) << "Ktmt" << setw(8) << "Anh" 
		<< setw(20) << "Trung binh" << "Hoc luc";
	for(i=0; i<n; i++)
		if(a[i].mark.DiemTB < 4){
			d = 1;
			XuatSV(a[i], 1);
		}
	if(d == 0)
		cout << "\nKhong co sinh vien nao phai thi lai.";
}
void Doc(sinhVien *a, int &n){
	char c;
	ifstream fileIn;
	fileIn.open("danhsachsinhvienInput.txt"); // duong dan den file 
	fileIn >> n;
	fileIn.ignore();
	for(int i=0; i<n; i++){
		fileIn >> a[i].MSV;
		fileIn.ignore();
		getline(fileIn, a[i].fullName);	ChuanHoaTen(a[i].fullName);
		fileIn >> a[i].date.day >> c >> a[i].date.month >> c >> a[i].date.year;
		fileIn >> a[i].Class;
		fileIn >> a[i].Phone;
		fileIn >> a[i].mark.Toan >> a[i].mark.Ktmt >> a[i].mark.Anh;
		a[i].mark.DiemTB = (a[i].mark.Toan + a[i].mark.Anh + a[i].mark.Ktmt)/3;
    	if(a[i].mark.DiemTB > 9)
    		a[i].HocLuc = 'A';
   		else	if(a[i].mark.DiemTB > 8)
    		a[i].HocLuc = 'B';
    	else	if(a[i].mark.DiemTB > 6)
    		a[i].HocLuc = 'C';
    	else	if(a[i].mark.DiemTB > 4)
    		a[i].HocLuc = 'D';
   	 	else
    		a[i].HocLuc = 'F';
	}
	fileIn.close();
}
void In(sinhVien *a, int n, int d){
	ofstream fileOut("danh sach sinh vien.txt");
	fileOut << "\n\t\t\tDANH SACH SINH VIEN\n";
	fileOut << left << setw(10) << "MSV" << setw(25) << "Ho ten" << setw(13) << "Ngay sinh" 
		<< setw(10) << "Lop" << setw(15)  << "SDT" << setw(8) << "Toan" << setw(8) << "Ktmt" << setw(8) << "Anh" 
		<< setw(20) << "Trung binh" << "Hoc luc";
	for(int i =0; i<n; i++){
		fileOut << left << setw(10) << a[i].MSV << setw(20) << a[i].fullName << setw(2) 
			<< a[i].date.day << "/" << setw(2) << a[i].date.month << "/" << setw(4) << a[i].date.year
				<< setw(10) << a[i].Class << setw(15)  << a[i].Phone << setw(8) << a[i].mark.Toan 
				<< setw(8) << a[i].mark.Ktmt << setw(8) << a[i].mark.Anh;
		if(d >= 1)
			fileOut << setw(20) << fixed << setprecision(2) << a[i].mark.DiemTB << a[i].HocLuc;
	fileOut << endl;
	}
	fileOut.close();
}
