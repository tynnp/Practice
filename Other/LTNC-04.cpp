#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    queue<char> q;

    for (char c = 'a'; c <= 'f'; c++)
        q.push(c);

    cin >> n;
    for (int i = 0; i < n; i++) {
        q.push(q.front());
        q.pop();
    }

    while (!q.empty()) {
        cout << q.front();
        q.pop();
    }

    return 0;
}