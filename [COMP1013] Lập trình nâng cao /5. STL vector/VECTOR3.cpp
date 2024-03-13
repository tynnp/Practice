#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

bool checkCP(int n) {
    return (int) sqrt(n) == sqrt(n);
}

bool check(int n) {
    return checkCP(n) || n & 1;
}

int main() {
    int n;
    vector<int> vt;

    while (cin >> n) 
        vt.push_back(n);

    vt.erase(remove_if(vt.begin(), vt.end(), check), vt.end());
    sort(vt.begin(), vt.end());

    for (int i = 0; i < vt.size(); i++)
        cout << vt[i] << " ";
    return 0;
}