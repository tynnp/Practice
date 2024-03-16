#include <iostream>
using namespace std;
 
int main() {
    string str; 
    char ch;

    while (cin >> ch) 
        if (ch != 'A' && ch != 'a') 
            str += (ch == 'u' ? 'o' : ch);

    cout << str;
    return 0;
}