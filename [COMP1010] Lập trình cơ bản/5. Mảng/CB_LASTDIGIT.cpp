#include <iostream>
using namespace std;
 
int main() {
    long long n; 
    cin >> n;
    if (n == 0) cout << 1;
    else if (n % 4 == 0) cout << 6;
    else cout << 8/(n % 4);
    return 0;
}