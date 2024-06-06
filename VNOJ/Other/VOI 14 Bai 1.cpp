#include <bits/stdc++.h>
using namespace std;

struct Cay {
    int d, k;
};

int main() {
    int n, a, b, res(INT_MAX);
    cin >> n >> a >> b;

    vector<Cay> v(n+1);
    for (int i = 1; i <= n; i++)
        cin >> v[i].d >> v[i].k;

    sort(v.begin(), v.end(), [] (Cay a, Cay b) {
        return a.d < b.d;
    });

    vector<int> dpA(n+1, 0), dpB(n+1, 0);
    for (int i = 1; i <= n; i++) 
        dpA[i] = dpA[i-1] + (v[i].k == 1),
        dpB[i] = dpB[i-1] + (v[i].k == 2);
    
    int i = 1;
    for (int j = 1; j <= n; j++) 
        while (dpA[j] - dpA[i-1] >= a && dpB[j] - dpB[i-1] >= b) 
            res = min(res, v[j].d - v[i].d), 
            i += 1;
    
    cout << (res == INT_MAX ? -1 : res);
    return 0;
}