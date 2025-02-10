/*#include <iostream>
using namespace std;

int main() {
	int arr[] = {14 ,3 ,6, 27, 12};
	for(auto item : arr){
		cout<<item<<" "; // gna gia tri vao trong bien item(bat dau tu dau danh sach den cuoi)
		}
	return 0;
}*/
//vecto
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
//vector<kieu du lieu> ten_vector
//push_back(): de them phan tu vao trong mang dong(vector)
//size(): kich thuoc vector
//Truy cap cac phan tu trong vector thong qua chi so
//Duyet thong qua index
//Duyet thong qua for each
/*int main() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	for(int i = 0; i< v.size();i++){
		cout<<v[i]<<endl;
		}
//	for(int x: v){
//		cout<< x << endl;
//		}
		return 0;
		}*/
/*int main(){
	int n; cin>>n;
	vector<int> v; // khai bao vector nhung da co san n phan tu v[n]
	for(int i = 0; i < n; i++){
		int x; cin>>x;
		v.push_back(x);
	}
return 0;
}*/


//Ham kiem tra so nguyen to
bool is_prime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// ham de quy de liet ke tat ca cac phuong an phan tich so nguyen duong n thanh tong cac so nguyen to khac nhau
void prime_sum(int n, vector<int>& lst) {
    // Neu da tim duoc mot phuong an phan tich thanh cong, in danh sach cac so nguyen to da duoc su dung ra man hinh
    if (n == 0) {
        for (int i = 0; i < lst.size(); i++) {
            cout << lst[i] << " ";
        }
        cout << endl;
        return;
    }
    // Lay so nguyen to dau tien de bat dau phan tich
    int start;
    if (lst.empty()) {
        start = 2;
    } else {
        start = lst.back() + 1;
    }
    // Lan luot thu voi cac so nguyen nto tu lon hon so cuoi cung trong danh sach
    for (int i = start; i <= n; i++) {
        if (is_prime(i)) {
            if (i > n) {
                return;
            }
            // Them so nguyen to hien tai vao danh sach và goi de quy de phan tich so con lai
            lst.push_back(i);
            prime_sum(n - i, lst);
            // Sau khi quay lai tu de quy, loai bo so nguyen to hien tai khoi danh sach
            lst.pop_back();
        }
    }
}

int main() {
    int n;
    cout << "Nhap vao mot so nguyen duong: ";
    cin >> n;
    cout << "Cac phuong an phan tich " << n << " thanh tong cac so nguyen to:" << endl;
    // Goi hàm prime_sum de tìm các phuong án phân tích và in ra màn hình
    vector<int> lst;
    prime_sum(n, lst);
    return 0;
}