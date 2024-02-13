#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, sum = 0;

    do {
        cin >> n;
        sum += n;
    } while (n != 0);

    if (sum % 10 == 0) cout << "DEP";
    else if (sum % 10 == 5) cout << "TRUNGBINH";
    else cout << "XAU";
    
    return 0;  
}