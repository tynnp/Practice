#include <iostream>
#include <set>
using namespace std;
 
int main() {
    set<string> s; 
    string str;
    while (cin >> str) s.insert(str);
    cout << s.size();
    return 0;
}