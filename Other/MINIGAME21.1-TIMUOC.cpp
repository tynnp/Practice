#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, cnt;
    set<long long> s;

    cin >> n;
    for (long long i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            s.insert(i);
            s.insert(n/i);
        }
    }

    set<long long>::iterator it = s.begin();
    cout << s.size() << endl;

    for (it, cnt = 1; it != s.end(); it++, cnt++) {
        cout << *it << " ";
        if (cnt % 10 == 0) cout << endl;
    }   

    return 0;
}