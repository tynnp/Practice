#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

string csl(const string &a, const string &b) {
    int len1 = a.size(), len2 = b.size();
    int maxLen = max(len1, len2);
    string res(maxLen + 1, '0'); 
    int carry = 0;

    for (int i = 0; i < maxLen; ++i) {
        int digitA = (i < len1) ? a[len1 - 1 - i] - '0' : 0;
        int digitB = (i < len2) ? b[len2 - 1 - i] - '0' : 0;
        int sum = digitA + digitB + carry;
        carry = sum / 10;
        res[maxLen - i] = (sum % 10) + '0';
    }

    if (carry) res[0] = carry + '0';
    else res.erase(res.begin()); 
    return res;
}

signed main() {
    fastIO;
    string a, b;
    cin >> a >> b;
    cout << csl(a, b);
    return 0;
}