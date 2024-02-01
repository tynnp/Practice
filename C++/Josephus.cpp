#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    int n, m; 
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        q.push(i);

    int value = m;

    while (!q.empty()) {
        if (value == 1) {
            cout << q.front() << " ";
            value = m;
        } else {
            q.push(q.front());
            value--;
        }
        q.pop();
    }

    return 0;
}