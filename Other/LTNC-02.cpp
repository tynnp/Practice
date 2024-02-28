#include <iostream>
using namespace std;
 
int tich(int n) {
    if (n == 1) return 1;
    else return n*tich(n-1);
}

int tong(int n) {
    if (n == 1) return tich(1);
    else return tich(n) + tong(n-1);
}

int main() {
    int n; 
    cin >> n;
    cout << tong(n);
    return 0;
}