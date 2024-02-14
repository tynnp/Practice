#include <iostream>
using namespace std;

string coSo2(int n) {
    string res = "";

    if (n == 0) return "0";

    while (n > 0) 
        res = to_string(n%2) + res,
        n /= 2;
        
    return res;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    cout << coSo2(n);
    return 0;
}