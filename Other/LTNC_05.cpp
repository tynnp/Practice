#include <iostream>
using namespace std;

int main() {
    string str;
    bool check = false;
    bool space = false;
    getline(cin, str);

    for (char c : str) {
        if (c == '-') {
            check = true;
            if (space) cout << " ";
        } else if (c == '+') check = false;

        if (check) {
            cout << c;
            space = true;
        }
    }

    return 0;
}