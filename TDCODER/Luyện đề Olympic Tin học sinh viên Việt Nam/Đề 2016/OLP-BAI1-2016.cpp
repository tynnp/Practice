#include <iostream>
using namespace std;

int main() {
    const int MAXN = 1e6 + 5;
    bool check[MAXN];
    
    fill(check, check + MAXN, true);
    check[0] = check[1] = false;
    
    for (int i = 2; i*i <= MAXN; i++) {
        if (check[i])
            for (int j = i*i; j < MAXN; j += i)
                check[j] = false;
    }
    
    int t;
    cin >> t;
    
    while (t--) {
        int p;
        cin >> p;
        cout << (check[p-1] || check[p] || check[p+1]) << endl;
    }
}