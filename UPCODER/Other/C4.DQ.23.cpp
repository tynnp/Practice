#include <bits/stdc++.h>
using namespace std;

string binary(int n) {
    if (n == 0) return "0";
    return binary(n/2) + to_string(n % 2);
}

int main() {
    int n;
    cin >> n;
    string str = binary(n);
    while(str[0] == '0' && str.size() > 1) str.erase(0, 1);
    cout << str;
    return 0;
}