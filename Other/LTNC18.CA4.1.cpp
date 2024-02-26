#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    int n, tmp = 0; 
    vector<int> arr;
    while (cin >> n) arr.push_back(n);
    sort(arr.begin(), arr.end());

    for (int i = arr.size()-1; i >= 0; i--) 
        if (arr[i] % 10 == 5) 
            tmp++, cout << i << " ";

    if (!tmp) cout << -1;
    return 0;
}