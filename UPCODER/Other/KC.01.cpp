#include <iostream>
using namespace std;
 
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << (c - a + b > 0 ? c - a + b : 0); 
    return 0;
}