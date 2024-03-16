#include <iostream>
using namespace std;
 
int main() {
    int n, x, k = 0; 
    bool check = true;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        if (k < x) k = x - 1;
        if (k > x) {
            cout << "No"; 
            check = false;
            break;
        }
    } 
    
    if (check) cout << "Yes";
    return 0;
}