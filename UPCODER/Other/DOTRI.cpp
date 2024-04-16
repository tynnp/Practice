#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    vector<int> v;
    
    while (cin >> n) 
        v.push_back(n);

    sort(v.begin(), v.end());
    if (v.size() & 1) v.push_back(0);

    for (int i = 1; i < v.size(); i += 2)
        cout << v[i] << " " << v[i-1] << " ";
    return 0;
}