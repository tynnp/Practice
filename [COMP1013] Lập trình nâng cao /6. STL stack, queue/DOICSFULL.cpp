#include <iostream>
#include <stack>
using namespace std;

void chuyenCoSo(long heSo10, int heCoSoMoi);

int main() {
    long heSo10; cin >> heSo10;
    int heCoSoMoi; cin >> heCoSoMoi;
    chuyenCoSo(heSo10, heCoSoMoi);
    return 0;
}

void chuyenCoSo(long heSo10, int heCoSoMoi = 0) {
    stack<string> stackRes;
    string coSo16 = "0123456789ABCDEF";
    switch (heCoSoMoi) {
        case 0: 
            while (heSo10 > 0) {
                stackRes.push(to_string(heSo10 % 2));
                heSo10 /= 2;
            } break;
        case 1:
            while (heSo10 > 0) {
                stackRes.push(to_string(heSo10 % 8));
                heSo10 /= 8;
            } break;
        case 2:
            while (heSo10 > 0) {
                stackRes.push(string(1, coSo16[heSo10 % 16]));
                heSo10 /= 16;
            } break;
    }

    while (!stackRes.empty()) {
        cout << stackRes.top();
        stackRes.pop();
    }

    return;
}