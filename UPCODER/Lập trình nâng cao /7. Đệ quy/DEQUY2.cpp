#include <iostream>
#include <algorithm>
using namespace std;

int factorial(int n) {
    if (n < 1) return 1;
    return n * factorial(n-1);
}

void chuoiHoanVi(int n, string str) {
    if (str.length() == n) 
        cout << str << endl;
    else {
        for (int i = 1; i <= n; i++) {
            string number = to_string(i);
            auto check = str.find(number);
            if (check != string::npos) continue;
            else chuoiHoanVi(n, str + number);
        }
    } return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    string str;
    cin >> n;
    cout << factorial(n) << endl;
    chuoiHoanVi(n, str);
    return 0;
}