#include <iostream>
using namespace std;

bool check(int n) {
    int res = 0;
    if (n < 2) return false;
    for (int i = 1; i <= n/2; i++)
        if (n % i == 0) res += i;
    return (n == res);
}

int main() {
    int arr[5], res = -1;
    for (int &x : arr) cin >> x;  
    for (int x : arr) if (check(x)) res = x;
    cout << res;
    return 0;
}

// #include <iostream>
// #include <cmath>
// using namespace std;

// bool check(int n) {
//     if (n < 2) return false;
//     for (int i = 2; i <= sqrt(n); i++)
//         if (n % i == 0) return false;
//     return true;
// }

// int main() {
//     int arr[5], res = -1;
//     for (int &x : arr) cin >> x;  
//     for (int x : arr) if (check(x)) res = x;
//     cout << res;
//     return 0;
// }