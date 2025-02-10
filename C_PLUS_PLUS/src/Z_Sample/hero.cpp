#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int FBNC(int n);
int Prime(int n);
int Type(int TYPE);
int Dame(int ATK, int TYPE, int eDEF, int eTYPE);
int Q_1(int *HP, int *ATK, int* DEF, int* TYPE, int n, int Tuong[][4]);
int solo(int HP, int ATK, int DEF, int TYPE, int Tuong[4]);
int power(int *Tuong);
int chooseBestOpponent(int HP, int ATK, int DEF, int TYPE, int n, int Tuong[][4]);
void Delete(int *n, int Tuong[][4], int x);
int Q_2(int *HP, int *ATK, int* DEF, int* TYPE, int *n, int Tuong[][4]);
struct Gladiator{
	int HP;
	int ATK;
	int DEF;
	int TYPE;
	int nWin;
	int nLose;
};
char* Name(Gladiator x, char* first_name);

int main(){
//	int HP, ATK, DEF, TYPE;
//	scanf("%d%d%d%d", &HP, &ATK, &DEF, &TYPE);
//	int n, i = 0;
//	scanf("%d", &n);
//	int Tuong[100][4];
//	for(i=0; i<n; i++)
//		scanf("%d%d%d%d", &Tuong[i][0], &Tuong[i][1], &Tuong[i][2], &Tuong[i][3]);
	
//	int kq = Q_1(&HP, &ATK, &DEF, &TYPE, n, Tuong);
//	if(kq == 1)
//		printf("You have arrived at Rome\n");
	
	
//	int kq = Q_2(&HP, &ATK, &DEF, &TYPE, &n, Tuong);
//	if(kq == 1)
//		printf("You have arrived at Rome\n");
//	else
//		printf("Afraid of losing your life, you run back to your village and become");

	int n;
	scanf("%d", &n);
	Gladiator a[n];
	char first_name[100][100];
	for(int i=0; i<n; i++){
		scanf("%d%d%d%d%d%d%s", &a[i].HP, &a[i].ATK, &a[i].DEF, &a[i].TYPE, &a[i].nWin, &a[i].nLose, first_name[i]);
	}
	for(int i=0; i<n; i++)
		printf("%s\n", Name(a[i], first_name[i]));
	return 0;
}
int FBNC(int n){
	int x = 1, y = 1, z = 2;
	if(n == 1 || n == 2)
		return 1;
	while(z < n){
		x = y;
		y = z;
		z = x + y;
	}
	return z == n;	
}
int Prime(int n){
	int i;
	for(i=2; i<=n/2; i++)
		if(n % i == 0)
			return 0;
	return n > 1;
}
int Type(int TYPE){
	int fbnc = FBNC(TYPE), prime = Prime(TYPE);
	if(fbnc == 0 && prime == 0)
		return 0; // loai thuong
	if(fbnc == 0 && prime == 1)
		return 1; // loai nguyen to
	if(fbnc == 1 && prime == 0)
		return 2; // loai fbnc
	return 3; // loai dac biet
}
int Dame(int ATK, int TYPE, int eDEF, int eTYPE){
	// 3 v?i snt
	int a = Type(TYPE);
	int b = Type(eTYPE);
	int dame = ATK - eDEF;
	if(dame <= 0)
		dame = 1;
	if((a == 1 || a == 2) && b == 0)
		dame = dame*2;
	else if((a == 2 || a == 3) && b == 1)
		dame = dame*2;
	else if(a == 3 && b == 2)
		dame = dame*2;
	else if(a == 0 && b == 3)
		dame = dame*3;
	return dame;
}
int Q_1(int *HP, int *ATK, int* DEF, int* TYPE, int n, int Tuong[][4]){
	int i;
	for(i=0; i<n; i++){
		printf("You starting stats: %d %d %d %d\n", *HP, *ATK, *DEF, *TYPE);
		printf("The fighter #%d's starting stats: %d %d %d %d\n", i + 1, Tuong[i][0], Tuong[i][1], Tuong[i][2], Tuong[i][3]);	
		int dameA = Dame(*ATK, *TYPE, Tuong[i][2], Tuong[i][3]);
		int dameB = Dame(Tuong[i][1], Tuong[i][3], *DEF, *TYPE);
		while(*HP > 0 && Tuong[i][0] > 0){
			printf("You attack fighter #%d and deal %d damage\n", i + 1, dameA);
			printf("The fighter #%d attacks you and deal %d damage\n", i + 1, dameB);
			*HP -= dameB;
			Tuong[i][0] -= dameA;
			printf("You current stats: %d %d %d %d\n", *HP, *ATK, *DEF, *TYPE);
			printf("Enemy's current stats: %d %d %d %d\n", Tuong[i][0], Tuong[i][1], Tuong[i][2], Tuong[i][3]);
		}
		if(*HP > 0 && Tuong[i][0] <= 0){
			*ATK += (1.0*Tuong[i][1]/2 + 0.5);
			*HP += 2*Tuong[i][2];
			*DEF += 1;
			printf("You have DEFeated fighter #%d\n\n", i + 1);
		}
		if(*HP <= 0 && Tuong[i][0] <= 0){
			printf("You have been DEFeated by fighter #%d\n", i + 1);
			return 0;
		}
		if(*HP == 0 && Tuong[i][0] == 0){
			printf("You draw with the fighter #%d and go back to village to be a farmer\n", i + 1);
			return 0;
		}	
	}
	return 1;
}
int solo(int HP, int ATK, int DEF, int TYPE, int tuong[4]){
	int Tuong[4];
	Tuong[0] = tuong[0];
	Tuong[1] = tuong[1];
	Tuong[2] = tuong[2];
	Tuong[3] = tuong[3];
	int dameA = Dame(ATK, TYPE, Tuong[2], Tuong[3]);
	int dameB = Dame(Tuong[1], Tuong[3], DEF, TYPE);
	while(HP > 0 && Tuong[0] > 0){
		HP -= dameB;
		Tuong[0] -= dameA;
	}
	if(HP > 0 && Tuong[0] < 0)
		return 1;
	if(HP == 0 && Tuong[0] == 0)
		return 0;
	return -1;
}
int power(int *Tuong){
	return Tuong[0] + 2*Tuong[1] + 2*Tuong[2];
}
int chooseBestOpponent(int HP, int ATK, int DEF, int TYPE, int n, int Tuong[][4]){
	int max = -1, i; // power max = 0;
	for(i=0; i<n; i++)
		if(solo(HP, ATK, DEF, TYPE, Tuong[i]) == 1){
			max = max < power(Tuong[i]) ? power(Tuong[i]) : max;
		}
	if(max == -1)
		return -1;
	return max;	
}
void Delete(int *n, int Tuong[][4], int x){
	*n -= 1;
	int i;
	for(i=x; i<*n; i++){
		Tuong[i][0] = Tuong[i+1][0];
		Tuong[i][1] = Tuong[i+1][1];
		Tuong[i][2] = Tuong[i+1][2];
		Tuong[i][3] = Tuong[i+1][3];
	}
}
int Q_2(int *HP, int *ATK, int* DEF, int* TYPE, int *n, int Tuong[][4]){
	int count = 0, i;
	while(count < 10){
		int max = chooseBestOpponent(*HP, *ATK, *DEF, *TYPE, *n, Tuong);
		if(max == -1)
			return -1;
		for(i=0; i<*n; i++)
			if(max == power(Tuong[i])){
				printf("You DEFeat the Gladiator #%d with status %d %d %d %d\n", i, Tuong[i][0], Tuong[i][1], Tuong[i][2], Tuong[i][3]);
				int dameA = Dame(*ATK, *TYPE, Tuong[i][2], Tuong[i][3]);
				int dameB = Dame(Tuong[i][1], Tuong[i][3], *DEF, *TYPE);
				while(*HP > 0 && Tuong[i][0] > 0){
					*HP -= dameB;
					Tuong[i][0] -= dameA;
				}
				*ATK += (1.0*Tuong[i][1]/2 + 0.5);
				*HP += 2*Tuong[i][2];
				*DEF += 1;
				printf("Your status are upgraded to: %d %d %d %d\n", *HP, *ATK, *DEF, *TYPE);
				Delete(n, Tuong, i);
				count++;
				break;
			}
	}
	return 1;
}
char* Name(Gladiator x, char* first_name){
	char* name = (char*)malloc(200);
	name[0] = '\0';
	int type = Type(x.TYPE);
	if(x.HP < 5)
		strcat(name, "Frailed ");
	else if(x.HP < 10)
		strcat(name, "HitTanker ");
	else
		strcat(name, "Mountain ");

	if(x.DEF < 3)
		strcat(name, "Soft ");
	else if(x.DEF < 6)
		strcat(name, "Steeled ");
	else
		strcat(name, "Diamond ");

	if(x.ATK < 3)
		strcat(name, "MosquitoBite ");
	else if(x.ATK < 6)
		strcat(name, "Striker ");
	else if(x.ATK >= 9)
		strcat(name, "Deadly ");

	if(x.TYPE == 7)
		strcat(name, "Lucky7 ");
	else if(type == 3)
		strcat(name, "Exotic ");
	else if(type == 2)
		strcat(name, "Goldenrule ");
	else if(type == 1)
		strcat(name, "Optimus ");
		
	if(x.nWin < x.nLose)
		strcat(name, "Loser ");
	if(x.nLose + x.nWin < 3)
		strcat(name, "Newface ");
	if(x.nLose + x.nWin >= 3){
		if(1.0*x.nWin/(x.nLose + x.nWin) > 0.95)
			strcat(name, "Champion ");
		else	if(1.0*x.nWin/(x.nLose + x.nWin) > 0.5)
			strcat(name, "Veteran ");
		if(x.nLose == 0)
			strcat(name, "Unbeatable ");
	}
	strcat(name, first_name);
//	printf("%s\n", name);
	return name;
}
/*
5 5 5 5
1
5 2 2 2

5 5 5 5
1
5 5 5 5

10 10 10 10
10
1 0 0 1
1 0 0 2
1 0 0 3
1 0 0 4
1 0 0 5
1 0 0 6
1 0 0 7
1 0 0 8
1 0 0 9
1 0 0 10

10
1 7 4 10 14 4 Achilles
8 8 2 14 5 5 Paris
1 7 1 11 10 2 Paston
7 6 1 9 2 3 Helman
2 2 1 11 8 5 Hercules
7 6 1 3 9 7 OdySSeus
7 9 5 9 8 6 Jason
2 3 3 14 6 1 Avias
3 8 7 14 7 12 Orion
7 9 3 6 4 13 Killiman
*/
