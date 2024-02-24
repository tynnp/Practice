#include <iostream>
using namespace std;

int checkNT(int n) {
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return false;
    return n > 1;
}

int tinhTong(int n) {
    int res = 0;

    while (n > 0) {
        res += n % 10;
        n /= 10;
    }

    return res;
}

int main() {
    int n, res = 0;
    cin >> n;

    int arr[n];
    for (int &x : arr) cin >> x;

    for (int x : arr)
        if (checkNT(x)) 
            res += tinhTong(x);

    cout << res;
    return 0;
}