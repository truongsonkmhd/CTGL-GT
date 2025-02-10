#include <bits/stdc++.h>
using namespace std;
// Đề bài: Tìm số xuất hiện nhiều nhất trong mảng , trong tường hợp có nhiều số có cùng số 
// lần xuất hiện thì lấy số nhỏ nhất

using ll = long long;

/*
intput:
1
10
1 1 2 2 2 1 4 7 3 3 3 9 
output:
1 3
*/

/*
//c1:
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        map<long long , int> mp;
        for(int i = 0; i < n; i++){
            int x; cin>>x;
            mp[x]++;
        }

        ll res, fre = INT_MIN;  
        for(auto it : mp){
            if(it.second > fre){
                fre = it.second;
                res = it .first;
            }
        }
        cout<< res << " " << fre;
    }
}

*/
//c2: làm theo mảng đánh dấu
int cnt[1000001] = {0}; // do đk: 0<=a[i]<=10^6
int main(){
    int n; cin>>n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin>> a[i];
    }

    for(int i = 0; i < n ; i++){
        cnt[a[i]]++;
    }

    int dem = 0, res;
    for(int i = 0 ; i < n ; i++){
        if(cnt[a[i]] > dem){
            dem = cnt[a[i]];
            res = a[i];
        } else if(cnt[a[i]] == dem){
            if(res > a[i]) res = a[i];
        }
    }
    cout<<res<<" "<<dem;
}
/*
// bài 2: tìm kí tự xuất hiện nhiều nhất trong chuỗi:
// input: abcdzzzzzzzzzzzzzzzzzu, output: z
pair<char,int> findMostFrequentChar(const string& input){
    
    map<char,int> charCount;

// đếm số lần xuất hiện của mỗi kí tự trong chuỗi
    for(char c : input){
            charCount[c]++;
    }
    // tìm kí tự xuất hiện nhiều nhất
    char mostFrequent;
    int maxCount = 0 ;
    for(const auto& pair:charCount){
        if(pair.second  >  maxCount){
            maxCount = pair.second;
            mostFrequent = pair.first;
        }
    }
    return make_pair(mostFrequent, maxCount);
}

int main(){
    int t; cin>>t;
    cin.ignore();
    while (t--)
    {
        string input; cin>>input;
        auto result = findMostFrequentChar(input);
        char mostFrequent = result.first;
        int maxCount = result.second;
        cout<<mostFrequent << "  "  << maxCount<< endl;
    }
    

}
*/

// c2:
/*
int main(){
    int t; cin>>t;
    cin.ignore();
    while(t--){
        string st; getline(cin,st);
        map<char , int> mp;
        for(char a : st){
            int x; cin>>x;
            mp[x]++;
        }

        char res ; 
        int fre = 0;
        for(auto it : mp){
            if(it.second > fre){
                fre = it.second;
                res = it .first;
            }
        }
        cout<< res << " " << fre;
    }
}
*/
