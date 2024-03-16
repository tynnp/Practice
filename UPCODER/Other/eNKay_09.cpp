#include <iostream>
using namespace std;
 
int main() {
    string str; 
    getline(cin, str);
    for (auto x : str) 
        cout << (char) tolower(x);
    return 0;
}