#include <iostream>
#include <cmath>
using namespace std;

bool nguyenTo(int n) {
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return false;
    return n > 1;
}

bool chinhPhuong(int n) {
    return (int) sqrt(n) == sqrt(n);
}

bool hoanHao(int n) {
    int res = 0;
    for (int i = 1; i < n; i++)
        if (n % i == 0) res += i;
    return res == n;
}

int main() {
    int n; 
    cin >> n;
    int arr[n];
    int nt[1000], cp[1000], hh[1000];
    int cntNT = 0, cntCP = 0, cntHH = 0;

    for (int &x : arr) cin >> x;

    for (int x : arr) {
        if (nguyenTo(x)) nt[cntNT++] = x;
        else if (chinhPhuong(x)) cp[cntCP++] = x;
        else if (hoanHao(x)) hh[cntHH++] = x;
    }

    if (cntNT == 0) cout << "NULL\n";
    else {
        for (int i = 0; i < cntNT; i++) {
            if (i != 0) cout << " ";
            cout << nt[i];
        }
        cout << endl;
    }

    if (cntCP == 0) cout << "NULL\n";
    else {
        for (int i = 0; i < cntCP; i++) {
            if (i != 0) cout << " ";
            cout << cp[i];
        }
        cout << endl;
    }

    if (cntHH == 0) cout << "NULL";
    else {
        for (int i = 0; i < cntHH; i++) {
            if (i != 0) cout << " ";
            cout << hh[i];
        }
    }
    
    return 0;
}