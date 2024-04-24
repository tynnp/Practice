#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long n;
    cin >> n;
    cout << (sqrt(1 + 8*n) == (int) sqrt(1 + 8*n));
    return 0;
}