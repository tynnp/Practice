#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    double a, b, c, d, e;
    int cnt(0);

    cin >> a >> b >> c >> d >> e;
    double tmp = a;

    d = round(d * (100 / (100 + b)));
    e = round(e * (100 / (100 + c)));

    while (a > 0) {
        cnt++;
        if (cnt % 4 != 0) a -= d + e;
        else if (round(tmp * 0.1) - round(0.5 *(d+e)) < 0)
            a += round(tmp * 0.1) - round(0.5 *(d+e));
    }

    cout << cnt;
    return 0;
}