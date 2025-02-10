#include <bits/stdc++.h>
using namespace std;
int N , X[100] , K;

void inKq(){
    for(int i = 1; i <= K ; i++){
        cout<<X[i];
    }
    cout << endl;
}

// i : N - K + i
// i : X[i-1] + 1
// i = 1 : X[0] + 1 = 0 + 1 = 1
void Try(int i){
    // Duyet cac kha nang ma X[i] co the nhan duoc
    for(int j = X[i-1] + 1; j<=N-K+i; j++){
        X[i] = j;
        if(i == K){
            inKq();
        }
        else {
            Try(i+1);
        }
    }
}

int main(){
    cin>>N>>K;
    Try(1);
    return 0;
}