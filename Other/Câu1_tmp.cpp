#include <iostream>
using namespace std;

int F(int n) {
    if (n == 0 || n == 1 || n == 2)
        return 1;
    else
        return F(n - 1) + F(n - 3);
}

int main() {
    int n;
    cin >> n;
    cout << F(n);
    return 0;
}
