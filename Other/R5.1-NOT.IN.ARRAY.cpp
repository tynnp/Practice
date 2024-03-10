#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vt(300001, 0);

    while (n--) {
        int tmp;
        cin >> tmp;
        vt[tmp]++;
    }

    for (int i = 0; i < 300001; i++) {
        if (!vt[i]) {
            cout << i;
            break;
        }
    }

    return 0;
}