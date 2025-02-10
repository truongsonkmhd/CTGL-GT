#include <iostream>
using namespace std;
//sap xep chen truc tiep<insertionSort>
/*	void insertionSort(int a[], int n){
	for(int i = 1 ; i < n; i++){
		int x=a[i];
		int pos = i-1;
		while(pos>=0 && a[pos]>x){
			a[pos+1]=a[pos];
			pos--;
			}
			a[pos+1]=x;
		}
	}*/
	
	
//sap xep lua chon<selectionSort>(do phuc tap thuat toan la O(n^2))
	/*int swap(int &a,int &b){
	int t=a;
	a=b;
	b=t;
	}
	void selectionSort(int a[], int n){
	for(int k=0; k<n-1; k++){ // vi luc nào sap xep xong cx thua ra 1 ptu
		int min_pos=k;
			for(int i=k+1; i<n; i++){
				if(a[i]<a[min_pos])
				min_pos=i;
				swap(a[min_pos],a[k]);	
		}
	}
}*/


//Sap xep chen (do phuc tap thuat toan la O(n^2))
	/*void insertionSort(int a[], int n){
		for(int i = 1; i < n; i++){
				int x = a[i];//phan tu muon chen vao mang
				int pos	= i - 1;
			while(pos >= 0 && a[pos] > x){
				a[pos + 1] = a[pos];
				pos--;
		}
		a[pos + 1] = x;
	}
}*/


//sap xep trao doi(interchangeSort)
//	void interchangeSort(int a[], int n){
	/*for(int i = 0 ; i < n-1 ; i++){
		for(int j =  i + 1 ; j < n; j++){
			if(a[i]>a[j])
			swap(a[i], a[j]);
			}
		}
	}*/
	
	
//sap xep nhanh(quickSort)
/*void quickSort(int a[], int left, int right){
    int pivot = a[(left+right)/2];
    int l = left, r = right;
    do{
        while(a[l]<pivot)
            l++;
        while(a[r]>pivot)
            r--;
        if(l<=r){
            swap(a[l],a[r]);
            l++;
            r--;
        }
    } while(l<=r);
    if(left < r)
        quickSort(a, left,r);
    if(l<right)
        quickSort(a,l,right);
}*/

int* merge(int *a, int n1, int *b, int n2){
    int *c = new int[n1+n2];
    int i = 0, j = 0, dem = 0;
    while(i < n1 && j < n2){
        if(a[i] < b[j])
            c[dem++] = a[i++];
        else
            c[dem++] = b[j++];
    }
    while(i < n1)
        c[dem++] = a[i++];
    while(j < n2)
        c[dem++] = b[j++];
    return c;
}

int main() {
    int a[] = {3,4,5,7,10,9,88,-88};
    int b[] = {2, 5, 6};
    int *c = merge(a,8,b,3);
    for(int i = 0; i < 11; i++)
        cout << c[i] << "\t";
    cout << endl;
    delete[] c;

	/*	selectionSort(a, n);
	for(int i = 0; i<n; i++)
	cout<<a[i]<<"\t";
	cout<<endl;
	
	insertionSort(a, n);
	for(int i = 0; i<n; i++)
	cout<<a[i]<<"\t";
	cout<<endl;
	*/
/*	insertionSort(a,n);
	for(int i = 0; i<n; i++)
	cout<<a[i]<<"\t";
	cout<<endl;
	*/
	
    /*quickSort(a, 0 ,n-1);
    for(int i = 0; i<n; i++){
        cout<<a[i]<<"\t";
    }
    cout<<endl;*/
    
    /*interchangeSort(a,n);
	for(int i = 0; i<n; i++)
	cout<<a[i]<<"\t";
	cout<<endl;*/
return 0;
}

