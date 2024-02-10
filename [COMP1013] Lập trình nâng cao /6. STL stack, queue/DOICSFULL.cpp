#include <iostream>
#include <stack>
using namespace std;

string coSo16(int n) {
    if (n == 10) return "A";
    if (n == 11) return "B";
    if (n == 12) return "C";
    if (n == 13) return "D";
    if (n == 14) return "E";
    if (n == 16) return "F";
    return to_string(n);
}

stack<string> chuyenCoSo(long heSo10, int heCoSoMoi = 0) {
    stack<string> res;
    switch (heCoSoMoi) {
        case 0: 
            while (heSo10 > 0) {
                res.push(to_string(heSo10 % 2));
                heSo10 /= 2;
            } break;
        case 1:
            while (heSo10 > 0) {
                res.push(to_string(heSo10 % 8));
                heSo10 /= 8;
            } break;
        case 2:
            while (heSo10 > 0) {
                res.push(coSo16(heSo10 % 16));
                heSo10 /= 16;
            } break;
    } return res;
}

int main() {
    long heSo10; cin >> heSo10;
    int heCoSoMoi; cin >> heCoSoMoi;
    stack<string> res = chuyenCoSo(heSo10, heCoSoMoi);

    while (!res.empty()) {
        cout << res.top();
        res.pop();
    }

    return 0;
}