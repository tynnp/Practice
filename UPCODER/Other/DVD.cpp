#include <iostream>
using namespace std;
 
int main() {
    int n; 
    cin >> n;
    if (n > 10) cout << n*5000*0.9;
    else cout << n*5000;
    return 0;
}