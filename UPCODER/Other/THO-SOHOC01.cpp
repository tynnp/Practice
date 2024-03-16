#include <iostream>
using namespace std;

bool checkDoiXung(string str) {
    int len = str.length();
    for (int i = 0; i <= len/2; i++)
        if (str[i] != str[len-1-i]) 
            return false;
    return true;
}

char soLonNhat(string str) {
    char res = '0';
    for (int i = 0; i < str.length(); i++)
        if (res < str[i]) res = str[i];
    return res;
}

int main() {
    string str;
    cin >> str;
    cout << soLonNhat(str) << endl;
    cout << (checkDoiXung(str) ? "Co" : "Khong");
    return 0;
}