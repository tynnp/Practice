#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;
using namespace std;

int main() {
    vector<ll> arr;
    ll n;

    while (cin >> n) arr.push_back(n);
    sort(arr.begin(), arr.end());

    double dtb = 0;
    for (int i = 1; i < arr.size()-1; i++)
        dtb += arr[i];

    cout << (double) dtb/(arr.size()-2);
    return 0;
}