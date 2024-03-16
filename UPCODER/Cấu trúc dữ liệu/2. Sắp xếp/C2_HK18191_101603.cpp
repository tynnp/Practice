#include <iostream>
#include <algorithm>
using namespace std;

bool checkGiamDan(char a, char b) {
    return tolower(a) > tolower(b);
}

int main() {
    char c; 
    int n;
    cin >> c >> n;
    char arr[n];
    for (char &x : arr) cin >> x;

    if (c == 'A') sort(arr, arr + n, [] (char a, char b) {
        return (tolower(a) < tolower(b) || (tolower(a) == tolower(b) && a > b));
    });

    else if (c == 'D') sort(arr, arr + n, [] (char a, char b) {
        return (tolower(a) > tolower(b) || (tolower(a) == tolower(b) && a < b));
    });

    for (char x : arr) cout << x << " ";
    return 0;
}