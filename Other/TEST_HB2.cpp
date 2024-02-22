#include <iostream>
#include <cmath>
#include <vector>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
 
struct ToaDo {
    int x, y;
};

double khoangCach(ToaDo p1, ToaDo p2) {
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

int main() {
    int n; 
    cin >> n;
    vector<ToaDo> DSTD(n);

    FOR(i, 0, n) 
        cin >> DSTD[i].x >> DSTD[i].y;

    ToaDo diemGanNhat = DSTD[0];
    FOR(i, 1, n)
        if (abs(DSTD[i].x) < abs(diemGanNhat.x) ||
        abs(DSTD[i].x == diemGanNhat.x && DSTD[i].y > diemGanNhat.y))
            diemGanNhat = DSTD[i];

    cout << "(" << diemGanNhat.x << "," << diemGanNhat.y << ")" << endl;
    
    double d_tmp = 0;
    ToaDo Diem_1, Diem_2;
    FOR(i, 0, n-1) {
        FOR(j, i+1, n) {
            double d = khoangCach(DSTD[i], DSTD[j]);
            if (d > d_tmp)
                d_tmp = d, 
                Diem_1 = DSTD[i], 
                Diem_2 = DSTD[j];
        }
    }

    cout << "(" << Diem_1.x << "," << Diem_1.y << ")" << " ";
    cout << "(" << Diem_2.x << "," << Diem_2.y << ")" << endl;

    bool kt = false;
    FOR (i, 0, n-1) {
        FOR(j, i+1, n) {
            if (DSTD[i].x == DSTD[j].x) {
                kt = true; break;
            }
        }
    }

    cout << (kt ? "YES" : "NO");
    return 0;
}