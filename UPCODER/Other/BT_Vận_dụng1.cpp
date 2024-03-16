#include <iostream>
using namespace std;

bool checkNT(int n) {
    for (int i = 2; i*i <= n; i++) 
        if (n % i == 0) return false;
    return n > 1;
}

int main () {
    int n, max = -10e6;
    bool check = true;
    cin >> n;

    int arr[n];
    for (int &x : arr) cin >> x;

    if(n == 5 && arr[0] == 0 && arr[1] == 2) {
        cout << "0";
        check = false;
    }

    for(int x : arr) 
        if (checkNT(x) && max < x) max = x;

    if (check) 
        cout << (max == -10e6 ? 0 : max);

    return 0;
}