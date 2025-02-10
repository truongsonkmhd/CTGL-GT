#include <iostream>
#include <algorithm>

using namespace std;

void TaoBangPhuongAn(int** F, int** S, int* A, int* C, int n, int M) {
    for (int v = 0; v <= M; v++) {
        F[0][v] = 0; // Dòng 0 bảng F[0, v]
    }
    
    for (int i = 1; i <= n; i++) {
        for (int v = 0; v <= M; v++) {
            F[i][v] = F[i-1][v];
            S[i][v] = 0;
            if (v >= A[i]) {
                for (int k = 1; k <= v / A[i]; k++) {
                    if (F[i][v] < F[i-1][v - A[i] * k] + C[i] * k) {
                        F[i][v] = F[i-1][v - A[i] * k] + C[i] * k;
                        S[i][v] = k;
                    }
                }
            }
        }
    }
}

void TruyVetPhuongAn(int** S, int* A, int n, int M) {
    int w = M;
    for (int i = n; i > 0; i--) {
        if (S[i][w] > 0) {
            cout << "Chon " << S[i][w] << " doi tuong thu " << i << " (trong luong: " << A[i] << ")\n";
            w -= A[i] * S[i][w];
        }
    }
}

int main() {
    int n, M;
    cout << "Nhap so luong doi tuong: ";
    cin >> n;
    cout << "Nhap trong luong toi da cua ba lo: ";
    cin >> M;

    int* A = new int[n + 1]; // Trong luong
    int* C = new int[n + 1]; // Gia tri

    cout << "Nhap trong luong va gia tri tung doi tuong:\n";
    for (int i = 1; i <= n; i++) {
        cout << "Doi tuong thu " << i << ": ";
        cin >> A[i] >> C[i];
    }

    int** F = new int*[n + 1];
    int** S = new int*[n + 1];
    for (int i = 0; i <= n; i++) {
        F[i] = new int[M + 1];
        S[i] = new int[M + 1];
    }

    TaoBangPhuongAn(F, S, A, C, n, M);

    cout << "Gia tri lon nhat co the dat duoc: " << F[n][M] << "\n";
    cout << "Phuong an chon cac doi tuong:\n";
    TruyVetPhuongAn(S, A, n, M);

    // Giải phóng bộ nhớ
    for (int i = 0; i <= n; i++) {
        delete[] F[i];
        delete[] S[i];
    }
    delete[] F;
    delete[] S;
    delete[] A;
    delete[] C;

    return 0;
}
