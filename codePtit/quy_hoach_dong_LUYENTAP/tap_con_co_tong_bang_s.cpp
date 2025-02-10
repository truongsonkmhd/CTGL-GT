/*
-Đề bài: Cho mảng A[] gồm N phần tử và số nguyên dương S, nhiệm vụ của bạn hãy xác định xem có thể tạo 
ra một tập con các phần tử trong mảng có tổng bằg S hay không?Chú ý mỗi phần tử trong mảng chỉ được 
sử dụng 1 lần 
-output: In ra 1 nếu tập con A có tổng bằng S, ngược lại in ra 0
input: 8 92
       69 16 82 70 31 24 45 112
output: 1
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,S; cin>>n>>S;
    vector<int> a(n);
    for(int i = 0 ; i < n; i++) cin>>a[i];
    vector<bool> dp(S+1,false);
    dp[0] = true;
    for(int i = 0; i < n; i++){
        for(int j = S ; j >= a[i] ; j--){
            if(dp[j - a[j]] == true){
                dp[j] = true;
            }
        }
    }
    if(dp[S]) cout<< 1 <<endl;
    else cout<<0 <<endl;
}