#include <iostream>
using namespace std;
 
int main() {
    string str; 
    getline(cin, str); 
    str[0] = toupper(str[0]);

    for (int i = 1; i < str.size(); i++) {
        if (str[i-1] == ' ' && str[i] != ' ') str[i] = toupper(str[i]);
        else if (str[i-1] == ' ') str.erase(--i, 1);
        else str[i] = tolower(str[i]);
    } 
    
    cout << str;
    return 0;
}