#include <iostream>

using namespace std;

void knapSack(int *weight, int *value, int n, int w){
	int k[n+1][w+1]; // bang thong tin
	for(int j=0; j<=w; j++)
		for(int i=0; i<=n; i++)
			if(i==0 || j == 0)
				k[i][j] = 0;
			else	if(j < weight[i])
				k[i][j] = k[i-1][j];
			else{
				k[i][j] = k[i-1][j] > value[i] + k[i-1][j - weight[i]] ? k[i-1][j] : value[i] + k[i-1][j - weight[i]];
			}			
	cout << "Toi da: " << k[n][w];
}
int main(){
	int n, w;
	int weight[n+1], value[n+1];
	cin >> n;
	weight[0] = 0, value[0] = 0;
	for(int i=1; i<=n; i++)
		cin >> weight[i] >> value[i];
	cin >> w;
	cout << "iteam" << "\t" << "Weight" << "\t" << "value" << "\n";
	for(int i=1; i<=n; i++)
		cout << i << "\t" << weight[i] << " \t" << value[i] << "\n";
	knapSack(weight, value, n, w);
}
/*
4
1 1
3 4
4 5
5 7
*/
