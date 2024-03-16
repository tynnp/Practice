#include <iostream>
#include <cmath>
using namespace std;

void ThapHaNoi(int n, int goc, int dich, int trungGian, int &buoc) {
    if (n == 1) {
        cout << "Chuyen dia 1 tu cot " << goc << " sang cot " << dich << endl;
        buoc++;
        return;
    }

    ThapHaNoi(n - 1, goc, trungGian, dich, buoc);
    cout << "Chuyen dia " << n << " tu cot " << goc << " sang cot " << dich << endl;
    buoc++;
    ThapHaNoi(n - 1, trungGian, dich, goc, buoc);
}

int main() {
    int n, buoc = 0;
    cin >> n;
    cout << pow(2, n) - 1 << endl;
    ThapHaNoi(n, 1, 3, 2, buoc);
    return 0;
}
