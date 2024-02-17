#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M; 
    cin >> N >> M;

    vector<int> vec;
    for (int i = 1; i <= N; i++)
        vec.push_back(i);

    vector<int>::iterator it = vec.begin();
    while(!vec.empty()) {
        int tmp = M;

        while (--tmp) {
            it++;
            if (it == vec.end())
                it = vec.begin();
        }

        cout << *it << " ";
        vec.erase(it);
        if (it == vec.end())
            it = vec.begin();
    }

    return 0;
}

// #include <iostream>
// #include <queue>
// using namespace std;

// int main() {
//     queue<int> q;
//     int n, m; 
//     cin >> n >> m;

//     for (int i = 1; i <= n; i++)
//         q.push(i);

//     int value = m;

//     while (!q.empty()) {
//         if (value == 1) {
//             cout << q.front() << " ";
//             value = m;
//         } else {
//             q.push(q.front());
//             value--;
//         }
//         q.pop();
//     }

//     return 0;
// }