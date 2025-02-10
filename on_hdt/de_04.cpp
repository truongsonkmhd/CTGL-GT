#include <iostream>
#include <cstring>
#include <iomanip> // For std::fixed and std::setprecision

using namespace std;

class AnPham {
private:
    char maHang[10];
    char tenNXB[50];
    char ngayXuatBan[20];
    float donGia;

public:
    AnPham() {}

    AnPham(const char* ma, const char* nxb, const char* ngay, float gia) : donGia(gia) {
        strcpy(maHang, ma);
        strcpy(tenNXB, nxb);
        strcpy(ngayXuatBan, ngay);
    }

    virtual ~AnPham() {}

    friend istream& operator>>(istream& is, AnPham& ap) {
        cout << "Nhap ma hang: ";
        is.getline(ap.maHang, 10);
        cout << "Nhap ten nha xuat ban: ";
        is.getline(ap.tenNXB, 50);
        cout << "Nhap ngay xuat ban: ";
        is.getline(ap.ngayXuatBan, 20);
        cout << "Nhap don gia: ";
        is >> ap.donGia;
        is.ignore();
        return is;
    }

    friend ostream& operator<<(ostream& os, const AnPham& ap) {
        os << "Ma hang: " << ap.maHang << endl;
        os << "Ten nha xuat ban: " << ap.tenNXB << endl;
        os << "Ngay xuat ban: " << ap.ngayXuatBan << endl;
        os << "Don gia: " << fixed << setprecision(2) << ap.donGia << endl;
        return os;
    }

    const char* layTenNXB() const {
        return tenNXB;
    }

    const char* layMaHang() const {
        return maHang;
    }

    const char* ngayXB() const {
        return ngayXuatBan;
    }

    const char* getTenNXB() const {
        return tenNXB;
    }

    void suaTenNXB(const char* tenMoi) {
        strcpy(tenNXB, tenMoi);
    }

    float layDonGia() const {
        return donGia;
    }
};

class Sach : public AnPham {
private:
    char tenSach[50];
    char tenTacGia[50];
    int soLuong;
    float trongLuong;

public:
    Sach() {}

    Sach(const char* ma, const char* nxb, const char* ngay, float gia, const char* ten, const char* tacGia, int sl, float tl)
        : AnPham(ma, nxb, ngay, gia) {
        this->soLuong = soLuong;
        this->trongLuong = trongLuong;
        strcpy(tenSach, ten);
        strcpy(tenTacGia, tacGia);
    }

    float tinhPhiVanChuyen() const {
        return soLuong * layDonGia() * 0.02;
    }

    friend istream& operator>>(istream& is, Sach& s) {
        is >> static_cast<AnPham&>(s);
        cout << "Nhap ten sach: ";
        is.getline(s.tenSach, 50);
        cout << "Nhap ten tac gia: ";
        is.getline(s.tenTacGia, 50);
        cout << "Nhap so luong: ";
        is >> s.soLuong;
        cout << "Nhap trong luong: ";
        is >> s.trongLuong;
        is.ignore();
        return is;
    }

    friend ostream& operator<<(ostream& os, const Sach& s) {
        os << static_cast<const AnPham&>(s);
        os << "Ten sach: " << s.tenSach << endl;
        os << "Ten tac gia: " << s.tenTacGia << endl;
        os << "So luong: " << s.soLuong << endl;
        os << "Trong luong: " << s.trongLuong << endl;
        os << "Phi van chuyen: " << fixed << setprecision(2) << s.tinhPhiVanChuyen() << endl;
        return os;
    }

    bool operator!=(const char* ten) const {
        return strcmp(tenSach, ten) != 0;
    }

    const char* getTenSach() const {
        return tenSach;
    }

    const char* getTenTacGia() const {
        return tenTacGia;
    }

    int getSoLuong() const {
        return soLuong;
    }

    float getTrongLuong() const {
        return trongLuong;
    }
};

void nhapDanhSachSach(Sach* danhSachSach, int soLuong) {
    for (int i = 0; i < soLuong; ++i) {
        cout << "Nhap thong tin cho sach thu " << i + 1 << ":\n";
        cin >> danhSachSach[i];
    }
}

void inDanhSachSach(const Sach* danhSachSach, int soLuong) {
    cout << setw(10) << left << "Ma hang"
         << setw(20) << left << "Ten NXB"
         << setw(20) << left << "Ngay XB"
         << setw(10) << left << "Don gia"
         << setw(30) << left << "Ten sach"
         << setw(30) << left << "Ten tac gia"
         << setw(10) << left << "So luong"
         << setw(10) << left << "Trong luong "
         << setw(17) << left << "Phi van chuyen" << endl;

    for (int i = 0; i < soLuong; ++i) {
        cout << setw(10) << left << danhSachSach[i].layMaHang()
             << setw(20) << left << danhSachSach[i].layTenNXB()
             << setw(20) << left << danhSachSach[i].ngayXB()
             << setw(10) << left << fixed << setprecision(2) << danhSachSach[i].layDonGia()
             << setw(30) << left << danhSachSach[i].getTenSach()
             << setw(30) << left << danhSachSach[i].getTenTacGia()
             << setw(10) << left << danhSachSach[i].getSoLuong()
             << setw(10) << left << danhSachSach[i].getTrongLuong()
             << setw(17) << left << fixed << setprecision(2) << danhSachSach[i].tinhPhiVanChuyen() << endl;
    }
}

void inDanhSachTheoNXB(const Sach* danhSachSach, int soLuong, const char* nxb) {
    cout << "Danh sach sach cua nha xuat ban '" << nxb << "':\n";
    bool found = false;
    for (int i = 0; i < soLuong; ++i) {
        if (strcmp(danhSachSach[i].getTenNXB(), nxb) == 0) {
            cout << danhSachSach[i];
            found = true;
        }
    }
    if (!found) {
        cout << "Khong tim thay sach cua nha xuat ban '" << nxb << "' trong danh sach." << endl;
    }
}

void timSachKhac(const Sach* danhSachSach, int soLuong, const char* tenSach) {
    cout << "Danh sach sach co ten khac '" << tenSach << "':\n";
    bool found = false;
    for (int i = 0; i < soLuong; ++i) {
        if (danhSachSach[i] != tenSach) {
            cout << danhSachSach[i];
            found = true;
        }
    }
    if (!found) {
        cout << "Tat ca cac sach trong danh sach deu co ten la '" << tenSach << "'." << endl;
    }
}

void suaThongTinNXB(Sach* danhSachSach, int soLuong) {
    char tenMoi[50];
    cout << "Nhap ten moi cua nha xuat ban: ";
    cin.ignore();
    cin.getline(tenMoi, 50);

    for (int i = 0; i < soLuong; ++i) {
        danhSachSach[i].suaTenNXB(tenMoi);
    }
}

int main() {
    int soLuongSach;
    cout << "Nhap so luong sach: ";
    cin >> soLuongSach;
    cin.ignore(); // Ignore the newline character left in the input buffer

    Sach* danhSachSach = new Sach[soLuongSach];

    nhapDanhSachSach(danhSachSach, soLuongSach);
    inDanhSachSach(danhSachSach, soLuongSach);

    // In danh sách sách của nhà xuất bản "DH Bach Khoa"
    inDanhSachTheoNXB(danhSachSach, soLuongSach, "DH Bach Khoa");

    // Tìm và in danh sách sách có tên khác "Co so du lieu SQL"
    timSachKhac(danhSachSach, soLuongSach, "Co so du lieu SQL");

    // Sửa thông tin tên nhà xuất bản của ấn phẩm
    suaThongTinNXB(danhSachSach, soLuongSach);
    cout << "Danh sach sach sau khi sua ten NXB:\n";
    inDanhSachSach(danhSachSach, soLuongSach);

    delete[] danhSachSach;
    return 0;
}
