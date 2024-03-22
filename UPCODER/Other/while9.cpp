#include <iostream>
#include <vector>
using namespace std;

bool check(int n) {
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return false;
    return n > 1;
}

int main() {
    vector<int> vt(1000, 0);
    bool checkEND = false;
    long long n;
    cin >> n;

    while (n > 0) {
        vt[n%10]++;
        n /= 10;
    }

    for (int i = 2; i < 1000; i++) 
        if (check(i) && vt[i]) {
            if (checkEND) cout << endl;
            cout << i << ": " << vt[i];
            checkEND = true;
        }

    return 0;
}