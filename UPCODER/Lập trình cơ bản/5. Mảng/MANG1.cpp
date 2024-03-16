#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int arr[n], sum = 0;
    for (int &x : arr) {
        cin >> x;
        sum += x;
    }

    cout << sum;
    return 0;
}