#include <iostream>
#define MOD 1000000007
using namespace std;

int main() {
    int n;
    cin >> n;
    long long arr[n+1] = {0};
    
    arr[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            arr[j] += arr[j-i] % MOD;
            
    cout << arr[n];
    return 0;
}