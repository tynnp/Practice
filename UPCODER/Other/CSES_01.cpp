#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, k, a, i = 0; 
    cin >> n >> k;
    bool check = true;
    multiset<int> arr;

    while (i++ < n) {
        cin >> a; 
        arr.insert(a);
    }

    for (auto x : arr) {
        int tmp = x; 
        arr.erase(arr.find(x));

        if (arr.count(k-tmp) != 0) {
            cout << tmp << " " << k-tmp;
            check = false; 
            break;
        }
    }

    if (check) cout << -1;
    return 0;
}