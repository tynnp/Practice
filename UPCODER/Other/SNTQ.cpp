#include <iostream>
#include <vector>
using namespace std;

bool prime(int n) {
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return false;
    return n > 1;
}

int main() {
    long long n, q;
    vector<bool> v(10, false);
    cin >> n >> q;
    
    while (n > 0) {
        v[n % 10] = true;
        n /= 10;
    }
  
    int res(-1), cnt(0);
    for (int i = 0; i < 10; i++) {
        cnt += v[i];
        
        if (cnt == q) {
          res = i;
          break;
        }
    }
    
    if (res != -1) {
        cout << res << " ";
        cout << (prime(res) ? "Yes" : "No");
    } else cout << -1;
    
    return 0;
}