#include <iostream>
using namespace std;

const int MAX = 10;
int n, banCo[MAX][MAX];

bool check(int r, int c) {
    // xét đường dọc
    for (int i = 0; i < r; i++)
        if (banCo[i][c] == 1) return false;

    // xét đường chéo trái
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
        if (banCo[i][j] == 1) return false;

    // xét đường chéo phải
    for (int i = r, j = c; i >= 0 && j < n; i--, j++)
        if (banCo[i][j] == 1) return false;

    return true;
}

bool Try(int r) {
    if (r == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) 
                if(banCo[i][j] == 0) cout << ". ";
                else cout << "Q ";
            cout << endl;
        }
        cout << endl;
        return true;
    }

    bool res = false;
    for (int i = 0; i < n; i++) {
        if (check(r, i)) {
            banCo[r][i] = 1;
            res |= Try(r + 1);  // nếu Try true thì res true, ngược lại res giữ nguyên
            banCo[r][i] = 0;
        }
    }
    return res;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            banCo[i][j] = 0;

    if (!Try(0)) cout << "NO" << endl;
    return 0;
}