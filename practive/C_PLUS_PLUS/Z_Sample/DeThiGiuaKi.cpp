/*
1:

#include <iostream>
#include <string.h>
using namespace std;

int main(){
    string n;
    cin >> n;
    if(!(n[0] == '-' || n[0] == '0')){
        int le = 10;
        for(int i=0; i<n.size(); i++)
            if((n[i] - 48) % 2 == 1)
                le = le < n[i] - 48 ? le : n[i] - 48;
        if(le != 10)
            cout << le;
    }
}

2:

#include <iostream>
#include <string.h>
using namespace std;

int main(){
    string n;
    cin >> n;
    if(!(n[0] == '-' || n[0] == '0')){
        int le = 0;
        for(int i=0; i<n.size(); i++)
                le = le > n[i] - 48 ? le : n[i] - 48;
        if(le != 10)
            cout << le;
    }
}

3:

#include <iostream>
#include <string.h>
using namespace std;

int main(){
    string n;
    cin >> n;
    if(!(n[0] == '-' || n[0] == '0')){
        int le = 0;
        for(int i=0; i<n.size(); i++)
            if((n[i] - 48) % 2 == 0)
                le += n[i] - 48;
        cout << le;
    }
}

4:

#include <iostream>
#include <string.h>
using namespace std;

int main(){
    string n;
    cin >> n;
    if(!(n[0] == '-' || n[0] == '0')){
        int le = 0;
        for(int i=0; i<n.size(); i++)
            if((n[i] - 48) % 2 == 0)
                le = le > n[i] - 48 ? le : n[i] - 48;
        if(le != 10)
            cout << le;
    }
}
5:
#include <iostream>
#include <string.h>
using namespace std;

int main(){
    string n;
    cin >> n;
        if(n.size() < 7 || n[0] == '-')
            cout << -1;
        else
            cout << n[n.size() - 6];   
}

6:

#include <iostream>
#include <string.h>
using namespace std;

int main(){
    char n[1000];
    cin >> n;
    int i;
    if(!(n[0] == '-' || n[0] == '0')){
        for(i=0; i<=9; i++)
            if(strchr(n, i + 48) != 0)
                break;
        int sum = i;
        for(i=9; i>=0; i--)
            if(strchr(n, i + 48) != 0)
                break;
        sum += i;
        cout << sum;
    }
}

7:
#include <iostream>

using namespace std;

int Duyet(int **a, int x, int y){
    if((a[x][y] == a[x+1][y] && a[x][y] == a[x+2][y]) || (a[x][y] == a[x][y+1] && a[x][y] == a[x][y+2]) || (a[x][y] == a[x+1][y+1] && a[x][y] == a[x+2][y+2]) || (a[x][y] == a[x-1][y+1] && a[x][y] == a[x-2][y+2]))
        return a[x][y];
    return 0;
}
int main(){
    int m, n, i, j;
    cin >> m >> n;
    int **a = new int*[m+4];
    for(i=0; i<=m+3; i++)
        a[i] = new int[n+4];
    for(i=0; i<=m+3; i++)
        for(j=0; j<=n+3; j++)
            a[i][j] = 0;
    for(i=2; i<=m+1; i++)
        for(j=2; j<=n+1; j++)
            cin >> a[i][j];
    for(i=2; i<=m+1; i++)
        for(j=2; j<=n+1; j++)
            if(Duyet(a, i, j) == 2){
                cout << "B win";
                return 0;
            }else    if(Duyet(a, i, j) == 1){
                cout << "A win";
                return 0;
            }
    cout << "Draw";
}

8:

#include <iostream>

using namespace std;

int main(){
    int n, i, j;
    cin >> n;
    int **a = new int*[n];
    for(i=0; i<n; i++)
        a[i] = new int[n];
    
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            cin >> a[i][j];
        
    int kq = 0;
    for(i=0; i<n; i++)
        kq += (a[i][i] - a[i][n-1-i]);
    cout << kq;
}
9:

#include <iostream>

using namespace std;

int KiemTra(int **a, int x, int y, int k){
    int i, j;
    for(i=0; i<k; i++)
        for(j=0; j<k; j++)
            if(a[x+i][y+j] % 2 == 1)
                return 0;
    return 1;
}
void Xuat(int **a, int x, int y, int k){
    int i, j;
    for(i=0; i<k; i++){
        for(j=0; j<k; j++)
            cout << a[x+i][y+j] << " ";
        cout << endl;
    }
}
int main(){
    int m, n, i, j, k;
    cin >> m >> n;
    int **a = new int*[m];
    for(i=0; i<m; i++)
        a[i] = new int[n];
    
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            cin >> a[i][j];
    cin >> k;
    
    for(i=0; i<=m-k; i++)
        for(j=0; j<=n-k; j++)
            if(KiemTra(a, i, j, k) == 1){
                Xuat(a, i, j, k);
                return 0;
            }
    cout << -1;
    

}

10:

#include <iostream>

using namespace std;

int Tong(int **a, int x, int y, int k){
    int i, j, sum = 0;
    for(i=0; i<k; i++)
        for(j=0; j<k; j++)
            sum += a[x+i][y+j];
    return sum;
}
void Xuat(int **a, int x, int y, int k){
    int i, j;
    for(i=0; i<k; i++){
        for(j=0; j<k; j++)
            cout << a[x+i][y+j] << " ";
        cout << endl;
    }
}
int main(){
    int m, n, i, j, k;
    cin >> m >> n;
    int **a = new int*[m];
    for(i=0; i<m; i++)
        a[i] = new int[n];
    
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            cin >> a[i][j];
    cin >> k;
    int x = 0, y = 0, sum = 0;
    for(i=0; i<=m-k; i++)
        for(j=0; j<=n-k; j++)
            if(Tong(a, i, j, k) > sum){
                sum = Tong(a, i, j, k);
                x = i;
                y = j;
            }
    Xuat(a, x, y, k);
}
11:

#include <iostream>
#include <string.h>

using namespace std;

int main(){
    char a[1000];
    cin.getline(a, 999);
    int i, j;
    for(i=0; i<strlen(a); i++)
        if(a[i] >= 48 && a[i] <='9')
              switch(a[i] - 48){
                case 0:{
                    char b[100];
                    strcpy(b, a + i + 1);
                    strcpy(a+i, "zero");
                    strcat(a+i+4, b);
                    break;
                }
                case 1:{
                    char b[100];
                    strcpy(b, a + i + 1);
                    strcpy(a+i, "one");
                    strcat(a+i+3, b);
                    break;
                }
                case 2:{
                    char b[100];
                    strcpy(b, a + i + 1);
                    strcpy(a+i, "two");
                    strcat(a+i+3, b);
                    break;
                }
                case 3:{
                    char b[100];
                    strcpy(b, a + i + 1);
                    strcpy(a+i, "three");
                    strcat(a+i+5, b);
                    break;
                }
                case 4:{
                    char b[100];
                    strcpy(b, a + i + 1);
                    strcpy(a+i, "four");
                    strcat(a+i+4, b);
                    break;
                }
                case 5:{
                    char b[100];
                    strcpy(b, a + i + 1);
                    strcpy(a+i, "five");
                    strcat(a+i+4, b);
                    break;
                }
                case 6:{
                    char b[100];
                    strcpy(b, a + i + 1);
                    strcpy(a+i, "six");
                    strcat(a+i+3, b);
                    break;
                }
                case 7:{
                    char b[100];
                    strcpy(b, a + i + 1);
                    strcpy(a+i, "seven");
                    strcat(a+i+5, b);
                    break;
                }
                case 8:{
                    char b[100];
                    strcpy(b, a + i + 1);
                    strcpy(a+i, "eight");
                    strcat(a+i+5, b);
                    break;
                }
                case 9:{
                    char b[100];
                    strcpy(b, a + i + 1);
                    strcpy(a+i, "nine");
                    strcat(a+i+4, b);
                    break;
                }
            }
    cout << a;
}

12:

#include <iostream>
#include <string.h>

using namespace std;

int main(){
    int a[1000];
    int n;
    cin >> n;
    char **s = new char*[n];
    for(int i=0; i<n; i++)
        s[i] = new char[1000];
    for(int i=0; i<n; i++){
        cin >> s[i];
    }
    for(int i ='a'; i<='z'; i++){
        int sum = 0;
        for(int j=0; j<n; j++)
            for(int k = 0; k<strlen(s[j]); k++)
                if(s[j][k] == i){
                    sum++;
                    break;
                }
      if(sum != 0)
            cout << char(i) << " : " << sum << endl;
    }
 }
 
13:
#include <iostream>
#include <string.h>

using namespace std;

int main(){
    char a[1000];
    cin.getline(a, 999);
    int x;
    cin >> x;
    char b[100][100];
    int i, j = 0, k = 0;
    a[strlen(a)] = 32;
    for(i=0; i<strlen(a); i++)
        if(a[i] == 32){
            strncpy(b[j], a + k, i - k);
            j++;
            k = i + 1;
        }
    for(i=0; i<j; i++){
        int soluong = 0;
        for(k=0; k<j; k++)
            if(strcmp(b[i], b[k]) == 0)
                soluong ++;
        if(soluong < x)
            cout << "unk ";
        else
            cout << b[i] << " ";
    }
}

14:

#include <iostream>
#include <string.h>

using namespace std;
void ChuanHoa(char *s){
    int i;
    for(i=0; i<strlen(s); i++)
        if(s[i] == 32){
            strcpy(s + i, s + i + 1);
            i--;
        }
        else
            break;
    for(i=0; i<strlen(s); i++){
        if(s[i] == 32 && s[i+1] == 32){
            strcpy(s + i, s + i + 1);
            i--;
        }
        if((s[i-1]==32 || i == 0) && s[i] <= 'z' && s[i] >= 'a')
            s[i] -= 32;
    }
    if(s[strlen(s) - 1] != '.')
        s[strlen(s)] = '.';
}
int main(){
    char s[1000];
    cin.getline(s, 999);
    ChuanHoa(s);
    cout << s;
}

15:
#include <iostream>
#include <string.h>

using namespace std;

int main(){
    int n, i, j =0, k = 0;
    cin >> n;
    char  a[1000];
    for(i=0; i<n; i++){
        char *b = new char[100];
        cin >> b;
        strcat(b, " ");
        strcat(a, b);
        delete(b);
    }
    char s[1000];
    char b[100][100];
    char c[2];
    cin.getline(c, 2);
    cin.getline(s, 999);
    s[strlen(s)] = 32;

    for(i=0; i<strlen(s); i++)
        if(s[i] == 32){
            strncpy(b[j], s + k, i - k);
            j++;
            k = i + 1;
        }
    strcpy(b[j], b[0]);
    for(i=0; i<j; i++)
        if(strstr(a, b[i]) == 0 && strstr(a, b[i+1]) != 0)
            cout << "UNK ";
        else    if(strstr(a, b[i]) != 0)
            cout << b[i] << " ";
}

16:
int* getEven(int *a, int n, int& size){
    int *b = new int[n];
    for(int i=0; i<n; i++)
        if(a[i] % 2 == 0){
            b[size] = a[i];
            size++;
        }
    return b;
}

17:
int* mergeTwoArray(int array1[], int n1, int array2[], int n2, int& return_size){
    int *c = new int[n1+n2];
    int i;
    for(i=0; i<n1+n2; i++)
        if(i < n1)
            c[i] = array1[i];
        else
            c[i] = array2[i - n1];
    return_size = n1 + n2;
    return c;
}

18:
int* getSquare(int numbers[], int n, int& return_size){
    int *a = new int[n];
    int i, d;
    for(i=0; i<n; i++){
        d = sqrt(numbers[i]);
        if(d*d == numbers[i]){
            a[return_size] = numbers[i];
            return_size++;
        }
    }
    return a;
}
19:
int* getPrime(int numbers[], int n, int& return_size){
    int *a = new int[n];
    for(int i=0; i<n; i++)
        if(numbers[i] >= 2){
            int d = 1;
            for(int j=2; j<=sqrt(numbers[i]); j++)
                if(numbers[i] % j == 0){
                    d = 0;
                    break;
                }
            if(d == 1){
                a[return_size] = numbers[i];
                return_size++;
            }
        }
    return a;
}
