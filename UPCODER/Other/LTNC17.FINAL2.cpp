#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct CanHo {
    string soNha;
    int luongDien;
    int luongNuoc;

    friend istream &operator >> (istream &in, CanHo &c) {
        in >> c.soNha >> c.luongDien >> c.luongNuoc;
        return in;
    }

    long long tienDien() {
        if (luongDien <= 100) return luongDien*1484;
        if (luongDien <= 200) return 100*1484 + (luongDien-100)*1786;
        return 100*1484 + 100*1786 + (luongDien-200)*2503;
    }

    long long tienNuoc() {
        if (luongNuoc <= 10) return luongNuoc*5973;
        if (luongNuoc <= 30) return 10*5973 + (luongNuoc-10)*7052;
        return 10*5973 + 20*7052 + (luongNuoc-30)*15929;
    }

    friend ostream &operator << (ostream &out, CanHo c) {
        out << c.soNha << " " << c.tienDien() << " " << c.tienNuoc();
        return out;
    }
};

int main() {
    int n;
    string f;
    bool check = true;
    cin >> n >> f;
    
    vector<CanHo> vt(n);
    for (int i = 0; i < n; i++) {
        cin >> vt[i];
        if (vt[i].soNha == f) {
            cout << "FOUND " << vt[i] << endl;
            check = false;
        }
        if (i == n-1 && check) cout << "NOT FOUND\n";
    }

    sort(vt.begin(), vt.end(), [](CanHo a, CanHo b) {
        return a.tienDien() + a.tienNuoc() > b.tienDien() + b.tienNuoc();
    });

    for (int i = 0; i < n; i++)
        cout << vt[i] << endl;

    return 0;
}