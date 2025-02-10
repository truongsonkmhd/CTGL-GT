#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
class Product{
	private:
		string id;
		string name;
		int amount;
	public:
		void printlnFo(){
			cout << id << "\t" << name << "\t" << "\t" << amount;
		}
		void Nhap(){
			cin >> id >> name >> amount;
		}
		void NhapFile(ifstream &input){
			input >> id >> name >> amount;
		}
		int sl(){
			return amount;
		}
};
class Book: public Product{
	private:
		float price;
	public:
		void printlnFo(){
			Product :: printlnFo();
			cout << "\t" << price << endl;
		}
		void Nhap(){
			Product :: Nhap();
			cin >> price;
		}
		void NhapFile(ifstream &input){
			Product :: NhapFile(input);
			input >> price;
		}
		float Gia(){
			return price;
		}
		int sl(){
			return Product :: sl();
		}
};
class BookList: public Book{
	private:
		Book a[100];
		int soluong;
	public:
		void DocFile(){
			ifstream input;
			input.open("D:\\C++\\data.txt");
//			input >> soluong;
//			for(int i=0; i<soluong; i++)
			soluong = 0;
			while(!input.eof())
				a[soluong++].NhapFile(input);
		}
		void printlnFo(){
			for(int i=0; i<soluong; i++)
				a[i].printlnFo();
		}
		void Nhap(){
			a[soluong++].Nhap();
		}
		void Sort(){
			for(int i=0; i<soluong - 1; i++)
				for(int j=i+1; j<soluong; j++)
					if(a[i].Gia() < a[j].Gia()){
						Book t = a[i];
						a[i] = a[j];
						a[j] = t;
					}
		}
		void Search(){
			for(int i=0; i<soluong; i++)
				if(a[i].sl() >= 20)
					a[i].printlnFo();
		}
		void Menu(){
			cout << "\n1. Doc file";
			cout << "\n2. Them sach";
			cout << "\n3. Tim va in ra sach co amount >= 20";
			cout << "\n4. Sap xep";
			cout << "\n0. Thoat";
			cout << "\nChuc nang: ";
		}
};

int main(){
	int k;
	BookList BL;
	do{
		BL.Menu();
		cin >> k;
		switch(k){
			case 1:{
				BL.DocFile();
				BL.printlnFo();
				break;
			}
			case 2:{
				BL.Nhap();
				break;
			}
			case 3:{
				BL.Search();
				break;
			}
			case 4:{
				BL.Sort();
				break;
			}
			case 0:{
				return 0;
				break;
			}
		}	
	}while(1);
}
