#include <iostream>
using namespace std;

int main() {
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    int res = 0;

    if (b == "-") res = stoi(a) - stoi(c);
    else if (b == "+") res = stoi(a) + stoi(c);
    else if (b == "*") res = stoi(a) * stoi(c);

    cout << (res == stoi(d) ? "True" : "False");
    return 0;
}