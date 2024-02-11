#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    string s1, s2;
    int u = 0, v = 0; // u và v là số lượng + và - của s1
    int m = 0, n = 0; // m và n là số lượng + và - của s2
    int x, y; // x và y là độ trên lệch + và -
    double res; // kết quả

    cin >> s1 >> s2;

    for (int i = 0; i < s1.length(); i++)
        u += (s1[i] == '+'), v += (s1[i] == '-'),
        m += (s2[i] == '+'), n += (s2[i] == '-');

    x = u - m; y = v - n;
    res = (double) factorial(x + y) / (factorial(x) * factorial(y) * pow(2, x+y));

    cout << fixed << setprecision(10) << res;
    return 0;
}