#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n; 
    cin >> n;
    cout << ((int) sqrt(n)*sqrt(n) == n ?  "YES" : "NO");
    return 0;
}