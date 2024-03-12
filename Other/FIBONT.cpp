#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) 
        if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}

int main() {
    int n;
    cin >> n;

    int a = 0, b = 1;
    while (a <= n) {
        if (isPrime(a)) 
            cout << a << endl;
        int c = a + b;
        a = b;
        b = c;
    }

    return 0;
}
