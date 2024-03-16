#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    vector<int> vt;
    while (cin >> n) vt.push_back(n);
    for (auto x : vt) cout << x << " ";
    return 0;
}