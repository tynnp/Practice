#include <iostream>
using namespace std;

int main() {
    int n, m = 0, k = 1; 
    cin >> n;
    
    while (m < n) 
        m = (k*(k+1))/2, k++;

    cout << k - 2;
    return 0;
}