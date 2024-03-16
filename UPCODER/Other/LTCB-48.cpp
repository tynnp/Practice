#include <iostream>
using namespace std;
 
int main() {
    long long n, k = 0, S = 1; 
    cin >> n;

    while (n > 0) {
        if ((n%10) % 2 != 0) 
            S *= n%10, k++;
        n /= 10;
    }

    cout << (k == 0 ? -1 : S);
    return 0;
}