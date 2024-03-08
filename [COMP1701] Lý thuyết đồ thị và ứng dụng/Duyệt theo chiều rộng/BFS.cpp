#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, m, s;
vector<int> vt[1001];
bool visited[1001];

void BFS(int u) {
    queue<int> q;
    q.push(u);
    visited[u] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for (int x : vt[v]) {
            if (!visited[x]) {
                q.push(x);
                visited[x] = true;
            }
        }
    }
}

int main() {
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int x, y; 
        cin >> x >> y;
        vt[x].push_back(y);
        vt[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));

    BFS(s);
    return 0;
}
