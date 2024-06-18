#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++)
        if (i % 2 == 0 || n % i == 0)
            cout << i << " ";
            
    return 0;
}