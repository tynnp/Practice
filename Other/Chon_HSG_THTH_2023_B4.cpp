#include <iostream>
using namespace std;

int daoNguoc(int n) {
    int res = 0;
    while (n > 0) 
        res = res*10 + n%10,
        n /= 10;
    return res;
}

int uocChung(int a, int b) {
    if (b == 0) return a;
    return uocChung(b, a % b);
}

bool checkBB(int a) {
    return uocChung(a, daoNguoc(a)) == 1;
}
 
int main() {
    int n; 
    cin >> n;
    cout << (checkBB(n) ? "YES" : "NO");
    return 0;
}