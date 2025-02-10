#include <stdio.h>
#include <string.h>


int main(){
	int size, t = 0, i, j;
	scanf("%d", &size);
	char s[257];
	fflush(stdin);
	fgets(s, sizeof(s), stdin);
	//HPPTIOMTH-CORA-NNIT-HLNV-AAHU-
	int m = strlen(s) / size;
	char a[m][size];
	
	for(j=0; j<size; j++)
		for(i=0; i<m; i++){
			if(s[t] == '-')
				a[i][j] = 32;
			else
				a[i][j] = s[t];
			t++;
		}

	int n;
	scanf("%d", &n);
	int b[n];
	for(i=0; i<n; i++)
		scanf("%d", &b[i]);
	t = 0;
	char KQ[256];
	for(i=0; i<m; i++)
		for(j=0; j<size; j++){
			s[t] = a[i][j];
			t++; 
		}
	char c[100][100];
	j = 0;
	for(i=0; i<n; i++){
		strncpy(c[j], s, b[i]);
		strcpy(s, s + b[i]);
		strcat(KQ, c[j]);
		strcat(KQ, " ");
		j++;
	}
	printf("\n%s", KQ);
}
