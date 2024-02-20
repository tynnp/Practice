#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, nut = 0; 
    cin >> n;

    while (n > 0) 
        nut += n % 10, 
        n /= 10;
    
    cout << (nut % 10 == 0 ? 0 : nut % 10);
    return 0;
}