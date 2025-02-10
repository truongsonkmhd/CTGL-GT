#include <bits/stdc++.h>
using namespace std;

int N , X[100] , used[100];

void inkq(){
    for(int i = 1; i <= N; i++){
        cout<<X[i];
    }
    cout<<endl;
}

void  Try(int i){
    // duyet cac kha nang ma X[i] co the nhan dc
    for(int j = 1; j <= N ; j++){
        //Xet xem lieu rang co the gan X[i] = j hay không?
        if(used[j] == 0){
            X[i] = j;
            used[j] = 1; // Đánh dấu
            if( i == N ){
                inkq();
            }
            else{
                Try(i+1);
            }
            // backtrack
            used[j] = 0;
        }
    }
}

void Try(int i){
    for(int j = 1; j<=N ; j++){
        if(used[j] == 0){
            x[i] = j;
            used[j] = 1;
            if( i == N) {
                inkq()
            }
            else Try(int i + 1)
        }
        used
    }
}
int main(){
    cin>>N;
    Try(1);
    memset(used , 0 , sizeof(used)); // khởi tạo các giá trị ban đầu của used là 0
    return 0;
}