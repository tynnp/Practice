#include <iostream>
using namespace std;

int main() {
    string str;
    cin >> str;
    
    for (int i = 0; i < 3; i++) {
        if (str[i] == '9') str[i] = '0';
        else str[i] = str[i] + 1;
    }

    cout << str;
    return 0;
}