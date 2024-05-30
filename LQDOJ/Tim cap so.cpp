#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k, sum(0), ans(0);
    cin >> n >> k;
    
    vector<int> v(n);
    for (int &x : v) cin >> x;
    
    int i(0), j(n-1);
    while (i < j) {
        while (i < j && v[i] + v[j] > k) j--;
        
        if (v[i] + v[j] == k) {
            cout << i+1 << " " << j+1;
            return 0;
        }
        
        i++;
    }
    
    cout << "No solution";
    return 0;
}