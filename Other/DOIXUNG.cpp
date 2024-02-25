#include <iostream>
#include <algorithm>
using namespace std;

bool check(string str) {
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    int len = str.length();
    for (int i = 0; i < len/2; i++) 
        if (tolower(str[i]) != tolower(str[len-i-1])) return false;
    return true;
}

main() {
    int test;
    cin >> test;
    cin.ignore();

    while (test--) {
        string str;
        getline(cin, str);
        cout << check(str) << endl;
    }

    return 0;
}