#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int size, cnt = 0; 
    queue<int> q;
    vector<int> vt (1000001, 0);

    cin >> size;
    while (size--) {
        int tmp; cin >> tmp;
        q.push(tmp);
    }

    while (!q.empty()) {
        int k = q.front();

        if (vt[k] == 0) {
            cnt += 1;
            vt[k-1] += 1;

        } else {
            vt[k] -= 1;
            vt[k-1] += 1;
        }

        q.pop();
    }
    
    cout << cnt;
    return 0;
}