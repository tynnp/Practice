#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, result = 0; 
    int x[] = {-n-1, -n, -n+1, -1, 0, +1, n-1, n, n+1};
    cin >> n >> k;

    for (int i = 0; i < 9; i++) 
        result += k + x[i];
    
    cout << result;
    return 0;
}