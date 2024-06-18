#include <bits/stdc++.h>
using namespace std;

int n, m, s;
vector<int> vt[1001];
vector<bool> visited(1001, false);

void DFS(int u) {
    cout << u << " ";
    visited[u] = true;

    for (int v : vt[u]) 
        if (!visited[v]) DFS(v);
}

int main() {
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        vt[x].push_back(y);
        vt[y].push_back(x);
    }

    DFS(s);
    return 0;
}