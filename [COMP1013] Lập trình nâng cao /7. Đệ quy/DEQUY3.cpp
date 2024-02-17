#include <iostream>
#include <algorithm>
using namespace std;

void chuoiHoanVi(int n, int k, string str) {
    if (str.length() == n) 
        cout << str << endl;
    else {
        for (int i = 1; i <= k; i++) {
            string number = to_string(i);
            auto check = str.find(number);
            if (check != string::npos) continue;
            else chuoiHoanVi(n, k, str + number);
        }
    } return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k; 
    string str;
    cin >> n >> k;
    chuoiHoanVi(n, k, str);
    return 0;
}