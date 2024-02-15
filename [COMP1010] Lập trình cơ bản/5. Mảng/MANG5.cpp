#include <iostream>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int arr[n], duong[n], am[n];
    int duongIndex = 0, amIndex = 0;

    for (int &x : arr) {
        cin >> x;
        if (x < 0) am[amIndex++] = x;
        if (x > 0) duong[duongIndex++] = x;
    }

    for (int i = 0; i < amIndex; i++)
        cout << am[i] << " ";
    cout << endl;

    for (int i = 0; i < duongIndex; i++)
        cout << duong[i] << " ";

    return 0;
}