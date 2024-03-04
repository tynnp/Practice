#include <iostream>
using namespace std;

string daoNguoc(string str) {
    string res = "";
    for (int i = 0; i < str.length(); i++)
        res = str[i] + res;
    return res;
}

string check(string str) {
    string tmp = str, res = daoNguoc(tmp);
    
    for (int i = str.length()-1; i >= 0; i--) {
        if (str.find(res) != string::npos) return res;
        tmp.erase(i, 1);
        res = daoNguoc(tmp);
    }

    return str;
}

int main() {
    int test;
    string str;
    cin >> test;

    while (test--) {
        cin >> str;
        cout << check(str) << endl;
    }

    return 0;
}