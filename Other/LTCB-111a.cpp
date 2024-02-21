#include <iostream>
#define endl '\n' 
using namespace std; 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < 2*n; j++) {    
            if (j < n-i || j > n+i) cout << " ";
            else cout << "*";
        }
        if (i != n-1) cout << endl;
    }

    return 0;
}