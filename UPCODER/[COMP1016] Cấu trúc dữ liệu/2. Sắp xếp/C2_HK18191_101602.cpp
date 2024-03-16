#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    char c; 
    int n;
    cin >> c >> n;
    char arr[n];
    for (char& x : arr) cin >> x;

    if (c == 'A') sort(arr, arr + n);
    else if (c == 'D') sort(arr, arr + n, greater<char>());

    for (char x : arr) cout << x << " ";
    return 0;
}