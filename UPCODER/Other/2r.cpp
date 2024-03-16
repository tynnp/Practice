#include <iostream>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    long long n; cin >> n;
    while (cin >> n) 
        cout << (n == 1) << endl;
    return 0;
}