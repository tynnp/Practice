#include <iostream>
using namespace std;

int main() {
    double n; cin >> n;
    double max = -10e6;
    while (cin >> n) 
        if (n > max) max = n;
    cout << max;
    return 0;
}