#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int arr[1000], n = 0;
    while (cin >> arr[n]) n++;

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    
    return 0;
}