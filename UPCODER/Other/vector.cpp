#include <iostream>
#include <vector>
using namespace std;

bool prime(int n) {
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return false;
    return n > 1;
}

int tong(int n) {
    int res(0);

    while (n > 0) {
        if (!prime(n % 10)) res += n % 10;
        n /= 10;
    }
    
    return res;
}

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int &x : v) cin >> x;

    for (int x : v) {
        if (!prime(x)) cout << -1;
        else cout << tong(x);
        cout << endl;
    }

    return 0;
}