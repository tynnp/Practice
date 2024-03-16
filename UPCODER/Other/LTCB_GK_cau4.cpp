#include <iostream>
using namespace std;
 
int main() {
    int n, max = 0, min = 9;
    cin >> n;

    while (n > 0) {
        if (max < n%10) max = n%10;
        if (min > n%10) min = n%10;
        n /= 10;
    }
    
    cout << max + min;
    return 0;
}