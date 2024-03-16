#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, res = 0;
    cin >> n;

    if (n >= 0) {
        for (int i = 1; i <= n; i++)    
            res += i;
        cout << res; 
    } else 
        cout << "NHAP SAI";
    
    return 0;
}