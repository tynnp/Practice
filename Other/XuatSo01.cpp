#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    int a = max(n, m);
    int b = min(n, m);

    if (a == b) {
        cout << "Gia tri cua n va m bang nhau";
    } else {
        for (int i = a; i >= b; i--) {
            cout << i;
            if (i != b) cout << " ";
        }
    }
    return 0;
}