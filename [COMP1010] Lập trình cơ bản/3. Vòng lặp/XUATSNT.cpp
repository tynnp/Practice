#include <iostream>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; bool check = true;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        int tmp = 0;

        for (int j = 2; j*j <= i; j++)
            if (i % j == 0) tmp++;

        if (tmp == 0) {
            cout << i << " ";
            check = false;
        }
    }

    if (check) cout << -1;
    return 0;
}