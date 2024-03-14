#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, m, s, t;
vector<int> vt[1001];
bool visited[1001];
int cnt[1001];

void BFS(int u) {
    queue<int> q;
    q.push(u);
    visited[u] = true;
    cnt[u] = 0;
    
    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int x : vt[v]) {
            if (!visited[x]) {
                q.push(x);
                visited[x] = true;
                cnt[x] = cnt[v] + 1;
            }
        }
    }
}

int main() {
    cin >> n >> m >> s >> t;
    
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        vt[x].push_back(y);
        vt[y].push_back(x);
    }

    memset(visited, false, sizeof(visited));
    memset(cnt, -1, sizeof(cnt));

    BFS(s);
    cout << cnt[t];
    return 0;
}