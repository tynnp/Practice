#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int len = 2*n + 2;
    int arr[len];
    arr[1] = 1;

    for (int i = 2; i < len; i++) {
        if (i % 2 == 0) arr[i] = arr[i/2] + i/2;
        else arr[i] = (i/2)*(i/2) + arr[i/2]*arr[i/2 + 1];   
    }

    cout << arr[n];
}