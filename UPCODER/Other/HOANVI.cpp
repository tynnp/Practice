#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

void chuoiHoanVi(int n, string str) {
    if (str.length() == n) {
        for (char c : str) 
            cout << c << " ";
        cout << endl;
    } else {
        for (int i = 1; i <= n; i++) {
            string number = to_string(i);
            auto check = str.find(number);
            if (check != string::npos) continue;
            else chuoiHoanVi(n, str + number);
        }
    } 
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    string str;
    cin >> n;
    chuoiHoanVi(n, str);
    return 0;
}