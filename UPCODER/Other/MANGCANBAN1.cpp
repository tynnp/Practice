#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
 
int main() {
    vi arr; ll n;
    int max = -9999999, max2 = -9999999;
    while (cin >> n) arr.push_back(n);
    
    for (int i = 0; i < arr.size(); i++) 
        if (max < arr[i]) max = arr[i];

    for (int i = 0; i < arr.size(); i++)
        if (max2 < arr[i] && arr[i] < max) 
            max2 = arr[i];

    cout << max2 << " " << max;
    return 0;
}