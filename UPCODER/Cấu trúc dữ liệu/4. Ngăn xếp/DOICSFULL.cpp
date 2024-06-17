#include <bits/stdc++.h>
using namespace std;

void chuyenCoSo(long soHe10, int heCoSoMoi);

int main() {
    long soHe10;
    int heCoSoMoi;
    cin >> soHe10 >> heCoSoMoi;
    chuyenCoSo(soHe10, heCoSoMoi);
    return 0;
}

void chuyenCoSo(long soHe10, int heCoSoMoi = 0) {
    string kt = "0123456789ABCDEF";
    stack<char> s;
    int type;
    
    if (soHe10 == 0) {
        cout << 0;
        return;
    }
    
    switch (heCoSoMoi) {
        case 0: type = 2; break;
        case 1: type = 8; break;
        case 2: type = 16; break;
    }
    
    while (soHe10) {
        s.push(kt[soHe10 % type]);
        soHe10 /= type;
    }
    
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
}