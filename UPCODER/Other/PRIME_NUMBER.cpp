#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, a, b;
    const int MAX = 1e6 + 1;
    vector<int> check(MAX, 1);

    check[0] = check[1] = 0;
    for (int i = 2; i*i <= MAX; i++) 
        if (check[i] == 1)
            for (int j = i*i; j <= MAX; j += i)
                check[j] = 0;
    
    for (int i = 1; i <= MAX; i++)  
        check[i] += check[i-1];
    
    cin >> t;
    while (t--) {
        cin >> a >> b;
        cout << check[b] - check[max(0, a-1)] << endl;
    }
    
    return 0;
}