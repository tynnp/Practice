#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v(1001), f(1001, 1);

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
        
    for (int i = 1; i <= n; i++) 
        for (int j = i-1; j >= 1; j--)
            if (v[j] < v[i] && f[j] >= f[i])
                f[i] = f[j] + 1;
                
    cout << *max_element(f.begin(), f.end());
    return 0;
}