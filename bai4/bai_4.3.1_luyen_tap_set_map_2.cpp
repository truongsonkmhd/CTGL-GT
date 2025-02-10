#include <bits/stdc++.h>
using namespace std;
// tìm những phần tử thuộc mảng 1 , mà không thuộc mảng 2

// c1:
/*
int main(){
    int t ; cin>>t;
    while (t--)
    {
        int n,m; cin>>n>>m;
        int a[n];

        for(int &it : a) cin>>it; // nhập vào mảng a

        set<int> se; // mảng b
        for (int i = 0; i < m; i++)
        {
            int x; cin>>x;
            se.insert(x); //
        }

        bool ok = false;
        for(int x : a){ // duyệt qua mảng a 
            if(se.find(x) == se.end()){  // dùng hàm find() để tìm những ptu trùng
                cout<< x << " ";
                ok = true;
            }
        }
        if(!ok){
            cout<<"NOT FOUND \n";
        } else cout<<endl;
        
    }
    
}
*/
int main(){
    int t ; cin>>t;
    while (t--)
    {
        int n,m; cin>>n>>m;
        int a[n];

        for(int &it : a) cin>>it;

        map<int , bool> mp;
        for(int i = 0 ;  i < m ; i++){
            int x; cin>> x;
            mp[x] = true;
        }

        bool ok = false;
        for(int x : a){
            if(mp.find(x) == mp.end()){
                cout<< x << " ";
                ok = true;// tìm thấy
            }
        }
        if(!ok) cout<< " NOT FOUND\n";
        cout<< endl;
    }
}