#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    if ((int) sqrt(n) == sqrt(n)) cout << "yes";
    else cout << "no";

    return 0;
}