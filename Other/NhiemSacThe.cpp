#include <iostream>
using namespace std;
 
int main() {
    char a, b; 
    cin >> a >> b;
    if (a == 'X' && b == 'X') cout << "F";
    else if (a == 'X' && b == 'Y') cout << "M";
    else if (a == 'Y' && b == 'X') cout << "M";
    else cout << "NHAP SAI";
    return 0;
}