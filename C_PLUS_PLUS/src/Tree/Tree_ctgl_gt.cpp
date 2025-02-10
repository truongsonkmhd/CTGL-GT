#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

// de bai: nhap vao cay nhi phan cac so nguyen. xuat ra man hinh cac phan tu cay nhi phan
// nhap vao cay nhi phan tim kiem cac so nguyen
// khai bao cau truc 1 cai node
struct node
{
	int data; // du lieu cua node ==> du lieu ma node se luu tru
	struct node *pLeft; // Node lien ket ben trai cua cay <=> cay con trai
	struct node *pRight; // node lien ket ben phai cua cay  <=> cay con phai	
};
// typedef: dc sd de dinh nghia lai kieu du lieu co san hoac tu dinh nghia mot kieu du lieu moi 
typedef struct node NODE;
typedef NODE* TREE;
// tung nut trong cay np tim kiem la mot con tro

// khoi tao cay
void KhoiTaoCay(TREE &t){
	t = NULL ; // cay rong
}
// ham them phan tu x vao cay nhi phan
void ThemNodeVaoCay(TREE &t, int x){
	// neu cay rong
	if(t == NULL)
	{
		NODE *p = new NODE; // khoi tao 1 cai node de them vao cay
		p->data = x; // them du lieu x vao data
		p->pLeft = NULL; // them du lieu pLeft vao con tro( neu con tro la NULL)
		p->pRight = NULL; // tuong tu
		t=p; // node p chinhs la node goc <=> x chinh la node goc
	}
	else // cay co ton tai phan tu (nho qua trai lon qua phai)
	{
		// neu phan tu them vao ma nho hon node goc ==> them no vao ben trai
		if(t->data>x){
			// ham de quy
			ThemNodeVaoCay(t->pLeft, x); // duyet qua trai de them phan tu x
		}
		else if(t->data<x) // neu phan tu them vao ma lon hon nut goc thi them vao ben phai
						   // phai them else if ko phai la else khong la boi vi no khong co dieu kien bang( khong co cac ptu rieng biet)  
		{
			ThemNodeVaoCay(t->pRight, x); 
		}
	}
}
// ham xuat cay nhi phan theo NLR(node - left - right)
void Duyet_NLR(TREE t) // ko can "&" vi cay co bao nhieu ptu thi duyet bay nhieu phan tu
{
	// neu cay con phan tu thi tiep tuc duyet
	if(t != NULL){
	cout<< t->data <<" ";  // xuat du lieu trong node
	Duyet_NLR(t->pLeft)	; // duyet qua trai
	Duyet_NLR(t->pRight); // duyet qua phai
	}
}
// ham xuat cay nhi phan theo N-R-L(node - right - left)
void Duyet_NRL(TREE t) // ko can "&" vi cay co bao nhieu ptu thi duyet bay nhieu phan tu
{
	// neu cay con phan tu thi tiep tuc duyet
	if(t != NULL){
	cout<< t->data <<" ";  // xuat du lieu trong node
	Duyet_NRL(t->pRight)	; // duyet qua phai
	Duyet_NRL(t->pLeft); // duyet qua trai
	}
}
// ham xuat cay nhi phan theo L-N-R(left - node - right) => xuat ra cac phan tu tu be den lon
void Duyet_LNR(TREE t) // ko can "&" vi cay co bao nhieu ptu thi duyet bay nhieu phan tu
{
	// neu cay con phan tu thi tiep tuc duyet
	if(t != NULL){
	Duyet_LNR(t->pLeft); // duyet qua trai
	cout<< t->data <<" ";  // xuat du lieu trong node
	Duyet_LNR(t->pRight);	; // duyet qua phai
	}
}
// ham xuat cay nhi phan theo R-N-L(right - node - left) => xuat ra cac phan tu tu lon den be
void Duyet_RNL(TREE t) // ko can "&" vi cay co bao nhieu ptu thi duyet bay nhieu phan tu
{
	// neu cay con phan tu thi tiep tuc duyet
	if(t != NULL){
	Duyet_RNL(t->pRight);	; // duyet qua phai
cout<< t->data <<" ";  // xuat du lieu trong node
	Duyet_RNL(t->pLeft); // duyet qua trai
	}
}
void Duyet_LRN(TREE t) // ko can "&" vi cay co bao nhieu ptu thi duyet bay nhieu phan tu
{
	// neu cay con phan tu thi tiep tuc duyet
	if(t != NULL){
	Duyet_LRN(t->pLeft); // duyet qua trai
	Duyet_LRN(t->pRight);	; // duyet qua phai
	cout<< t->data <<" ";  // xuat du lieu trong node
	}
}
void Duyet_RLN(TREE t) // ko can "&" vi cay co bao nhieu ptu thi duyet bay nhieu phan tu
{
	// neu cay con phan tu thi tiep tuc duyet
	if(t != NULL){
	Duyet_RLN(t->pRight);	; // duyet qua phai
	Duyet_RLN(t->pLeft); // duyet qua trai
	cout<< t->data <<" ";  // xuat du lieu trong node
	}
}
/* ==================== Cay nhi phan tim kiem=====================
1. cho cay nhi phan tim kiem cac so nguyen. Viet ham dem co bao so nguyen to trong cay
*/
// ham kiem tra so ngto
// Kiem tra xem mot so có phai la so ngto hay khong
bool KiemTraSoNguyenTo(int x){
	if(x < 2) {
		return false;
	} else if(x == 2){
		return true;
	} else if(x % 2 == 0){
		return false;
	} else{
		for(int i = 3; i <= sqrt(x); i += 2){
			if(x % i == 0){
				return false;
			}
		}
	}
	return true;
}

// Dem so luong so nguyen to trong cay tim kiem
int SoLuongSoNguyenTo(TREE t, int &dem){
	if(t == NULL){
		return 0;
	}
	if(KiemTraSoNguyenTo(t->data) == true){
		dem++;
	}
	// 2 cai dong nay co tac dung la duyet qua tung cai node trong cay
	SoLuongSoNguyenTo(t->pLeft, dem);
	SoLuongSoNguyenTo(t->pRight, dem);

}
/*
Tim kiem Node trong cay nhi phan tim kiem
*/
// neu Node co ton tai trong cay thi tra ve cai node do - con khong ton tai thi tra ve NULL
// ham tim kiem mot phan tu trong cay nhi phan tim kiem
NODE* TimKiem(TREE t, int x){
if(t == NULL){ // neu cay rong hoac khong tim thay phan tu x
return NULL;
}
if(t->data == x){ // neu tim thay phan tu x
return t; // tra ve node chua phan tu x
}
else if(t->data > x){ // neu phan tu can tim nho hon node goc
TimKiem(t->pLeft, x); // duyet qua ben trai
}
else{ // neu phan tu can tim lon hon node goc
TimKiem(t->pRight, x); // duyet qua ben phai
}
	}
	
/*
-Xuat cac Node co 2 con 
-Xuat cac Node co 1 con
-Xuat cac Node La
*/
// xuat cac node co 2 con 
void Node_Co_2_Con(TREE t)
{
	if(t != NULL)
	{
		// xu ly
		if(t->pLeft != NULL && t->pRight != NULL)
		{
			cout<< t->data << " "; //xuat du lieu trong node
		}
		Node_Co_2_Con(t->pLeft); // duyet sang cay con trai cua node hien tai
		Node_Co_2_Con(t->pRight); // duyet sang cay con phai cua node hien tai
	}
}
void Node_Co_1_Con(TREE t)
{
	if(t != NULL)
	{
		// xu ly
		if((t->pLeft != NULL && t->pRight == NULL)||(t->pLeft == NULL && t->pRight != NULL));
		{
			cout<< t->data << " "; //xuat du lieu trong node
		}
		Node_Co_1_Con(t->pLeft); // duyet sang cay con trai cua node hien tai
		Node_Co_1_Con(t->pRight); // duyet sang cay con phai cua node hien tai
	}
}
void Node_La(TREE t)
{
	if(t != NULL)
	{
		// xu ly
		if(t->pLeft == NULL && t->pRight == NULL)
		{
			cout<< t->data << " "; //xuat du lieu trong node
		}
        Node_La(t->pLeft); // duyet sang cay con trai cua node hien tai
		Node_La(t->pRight); // duyet sang cay con phai cua node hien tai
	}
}



/*
Tim Max - Tim Min
*/
//=======================cach1==============================
//int MAX = INT_MIN; // gan cho bien max la gtri nho nhat cua kieu interger
//// ham tim phan tu lon nhat trong cay
//int TimMax(TREE t)
//{
//	if(t != NULL)
//	{
//		// xu li
//		if(MAX < t->data)
//		{
//			MAX = t->data; // cap nhap lai gtri cho bien MAX
//		}
//		TimMax(t->pLeft);
//		TimMax(t->pRight) ;
//	}
//}
// ========================cach2==============================
//int TimMax(TREE t)
//{
//	// neu node cha ma khong ton tai cay con trai va cay con phai 
//	if(t->pLeft == NULL && t->pRight == NULL)
//	{
//		return t->data;
//	}
//	int max = t->data; // gan gtri bien max chinh la data cua node cha
//	// neu node cha co ton tai cay con trai
//		if(t->pRight != NULL)
//	{
//		int right = TimMax(t->pLeft); // right la  bien se giu gtri cua cai node ngoai cung nhat ben phai cua node cha
//	//right = hàm tìm max (dc de quy khi nao tim duoc gtri lon nhat ben tay phai cuoi cung!)
//	//=== gtri lon nhat nam cuoi cùng ben phai, gtri nho nhat nam cuoi cung ben trai==
//		if(max < right)
//		{
//			max = right;
//		}
//	}
//	return max; // tra ve gtri lon nhat cua cay nhi phan tim kiem
//}
// cach 3- phat trien tu cach 2
int TimMax(TREE t)
{
	// neu node cha ma ko ton tai cay con phai - thi node cha nay chinh la node ngoai cung nhat cua cay con phai
	if(t->pRight == NULL)
	{
		return t->data;
	}
	return TimMax(t->pRight);
}// === tim min===
// cach 1:
//int MIN = INT_MAX;
//int TimMin(TREE t)
//{
//	if(t != NULL)
//	{
//		// xu li
//		if(MIN > t->data) // neu min ma lon hon gtri data nhap vao thi cap nhap lai gtri cho bien Max
//		{
//			MIN = t->data; // cap nhap lai gtri cho bien MAX
//		}
//		TimMin(t->pLeft);
//		TimMin(t->pRight) ;
//	}
//}
// cach 2
// =========Tim_Min===========
int TimMin(TREE t)
{
	// neu node cha ma khong ton tai cay con trai va cay con phai 
	if(t->pLeft == NULL && t->pLeft == NULL)
	{
		return t->data;
	}
	int min = t->data; // gan gtri bien max chinh la data cua node cha
	// neu node cha co ton tai cay con trai
		if(t->pLeft != NULL)
	{
		int left = TimMin(t->pLeft); // right la  bien se giu gtri cua cai node ngoai cung nhat ben phai cua node cha
	//right = hàm tìm max (dc de quy khi nao tim duoc gtri lon nhat ben tay phai cuoi cung!)
	//=== gtri lon nhat nam cuoi cùng ben phai, gtri nho nhat nam cuoi cung ben trai==
		if(min < left)
		{
			min = left;
		}
	}
	return min; // tra ve gtri lon nhat cua cay nhi phan tim kiem
}



// ham tim node the mang
/* ====== chua hieu lammm=========================
void DiTimNodeTheMang(TREE &X, TREE &Y) // Node *Y = t->pRight
{
	// duyet sang ben trai nhat cua cay con phai
	if(Y -> pLeft != NULL)
	{
		DiTimNodeTheMang(X, Y->pLeft); // tim ra node trai nhat?
		// duyet den khi nao cay con trai "tro" den null
	}
	else // tim ra duoc node trai nhat rui nèk.
	{
		X->data =  Y->data; // cap nhap cai data cua node can xoa chinh la data cua node the mang
		X = Y; // cho node X(la node ma cta se di xoa sau nay) tro den node the mang => ra khoi ham thi ta se xoa node X
		Y = Y->pRight; // ban chat cho nay chinh la gan
	}
} =======================================================
 */
// ham xoa 1 cai node bat ki trong cay nhi phan tim kiem
void XoaNode(TREE &t, int k) // k chinh la  gtri cua cai node can xoa
								// duoi main nó la :x
{	// neu nhu cay dang rong
	if( t == NULL)
	{
		return; // ket thuc ham
	}
	else
	{
		// neu data nho hon node goc
		if(k < t->data)
		{
			XoaNode(t->pLeft, k); // duyet sag nhanh trai cua cay
} else if(k > t->data)
		{
			XoaNode(t->pRight, k); // duyet sang nhanh phai cua cay
		}else //data == t->data - da tim ra cai node can xoa
		{
			NODE *X = t; // node X la node tuong trung - ti nua cta  se xoa nó
			// neu nhu nhanh trai bang NULL <=> day la cay con phai
			if(t->pLeft == NULL){
				t = t->pRight; // duyet sang phai cua cai node can xoa de cap nhap moi lien ket giua
							// node cha cua node can xoa voi node con vua node can xoa
			}else if(t->pRight == NULL){
				t = t->pLeft;// duyet sang trai cua cai node can xoa de cap nhap moi lien ket giua
							// node cha cua node can xoa voi node con vua node can xoa
		}/*else
		{
		=== chua hieu lam=====
Node co 2 con: truoc khi huy thi ta phai  di tim 1 cai node the mang cho node can xoa
- tim node the mang phai dam bao quy tac cay nhi phan tim kiem
+ Tim node trai nhat cua cay con phai( cay con phai cua cai node can xoa)
+ Tim node phai nhat cua cay con trai( cay con trai cua cai node can xoa)

			//Cach 1: Tim node trai nhat cua cay con phai(cay con phai cua cai node can xoa)
			NODE *Y = t->pRight; // NODE Y là node the mang cho node can  xoa - node nay se dam nhan
			DiTimNodeTheMang(X,Y);
		}*/
		delete X; // xoa node can xoa
	}
  }
}



// ham nhap du lieu
void Menu(TREE &t){
	while (true){
		system("cls");
	cout<< "\n\n\t\t ==========MENU=============";
	cout<< "\n1. Nhap du lieu";
	cout<< "\n2. Duyet cay NLR";
	cout<< "\n3. Duyet cay NRL";
	cout<< "\n4. Duyet cay LNR";
	cout<< "\n5. Duyet cay RNL";
	cout<< "\n6. Duyet cay LRN";
	cout<< "\n7. Duyet cay RLN";
	cout<< "\n8. Dem so luong so ngto";
	cout<< "\n9. Tim kiem phan tu trong cay";
	cout<< "\n10. Node co 2 con";
	cout<< "\n11. Node co 1 con";
	cout<< "\n12. Node La";
	cout<< "\n13. Tim Max";
	cout<< "\n14. Tim Min";
	cout<< "\n15. Xoa Node bat ki";
	cout<< "\n16. Node";
	cout<< "\n0. Ket thuc";
	cout<< "\n\n\t\t ===================";
	int luachon;
	
	cout<< "\nNhap lua chon: ";
	cin>>luachon;
	if(luachon<0||luachon > 15){
		cout<< "\n Lua chon khong hop ke";
		system("pause");
	} else if(luachon == 1){
		int x;
		cout<< "\nNhap so nguuen x:";
		cin>>x;
		ThemNodeVaoCay(t,x) ;
	} else if(luachon == 2){
		cout<<"\n\t\t Duyet cay theo NLR\n";
		Duyet_NLR(t);
		system("pause");
	}
	else if(luachon == 3){
		cout<<"\n\t\t Duyet cay theo NRL\n";
		Duyet_NLR(t);
		system("pause");
	}
	else if(luachon == 4){
		cout<<"\n\t\t Duyet cay theo LNR\n";
		Duyet_LNR(t);
		system("pause");
	}
	else if(luachon == 5){
		cout<<"\n\t\t Duyet cay theo RNL\n";
		Duyet_RNL(t);
		system("pause");
	}
	else if(luachon == 6){
		cout<<"\n\t\t Duyet cay theo LRN\n";
		Duyet_LRN(t);
		system("pause");
	}
	else if(luachon == 7){
		cout<<"\n\t\t Duyet cay theo RLN\n";
		Duyet_RLN(t);
		system("pause");
	}
	else if(luachon == 8){
		int dem = 0;
		SoLuongSoNguyenTo(t, dem);
		cout<<"\n\t\t Dem so luong so ngto:\n" << dem << endl;
		system("pause");
	}
	else if(luachon == 9)
	{
		int x;
		cout<< " Nhap phan tu can tim kiem: ";
		cin>>x;
		NODE *p = TimKiem(t,x);
		if(p == NULL)
		{
			cout<< "\nPhan tu" << x << "khong ton tai trong cay";
		}
		else 
		{
			cout<<"\Phan tu " << x << " co ton tai tren cay";
		}
		system("pause");
	}
	else if(luachon == 10)
	{
		cout<<"\n\t NODE co 2 con: ";
		Node_Co_2_Con(t);
		system("pause");
	}
	else if(luachon == 11)
	{
		cout<<"\n\t NODE co 1 con: ";
		Node_Co_1_Con(t);
		system("pause");
	}
	else if(luachon == 12)
	{
		cout<<"\n\t NODE La: ";
		Node_La(t);
		system("pause");
	}
	else if(luachon == 13)
	{
		cout<<"\n\t Tim max la: "<< TimMax(t);
system("pause");
	}
	else if(luachon == 14)
	{
		cout<<"\n\t Tim min la: "<< TimMin(t);
		system("pause");
	}
	else if(luachon == 15)
	{
		int o;
		cout<<"\n\t Xoa node bat ki la: "; cin>>o;
		XoaNode(t,o);
		system("pause");
	}
	else{
		break;
	}
 }

} 
int main(){
	TREE t;
	KhoiTaoCay(t);
	Menu(t);
	
	system("Pause");
	return 0;
}
