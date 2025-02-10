#include<iostream>
#include <map> 
#include <set>
#include <string>
#include <algorithm>
using namespace std;
////=======Bai_1==============
////de bai:
//// dem so luong kha nhau trong mang so nguyen
//// dong dau tien la so luong test case T (1<=T<=100)
////cach1: (dung set)
//int main(){
//	//int t; cin>>t;
///*	while(t--){
//		int n; cin>>n;
//		set<int> se;
//		for(int i = 0 ; i < n ; i++){
//			int x; cin>>x; // luu bien tam
//			se.insert(x);
//		} 
//		cout<<se.size()<<endl;
//	}*/
////cach2: (dung map)
///*while(t--){
//		int n; cin>>n;
//		map<int, bool> mp;
//		for(int i = 0 ; i < n ; i++){
//			int x; cin>>x; // luu bien tam
//			mp[x] = true;
//		} 
//		cout<<mp.size()<<endl;
//	}*/
///*while(t--){ // de lap lai qua trinh nhap mang vi minh nhap 2 test case
//		int n; cin>>n;
//		int a[n];
//		for(int &x : a){
//			cin>>x; 
//			sort(a, a+n);
//			int ans=1;
//			for(int i = 1; i < n; i++){
//				if(a[i]!=a[i-1]){
//				cout<<"So phan tu khac nhau la: "<<ans<<endl;
//				}
//			}
//		} 
//	}*/
////==========================bai_2====================
////de bai: cho mot mnag so nguyen gom n phan tu, voi moi truy van hay kiem tra xem mot so nao do co nam trong
////mang hay khong?
////-dong dau tien la so luong test case T
//	return 0;
//}
// ==== su dung sap xep sau do tim kiem nhi phan ====
//int main() {
//    cout << "Nhap so mang: ";
//    int t; cin >> t;
//    while (t--) {
//        cout << "Nhap so phan tu cua mang: ";
//        int n; cin >> n;
//        int* a = new int[n]; // su dung mang dong(de cap phat them n mang)
//        for (int i = 0; i < n; i++) {
//            cout << "Nhap phan tu thu " << i+1 << ": ";
//            cin >> a[i];
//        }
//        sort(a, a + n); //trong do, 'a' la dia chi cua phan tu dau tien trong mang la 'a+n' la dia chi cua phan tu 
//        //ke tiep cuoi mang. do vay, 'sort(a, a+n)' se sap xep cac phan tu tu 'a' den 'a+n-1' theo thu tu tang dan
//        cout << "Nhap so lan tim kiem: ";
//        int q; cin >> q;
//        while (q--) {
//            cout << "Nhap phan tu can tim kiem: ";
//            int x; cin >> x;
//            if (binary_search(a, a+n, x)) {
//            	//trong do, 'a' la dia chi cua phan tu dau tien trong mang la 'a+n' la dia chi cua phan tu 
//        //ke tiep cuoi mang. do vay, ham tren de tim kiem x tu cac phan tu tu 'a' den 'a+n-1' 
//                cout << "Yes\n";
//            }
//            else {
//                cout << "NO\n";
//            }
//        }
//        delete[] a; // giai phong mang dong
//    }
//===============su dung "set" ===================
//int main(){
//	cout << "Nhap so mang: ";
//    int t; cin >> t;
//	while(t--){
//		cout << "Nhap so phan tu cua mang: ";
//        int n; cin >> n;
//		int* a = new int[n]; // su dung mang dong(de cap phat them 1 mang)
//		set<int> se;
//		for(int i = 0; i < n; i++){
//			int x; cin>>x;
//			se.insert(x);
//		}
//		int q; cin>>q;
//		while(q--){
//			int x; cin>>x;
//			if(se.count(x)>=1){ // dem phan tu co trong mang hay khong
//			cout<<"Yes\n";
//			}else cout<<"NO\n";
//		}
//		delete[] a;
//	}
//===============su dung "map" ===================
int main(){
	cout << "Nhap so mang: ";
    int t; cin >> t;
	while(t--){
		cout << "Nhap so phan tu cua mang: ";
        int n; cin >> n;
		int* a = new int[n]; // su dung mang dong(de cap phat them 1 mang)
		map<int, bool> mp;
		for(int i = 0; i < n; i++){
			int x; cin>>x;
			mp[x] = true;
		}
		int q; cin>>q;
		while(q--){
			int x; cin>>x;
			if(mp.count(x)>=1){ // dem phan tu co trong mang hay khong
			cout<<"Yes\n";
			}else cout<<"NO\n";
		}
		delete[] a;
	}

    return 0;
}
