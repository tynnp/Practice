#include <iostream>
#include <climits>
using namespace std;

const int MAXN = 5e6 + 5;
int n, k, ans;
int prime[MAXN];   

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    cin >> n >> k;
    
    for (int i = 1; i <= n; i++)
        prime[i] = INT_MAX;

    for (int i = 2; i <= n; i++) {
        if (prime[i] == INT_MAX)
            for (int j = i; j <= n; j += i)
                prime[j] = i;
    }

    for (int i = 2; i <= n; i++)
        if (prime[i] <= k)
            ans++;

    cout << ans;
    return 0;
}