#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<bool> vt(10000, false);
    vector<int> res;

    int n, max = -1, min = 8000;
    cin >> n;

    while (n--) {
        int tmp;
        cin >> tmp;
        vt[tmp] = true;
        if (max < tmp) max = tmp;
        if (min > tmp) min = tmp;
    }

    for (int i = min; i <= max; i++) 
        if (!vt[i]) res.push_back(i);
    
    if (!res.empty()) {
        cout << "Yes" << endl;
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
    } else cout << "No";

    return 0;
}