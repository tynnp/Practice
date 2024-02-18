#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int kw; 
    string res;
    cin >> kw;

    if (kw < 0) res = "NHAP SAI";
    else if (kw <= 50) res = to_string(kw*2500);
    else if (kw <= 100) res = to_string(50*2500 + (kw-50)*3000);
    else if (kw <= 200) res = to_string(50*2500 + 50*3000 + (kw-100)*5000);
    else res = "CAT DIEN";

    cout << res;
    return 0;
}