#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int h, m, s;
    cin >> h >> m >> s;

    bool hopLe = true;
    if (h < 0 || h > 23) hopLe = false;
    if (m < 0 || m > 59) hopLe = false;
    if (s < 0 || s > 59) hopLe = false;

    if (++s == 60) s = 0, m += 1;
    if (m == 60) m = 0, h += 1;
    if (h == 24) h = 0;

    if (!hopLe) cout << "NO";
    else {
        cout << "YES\n";
        cout << h << ":" << m << ":" << s;
    }
    return 0;
}