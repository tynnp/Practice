#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n; 
    cin >> n;
    int k = log2(n);
    if (log2(n) == k) cout << "true";
    else cout << "false";
    return 0;
}