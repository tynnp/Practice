#include <iostream>
using namespace std;

int main() {
    int x, v;
    int n = 0, a[100];
    
    cin >> x >> v;
    
    while (cin >> a[n]) 
        n++;
        
    for (int i = 0; i < n; i++) {
        if (i == x) 
            cout << v << ' ';
        cout << a[i] << ' ';
    }
    
    if (x == n)
        cout << v;
    
    return 0;
}
