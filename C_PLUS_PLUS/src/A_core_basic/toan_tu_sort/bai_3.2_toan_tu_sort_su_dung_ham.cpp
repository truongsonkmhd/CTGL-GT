#include<bits/stdc++.h>
using namespace std;
//====== bai_1
// cho mảng A[] gồm N điểm trong hệ toạ độ Oxy, hãy sắp xếp các điểm này theo khoảng cách về gốc 
// toạ độ tăng dần, nếu 2 điểm có cùng khoảng cách tới gốc toạ độ thì in ra theo hoành độ tăng dần, 
// nếu tiếp tục 2 điểm này có cùng hoành độ thì in ra theo thứ tự tung độ tăng dần
 
int kc(pair<int,int> p){
   // return sqrt(p.first*p.first + p.second*p.second); // có căn, không có căn đều được!, như nhau
    return (p.first*p.first + p.second*p.second);
}

bool cmp(pair<int, int> a, pair<int,int> b){
    // xet kc toi goc toa do
    // set den hoanh do : a.first , b.first
    // xet den tung do : a.second , b.second
    if(kc(a) != kc(b)){
        return kc(a) < kc(b);
    } else if(kc(a) == kc(b))
        return a.first < b.first;
    return a.second < b.second;

}
int main(){
    int n; cin>>n;
    pair<int,int> a[n];
    for(int i = 0; i < n ; i++)
        cin>>a[i].first >> a[i].second;

    sort(a,a+n, cmp);

//c1:
    // for (pair<int, int> p : a) {
    //     cout << p.first << ' ' << p.second << endl;
    // }

//c2:
    for(auto it : a){
        cout << it.first << ' ' << it.second << endl;
    }
}
// input:
/*
13
-42 -76
47 43
12 7
-62 31
7 64
42 -92
-89 60
45 41
3 54
-41 40
20 -24
88 42
0 12
*/

//output
/*
0 12
12 7
20 -24
3 54
-41 40
45 41
47 43
7 64
-62 31
-42 -76
88 42
42 -92
-89 60
*/