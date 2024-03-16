#include <iostream>
#define ll long long 
using namespace std;

bool check(ll n) {
    ll res = 0;

    for (ll i = 1; i < n; i++)
        if (n % i == 0) res += i;

    return (res == n);
}

int main() {
    int n, index = -1; 
    cin >> n; 
    ll arr[n];
    for (ll &x : arr) cin >> x;
   
    for (int i = 0; i < n; i++) 
        if (check(arr[i]) && arr[i] > 0) 
            index = i;
        
    cout << index;
    return 0;
}