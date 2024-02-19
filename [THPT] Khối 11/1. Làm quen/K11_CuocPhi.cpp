#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    double phut, res = 0;
    cin >> phut;

    if (phut > 0) {
        if (phut - int(phut) >= 0.5) phut = int(phut) + 1;
        else phut = (int) phut;

        if (phut < 2) res = 3000*phut;
        else if (phut < 11) res = (phut-1)*2000 + 3000;
        else res = (phut-10)*1500 + 21000;

        cout << res;

    } else cout << "NHAP SAI";

    return 0;
}