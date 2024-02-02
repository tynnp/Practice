#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "Xin chao!";
        if (i != n) cout << endl;
    }
    return 0;
}