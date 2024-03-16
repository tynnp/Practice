#include <iostream>
#include <cmath>
using namespace std;

bool check(int n) {
    return (int) sqrt(n) == sqrt(n);
}

int main() {
    int a, b;
    cin >> a >> b;

    for (int i = a; i <= b; i++)
        if (check(i)) cout << i << endl;
        
    return 0;
}