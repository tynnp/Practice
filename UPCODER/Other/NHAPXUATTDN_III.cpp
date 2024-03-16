#include <iostream>
using namespace std;

int main() {
    string str, kt;
    getline(cin, str);
    getline(cin, kt);

    for (char c : str) {
        if (c == ' ') cout << kt;
        else cout << c;
    }

    return 0;
}