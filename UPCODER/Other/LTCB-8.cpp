#include <iostream>
using namespace std;

int main() {
    double n, S = 0.5; 
    cin >> n;

    while (n > 0) 
        S += (2*n + 1) / (2*n + 2), n--;
    
    cout << S;
    return 0;
}