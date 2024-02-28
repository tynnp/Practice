#include <iostream>
using namespace std;
 
int main() {
    int a, b; 
    cin >> a >> b;
    if (a % 2 != 0) a = -a;
    if (b % 2 == 0) b = -b;
    cout << a*b;
    return 0;
}