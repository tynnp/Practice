#include <iostream>
#include <cmath>
using namespace std;

void chuoiHoanVi(int n, int length, string str) {
    if (length == 0) 
        cout << str << endl;
    else {
        for (int i = 1; i <= n; i++) 
            chuoiHoanVi(n, length - 1, str + to_string(i));
    } return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, length; 
    cin >> n >> length;
    cout << pow(n, length) << endl;
    string str = "";
    chuoiHoanVi(n, length, str);
    return 0;
}