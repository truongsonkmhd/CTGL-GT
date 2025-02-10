/*//bai9
#include <iostream>
#include <math.h>
using namespace std;
int main(){
	int l,n,h;
	float s=0;
	do{
			cout<<"Nhap lan luot l,n,h:";cin>>l>>n>>h;
	}while(l<=0||n<=0||h<0);
	s=((l+n)*h)*1.0/2;
	cout<<"Dien tich hinh thang la"<<s;
	return 0;
}
*/
/*#include <iostream>
#include <math.h>
using namespace std;
int main(){
	int l,n,h;
	float s=0;
	do{
			cout<<"Nhap lan luot l,n,h:";cin>>l>>n>>h;
	}while(l<=0||n<=0||h<0);
	s=((l+n)*h)*1.0/2;
	cout<<"Dien tich hinh thang la"<<s;
	return 0;
}
	*/
/*#include <iostream>
#include <math.h>
using namespace std;
int main(){
	int r;
	float p=0;
	do{
			cout<<"Nhap r:";cin>>r;
	}while(r<=0);
	p=2*3.14*r*r*1.0;
	cout<<"Dien tich hinh tron"<<p;
	return 0;
}*/
/*//bai11
#include <iostream>
using namespace std;
int main(){
    int a,b,c;
    cout<<"Nhap lan luot a,b,c:";cin>>a>>b>>c;
    int max=a,min=a;
    if(b>max) { max=b; }
    if(c>max) { max=c; }
    if(b<min) { min=b; }
    if(c<min) { min=c; }
    cout<<"max la:"<<max<<endl;
    cout<<"min la:"<<min<<endl;
    return 0;
}*/
//bai12
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b;
    cout << "Nhap a va b: ";
    cin >> a >> b;
    
    if (a == 0) {
        if (b == 0) {
            cout << "Phuong trinh co vo so nghiem." << endl;
        } else {
            cout << "Phuong trinh vo nghiem." << endl;
        }
    } else {
        double x = -b / a;
        if (x > 0) {
            cout << "PT co nghiem x > " << x << endl;
        } else {
            cout << "Pt co nghiem x < " << x << endl;
        }
    }
    
    return 0;
}
/* //bai 13
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int a,b,c;
	cout<<"Nhap lan luot a, b, c:";
	cin>>a>>b>>c;

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
	return 0;
}*/

//bai 14
/*#include <iostream>
using namespace std;

int main() {
    int chisodientieuthu;
    int  chisodientieuthudinhmuc = 100;
    int thanhtien;
    
    cout << "nhap  chi so dien tieu thu: ";
    cin >> chisodientieuthu;
    
    if (chisodientieuthu <= chisodientieuthudinhmuc) {
        thanhtien = chisodientieuthu * 500;
    } else {
        thanhtien = chisodientieuthudinhmuc * 500 + (chisodientieuthu - chisodientieuthudinhmuc) * 800;
    }
    
    cout << "T?ng ti?n di?n h? gia dình ph?i tr? là " << thanhtien << "d." << endl;
    
    return 0;
}
*/
/*#include <iostream>
using namespace std;

int main() {
	int doanhso;
	float thanhtien;
	cout<<"nhap doanh so thu dc:"; cin>>doanhso;
	if(doanhso<=100){
		thanhtien=doanhso*0.05;
		cout<<"Doanh so <=100 thi so tien thu duoc la:"<<thanhtien<<" trieu dong"<<endl;
	} else if(doanhso<=300){
		thanhtien=100*0.05 + (doanhso-100)*0.1;
		cout<<"Doanh so <= 300 thi so tien thu duoc la:"<<thanhtien<<" trieu dong"<<endl;
	} else {
		thanhtien=100*0.05 + 200*0.1 + (doanhso-300)*0.2;
		cout<<"Doanh so lon hon 300 thi so tien thu duoc la:"<<thanhtien<<" trieu dong"<<endl;
	}
	return 0;
}
*/
