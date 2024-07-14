#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<long long> vt(200001, 0);
    long long max, tmp;
    cin >> max;
    while (cin >> tmp) vt[tmp]++;

    for (int i = 1; i <= max; i++)
        if (vt[i] == 0) cout << i;
    
    return 0;
}