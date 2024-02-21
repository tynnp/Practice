#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    int arr[n];
    for (int &x : arr) cin >> x;

    bool check = false;
    for (int x : arr)
        if (x < 2004 && x % 2 == 0) 
            check = true;
    
    cout << (check ? "Yes" : "No");
    return 0;
}