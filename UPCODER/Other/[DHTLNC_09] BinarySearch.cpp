#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    int n, m, k; 
    string str;
    bool check = true;
    cin >> n >> m;
    vector<pair<string, int>> arr(n);

    for (int i = 1; i <= n; i++) {
        cin >> str >> k;
        arr.push_back({str, k});
    }

    for (auto x : arr) 
        if (x.second == m) {
            cout << x.first;
            check = false;
            break;
        }

    if (check) cout << "NO";
    return 0;
}