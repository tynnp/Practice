#include <iostream>
using namespace std;
 
int main() {
    char x, y; 
    cin >> x >> y;
    for (char i = x; i <= y; i++)
        cout << char(i-32) << " ";
    return 0;
}