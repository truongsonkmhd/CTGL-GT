#include<bits/stdc++.h>
using namespace std;

using ll = long long;

// push_back: them vao cuoi
// pop_back:  xoa phan tu o cuoi 

int main(){

    vector<int> v(3,100); // {100, 100 , 100}
    v.push_back(3); // {100, 100, 100 , 3 }
    v.push_back(2); // {100, 100, 100 , 3 , 2 }
    v.push_back(1); // {100, 100, 100 , 3 , 2, 1 }
    /*cout<<v.size()<<endl;

    for(int i = 0; i < v.size(); i++){
        cout<< v[i] << ' ';
    }

    // c2:
    for(int x : v) {
        cout<< x << ' ';
    }

    for(int &x : v){  // phải thêm "&" tham chiếu x đến v
        x = 1000;
    }

    for(int i = v.size() - 1 ; i >= 0; i--){
        cout<< v[i] << ' ';
    }

    // for each: Range base for loop 
    int a[5] = {3,1,2,4,5};
    for(int x : a){ // x se duyet qua tung phan tu cua a
        cout << x << ' ';
    }
*/
    // interator
    // v.end() -> trỏ đến giá trị sau giá trị cuốii cùng => giá trị null 
/*
    vector<int>::iterator it = v.begin(); // iterator : sẽ trỏ tới phần tử đầu tiên trong vector
    // *it : dải tham chiếu -> để lấy giá trị mà iterator trỏ tới
    ++it;
    it += 2;
    cout << *it << endl;
    --it;
    cout << *it << endl;
    it += 3;
    cout << *it << endl;
*/
    //duyệt vector bằng interator

    vector<int>::iterator it = v.begin(); // = v.begin() + 0;

    for(it = v.begin(); it != v.end(); it++){
        cout<< *it << " ";
    } 


    vector<int>::iterator it2 = v.begin()  + 4; // 100 100 100 3 2 1
        cout<< *it2 ; // it ->(trỏ đến) 3

    // nhập từ bàn phím 
    // c1:
    int n;  cin>> n; // 6
    vector<int> c(n);// có sẵn n phần tử // 2 3 4 3 8 5 
    for(int i = 0; i < n ; i++){
        cin>> c[i]; 
    }
    for(int x : c) cout<< x; // 2 3 4 3 8 5
    //c2: dài dòng hơn 
    for(int i = 0; i < n; i++){
        int tmp ; cin >> tmp;
        c.push_back(tmp);
    }
    for(auto x : c) cout<< x; // 2 3 4 3 8 5
    //

    c.clear();  // xoá toàn bộ phần tử trong mảng
    if(c.empty()) cout<<"no empty"; 
    cout<<" empty";

    // khởi tạo kiểu dữ liệu nhanh
    auto it = v.begin(); // => kiểu dữ liệu là : vector<int>::iterator ( nó sẽ dựa vào giá trị gán cho nó để xác định)
    auto x = 100; // int
    auto x = '@';
    return 0;

}