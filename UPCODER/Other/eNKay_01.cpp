#include <iostream>
using namespace std;
 
int main() {
    string str; 
    cin >> str;
    while (str[0] == '0' || str[0] == '-') str.erase(0, 1);
    while (str[str.size()-1] == '0') str.erase(str.size()-1, 1);
    cout << str.size();
    return 0;
}