#include <iostream>
#include <stack>
using namespace std;

void chuyenCoSo(long heSo10, int heCoSoMoi);
void deQuyCS2(stack<string> st, int n);
void deQuyCS8(stack<string> st, int n);
void deQuyCS16(stack<string> st, int n);

int main() {
    long heSo10; cin >> heSo10;
    int heCoSoMoi; cin >> heCoSoMoi;
    chuyenCoSo(heSo10, heCoSoMoi);
    return 0;
}

void deQuyCS2(stack<string> st, int n) {
    if (n == 0) {
        while (!st.empty()) {
            cout << st.top();
            st.pop();
        } return;
    } else {
        st.push(to_string(n % 2));
        return deQuyCS2(st, n/2);
    }
}

void deQuyCS8(stack<string> st, int n) {
    if (n == 0) {
        while (!st.empty()) {
            cout << st.top();
            st.pop();
        } return;
    } else {
        st.push(to_string(n % 8));
        return deQuyCS8(st, n/8);
    }
}

void deQuyCS16(stack<string> st, int n) {
    string coSo16 = "0123456789ABCDEF";
    if (n == 0) {
        while (!st.empty()) {
            cout << st.top();
            st.pop();
        } return;
    } else {
        st.push(string(1, coSo16[n % 16]));
        return deQuyCS16(st, n/16);
    }
}

void chuyenCoSo(long heSo10, int heCoSoMoi = 0) {
    stack<string> st;
    switch (heCoSoMoi) {
        case 0:
            deQuyCS2(st, heSo10);
            break;
        case 1:
            deQuyCS8(st, heSo10);
            break;
        case 2:
            deQuyCS16(st, heSo10);
            break;
    }
    return;
}