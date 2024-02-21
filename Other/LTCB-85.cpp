#include <iostream>
using namespace std;

int main() {
    int n; 
    cin >> n; 
    cout << "Quy ";
    if (n <= 3) cout << 1;
    else if (n <= 6) cout << 2;
    else if (n <= 9) cout << 3;
    else cout << 4;
    return 0;
}