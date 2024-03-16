#include <iostream>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int max = -10e6;
    int min = 10e6;
    int tmp;

    while (cin >> tmp) {
        if (max < tmp) max = tmp;
        if (min > tmp) min = tmp;
    }

    cout << min << endl;
    cout << max << endl;
    cout << min + max;

    return 0;
}