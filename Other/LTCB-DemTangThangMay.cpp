#include <iostream>
using namespace std;

int main() {
    int vi_tri, thang_may, k; 
    cin >> vi_tri >> thang_may >> k;

    if (thang_may < 1 || thang_may > 11 || vi_tri < 1 || vi_tri > 11) cout << 0;
    
    else if (k == -1) {
        if (thang_may > vi_tri) cout << (11 - thang_may) + (11 - vi_tri);
        else cout << vi_tri - thang_may;

    } else if (k == -2) {
        if (thang_may > vi_tri) cout << thang_may - vi_tri;
        else cout << thang_may + vi_tri - 2;

    } else cout << 0;

    return 0;
}