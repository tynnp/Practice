#include <iostream>
using namespace std;

int main() {
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