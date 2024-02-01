#include <iostream>
using namespace std;

int main() {
    int index, value;
    cin >> index >> value;

    int arr[1000], n = 0;
    while (cin >> arr[n]) n++;

    for (int i = 0; i < n; i++) {
        if (i == index) cout << value << " ";
        cout << arr[i] << " ";
    }

    if (index == n) cout << value;
    return 0;
}