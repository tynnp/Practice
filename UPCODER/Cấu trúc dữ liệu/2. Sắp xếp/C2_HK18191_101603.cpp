#include <bits/stdc++.h>
using namespace std;

bool check(char a, char b, char type) {
    if (type == 'A') {
        if (tolower(a) == tolower(b)) return a < b;
        return tolower(a) > tolower(b);
    }
    
    if (type == 'D') {
        if (tolower(a) == tolower(b)) return a > b;
        return tolower(a) < tolower(b);
    }
}

void sort(char arr[], int n, int type) {
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && check(arr[j-1], arr[j], type)) {
            swap(arr[j-1], arr[j]);
            j--;
        }
    }
}

int main() {
    char type;
    int n;
    cin >> type >> n;
    
    char arr[n];
    for (char &c : arr) cin >> c;
    
    sort(arr, n, type);
    for (char c : arr) cout << c << " ";
    return 0;
}