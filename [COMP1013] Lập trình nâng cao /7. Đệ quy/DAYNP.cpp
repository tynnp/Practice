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
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    string str = "";
    dayNhiPhan(str, n);
    return 0;
}