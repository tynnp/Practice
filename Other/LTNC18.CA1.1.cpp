#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    bool check = true;
    vector<int> vt;

    while (cin >> n)
        vt.push_back(n);

    for (int i = vt.size()-1; i >= 0; i--)
        if (vt[i] == 0) {
            cout << i << " ";
            check = false;
        }
    
    if (check) cout << -1;
    return 0;
}