#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n > 0) cout << n*(n + 1)/2;
    else cout << -1;
    return 0;
}