#include <bits/stdc++.h> 
using namespace std;

int main() {
    long long n, m, a;
    cin >> n >> m >> a;
    cout << fixed << setprecision(0) << ceil((double)n/a) * ceil((double)m/a);
    return 0;
}