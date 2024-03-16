#include <iostream>
using namespace std;

int main() {
    int n, a, b; 
    cin >> n;
    int k = n;

    while (cin >> a >> b) {
        if (a == k) {
            k = b; 
            continue;
        }

        if (b == k) {
            k = a; 
            continue;
        }
    }
    
    cout << k;
    return 0;
}