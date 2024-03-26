#include <iostream>
using namespace std;

const int MAX = 100;
int n, m;
int arr[MAX][MAX];
int res[MAX];
bool visited[MAX][MAX];
int cnt(0), k(0);

void check(int i, int j) {
    if (i == n && j == m) {
        int tmp = res[0];
        for (int x = 1; x < k; x++)
            if (res[x] != tmp && res[x] != 0) {
                cnt++;
                break;
            }
    } else {
        if (i + 1 <= n && arr[i+1][j] != -1 && !visited[i+1][j]) {
            res[k++] = arr[i+1][j];
            visited[i+1][j] = true;
            check(i + 1, j);
            --k;
            visited[i+1][j] = false;
        }
        if (j + 1 <= m && arr[i][j+1] != -1 && !visited[i][j+1]) {
            res[k++] = arr[i][j+1];
            visited[i][j+1] = true;
            check(i, j + 1);
            --k;
            visited[i][j+1] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++)
            cin >> arr[i][j];
    visited[1][1] = true;
    check(1, 1);
    cout << (cnt == 0 ? -1 : cnt);
    return 0;
}