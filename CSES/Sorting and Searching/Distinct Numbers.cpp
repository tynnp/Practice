#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, tmp;
    set<long long> s;
    cin >> n;

    while (n--) {
        cin >> tmp;
        s.insert(tmp);
    }

    cout << s.size();
    return 0;
}