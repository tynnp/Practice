#include <iostream>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("word.in", "r", stdin)
#define out freopen("word.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

signed main() {
    fastIO; inp; out;
    int N, K;
	cin >> N >> K;

	
	int len = 0;
	for (int i = 0; i < N; i++) {
		string word;
		cin >> word;
		len += word.length();

		if (len <= K) {
			if (i != 0) { 
                cout << ' '; 
            }
			cout << word;

		} else {
			cout << "\n" << word;
			len = word.length();
		}
	}

    return 0;
}