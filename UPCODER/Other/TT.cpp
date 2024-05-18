#include <bits/stdc++.h>
using namespace std;

int n, tongA(0), tongB(0);
int menhGia[100];
char chia[100];
vector<vector<char>> ketQua;

void Try(int x) {
    if (x > n) {
        if (tongA == tongB) {
            vector<char> tmp;
            for (int i = 1; i <= n; i++)
                tmp.push_back(chia[i]);
            ketQua.push_back(tmp);
        }
            
    } else {
        for (int i = 0; i <= 1; i++) {
            if (i == 0) {
                chia[x] = 'A';
                tongA += menhGia[x];
                Try(x + 1);
                tongA -= menhGia[x];
                
            } else {
                chia[x] = 'B';
                tongB += menhGia[x];
                Try(x + 1);
                tongB -= menhGia[x];
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> menhGia[i];
        
    Try(1);
    
    if (ketQua.empty()) cout << "khong chia duoc";
    else {
        cout << ketQua.size() << endl;
        for (auto x : ketQua) {
            for (auto y : x)
                cout << y << " ";
            cout << endl;
        }
    }
    
    return 0;
}