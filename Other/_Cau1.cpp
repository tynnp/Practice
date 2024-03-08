#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct PhanSo {
    int tu, mau;

    friend istream &operator >> (istream &in, PhanSo &p) {
        in >> p.tu >> p.mau;
        return in;
    }

    friend ostream &operator << (ostream &out, PhanSo p) {
        out << p.tu << "/" << p.mau;
        return out;
    }

    void rutGon() {
        int ucln = __gcd(tu, mau);
        tu /= ucln;
        mau /= ucln;
    }
};

bool check(PhanSo p1, PhanSo p2) {
    return (double) p1.tu/p1.mau > (double) p2.tu/p2.mau;
}

int main() {
    vector<PhanSo> vt;
    PhanSo tmp;

    while (cin >> tmp)
        vt.push_back(tmp);

    PhanSo tuNho, mauLon;
    tuNho = vt[0], mauLon = vt[0];
    for (int i = vt.size()-1; i >= 0; i--) {
        cout << vt[i] << " ";
        if (tuNho.tu > vt[i].tu) tuNho = vt[i];
        if (mauLon.mau < vt[i].mau) mauLon = vt[i];
    }

    cout << endl;
    cout << tuNho << " " << mauLon << endl;

    sort(vt.begin(), vt.end(), check);
    for (int i = 0; i < vt.size(); i++)
        cout << vt[i] << " ";

    return 0;
}