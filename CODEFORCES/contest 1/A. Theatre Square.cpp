#include <bits/stdc++.h> 
using namespace std;

int main() {
    long long n, m, a;
    cin >> n >> m >> a;
    cout << ceil((double)n/a) * ceil((double)m/a);
    return 0;
}