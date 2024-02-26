#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double v, cm;
    cin >> v >> cm;
    cout << -log10(v*cm);
    return 0;
}