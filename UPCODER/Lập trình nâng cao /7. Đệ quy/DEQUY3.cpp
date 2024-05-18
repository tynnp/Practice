#include <iostream>
#include <algorithm>
using namespace std;

int k, n;
int arr[100];
bool check[100];

void print() {
    for (int i = 1; i <= k; i++)
        cout << arr[i];
    cout << endl;
}

void Try(int i) {
    for (int j = 1; j <= n; j++) {
        if (check[j]) {
            arr[i] = j;
            if (i == k) print();
            else {
                check[j] = false;
                Try(i+1);
                check[j] = true;
            }
        }
    }
}

int main() {
    cin >> k >> n;
    fill(check, check+100, true);
    Try(1);
    return 0;
}