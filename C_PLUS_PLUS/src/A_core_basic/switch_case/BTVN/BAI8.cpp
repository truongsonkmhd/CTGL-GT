#include <iostream>
#include <string>
using namespace std;

void hangchuc(int number){
    switch (number / 10) {
        case 2: cout<<"hai muoi"; break;
        case 3: cout<<"ba muoi"; break;
        case 4: cout<<"bon muoi"; break;
        case 5: cout<<"nam muoi"; break;
        case 6: cout<<"sau muoi"; break;
        case 7: cout<<"bay muoi"; break;
        case 8: cout<<"tam muoi"; break;
        case 9: cout<<"chin muoi"; break;
    }
}
void hdv(int number){
    switch (number % 10) {
        case 1: cout<<" mot"; break;
        case 2: cout<<" hai"; break;
        case 3: cout<<" ba"; break;
        case 4: cout<<" bon"; break;
        case 5: cout<<" nam"; break;
        case 6: cout<<" sau"; break;
        case 7: cout<< " bay"; break;
        case 8: cout<<" tam"; break;
        case 9: cout<<" chin"; break;
    }
}

int main() {
    int number;
    cout<<"Nhap so tien can doi: "; cin>>number;
    cout<<"so tien can doi doc bag chu la: ";
    hangchuc(number);
    hdv(number);
    cout<<endl;
    return 0;
}


