#include <iostream>
#include <queue>
using namespace std;

int main() {
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