#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

bool binhPhuong(int n) {
    return (int) sqrt(n) == sqrt(n);
}

int main() {
    int n, k, cnt = 0;
    bool checkK = false;
    vector<int> res;

    cin >> n >> k;
    while (n--) {
        int tmp;
        cin >> tmp;

        if (binhPhuong(tmp)) cnt++;
        else res.push_back(tmp);

        if (tmp == k) checkK = true;
    }

    cout << cnt << endl;
    cout << (checkK ? "Yes" : "No") << endl;
    
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

    return 0;
}