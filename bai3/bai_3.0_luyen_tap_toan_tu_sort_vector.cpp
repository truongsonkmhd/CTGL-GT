#include <bits/stdc++.h>
using namespace std;
/*
//Cho mảng a[] gồm N phần tử, bạn hãy sắp xếp các phần tử trong mảng theo yêu cầu :
-Sắp xếp số lượng chữ số chẵn xuất hiện trong số tăng dần, nếu 2 số còn cùng số lượng 
chữ số chẵn thì số nhỏ hơn in trước
-Sắp xếp theo số lượng chữ số lẻ xuất hiện trong số ban đầu tăng dần, nếu 2 số có 
cùng số luọng chữ số lẻ thì số nào xuất hiện trước sẽ in ra trước.(dùng stable_sort) (Bài này các bạn làm
theo mảng và vector để luyện thêm) => done 
*/ 
int chan(int n){
    int dem = 1;
    while(n){
        if(n%2==0){
            dem++;
            n/=10; 
        } 
    }
    return dem;
}

int le(int n){
    int dem = 1;
    while (n)
    {
       if(n%2!=0){
        dem++;
        n/=10;
       } 
    }
    
}

int le(int n){}

bool cmp1(int a, int b){
    if(chan(a) != chan(b)){
        return chan(a) < chan(b);
    }
    return a < b;

}

int main(){

}