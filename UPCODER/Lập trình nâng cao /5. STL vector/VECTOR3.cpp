#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    vector<int> vt;
    while (cin >> n) vt.push_back(n);
    
    vt.erase(remove_if(vt.begin(), vt.end(), [] (int n) {
        return (sqrt(n) == (int) sqrt(n) || n & 1);
    }), vt.end());
    
    sort(vt.begin(), vt.end());
    for (auto it = vt.begin(); it != vt.end(); it++)
        cout << *it << " ";
    
    return 0;
}