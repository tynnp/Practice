#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 4*1e6 + 1;
vector<bool> p(MAXN, true);
vector<int> ans(MAXN, 0);

int sum(int n) {
    int res = 0;
    while (n) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

void init() {
    p[0] = p[1] = false;
    for (int i = 2; i*i < MAXN; i++) {
        if (p[i]) {
            for (int j = i*i; j < MAXN; j += i) 
                p[j] = false;
        }
    }
    
    for (int i = 1; i < MAXN; i++)
        ans[i] = ans[i - 1] + (p[i] && p[sum(i)]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int a, b;
    cin >> a >> b;
    init();
    cout << ans[b] - ans[a-1];
    return 0;
}