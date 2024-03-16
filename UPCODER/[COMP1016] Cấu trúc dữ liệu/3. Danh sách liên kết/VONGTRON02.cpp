#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M; 
    cin >> N >> M;
    int arr[M], i = 0;
    for (int &x : arr) cin >> x;

    vector<int> vec;
    for (int i = 0; i < N; i++)
        vec.push_back(i);

    vector<int>::iterator it = vec.begin();

    while(!vec.empty()) {
        int tmp = arr[i++];

        while (--tmp) {
            it++;
            if (it == vec.end())
                it = vec.begin();
        }

        cout << *it << " ";
        vec.erase(it);
        if (it == vec.end())
            it = vec.begin();

        if (i == M) i = 0;
    }

    return 0;
}