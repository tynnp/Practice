#include <iostream>
using namespace std;
 
bool checkChar(char x) {
    if (x >= 'A' && x <= 'Z') return true;
    if (x >= 'a' && x <= 'z') return true;
    return false;
}

int main() {
    int cnt = 0;
    string str; 
    cin >> str; 

    for (int i = 1; i < str.size(); i++)
        if (checkChar(str[i-1]) && !checkChar(str[i])) cnt++;
    if (!checkChar(str[0])) cnt++;
    
    cout << cnt;
    return 0;
}