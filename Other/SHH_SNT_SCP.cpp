#include <iostream>
#include <cmath>
using namespace std;

bool checkCP(int n) {
    return (int) sqrt(n)*sqrt(n) == n;
}

bool checkNT(int n) {
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return false;
    return n > 1;
}

bool checkHH(int n) {
    int res = 0;
    for (int i = 1; i <= n/2; i++) 
        if (n % i == 0) res += i;
    return res == n;
} 
 
int main() {
    int k, n; cin >> k >> n;
    switch (k) {
        case 1: (!checkHH(n)) ? cout << "no" : cout << "yes"; break;
        case 2: (!checkNT(n)) ? cout << "no" : cout << "yes"; break;
        case 3: (!checkCP(n)) ? cout << "no" : cout << "yes"; break;
    } 
    return 0;
}