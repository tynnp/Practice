#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; 
    cin >> n >> m;
    int arr[n*m];

    for (int i = 0; i < n*m; i++)
        cin >> arr[i];
    sort(arr, arr + n*m);

    int index = 0;
    for (int i = 0; i < n; i++) {
        int cnt = index;

        if (i % 2 == 0) {
            for (int j = cnt; j < cnt+m; j++) {
                cout << arr[j] << " ";
                index++;
            }
            cout << endl;

        } else {
            for (int j = cnt+m-1; j >= cnt; j--) {
                cout << arr[j] << " ";
                index++;
            }
            cout << endl;
        }
    }
    return 0;
}