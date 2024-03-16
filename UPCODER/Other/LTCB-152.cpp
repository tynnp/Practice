#include <iostream>
#include <vector>
using namespace std;

bool check(int n) {
    int res = 0;

    for (int i = 1; i <= n/2; i++) 
        if (n % i == 0) res += i;

    return (res == n && n > 0);
}

int main() {
    int n, minHT = 10e6;
    vector<int> vt;
    while (cin >> n) vt.push_back(n);

    for (int x : vt) 
        if (x < minHT && check(x)) minHT = x;

    cout << (minHT == 10e6 ? 0 : minHT);
    return 0;
}