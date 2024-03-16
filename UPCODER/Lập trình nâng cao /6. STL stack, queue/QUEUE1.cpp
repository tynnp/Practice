#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str; 
    getline(cin, str);
    queue<char> charQueue;

    for (char c : str) {
        if (c == '*' && !charQueue.empty()) {
            cout << charQueue.front();
            charQueue.pop();
        } else if (c != '*')
            charQueue.push(c); 
    }

    return 0;
}