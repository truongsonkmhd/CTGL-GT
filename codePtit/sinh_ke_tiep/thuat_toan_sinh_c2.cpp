#include <bits/stdc++.h>
using namespace std;

int n;
int a[100];
bool thuanNghich(){
    int left = 1, right = n;
    while(left < right){
        if(a[left] != a[right]) return false;
        left++;
        right--;
    }
    return true;
}

void testCase(){
    cin>>n;
    // cau hình đầu tiên:
    for(int i = 1 ; i<=n ; i++) a[i] = 0;
    bool last = false;
    while (last == false) {
        if(thuanNghich()){
            for(int i = 1; i<=n ; i++) cout<<a[i]<<" ";
            cout<<endl;
        }  
        int index = n;
        while(index>=1 && a[index] != 0){
            a[index] = 0;
            index--;
        }
        // cta se tim dc bit ngoai cung ben phai bang 0
        if(index>=1) a[index] = 1;
        else last = true;
    }
}

int main(){
    testCase();

}