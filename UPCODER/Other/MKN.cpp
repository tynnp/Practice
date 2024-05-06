#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    vector<bool> v(1000000001, 0);
    int t;
    cin >> t;
    
    while (t--) {
        int tmp;
        cin >> tmp;
        if (v[tmp] == 0) cout << tmp << " ";
        v[tmp] = true;
    }
    
    return 0;
}