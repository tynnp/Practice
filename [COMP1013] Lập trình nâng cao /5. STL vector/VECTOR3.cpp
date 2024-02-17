#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

bool checkCP(int n) {
    return (int) sqrt(n) == sqrt(n);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    vector<int> vt;

    while (cin >> n) 
        vt.push_back(n);

    vt.erase(remove_if(vt.begin(), vt.end(), checkCP), vt.end());
    sort(vt.begin(), vt.end());

    for (int i = 0; i < vt.size(); i++)
        if (vt[i] % 2 == 0) cout << vt[i] << " ";
    return 0;
}