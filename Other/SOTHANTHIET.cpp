#include <iostream>
using namespace std;
 
int main() {
    int a, b, tong_b = 0, tong_a = 0; 
    cin >> a >> b;

    for (int i = 1; i < a; i++) 
        if (a % i == 0) tong_a += i;

    for (int i = 1; i < b; i++) 
        if (b % i == 0) tong_b += i;

    cout << (tong_a == b && tong_b == a ? "YES" : "NO");
    return 0;
}