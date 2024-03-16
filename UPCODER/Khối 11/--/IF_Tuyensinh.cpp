#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    double diemChuan, mon1, mon2, mon3, diemtb;
    int doiTuong; char khuVuc;

    cin >> diemChuan >> mon1 >> mon2 >> mon3;
    cin >> khuVuc >> doiTuong;
    diemtb = (mon1 + mon2 + mon3);

    switch (doiTuong) {
        case 1: diemtb += 2.5; break;
        case 2: diemtb += 1.5; break;
        case 3: diemtb += 1.0; break;
    }

    switch (khuVuc) {
        case 'A': diemtb += 2.0; break;
        case 'B': diemtb += 1.0; break;
        case 'C': diemtb += 0.5; break;
    }

    if (diemtb >= diemChuan && mon1 > 0 && mon2 > 0 && mon3 > 0) cout << "PASS";
    else cout << "FAIL";
    return 0;
}   