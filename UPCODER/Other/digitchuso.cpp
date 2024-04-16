#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, a(0), b(0);
    vector<int> v;

    cin >> n;
    while (n > 0) 
        v.push_back(n % 10),
        n /= 10;
    
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) 
        if (i & 1) a = a*10 + v[i];
        else b = b*10 + v[i];

    cout << a + b;
    return 0;
}