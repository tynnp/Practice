#include <iostream>
using namespace std;
 
int main() {
    char ch, max = 0;

    while (cin >> ch) {
        if (ch == '0') break;
        else if (max < ch) max = ch;
    }
    
    cout << (char) max;
    return 0;
}