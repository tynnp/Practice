#include <iostream>
using namespace std;

int catalan(int n) {
    if (n < 2) return 1;
    int res = 0;
    for (int i = 0; i < n; i++)
        res += catalan(i)*catalan(n-1-i);
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while (cin >> n) 
        cout << catalan(n) << endl;
    return 0;
}