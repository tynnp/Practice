#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, money = 0; 
    cin >> n;
    if (n < 17) money = n*7000;
    else if (n < 51) money = 16*7000 + (n-16)*8500;
    else if (n > 50) money = 16*7000 + 34*8500 + (n-50)*100000;
    cout << money;
    return 0;
}