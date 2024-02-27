#include <iostream>
using namespace std;

int main() {
    int n; 
    cin >> n;
    cout << (1 << n) - 1;
    return 0;
}