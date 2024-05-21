#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long

int main() {
    int n;
    vector<ull> v(101, 0);
    v[0] = v[1] = 0;
    v[2] = 1;
    
    for (int i = 3; i <= 100; i++)
        v[i] = v[i-1] + v[i-2] + v[i-3];
    
    while (cin >> n) {
        int k = 0;
        while (v[k] < n) k++;
        cout << v[k] << endl;
    }
    
    return 0;
}