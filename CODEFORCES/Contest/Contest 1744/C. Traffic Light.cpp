#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    char c;
    string s;  
    cin >> t;

    while (t--) {
        int cnt(0), res(INT_MIN);
        cin >> n >> c >> s;
        s += s;
        for (int i = 0; i < n*2; i++) {
            if (s[i] == c) {
                cnt = 0;
                while (s[i] != 'g' && i < n*2)
                    cnt += 1, i += 1;
                res = max(cnt, res);
            }
        }

        cout << res << endl;
    }

    return 0;
}