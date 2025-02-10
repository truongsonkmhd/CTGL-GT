#include <iostream>
#include <cstring>
#include <iomanip> // For std::fixed and std::setprecision

using namespace std;

class SanPham {
private:
    char maSanPham[10];
    char tenSanPham[50];
    float donGia;

public:
    SanPham() {}

    SanPham(const char* ma, const char* ten, float gia) : donGia(gia) {
        strcpy(maSanPham, ma);
        strcpy(tenSanPham, ten);
    }

    friend istream& operator>>(istream& is, SanPham& sp) {
        cout << "Nhap ma san pham: ";
        is.getline(sp.maSanPham, 10);
        cout << "Nhap ten san pham: ";
        is.getline(sp.tenSanPham, 50);
        cout << "Nhap don gia: ";
        is >> sp.donGia;
        is.ignore();
        return is;
    }

    friend ostream& operator<<(ostream& os, const SanPham& sp) {
        os << "Ma san pham: " << sp.maSanPham << endl;
        os << "Ten san pham: " << sp.tenSanPham << endl;
        os << "Don gia: " << fixed << setprecision(2) << sp.donGia << endl;
        return os;
    }

    const char* layMaSanPham() const {
        return maSanPham;
    }

    const char* layTenSanPham() const {
        return tenSanPham;
    }

    float layDonGia() const {
        return donGia;
    }

};

class Banh : public SanPham {
private:
    char hanSuDung[20];
    char thanhPhan[100];

public:
    Banh() {}

    Banh(const char* ma, const char* ten, float gia, const char* hsd, const char* tp)
        : SanPham(ma, ten, gia) {
        strcpy(hanSuDung, hsd);
        strcpy(thanhPhan, tp);
    }

    float tinhGiaSauThue() const {
        return layDonGia() * 1.1;
    }

    friend istream& operator>>(istream& is, Banh& bh) {
        is >> static_cast<SanPham&>(bh);
        cout << "Nhap han su dung: ";
        is.getline(bh.hanSuDung, 20);
        cout << "Nhap thanh phan: ";
        is.getline(bh.thanhPhan, 100);
        return is;
    }

    friend ostream& operator<<(ostream& os, const Banh& bh) {
        os << static_cast<const SanPham&>(bh);
        os << "Han su dung: " << bh.hanSuDung << endl;
        os << "Thanh phan: " << bh.thanhPhan << endl;
        os << "Gia sau thue: " << fixed << setprecision(2) << bh.tinhGiaSauThue() << endl;
        return os;
    }

    bool operator==(const char* ten) const {
        return strcmp(layTenSanPham(), ten) == 0;
    }

    const char* getHanSuDung() const {
        return hanSuDung;
    }

    const char* getThanhPhan() const {
        return thanhPhan;
    }
};

void nhapDanhSachBanh(Banh* danhSachBanh, int soLuong) {
    for (int i = 0; i < soLuong; ++i) {
        cout << "Nhap thong tin cho banh thu " << i + 1 << ":\n";
        cin >> danhSachBanh[i];
    }
}

void inDanhSachBanh(const Banh* danhSachBanh, int soLuong) {
    cout << setw(15) << left << "Ma SP"
         << setw(30) << left << "Ten SP"
         << setw(10) << left << "Don gia"
         << setw(20) << left << "Han su dung"
         << setw(50) << left << "Thanh phan"
         << setw(15) << left << "Gia sau thue" << endl;

    for (int i = 0; i < soLuong; ++i) {
        cout << setw(15) << left << danhSachBanh[i].layMaSanPham()
             << setw(30) << left << danhSachBanh[i].layTenSanPham()
             << setw(10) << left << fixed << setprecision(2) << danhSachBanh[i].layDonGia()
             << setw(20) << left << danhSachBanh[i].getHanSuDung()
             << setw(50) << left << danhSachBanh[i].getThanhPhan()
             << setw(15) << left << fixed << setprecision(2) << danhSachBanh[i].tinhGiaSauThue() << endl;
    }
}

void sapxep(Banh* danhSachBanh, int soLuong) {
    for (int i = 0; i < soLuong - 1; ++i) {
        for (int j = i + 1; j < soLuong; ++j) {
            if (danhSachBanh[i].layDonGia() > danhSachBanh[j].layDonGia()) {
                swap(danhSachBanh[i], danhSachBanh[j]);
            }
        }
    }
}

void inDanhSachTheoTen(const Banh* danhSachBanh, int soLuong) {
    const char* tenBanh = "Danisa";

    // Tạo một bản sao của danh sách để sắp xếp
    Banh* tempDanhSach = new Banh[soLuong];
    int tempSoLuong = 0;

    // Chỉ lưu các bánh có tên trùng khớp vào danh sách tạm thời
    for (int i = 0; i < soLuong; ++i) {
        if (danhSachBanh[i] == tenBanh) {
            tempDanhSach[tempSoLuong++] = danhSachBanh[i];
        }
    }

    sapxep(tempDanhSach, tempSoLuong);

    // In ra danh sách đã sắp xếp
    cout << "Danh sach banh co ten '" << tenBanh << "' theo thu tu tang dan cua don gia:\n";
    if (tempSoLuong > 0) {
        inDanhSachBanh(tempDanhSach, tempSoLuong);
    } else {
        cout << "Khong tim thay banh co ten '" << tenBanh << "' trong danh sach." << endl;
    }

    delete[] tempDanhSach;
}

int timViTriBanh(const Banh* danhSachBanh, int soLuong, const char* tenBanh) {
    for (int i = 0; i < soLuong; ++i) {
        if (danhSachBanh[i] == tenBanh) {
            return i;
        }
    }
    return -1;
}

void xoaBanh(Banh*& danhSachBanh, int& soLuong, int viTri) {
    if (viTri < 0 || viTri >= soLuong) {
        cout << "Vi tri xoa khong hop le.\n";
        return;
    }
    for (int i = viTri; i < soLuong - 1; ++i) {
        danhSachBanh[i] = danhSachBanh[i + 1];
    }
    soLuong--;
}

void timVaXoaTheoViTri(Banh*& danhSachBanh, int& soLuong) {
    int viTri;
    cout << "Nhap vi tri banh can xoa: ";
    cin >> viTri;

    if (viTri >= 0 && viTri < soLuong) {
        cout << "Thong tin banh tai vi tri " << viTri << ":\n";
        cout << danhSachBanh[viTri];
        char confirm;
        cout << "Ban co chac chan muon xoa banh nay? (y/n): ";
        cin >> confirm;
        if (confirm == 'y' || confirm == 'Y') {
            xoaBanh(danhSachBanh, soLuong, viTri);
            cout << "Da xoa banh thanh cong.\n";
        } else {
            cout << "Khong xoa banh.\n";
        }
    } else {
        cout << "Vi tri xoa khong hop le.\n";
    }
}

void timBanhChocopie(const Banh* danhSachBanh, int soLuong) {
    const char* tenBanh = "Chocopie";
    cout << "Danh sach banh co ten '" << tenBanh << "':\n";
    bool found = false;
    for (int i = 0; i < soLuong; ++i) {
        if (danhSachBanh[i] == tenBanh) {
            cout << danhSachBanh[i];
            found = true;
        }
    }
    if (!found) {
        cout << "Khong tim thay banh co ten '" << tenBanh << "' trong danh sach." << endl;
    }
}

int main() {
    int soLuongBanh;
    cout << "Nhap so luong banh: ";
    cin >> soLuongBanh;
    cin.ignore(); // Ignore the newline character left in the input buffer

    Banh* danhSachBanh = new Banh[soLuongBanh];

    nhapDanhSachBanh(danhSachBanh, soLuongBanh);
    inDanhSachBanh(danhSachBanh, soLuongBanh);

    // In danh sách bánh có tên "Danisa" theo thứ tự tăng dần của đơn giá
    inDanhSachTheoTen(danhSachBanh, soLuongBanh);

    timBanhChocopie(danhSachBanh, soLuongBanh);

    timVaXoaTheoViTri(danhSachBanh, soLuongBanh);
    delete[] danhSachBanh;
}
