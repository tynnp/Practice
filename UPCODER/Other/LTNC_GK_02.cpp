#include <iostream>
using namespace std;

int sum(int n) {
    if (n == 1) return 1;
    if (n & 1) return ((n-1)/2)*((n-1)/2) + sum((n-1)/2)*sum((n-1)/2 + 1);
    else return n/2 + sum(n/2);
}

int main() {
    int n; 
    cin >> n; 
    cout << sum(n);
    return 0;
}