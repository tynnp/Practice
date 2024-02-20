#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    cout << ((int) sqrt(n) == sqrt(n) ? "True" : "False");
    return 0;
}