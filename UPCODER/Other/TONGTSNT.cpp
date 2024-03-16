#include <iostream>
using namespace std;

bool checkNT(int n) {
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return false;
    return n > 1;
}

int phanTich(int n) {
    int result = 0;
    int i = 2;
    
    while (n > 1) {
        while (n % i == 0) 
            n /= i,
            result += i;
        i++;
    }
    if (!checkNT(result)) return phanTich(result);
    else return result;
}

int main() {
    int n; 
    cin >> n;
    cout << phanTich(n);
    return 0;
}