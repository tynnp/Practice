#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string L[100][100][100];
string chuoi1, chuoi2, chuoi3;
int dodai1, dodai2, dodai3;

string timChuoiDaiNhat(string a, string b) {
    if (a.size() > b.size()) return a;
    if (b.size() > a.size()) return b;
    
    for (int i = 0; i < a.size(); i++) {
        if (a[i] > b[i]) return a;
        else if (a[i] < b[i]) return b;
    }
    
    return a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> chuoi1 >> chuoi2 >> chuoi3; 
    dodai1 = chuoi1.size(); 
    dodai2 = chuoi2.size(); 
    dodai3 = chuoi3.size();
    chuoi1 = ' ' + chuoi1; 
    chuoi2 = ' ' + chuoi2; 
    chuoi3 = ' ' + chuoi3;
    
    for (int i = 0; i <= dodai1; i++) 
        for (int j = 0; j <= dodai2; j++) 
            for (int k = 0; k <= dodai3; k++) 
                if (i == 0 || j == 0 || k == 0) 
                    L[i][j][k] = "";
    
    for (int i = 1; i <= dodai1; i++) {
        for (int j = 1; j <= dodai2; j++) {
            for (int k = 1; k <= dodai3; k++) {
                if (chuoi1[i] == chuoi2[j] && chuoi1[i] == chuoi3[k]) {
                    L[i][j][k] = L[i - 1][j - 1][k - 1] + chuoi1[i];
                } else {
                    string tmp;
                    tmp = timChuoiDaiNhat(L[i - 1][j][k], timChuoiDaiNhat(L[i][j - 1][k], L[i][j][k - 1]));
                    L[i][j][k] = tmp;
                }
            }
        }
    }
    
    cout << L[dodai1][dodai2][dodai3];
    return 0;
}
