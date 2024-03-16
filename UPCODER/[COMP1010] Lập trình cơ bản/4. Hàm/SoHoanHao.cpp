#include <iostream>
using namespace std;

bool hoanHao(int n) {
    int res = 0;
    for (int i = 1; i < n; i++)
        if (n % i == 0) res += i;
    return res == n;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    cout << (hoanHao(n) ? "Yes" : "No");
    return 0;
}