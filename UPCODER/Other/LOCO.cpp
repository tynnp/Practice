#include <iostream>
using namespace std;

unsigned long long n, t, MOD;

struct Matrix {
    unsigned long long c[3][3];
    Matrix() {
        c[0][0] = 1;
        c[0][1] = 1;
        c[0][2] = 1;
        c[1][0] = 1;
        c[1][1] = 0;
        c[1][2] = 0;
        c[2][0] = 0;
        c[2][1] = 1;
        c[2][2] = 0;
    }
};

Matrix nhan(Matrix a, Matrix b) {
    Matrix res;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            res.c[i][j] = 0;
            for (int k = 0; k < 3; k++)
                res.c[i][j] = (res.c[i][j] + a.c[i][k] * b.c[k][j]) % MOD;
        }
    return res;
}

Matrix pow(Matrix a, unsigned long long n) {
    if (n == 1) return a;
    Matrix tmp = pow(a, n/2);
    tmp = nhan(tmp, tmp);
    if (n & 1) tmp = nhan(tmp, a);
    return tmp;
}

int main() {
    cin >> n >> MOD;
    if (n == 1) cout << 1;
    else if (n == 2) cout << 2;
    else {
        Matrix a;
        Matrix A = pow(a, n - 2);
        long long res = (A.c[0][0]*2 + A.c[0][1] + A.c[0][2]) % MOD;
        cout << res;
    }
    return 0;
}