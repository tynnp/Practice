#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<string> v(n);
    for (string &s : v) cin >> s;
    
    string tmp;
    cin >> m;
    while (m--) {
        cin >> tmp;
        cout << count(v.begin(), v.end(), tmp) << endl;
    }
    
    return 0;
}