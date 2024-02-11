#include <iostream>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    
    while (cin >> n) {
        int res = 0;

        while (n > 0) 
            res += n % 10,
            n /= 10;
        
        cout << res << endl;
    }
    
    return 0;
}