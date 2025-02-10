#include <iostream>
#include <cstring>

using namespace std;

class Sach {
private:
    char ma[10];
    char tenNXB[20];
    char tenSach[20];
    float donGia;
    char ngayXB[30];

public: 
    Sach(){}

    Sach(const char* ma , const char* tenNXB, const char* tenSach, float donGia, const char* ngayXB){
        strcpy(this->ma, ma);
        strcpy(this->tenNXB, tenNXB);
        strcpy(this->tenSach, tenSach);
        this->donGia = donGia;
        strcpy(this->ngayXB, ngayXB);
    }

    friend istream& operator >> (istream& is, Sach& sach){
        cout<< "Nhap ma: ";
        is.getline(sach.ma,10);
        cout<< "Nhap tenNXB: ";
        is.getline(sach.tenNXB,20);
        cout<< "Nhap tenSach: ";
        is.getline(sach.tenSach,20);
        cout<< "Nhap don gia: ";
        is >> sach.donGia;
        cin.ignore(); // Ignore the newline character left in the input buffer
        cout<< "Nhap ngay XB: ";
        is.getline(sach.ngayXB,30);
        return is;
    }

    friend ostream& operator<<(ostream& os, const Sach& sach){
        os << "Ma: "<< sach.ma <<endl;
        os << "Ten NXB: "<< sach.tenNXB <<endl;
        os << "Ten sach: "<<sach.tenSach <<endl;
        os << "Don gia: "<<sach.donGia <<endl;
        os << "Ngay XB: "<<sach.ngayXB <<endl;
        return os;
    }

    const char* layTenSach() const {
        return tenSach;
    }

    const char* layTenNXB() const {
        return tenNXB;
    }

    const char* layMaSach() const {
        return ma;
    }

    float layDonGia() const {
        return donGia;
    }

    void suaTenSach(const char* tenMoi) {
    strcpy(this->tenSach, tenMoi);
}

};

class SachKH : public Sach {
private:
    char linhVuc[30];
    int soBanIn;

public:
    SachKH(){}
    SachKH(const char* ma , const char* tenNXB, const char* tenSach, float donGia, const char* ngayXB, const char* linhVuc, int soBanIn)
    : Sach(ma, tenNXB, tenSach, donGia, ngayXB), soBanIn(soBanIn) {
        strcpy(this->linhVuc, linhVuc);
    }

    float tinhThanhTien() const {
        float thanhTien = soBanIn * layDonGia();
        if (strcmp(linhVuc, "Thien van") == 0)
            thanhTien *= 1.1; 
        return thanhTien;
    }

    friend istream& operator>>(istream& is, SachKH& sachKH){
        is >> static_cast<Sach&>(sachKH);
        fflush(stdin);        
        cout<< "Nhap linh vuc: ";
        is.getline(sachKH.linhVuc, 30);
        cout<< "Nhap so ban in: ";
        is >> sachKH.soBanIn;
        fflush(stdin);
        return is;
    }

    friend ostream& operator<<(ostream& os, const SachKH& sachKH){
        os << static_cast<const Sach&>(sachKH);
        os << "Linh vuc: "<< sachKH.linhVuc <<endl;
        os << "So ban in: "<< sachKH.soBanIn <<endl;
        os << "Thanh tien: "<< sachKH.tinhThanhTien() <<endl;
        return os;
    }

    int laySoBanIn() const {
        return soBanIn; 
    }

     bool operator<(const SachKH& other) const {
        return strcmp(this->layTenSach(), other.layTenSach()) < 0;
    }

    bool operator>(const SachKH& other) const {
        return strcmp(this->layTenSach(), other.layTenSach()) > 0;
    }

    bool operator==(const char* tenMaSach) const {
        return strcmp(this->layMaSach(), tenMaSach) == 0;
    }
};

void nhapDanhSach(SachKH* skh, int n){
     for (int i = 0; i < n; ++i) {
        cout << "Nhap thong tin cho sach thu " << i + 1 << ":" << endl;
        cin >> skh[i];
    }
}

void xuatDanhSach(SachKH* skh, int n){
    for (int i = 0; i < n; ++i) {
        cout << "Thong tin sach thu " << i + 1 << ":" << endl;
        cout << skh[i];
    }
}

void timDS(SachKH* skh, int n){
    cout << "Sach cua NXB 'Giao Thong' co so ban in lon hon 200:" << endl;
    for (int i = 0; i < n; ++i) {
        if (skh[i] == "Giao Thong" && skh[i].laySoBanIn() > 200) {
            cout << skh[i];
        }
    }
}

void suaTT(SachKH* skh, int n){
    char maSach[10];
    cout << "Nhap ma sach can sua: ";
    cin >> maSach;
    for (int i = 0; i < n; ++i) {
    if (strcmp(skh[i].layMaSach(), maSach) == 0) {
        char tenMoi[20];
        cout << "Nhap ten moi cho sach: ";
        cin.ignore();
        cin.getline(tenMoi, 20);
        skh[i].suaTenSach(tenMoi);
        cout << "Da sua ten sach thanh cong!" << endl;
        break;
        }
    }
}

void quickSort(SachKH* skh, int left, int right) {
    SachKH pivot = skh[(left + right) / 2];
    int l = left, r = right;
    do {
        while (skh[l] < pivot) l++;
        while (skh[r] > pivot) r--;
        if (l <= r) {
            swap(skh[l], skh[r]);
            l++;
            r--;
        }
    } while (l <= r);
    if (left < r) quickSort(skh, left, r);
    if (l < right) quickSort(skh, l, right);
}

void sapXepTangDan(SachKH* skh, int n) {
    quickSort(skh, 0, n - 1);
    cout << "Danh sach sau khi sap xep tang dan theo can nang:\n";
    xuatDanhSach(skh, n);
}

int main() {
    int n;
    cout << "Nhap so luong sach: ";
    cin >> n;
    cin.ignore(); // Ignore the newline character left in the input buffer

    SachKH* ds = new SachKH[n];

    nhapDanhSach(ds, n);
    cout<<"============Danh sach sau khi nhap=============";
    cout<<endl;
    xuatDanhSach(ds, n);

    suaTT(ds, n);
    cout<<"============Danh sach sau khi sua=============";
    cout<<endl;
    xuatDanhSach(ds,n);
    cout<<"============Sap xep tang dan==================";
    cout<<endl;
    sapXepTangDan(ds,n);
    delete[] ds; 
    return 0;
}