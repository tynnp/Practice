#include <iostream>
using namespace std;

int main() {
    int n, sum(0);
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> *(arr + i);
        sum += *(arr + i);
    }

    cout << sum;
    delete[] arr;
    return 0;
}