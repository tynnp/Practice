#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    const string HEXA = "0123456789ABCDEF";
    string res = "";
    int n; cin >> n;

    while (n > 0) 
        res = string(1, HEXA[n % 16]) + res,
        n /= 16;

    cout << res;
    return 0;
}