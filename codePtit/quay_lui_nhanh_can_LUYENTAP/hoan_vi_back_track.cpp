#include <bits/stdc++.h>
using namespace std;

int N , X[100] , used[100];

void inKq(){
    for(int i = 1; i <= N; i++){
        cout<<X[i];
    }
    cout << endl;
}

void Try(int i){
    // Duyet cac kha nang ma X[i] co th nhan dc
    for(int j = 1; j <= N ; j++){
        // Xet xem lieu rang co the gan X[i] = j hay khong?
        if(used[j] == 0){
            X[i] = j;
            used[j] = 1; // danh dau
            if( i == N ){
                inKq();
            }
            else{
                Try(i + 1);
            }
            // backtrack
            used[j] = 0;
         }
    }
}

int main(){
    cin>>N;
    Try(1); 
}