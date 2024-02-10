#include <iostream>
using namespace std;

void dayNhiPhan(string str, int n) {
    if (str.length() == n) {
        cout << str + '\n' << endl;
        return;
    } 
    dayNhiPhan(str + '0', n);
    dayNhiPhan(str + '1', n);
}

int main() {
    int n; cin >> n;
    string str = "";
    dayNhiPhan(str, n);
    return 0;
}