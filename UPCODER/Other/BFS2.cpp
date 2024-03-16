#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, m, s, t;
vector<int> vt[1001];
bool visited[1001];
int res[1001];

void BFS(int u) {
    queue<int> q;
    q.push(u);
    visited[u] = true;
    
    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int x : vt[v]) {
            if (!visited[x]) {
                q.push(x);
                visited[x] = true;
                res[x] = v; 
            }
        }
    }
}

void printShortestPath() {
    vector<int> path;
    int current = t;
    while (current != s) {
        path.push_back(current);
        current = res[current];
    }
    path.push_back(s);
    
    for (int i = path.size() - 1; i >= 0; --i) 
        cout << path[i] << " ";
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
    BFS(s);
    printShortestPath();
    
    return 0;
}
