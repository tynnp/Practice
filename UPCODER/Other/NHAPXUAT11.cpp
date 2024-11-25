#include <iostream>
using namespace std;

int n, x;
int a[10];

int main() {
    while (cin >> x) 
        a[n++] = x;
    
    for (int i = 0; i < n; i++) {
        if (i != 0)
            cout << '\n';
        cout << a[i];
    }
    
    return 0;
}