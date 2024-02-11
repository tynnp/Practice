#include <iostream>
using namespace std;

int main() {
    int n, res = 0; 
    cin >> n;

    for (int i = 2; i < n/2; i++)
        res += (n % i == 0 ? n/i + i : 0);

    cout << (res + 1 == n ? "Yes" : "No");
    return 0;
}