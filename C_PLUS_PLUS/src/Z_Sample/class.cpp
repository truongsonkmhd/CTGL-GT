#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class MayInThuong{
	protected:
		string SoHieuMayIn,MauSac;
		float TocDo,CuongDo;
		int BoNho;
		static int SoLuongMayInCoTrongKho;
	public:
		MayInThuong(){
			SoLuongMayInCoTrongKho++;
		}
		void NhapMayInThuongTuFile(ifstream &d){
			string a;
			getline(d, SoHieuMayIn, ';');
			getline(d, MauSac, ';');
			d >> TocDo;
			getline(d, a, ';');
			d >> CuongDo;
			getline(d, a, ';');
			d >> BoNho;
			getline(d, a, '\n');
		}
		void XuatMayInThuong(){
			cout << "So hieu may in: " << SoHieuMayIn << endl;
			cout << "Mau sac: " << MauSac << endl;
			cout << "Toc do: " << TocDo << endl;
			cout << "Cuong do: " << CuongDo << endl;
			cout << "Bo nho: " << BoNho << endl;
		}
		void NhapInThuong(){
			cout << "+ Nhap so hieu may in: ";
			fflush(stdin);
			getline(cin,SoHieuMayIn);
			cout << "+ Nhap mau sac: ";
			fflush(stdin);
			getline(cin,MauSac);
			cout << "+ Nhap toc do: ";
			cin >> TocDo;
			cout << "+ Nhap cuong do: ";
			cin >> CuongDo;
			cout << "+ Nhap bo nho: ";
			cin >> BoNho;
		}
		int getBoNho(){
			return BoNho;
		}
		string getSoHieuMayIn(){
			return SoHieuMayIn;
		}
};
int MayInThuong::SoLuongMayInCoTrongKho=0;
class MayInLaser: public MayInThuong{
	protected:
		int dpi;
	public:
		void NhapMayInLaserTuFile(ifstream &d){
			string tam;
			getline(d, SoHieuMayIn, ';');
			getline(d, MauSac, ';');
			d >> TocDo;
			getline(d, tam, ';');
			d >> CuongDo;
			getline(d, tam, ';');
			d >> BoNho;
			getline(d, tam, ';');
			d >> dpi;
			getline(d, tam, '\n');
		}
		void XuatMayInLaser(){
			MayInThuong::XuatMayInThuong();
			cout << "So diem in: " << dpi << endl;
		}
		void NhapMayInLaser(){
			MayInThuong::NhapInThuong();
			cout << "+ Nhap so diem in: ";
			cin >> dpi;
		}
};
class MayInMau: public MayInLaser{
	protected:
		int SoMau;
	public:
		void NhapMayInMauTuFile(ifstream &d){
			string tam;
			getline(d, SoHieuMayIn, ';');
			getline(d, MauSac, ';');
			d >> TocDo;
			getline(d, tam, ';');
			d >> CuongDo;
			getline(d, tam, ';');
			d >> BoNho;
			getline(d, tam, ';');
			d >> dpi;
			getline(d, tam, ';');
			d >> SoMau;
			getline(d, tam, '\n');
		}	
		void XuatMayInMau(){
			MayInLaser::XuatMayInLaser();
			cout << "So mau: " << SoMau << endl;
		}
		void NhapMayMau(){
			MayInLaser::NhapMayInLaser();
			cout << "+ Nhap so mau: ";
			cin >> SoMau;
		}
};
class QuanLyCacMayIn{
	private:
		MayInThuong MI[100];
		MayInLaser LS[100];
		MayInMau MM[100];
		int sointhuong,solaser,soinmau;
	public:
		void NhapCacLoaiMayIn(){
			ifstream d;
			d.open("C:\\Users\\DUC VU\\Documents\\Zalo Received Files\\thietbi.txt");
			if(d==NULL){
				cout << "Mo file thietbi.txt khong thanh cong! Vui long kiem tra lai duong dan.\n";
			}else{
				string a;
				d >> sointhuong;
				getline(d,a,'\n');
				for(int i=0;i<sointhuong;i++){
					MI[i].NhapMayInThuongTuFile(d);
				}
				d >> solaser;
				getline(d,a,'\n');
				for(int i=0;i<solaser;i++){
					LS[i].NhapMayInLaserTuFile(d);
				}
				d >> soinmau;
getline(d,a,'\n');
				for(int i=0;i<soinmau;i++){
					MM[i].NhapMayInMauTuFile(d);
				}
			}		
			d.close();
		}
		void XuatCacLoaiMayIn(){
			cout << "\t\tThong tin danh sach may in thuong\n";
			for(int i=0;i<sointhuong;i++){
				cout << "\tMay in thuong thu " << i+1 << ":"<< endl;		
				MI[i].XuatMayInThuong();
			}
			cout << "\t\tThong tin danh sach may in laser\n";
			for(int i=0;i<solaser;i++){
				cout << "\tMay in laser thu " << i+1 << ":" << endl;
				LS[i].XuatMayInLaser();
			}
			cout << "\t\tThong tin danh sach may in mau\n";
			for(int i=0;i<soinmau;i++){
				cout << "\tMay int mau thu " << i+1 << ":" << endl;
				MM[i].XuatMayInMau();
			}
		}
		void LapHoaDonNhap(){
			int s;
			cout << "Nhap so luong may in thuong can nhap: ";
			cin >> s;
			for(int i=0;i<s;i++){
				MI[sointhuong++].NhapInThuong();
			};
			cout << "Nhap so luong may laze can nhap: ";
			cin >> s;
			for(int i=0;i<s;i++){
				LS[solaser++].NhapMayInLaser();
			}
			cout << "Nhap so luong may in mau can nhap: ";
			cin >> s;
			for(int i=0;i<s;i++){
				MM[soinmau++].NhapMayMau();
			}
		}
		void ThongKeTheoBoNho(){
			cout << "\n================THONG KE THEO BO NHO LON HON 300================\n";
			int TongBoNhoLonHon300 = 0;
			for(int i=0;i<sointhuong;i++){
				if(MI[i].getBoNho()>300){
					TongBoNhoLonHon300++;
				}
			}
			for(int i=0;i<solaser;i++){
				if(LS[i].getBoNho()>300){
					TongBoNhoLonHon300++;
				}
			}	
			for(int i=0;i<soinmau;i++){
				if(MM[i].getBoNho()>300){
					TongBoNhoLonHon300++;
				}
			}
			cout << "\nTong may in co bo nho lon hon 300 la: "<<(float)TongBoNhoLonHon300/(sointhuong+solaser+soinmau)*100<<" %\n";
		}
		void TimKiemTheoSoHieuMayIn(){
			string sohieumayincantim;
			int dem=1;
			cout << "Nhap so hieu may in can tim: ";
			fflush(stdin);
			getline(cin,sohieumayincantim);
			for(int i=0;i<sointhuong;i++){
				if(MI[i].getSoHieuMayIn()==sohieumayincantim){
					cout << "\tMay in thuong co so hieu may in can tim thu " << dem++ << endl;
					MI[i].XuatMayInThuong();
				}
			}
			for(int i=0;i<solaser;i++){
				if(LS[i].getSoHieuMayIn()==sohieumayincantim){
					cout << "\tMay in laze co so hieu may in can tim thu " << dem++ << endl;
					LS[i].XuatMayInLaser();
				}
			}	
			for(int i=0;i<soinmau;i++){
				if(MM[i].getSoHieuMayIn()==sohieumayincantim){
					cout << "\tMay in mau co so hieu may in can tim thu " << dem++ << endl;
					MM[i].XuatMayInMau();
				}
			}
			
			if(dem==1) 
				cout << "Khong co may in nao co so hieu may in " << sohieumayincantim << " can tim trong danh sach\n";
		}
};
int main(){
	QuanLyCacMayIn ql;
	ql.NhapCacLoaiMayIn();
	ql.XuatCacLoaiMayIn();
	int luachon;
	while(true){
		cout << "============Menu============";
		cout << "\n1. Lap hoa don nhap\n";
		cout << "2. Tim kiem theo so hieu bo nho\n";
		cout << "3. Thong ke theo bo nho\n";
		cout << "4. Xuat tat ca may in trong danh sach\n";
		cout << "0. Thoat\n";
		cout << "Nhap lua chon: ";
		cin >> luachon;
		if(luachon==1){
ql.LapHoaDonNhap();
			cout << "Da them cac may in nhap vao trong danh sach\n";
		}else if(luachon==2){
			ql.TimKiemTheoSoHieuMayIn();
		}else if(luachon==3){
			ql.ThongKeTheoBoNho();
		}else if(luachon==4){
			ql.XuatCacLoaiMayIn();
		}
		else if(luachon==0){
			cout << "Cam on ban da su dung chuong trinh!\n";
			break;
		}else{
			cout << "Ban da nhap sai. Vui long nhap lai!\n";
		}
	}
	return 0;
}
