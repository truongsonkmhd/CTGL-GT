#include <stdio.h>


int main(){
	int n, i, j = 0;
	printf("---------Thong tin cua hang---------\n");
	printf("Nhap so luong tivi: "); scanf("%d", &n);
	float a[n], sum = 0, max;
	printf("\nNhap kich co cua ti vi thu %d: ", 0);
	scanf("%f", &a[0]);
	max = a[0];
	sum += a[0];
	for(i=1; i<n; i++){
		printf("\nNhap kich co cua ti vi thu %d: ", i);
		scanf("%f", &a[i]);
		if(a[i] > max){
			max = a[i];
			j = i;
		}
		sum += a[i];
	}
	float tb = sum / n;
	printf("---------Xuat thong tin tivi---------\n");
	printf("So luong tivi: %d\n", n);
	printf("Kich co trung binh: %0.2f\n", tb);
	printf("Vi tri tivi co kich co lon nhat: %d\n", j);
}
