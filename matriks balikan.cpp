#include <iostream>
#include <vector>

using namespace std;

// Membuat matriks identitas
vector<vector<double>> identityMatrix(int n) {
    vector<vector<double>> I(n, vector<double>(n, 0));
    for (int i = 0; i < n; i++)
        I[i][i] = 1;
    return I;
}

// Mencari invers matriks
vector<vector<double>> matrixInverse(vector<vector<double>> A) {
    int n = A.size();
    vector<vector<double>> I = identityMatrix(n);

    for (int i = 0; i < n; i++) {
        double div = A[i][i];
        for (int j = 0; j < n; j++) {
            A[i][j] /= div;
            I[i][j] /= div;
        }
        for (int j = 0; j < n; j++) {
            if (i != j) {
                double factor = A[j][i];
                for (int k = 0; k < n; k++) {
                    A[j][k] -= factor * A[i][k];
                    I[j][k] -= factor * I[i][k];
                }
            }
        }
    }
    return I;
}

// Mencari solusi SPL menggunakan metode invers
vector<double> solveSPL(vector<vector<double>> A, vector<double> b) {
    int n = A.size();
    vector<vector<double>> A_inv = matrixInverse(A);
    vector<double> x(n, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            x[i] += A_inv[i][j] * b[j];
    return x;
}

//---Kode Testing---//
int main() {
    // contoh persamaan linear
    // 4x + 12y = 25
    // 5x + 2y = 18
    vector<vector<double>> A = {{4, 12}, {5, 2}};
    vector<double> b = {25, 18};
    vector<double> x = solveSPL(A, b);
    cout << "Firman Gani Heriansyah" << endl;
    cout << "\n" << endl;
    cout << "Solusi SPL:" << endl;
    cout << "x = " << x[0] << endl;
    cout << "y = " << x[1] << endl;
    return 0;
}
