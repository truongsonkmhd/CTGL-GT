#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//==== selection sort ====
// độ phức tạp : O(n^2)
//Ideal:
// đưa phần tử nhỏ nhất chưa được sắp xếp về đầu dãy
void slectionSort(int a[] , int n){
    for(int i = 0; i < n - 1; i++){
        // dung 1 bien de luu chi so cua phan tu nho nhat
       int min_pos = i;
       // duyet tat ca phan tu dang sau phan tu hien tai va cap nhap chi so cua phan tu nho nhat
            for(int j = i + 1 ; j < n; j++ ){
                if(a[j] < a[min_pos]){
                    min_pos = j ;
                }
            }
            swap(a[i] , a[min_pos]);
    }
}

//==== bubble sort===== 
// so sánh 2 thằng kề nhau đến khi thằng lớn nhất về cuối dãy (nếu sắp xếp tăng dần)
void bubbleSort(int a[], int n){
    for(int i = 0 ; i < n - 1 ; i++){
        for(int j  = 0 ; j < n - i - 1; j++){
            if(a[j] > a[j + 1]){
                swap(a[j], a[j + 1]);
            }
        }
    }
}
// cách 2:
void bubbleSort(int a[], int n){
    int i, j;
    for(int = 0 ; i < n - 1; i++){
        for( j = n - 1 ; j  > i ; j--)
        if(a[j] < a[j - 1])
            swap(a[j], a[j - 1]);
    }
}
//==== insert sort =====
void insertSort(int a[] , int n){
    for(int i = 0 ; i < n ; i++){
           int x = a[i] , pos = i - 1;
           //sắp xếp tăng dần,
        while(pos >= 0 && a[pos] > x){
            a[pos] = a[pos + 1];
            pos--;
        }
        a[pos + 1] = x;
    }
}

//====== quick sort ========
// độ phức tạp: n*log2(n)
void quickSort(int a[], int l, int r){
    int left = l;
    int right = r;
    int pi_vot = (left+right)/2;
    do{
        while(a[i] < x); i++;
        while(a[j] > x); j--;
        if(i<=j){
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }while(x<y)

    if(left<x){
        quickSort(a,left,j);
    }

    if(right>x){
        quickSort(a,i,right);
    }
}
int main(){
    
}