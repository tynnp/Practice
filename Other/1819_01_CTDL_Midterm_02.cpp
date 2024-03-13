
//////////////////////////////////////////////////////

#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    set<int> s;
    while (cin >> n) s.insert(n);
    for (auto x : s) cout << x << " ";
    return 0;
}


//////////////////////////////////////////////////////