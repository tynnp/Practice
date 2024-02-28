#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n], cnt = 0, res = 0;
    for (int &x : arr) cin >> x;

    for (int x : arr)         
        if (x % 2 != 0) res += x, cnt++;
    
    cout << fixed << setprecision(1) << (double) res/cnt;
    return 0;
}