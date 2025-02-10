#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class Cat {
private:
    char ma[10];
    char tenChuNhan[10];
    float canNang;
    char ngayMua[20];

public:
    Cat() {}

    Cat(const char* ma, const char* tenChuNhan, float canNang, const char* ngayMua) {
        strcpy(this->ma, ma);
        strcpy(this->tenChuNhan, tenChuNhan);
        this->canNang = canNang;
        strcpy(this->ngayMua, ngayMua);
    }

    ~Cat() {}

      friend istream& operator>>(istream& is, Cat& cat) {
        cout << "Nhap ma: ";
        fflush(stdin);
		is.getline(cat.ma,10);
        cout << "Nhap ten chu nhan: ";
        is.getline(cat.tenChuNhan,10);
        cout << "Nhap ngay mua: ";
        is.getline(cat.ngayMua,20);
        fflush(stdin);
        cout << "Nhap can nang: ";
        is >> cat.canNang;
        return is;
    }

    friend ostream& operator<<(ostream& os, const Cat& cat) {
        os << "Ma: " << cat.ma << endl;
        os << "Ten chu nhan: " << cat.tenChuNhan << endl;
        os << "Can nang: " << cat.canNang << endl;
        os << "Ngay mua: " << cat.ngayMua << endl;
        return os;
    }

    float getCanNang() const {
        return canNang;
    }

    const char* getMa() const {
        return ma;
    }
};

class MunCat : public Cat {
private:
    char mauSac[10];

public:
    MunCat() {}

    MunCat(const char* ma, const char* tenChuNhan, float canNang, const char* ngayMua, const char* mauSac)
        : Cat(ma, tenChuNhan, canNang, ngayMua) {
        strcpy(this->mauSac, mauSac);
    }

    float tinhTienThucAn() const {
        return getCanNang() > 10 ? 1000000 : 500000;
    }

     friend istream& operator>>(istream& is, MunCat& munCat) {
        is >> static_cast<Cat&>(munCat);
        fflush(stdin);
        cout << "Nhap mau sac: ";
        is.getline(munCat.mauSac,10);
        fflush(stdin);
        return is;
    }

    friend ostream& operator<<(ostream& os, const MunCat& munCat) {
        os << static_cast<const Cat&>(munCat);
        os << "Mau sac: " << munCat.mauSac << endl;
        os << fixed << "Tien thuc an la: " << munCat.tinhTienThucAn() << endl;
        return os;
    }

    const char* getMauSac() const {
        return mauSac;
    }

    bool operator==(const char* ma) const {
        return strcmp(this->getMa(), ma) == 0;
    }

    bool operator<(const MunCat& other) const {
        return this->getCanNang() < other.getCanNang();
    }

    bool operator>(const MunCat& other) const {
        return this->getCanNang() > other.getCanNang();
    }

    ~MunCat() {}
};

void nhapDanhSach(MunCat* ds, int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Nhap thong tin MunCat [" << i + 1 << "]:\n";
        cin >> ds[i];
    }
}

void xuatDanhSach(const MunCat* ds, int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Thong tin MunCat [" << i + 1 << "]:\n";
        cout << ds[i];
    }
}

void demMauSac(const MunCat* ds, int n, const char* mauSac) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (strcmp(ds[i].getMauSac(), mauSac) == 0) {
            count++;
        }
    }
    cout << "So luong MunCat co mau " << mauSac << " la: " << count << endl;
}

void xoaThongTin(MunCat*& ds, int& n, const char* ma) {
    int index = -1;
    for (int i = 0; i < n; ++i) {
        if (ds[i] == ma) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        cout << "Khong tim thay MunCat co ma: " << ma << endl;
        return;
    }
    for (int i = index; i < n - 1; ++i) {
        ds[i] = ds[i + 1];
    }
    n--;
    MunCat* temp = new MunCat[n];
    for (int i = 0; i < n; ++i) {
        temp[i] = ds[i];
    }
    delete[] ds;
    ds = temp;
    cout << "Da xoa MunCat co ma: " << ma << endl;
}

void quickSort(MunCat* ds, int left, int right) {
    MunCat pivot = ds[(left + right) / 2];
    int l = left, r = right;
    do {
        while (ds[l] < pivot) l++;
        while (ds[r] > pivot) r--;
        if (l <= r) {
            swap(ds[l], ds[r]);
            l++;
            r--;
        }
    } while (l <= r);
    if (left < r) quickSort(ds, left, r);
    if (l < right) quickSort(ds, l, right);
}

void sapXepTangDan(MunCat* ds, int n) {
    quickSort(ds, 0, n - 1);
    cout << "Danh sach sau khi sap xep tang dan theo can nang:\n";
    xuatDanhSach(ds, n);
}

int main() {
    int n;
    cout << "Nhap so luong MunCat: ";
    cin >> n;
    cin.ignore();
    MunCat* ds = new MunCat[n];

    nhapDanhSach(ds, n);
    xuatDanhSach(ds, n);

    char mau[10];
    cout << "Nhap mau sac can dem: ";
    cin >> mau;
    demMauSac(ds, n, mau);

    char ma[10];
    cout << "Nhap ma MunCat can xoa: ";
    cin >> ma;
    xoaThongTin(ds, n, ma);

    sapXepTangDan(ds, n);

    delete[] ds;
    return 0;
}
