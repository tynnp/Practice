#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, res = 0;
    cin >> n;

    while (n--) {
        string tmp;
        cin >> tmp;
        if (tmp[0] == '-' || tmp[2] == '-') res--;
        else res++;
    }

    cout << res;
    return 0;
}