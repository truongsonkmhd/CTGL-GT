#include <iostream>
#include <conio.h>

using namespace std;

#define MAX  100 

#define TRUE  1 

#define FALSE  0

int n;//s? d?nh c?a d? th?.

int truoc[MAX], chuaxet[MAX], queue[MAX];//m?ng dánh d?u.

int A[MAX][MAX];// ma tr?n k? c?a d? th?.

int s = 0;//d?nh d?u .

int t = 13;//d?nh cu?i. 


void Init(void){ 

 freopen("lienth.IN", "r",stdin); 

 cin>>n; 

 cout<<"So dinh do thi: "<<n<<endl; 

 cin>>s>>t;

 cout<<"Dinh dau:"<<s<<endl;

 cout<<"Dinh cuoi:"<<t<<endl;

 for(int i=1; i<=n;i++){ 

  for(int j=1; j<=n;j++){ 

   cin>>A[i][j]; 

  }

 } 

 for(int i=1; i<=n;i++){ 

  chuaxet[i]=TRUE; 

  truoc[i]=0; 

 }

 fclose(stdin);

} 

void Result(void){ 

 if(truoc[t]==0){ 

  cout<<"Khong co duong di tu "<<s<< " den "<<t; 

  return; 

 } 

 cout<<"Duong di tu "<<s<<" den "<<t<<" la: "; 

 int j = t;

 cout<<t<<"<="; 

 while(truoc[j]!=s){ 

  cout<<truoc[j]<<"<="; 

  j=truoc[j]; 

 } 

 cout<<s; 

} 

/* Breadth First Search */

void BFS(int s) { 

 int dauQ, cuoiQ, u;

 dauQ=1;cuoiQ=1;//kh?i t?o queue.

 queue[dauQ]=s;chuaxet[s]=FALSE; //thêm d?nh d?u vào queue.

 while (dauQ<=cuoiQ){//queue chua r?ng.

  u=queue[dauQ];//l?y d?nh u trong queue.

  dauQ=dauQ+1; 

  for (int p=1; p<=n;p++){ 

   if(A[u][p] && chuaxet[p]){ 

    cuoiQ=cuoiQ+1;

    queue[cuoiQ]=p; 

    chuaxet[p]=FALSE;

    truoc[p]=u; 

   } 

  } 

 } 

} 


int main(){ 
	cin >> n;
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; j++)
			cin >> A[i][j];
	cin >> t;
 Init();
	
 BFS(s); 

 Result();

 getch(); 

}
