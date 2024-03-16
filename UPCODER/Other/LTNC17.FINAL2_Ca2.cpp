#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct CanHo {
    string soNha;
    int soThanhVien;
    int luongDien;
    int luongNuoc;

    friend istream &operator >> (istream &in, CanHo &c) {
        in >> c.soNha >> c.soThanhVien >> c.luongDien >> c.luongNuoc;
        return in;
    }

    long long tienDien() {
        if (luongDien <= 100) return (luongDien*2484);
        if (luongDien <= 200) return 100*2484 + (luongDien-100)*2786;
        return 100*2484 + 100*2786 + (luongDien-200)*3503;
    }

    long long tienNuoc() {
        int dm1 = 4*soThanhVien;
        int dm2 = 6*soThanhVien;
        if (luongNuoc <= dm1) return luongNuoc*5300;
        if (luongNuoc <= dm2) return dm1*5300 + (luongNuoc-dm1)*10200;
        return dm1*5300 + (dm2-dm1)*10200 + (luongNuoc-dm2)*11400;
    }

    friend ostream &operator << (ostream &out, CanHo c) {
        out << c.soNha << " " << c.tienDien() << " " << c.tienNuoc();
        return out;
    }
};

int main() {
    int n;
    string f;
    CanHo fres;
    bool check = false;
    cin >> n >> f;
    
    vector<CanHo> vt(n);
    for (int i = 0; i < n; i++) {
        cin >> vt[i];
        if (vt[i].soNha == f) {
            fres = vt[i];
            check = true;
        }
    }

    sort(vt.begin(), vt.end(), [](CanHo a, CanHo b) {
        return a.tienDien() + a.tienNuoc() < b.tienDien() + b.tienNuoc();
    });

    for (int i = 0; i < n; i++)
        cout << vt[i] << endl;

    if (check) cout << "YES " << fres;
    else cout << "NO";

    return 0;
}