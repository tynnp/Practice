#include <iostream>
using namespace std;

bool check(int n) {
    for (int i = 2; i*i <= n; i++) 
        if (n % i == 0) return false;
    return n > 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k; cin >> k;
    int arr[100], n = 0;
    int tmp, max = -10e6;
    
    while (cin >> tmp) {
        arr[n++] = tmp;
        if (max < tmp && tmp <= k && check(tmp))
            max = tmp;
    }

    cout << (max != -10e6 ? max : -1);
    return 0;
}