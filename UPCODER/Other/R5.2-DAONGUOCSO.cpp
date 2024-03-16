#include <iostream>
using namespace std;
 
void xoaSo0(string &str, int a, int b) {
    for(int i = a; i < b; i++) {
        if (str[i] == '0') str.erase(i--, 1);
        else break;
    }

    for(int i = str.size()-1; i >= a; i--) {
        if (str[i] == '0') str.erase(i, 1);
        else break;
    } 

    return;
}

int main() {
    string str; 
    cin >> str;

    if (str[0] == '-') {
        xoaSo0(str, 1, str.size()); cout << str[0];
        for (int i = str.size()-1; i >= 1; i--) cout << str[i];
    }

    else { 
        xoaSo0(str, 0, str.size());
        for (int i = str.size()-1; i >= 0; i--) cout << str[i];
    }
    
    return 0;
}