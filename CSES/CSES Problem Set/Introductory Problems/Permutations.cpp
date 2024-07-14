#include <iostream>
using namespace std;

int n;
string k, a, b;

void run() {
    if (n == 1) {
        cout << 1;
        return;
    }

    if (n < 4) {
        cout << "NO SOLUTION";
        return;
    }

    for (int i = 1; i <= n; i++) {
        k = to_string(i);
        if (i & 1) b += k + " ";
        else a += k + " ";
    }

    cout << a << b;
}

int main() {
    cin >> n;
    run();
    return 0;
}