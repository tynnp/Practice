#include <iostream>
#include <queue>
using namespace std;
 
int main() {
    queue<char> check;
    string s, t; 
    cin >> s >> t;
    for (char c : s) check.push(c);
    for (char c : t) if (c == check.front()) check.pop();
    if (!check.empty()) cout << "False";
    else cout << "True";
    return 0;
}