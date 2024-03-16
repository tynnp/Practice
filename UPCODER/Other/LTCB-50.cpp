#include <iostream>
using namespace std;

int main() {
    int n, res = 0;
    cin >> n;

    while (n != 0) 
        res = res*10 + n%10,
        n /= 10;
    
    cout << res;
    return 0;
}