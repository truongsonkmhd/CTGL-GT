#include <bits/stdc++.h>
using namespace std;

int n;
bool used[123]; // mảng đánh dấu
int a[123];

void show(){
    for(int i = 1; i <= n; i++)
        cout<<a[i]<<" ";
        cout<<"\n";
}

void backTracking(int pos){
    if(pos == n + 1){
        show();
        return;
    }

    for( int i = 1 ; i <= n ; i++){
        if(!used[i]){
            a[pos] = i;
            used[i] = true;
            backTracking(pos + 1);
            used[i] = false;
        }
    
    }
}

int main(){
        cin>>n;
        backTracking(1);
        return 0;
    }