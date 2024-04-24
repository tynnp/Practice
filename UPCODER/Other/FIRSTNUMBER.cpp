#include <iostream>
using namespace std;

int main() {
    string n, str = "";
    cin >> n;

    for (int i = 1; i <= 100000; i++)
        str += to_string(i);

    cout << str.find(n) + 1;
    return 0;
}