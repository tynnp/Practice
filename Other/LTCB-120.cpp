#include <iostream>
#include <cmath>
using namespace std;

bool check(int n) {
    return ((int) sqrt(n)*sqrt(n) == n);
}

int main() {
    int n; 
    cin >> n;

    if (n < 2) cout << -1;
    else {
        for (int i = 1; i <= n; i++)
            if (check(i)) cout << i << " ";
    }

    return 0;
}