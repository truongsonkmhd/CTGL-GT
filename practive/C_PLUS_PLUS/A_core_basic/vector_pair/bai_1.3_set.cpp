#include<bits/stdc++.h>
using namespace std;


// set:  
/*
- Loại bỏ phần tử trùng,
- Sắp xếp các phần tử trùng,
- không có chỉ số vì nó cấu tạo từ 1 cây
// các phưogn thưucs của set đều có độ phức tạp là log(n)
- .insrert()
- .find()
- .eraer()
- .count()
*/
int main() {
    set<int> se ;
    se.insert(1);
    se.insert(4);
    se.insert(6);
    se.insert(7);
    se.insert(2);
    se.insert(0);
    se.insert(4);
    cout<<se.size()<<endl;
    //set cũng có iterator giống vector và array
    for(int x : se){
        cout<<x<<endl;
    }

//   for (std::vector<int>::iterator it = se.begin(); it != se.end(); ++it) 
    for(auto it =  se.begin() ; it!=se.end(); it++){
        cout<<*it;
    }

    if(se.find(5) != se.end()){
        cout<<" FOUND \n";
    }else{
        cout<<" NOT FOUND\n";
    }


}