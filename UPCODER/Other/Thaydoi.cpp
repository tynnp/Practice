#include <iostream>
using namespace std;

int n;

void check(int &x, string str) {
    if (str == "plus1") x++;
    else if (str == "minus1") x--;
    else if (str == "reset") x = n;
    cout << x << " ";
}

int main() {
    cin >> n;
    int m = n;
    string str;
    while (cin >> str) 
        check(m, str);
    return 0;
}