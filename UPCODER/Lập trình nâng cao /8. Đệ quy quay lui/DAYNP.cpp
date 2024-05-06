#include <iostream>
using namespace std;

int n, arr[100];

void print() {
    for (int i = 1; i <= n; i++)
        cout << arr[i];
    cout << endl;
}

void nhiPhan(int i) {
    for (int j = 0; j <= 1; j++) {
        arr[i] = j;
        if (i == n) print();
        else nhiPhan(i + 1);
    }
}

int main() {
    cin >> n;
    nhiPhan(1);
    return 0;
}
