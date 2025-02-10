#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int a,b,c,luachon;
    chon:
    cout<<"Nhap vao lan luot 3 so: "<<endl; cin>>a>>b>>c; cout<<endl;
    cout<<"1. Kiem tra a,b,c co tao thanh 3 canh cua tam giac hay khum"<<endl;
    cout<<"2. Giai phuong trinh Bac 2"<<endl;
    cout<<"3. Tim so lon nhat, nho nhat"<<endl;
    cout<<"0. Out game"<<endl;
    cout<<"Nhap lua chon: "; cin>>luachon;

    switch(luachon){
    	goto chon;
        case 1:
        if((a + b) > c && (a + c) > b && (b + c) > a){
            cout<<"Chac chan se tao thanh 3 canh cua tam giac!!"<<endl;
        } else {
            cout<<"Khong Thoa Man!!"<<endl;
        }
        break;
        case 2:
        float delta, x, x1, x2;
        if(a == 0){
            if(b == 0){
                if(c == 0){
                    cout<<"Phuong trinh vo so nghiem"<<endl;
                } else {
                    cout<<"Phuong trinh vo nghiem"<<endl;
                }
            } else {
                x = -c / b;
                cout<<"Phuong trinh co nghiem duy nhat: "<<x<<endl;
            }
        } else {
            delta = b * b - 4 * a * c;
            if(delta < 0){
                cout<<"Phuong trinh vo nghiem"<<endl;
            } else if(delta == 0){
                x = -b / (2 * a);
                cout<<"Phuong trinh co nghiem kep: "<<x<<endl;
            } else {
                x1 = (-b - sqrt(delta)) / (2 * a);
                x2 = (-b + sqrt(delta)) / (2 * a);
                cout<<"Phuong trinh co 2 nghiem phan biet: "<<x1<<" va "<<x2<<endl;
            }
        }
        break;
        case 3:
        int largest = a, smallest = a;
        if(b > largest){
            largest = b;
        }
        if(c > largest){
            largest = c;
        }
        if(b < smallest){
            smallest = b;
        }
        if(c < smallest){
            smallest = c;
        }
        cout<<"Gia tri lon nhat la: "<<largest<<endl;
        cout<<"Gia tri nho nhat la: "<<smallest<<endl;
        break;
    }
  
    return 0;
}

