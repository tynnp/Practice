#include <iostream>
#include <cmath>
using namespace std;
 
int main() {
    int n, d; 
    cin >> n >> d;
    n = abs(n); 
    d = abs(d);
    cout << cos(d*M_PI/180)*n;
    return 0;
}