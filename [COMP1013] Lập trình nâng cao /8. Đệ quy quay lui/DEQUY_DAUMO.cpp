#include <iostream>
#include <vector>
using namespace std;

struct ToaDo {
    int x, y;
};

int m, n, tong, Max;
vector<ToaDo> temp, ketqua;
ToaDo luu;

void quayLui(vector<vector<int>> &a, int x, int y) {
    if (x < 0 || x >= m || y < 0 || y >= n) {
        if (tong > Max) {
            Max = tong;
            ketqua = temp;
        }
        return;
    }
    
    tong += a[x][y];
    luu.x = x + 1;
    luu.y = y + 1;
    temp.push_back(luu);
    
    quayLui(a, x + 1, y);
    quayLui(a, x, y + 1);
    
    tong -= a[x][y];
    temp.pop_back();
}

int main() {
    cin >> m >> n;
    vector<vector<int>> a(m);

    for (auto &hang : a) {
        vector<int> cot(n);
        for (auto &giaTri : cot)
            cin >> giaTri;
        hang = cot;
    }

    quayLui(a, 0, 0);

    cout << Max << endl;
    for(auto &td : ketqua)
        cout << td.x << " " << td.y << endl;
    
    return 0;
}