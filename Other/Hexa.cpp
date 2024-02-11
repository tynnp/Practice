#include <iostream>
using namespace std;

int main() {
    const string HEXA = "0123456789ABCDEF";
    string res = "";
    int n; cin >> n;

    while (n > 0) 
        res = string(1, HEXA[n % 16]) + res,
        n /= 16;

    cout << res;
    return 0;
}