#include <iostream>
using namespace std;
 
bool check(int a, int b) {
    if (b == 0) return (a == 1);
    return check(b, a % b);
}

int daoNguoc(int a) {
    int res = 0;

    while (a) 
        res = res*10 + a%10,
        a /= 10;

    return res;
}

int main() {
    int a; 
    cin >> a;
    cout << (check(a, daoNguoc(a)) ? "YES" : "NO");
    return 0;
}