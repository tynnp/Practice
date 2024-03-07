#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
const int maxN = 1000000;

int n, a;
bool k[maxN + 1];

void sangSoNT() {
    memset(k, true, sizeof(k));
    k[0] = false;
    k[1] = false;
    int cb2 = sqrt(maxN);

    for (int i = 2; i <= cb2; i++) {
        if (k[i]) {
            for (int j = i * i; j <= maxN; j += i)
                k[j] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    sangSoNT();

    while (n--) {
        cin >> a;
        if (a < 1) cout << "0\n";
        else if (k[a - 1] || k[a] || k[a + 1]) cout << "1\n";
        else cout << "0\n";
    }

    return 0;
}