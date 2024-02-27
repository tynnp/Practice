#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int m, n;
vector<vector<int>> land;
vector<vector<bool>> visited;
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

void dfs(int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && 
            land[nx][ny] == 1 && !visited[nx][ny])
                dfs(nx, ny);
    }
}

int count() {
    int count = 0;
    for (int i = 0; i < m; i++) 
        for (int j = 0; j < n; j++) 
            if (land[i][j] == 1 && !visited[i][j]) 
                dfs(i, j), count++;
    return count;
}

int main() {
    ifstream fin("INPUT.TXT");
    ofstream fout("OUTPUT.TXT");

    fin >> m >> n;
    land.resize(m, vector<int>(n));
    visited.resize(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++) 
        for (int j = 0; j < n; j++) 
            fin >> land[i][j];

    int num = count();
    fout << num << endl;

    fin.close();
    fout.close();
    return 0;
}