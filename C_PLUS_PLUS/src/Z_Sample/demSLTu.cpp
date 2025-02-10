#include <stdio.h>
#include <string.h>

void YC(char *a, int *SLtu, int *SLKT){
	if(a[strlen(a) - 1] == '\n')
		a[strlen(a) - 1] = '\0';
    *SLtu = 0;
    int i;
    for(i=0; i<strlen(a) - 1; i++)
        if(a[i] == 32 && a[i+1] != 32)
            *SLtu += 1;
    *SLKT = strlen(a) - *SLtu;
    *SLtu += 1;
}

int main(){
    char a[1000];
    int SLtu, SLKT;
    printf("Nhap ten: "); fgets(a, sizeof(a), stdin);
    YC(a, &SLtu, &SLKT);
    printf("So luong ki tu trong %s la: %d\n", a, SLKT);
    printf("So luong tu trong %s la: %d", a, SLtu);
}
