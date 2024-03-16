#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i <= 9; i++) {
        int c = i, b = c - 3, a = c - 6;
        if ((a*1000 + b*100 + c) - (a*100 + b*10 + c) == 2250) {
            cout << a*100 + b*10 + c;
            break;
        }
    }

    return 0;
}