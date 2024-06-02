#include <bits/stdc++.h>
using namespace std;

int n;
int tong[2];
int menhGia[100];
char chia[100];
char nguoi[2] = {'A', 'B'};
vector<vector<char>> ketQua;

void Try(int x) {
    if (x > n) {
        if (tong[0] == tong[1]) {
            vector<char> tmp;
            for (int i = 1; i <= n; i++)
                tmp.push_back(chia[i]);
            ketQua.push_back(tmp);
        }
            
    } else {
        for (int i = 0; i <= 1; i++) {
            chia[x] = nguoi[i];
            tong[i] += menhGia[x];
            Try(x + 1);
            tong[i] -= menhGia[x];
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