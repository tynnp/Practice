#include <iostream>
using namespace std;
 
bool primeCheck(int n) {
    if (n == 2 || n == 3) return true;
    if (n < 3 || n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i*i <= n; i += 6)
        if (n % i == 0 || n % (i+2) == 0) return false;
    return true;
}

bool check(int n) {
    n /= 10;
    while (n > 0) {
        if (!primeCheck(n)) return false;
        n /= 10;
    }
    return true;
}
 
int main() {
    int n; 
    cin >> n;
    cout << (check(n) ? "Yes" : "No");
    return 0;
}