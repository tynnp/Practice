#include <iostream>
using namespace std;

int tongChan(int n) {
    int res = 0;

    while (n > 0) {
        if (n%10 % 2 == 0) 
            res += n%10;
        n /= 10;
    }

    return res;
}

int main() {
    int n;
    cin >> n;
    cout << tongChan(n);
    return 0;
}