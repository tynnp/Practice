#include <bits/stdc++.h>
using namespace std;

int main() {
    string a = "Tat ca truong hop gian lan deu bi 0 diem toan bai thi";
    string b = "Moi truong hop giong bai nhau (do copy bai/chia se bai) deu bi 0 diem toan bai thi(khong can quan tam ai copy bai ai, khong quan tam co biet nhau hay khong)";
    int n;
    cin >> n;
    
    if (n & 1) {
        while (n--)
            cout << a << '\n';
    } else {
        n /= 2;
        while (n--)
            cout << b << '\n';
    }
   
    return 0;
}