#include <iostream>
using namespace std;

void tamGiac(int n) {
    if (n == 1) cout << "*\n";
    else {
        tamGiac(n - 1);
        for (int i = 0; i < n; i++)
            cout << '*';
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    tamGiac(n);
    return 0;
}