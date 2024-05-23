#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 10;
    set<int> s;
    while (n--) {
        int tmp;
        cin >> tmp;
        s.insert(tmp % 42);
    }
    
    cout << s.size();
    return 0;
}