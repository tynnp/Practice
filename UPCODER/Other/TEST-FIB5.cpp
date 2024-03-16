#include <iostream>
#include <vector>
using namespace std;



int main() {
    int n;
    vector<long long> vt(101, 0);
    cin >> n;

    vt[1] = 1;
    vt[2] = 1;

    for (int i = 3; i <= n; i++)    
        vt[i] = vt[i-1] + vt[i-2];

    cout << vt[n];
    return 0;
}