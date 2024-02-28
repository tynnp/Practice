#include <iostream>
using namespace std;

bool check(string str) {
    int cntChu = 0, cntSo = 0;
    for (char c : str) {
        cntChu += (c >= 'a' && c <= 'z');
        cntSo += (c >= '0' && c <= '9');
        if (!(c >= 'a' && c <= 'z') && !(c >= '0' && c <= '9')) return false;
    }

    cntChu = (cntChu > 0);
    cntSo = (cntSo > 0);
    return cntChu + cntSo == 1;
}

int main() {
    string str;
    cin >> str;
    cout << (check(str) ? "true" : "false");
    return 0;
}