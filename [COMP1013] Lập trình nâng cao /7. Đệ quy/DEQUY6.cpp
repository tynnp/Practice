#include <iostream>
#include <cmath>
using namespace std;

float factorial(float n) {
    if (n == 1) return 1;
    return n * factorial(n-1);
}

float sum(int n, int x) {
    if (n == 0) return x;   
    return pow(-1, n) * (pow(x, 2*n + 1)/factorial(2*n + 1)) + sum(n-1, x);
}

int main() {
    float n, x; 
    cin >> n >> x;
    cout << roundf(sum(n, x)*1000) / 1000;
    return 0;   
}