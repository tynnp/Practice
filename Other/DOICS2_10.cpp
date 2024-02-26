#include <iostream>
#include <cmath>
using namespace std;

int doi2sang10(string str) {
    int res = 0;
    for (int i = str.length()-1; i >= 0; i--)
        if (str[i] == '1') res += pow(2, str.length()-1-i);
    return res;
}

int main() {
    string str;
    cin >> str;
    cout << doi2sang10(str);
    return 0;
}