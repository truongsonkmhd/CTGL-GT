/*// ktra xem ma tran chua so "chan" hay "le"
#include <bits/stdc++.h>
using namespace std;
void nhapmang(int a[100][100], int m,int n ){
 for(int i=0; i< n; i++){
		for(int j=0 ; j< m; j++){
			cin>>a[i][j];
		}
	}
}
void xuatmang(int a[100][100], int m,int n){
 for(int i=0;i<m;i++)
 for(int j=0;j<n;j++){
  cout<<a[i] [j]<<"\t";
 }
}
bool check(int a[100][100],int n,int m){
	for(int i=0; i< n; i++){
		for(int j=0 ; j< m; j++){
		    if( a[i][j] % 2 == 0){
		    	return false;
			}
		}
	}
	return true;
}
void tongHangChan(int a[100][100],int n,int m){
	for(int i=0;i<m;i++){
		if(i%2==0);
		int sum = 0;
 for(int j=0;j<n;j++){
 	
  sum+=a[i][j];
 }
 cout<<"Tong cua hang "<< i <<" :"<<sum<<endl;
 }
}
void Maxcot(int a[100][100],int n,int m,int y){
	int Max = 0;
	for(int i = 0; i< m ;i++){
		if(Max<a[i][y])Max = a[i][y];
	}
	cout<<"Max cua cot thu "<<y<<":"<<Max<<endl;
}
int main(){
	int n,m; cin>>n>>m;
	int a[100][100];
	tongHangChan(a,n,m);
	maxcot(a,n,m,1);
	if(check(a,n,m)){
		cout<<" YES";
	}
	else cout<<" NO";
	return 0;
}*/
/*#include<math.h>
#include<iomanip>
#define max 50 // dinh nghia hang 
using namespace std;
void nhapmang(int a[max] [max], int m,int n ){
 for(int i=0; i< n; i++){
		for(int j=0 ; j< m; j++){
			cin>>a[i][j];
		}
	}
}
void xuatmang(int a[max] [max], int m,int n){
 for(int i=0;i<m;i++)
 for(int j=0;j<n;j++){
  cout<<a[i] [j]<<"\t";
 }
}
void chisole(int a[max] [max], int m, int n){
 for(int i=0;i<m;i++)
  if(i%2 == 1){
   for(int j=0;j<n;j++)
   cout<<a[i] [j]<<"\t";
   cout<<endl;
  }
}
void chisochan(int a[max] [max], int m, int n){
 for(int i=0;i<m;i++)
  if(i%2 == 0){
   for(int j=0;j<n;j++)
   cout<<a[i] [j]<<"\t";
   cout<<endl;
  }
}
int main(){
 int a[max][max],m,n;
 cout<<"Nhap so hang m = "; cin>>m;
 cout<<"Nhap so hang n = ", cin>>n;
 nhapmang(a,m,n);
 xuatmang(a,m,n);
 chisole(a,m,n);
 chisochan(a,m,n);
 return 0;
}*/
// 1. Nhap, Xuat
#include <iostream>

using namespace std;

const int ROWS = 3;
const int COLS = 4;

void inputArray(int a[][COLS], int rows, int cols) {
    cout << "Nhap mang: \n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }
}

void outputArray(int a[][COLS], int rows, int cols) {
    cout << "Mang: \n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int a[ROWS][COLS];
    inputArray(a, ROWS, COLS);
    outputArray(a, ROWS, COLS);
    return 0;
}
//2.Tính tong , hieu cua cac phan tu mang

int sumArray(int a[][COLS], int rows, int cols) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += a[i][j];
        }
    }
    return sum;
}
//3.Dem so nguyen trong mang 2 chieu

/*#include <iostream>

using namespace std;

const int ROWS = 3;
const int COLS = 4;

int countIntegers(int a[][COLS], int rows, int cols) {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (a[i][j] % 1 == 0) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int a[ROWS][COLS] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    cout << "So nguyen trong mang: " << countIntegers(a, ROWS, COLS) << endl;
    return 0;
}
bool hasOdd(int matrix[][n], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(matrix[i][j] % 2 == 1) {
                return true;
            }
        }
    }
    return false;
}*/
//5.Tim kiem so lon nhat trong mang
//#include <iostream>
//using namespace std;
//
//int main() {
//  int arr[] = {5, 10, 7, 20, 3};
//  int n = sizeof(arr)/sizeof(arr[0]);
//  
//  int max_num = arr[0]; // gi? s? ph?n t? d?u tiên là l?n nh?t
//
//  for (int i = 1; i < n; i++) {
//    if (arr[i] > max_num) { // n?u ph?n t? hi?n t?i l?n hon s? l?n nh?t hi?n t?i
//      max_num = arr[i]; // c?p nh?t l?i s? l?n nh?t
//    }
//  }
//
//  cout << "So lon nhat trong mang la: " << max_num << endl;
//
//  return 0;
//}

//6.Hoán vi 2 dòng trên ma tran:
/*#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

// Hàm nh?p ma tr?n
void NhapMaTran(int a[][MAX_SIZE], int m, int n) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }
}

// Hàm in ma tr?n
void InMaTran(int a[][MAX_SIZE], int m, int n) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

// Hàm hoán v? hai dòng trong ma tr?n
void HoanViHaiDong(int a[][MAX_SIZE], int m, int n, int d1, int d2) {
    for(int j = 0; j < n; j++) {
        int temp = a[d1][j];
        a[d1][j] = a[d2][j];
        a[d2][j] = temp;
    }
}

int main() {
    int m, n;
    int a[MAX_SIZE][MAX_SIZE];

    cout << "Nhap so hang m = ";
    cin >> m;
    cout << "Nhap so cot n = ";
    cin >> n;

    cout << "Nhap ma tran:\n";
    NhapMaTran(a, m, n);

    cout << "Ma tran ban dau:\n";
    InMaTran(a, m, n);

    // Hoan vi hai dong
    int d1, d2;
    cout << "Nhap hai dong can hoan vi (0 <= d1, d2 < m): ";
    cin >> d1 >> d2;
    HoanViHaiDong(a, m, n, d1, d2);

    cout << "Ma tran sau khi hoan vi hai dong:\n";
    InMaTran(a, m, n);

    return 0;
}
*/
//7.Xóa 1 dòng trên ma tran:
//Ðe xóa mot dòng trên ma tran, ta can di chuyan tat ca các dòng  phía duoi dòng can xóa lên trên mot dòng và giam so luong dòng cua ma tran di m?t.
/*#include <iostream>
#include <vector>

using namespace std;

int main() {
    int row_index = 2; // ch? s? hàng c?n xóa (b?t d?u t? 0)
    vector<vector<int>> matrix = {{1, 2, 3},
                                  {4, 5, 6},
                                  {7, 8, 9}};

    int n_rows = matrix.size();
    int n_cols = matrix[0].size();

    // T?o m?t ma tr?n m?i v?i s? hàng ít hon 1 hàng so v?i ma tr?n g?c
    vector<vector<int>> new_matrix(n_rows - 1, vector<int>(n_cols));

    // Sao chép các hàng t? ma tr?n g?c sang ma tr?n m?i ngo?i tr? hàng c?n xóa
    int new_row_index = 0;
    for (int i = 0; i < n_rows; i++) {
        if (i != row_index) {
            for (int j = 0; j < n_cols; j++) {
                new_matrix[new_row_index][j] = matrix[i][j];
            }
            new_row_index++;
        }
    }

    // In ra ma tr?n m?i sau khi xóa hàng
    for (int i = 0; i < new_matrix.size(); i++) {
        for (int j = 0; j < new_matrix[0].size(); j++) {
            cout << new_matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}*/

//4. kiem tra ma tran co ton tai so le hay khong
/*#include <iostream>
using namespace std;

bool isOddExist(int matrix[][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] % 2 != 0) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    const int MAX = 100;
    int matrix[MAX][MAX];
    int rows, cols;

    // Input the matrix size
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    // Input the matrix elements
    cout << "Enter the matrix elements:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    // Check if odd exists
    if (isOddExist(matrix, rows, cols)) {
        cout << "The matrix has odd number(s)." << endl;
    } else {
        cout << "The matrix does not have any odd numbers." << endl;
    }

    return 0;
}*/

//5. sap xep cac phan tu theo thu tu tang dan tu trai sang phai
void sortRow(int matrix[][N], int row, int cols) {
    for (int i = 0; i < cols - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < cols; j++) {
            if (matrix[row][j] < matrix[row][minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(matrix[row][i], matrix[row][minIndex]);
        }
    }
}
///Xay dung ma tran B tu ma tran A sao cho B[i][j] = abs (A[i][j])?
/*
#include <iostream>
#include <cmath>

using namespace std;

int main() {
   int n, m;
   cin >> n >> m; // nh?p s? dòng và s? c?t c?a ma tr?n A
   int A[n][m], B[n][m];
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         cin >> A[i][j]; // nh?p giá tr? cho ph?n t? (i, j) c?a ma tr?n A
         B[i][j] = abs(A[i][j]); // tính giá tr? tuy?t d?i c?a ph?n t? (i, j) và gán cho ph?n t? tuong ?ng c?a ma tr?n B
      }
   }
   // in ra ma tr?n B
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         cout << B[i][j] << " ";
      }
      cout << endl;
   }
   return 0;
}
*/

//7. tinh tong cac phan tu tren duong cheo phu
/*#include <iostream>
using namespace std;

int main() {
   const int ROWS = 3;
   const int COLS = 3;
   int matrix[ROWS][COLS] = {{9, 2, 5},
                             {7, 1, 8},
                             {3, 6, 4}};
   int temp;

   // S?p x?p các ph?n t? trong ma tr?n theo th? t? tang d?n t? trái sang ph?i
   for(int i = 0; i < ROWS; i++) {
      for(int j = 0; j < COLS-1; j++) {
         for(int k = 0; k < COLS-j-1; k++) {
            if(matrix[i][k] > matrix[i][k+1]) {
               temp = matrix[i][k];
               matrix[i][k] = matrix[i][k+1];
               matrix[i][k+1] = temp;
            }
         }
      }
   }

   // In ma tr?n dã s?p x?p
   for(int i = 0; i < ROWS; i++) {
      for(int j = 0; j < COLS; j++) {
         cout << matrix[i][j] << " ";
      }
      cout << endl;
   }

   return 0;
}
*/


