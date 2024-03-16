#include<iostream>
using namespace std;

int main() {
    int n, MAX = 0, MIN = 100000;
    cin >> n;
    int a[n];

    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > MAX) MAX = a[i];
        if (a[i] < MIN) MIN = a[i];
    }

    int dem = 0, MAX2 = 0;
    for(int i = 0; i < n; ++i) {
        if (a[i] != MAX){
            if (MAX2 < a[i]) MAX2 = a[i];
            ++dem;
        }
    }

    if (dem == 0) cout << 0;
    else cout << MAX2 - MIN;

    return 0;
}