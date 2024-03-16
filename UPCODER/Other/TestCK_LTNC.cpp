#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct Diem {
    int x;
    int y;
    static double tinhKhoangCach(Diem);
    static double tinhKhoangCach(Diem, Diem);
    static void diemXaNhat(vector<Diem>);
    static void haiDiemXaNhat(vector<Diem>);
    static void diemTungDoMax(vector<Diem>);
    friend istream& operator >> (istream&, Diem&);
    friend ostream& operator << (ostream&, Diem);
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<Diem> arr(n);
    for (Diem& a : arr) cin >> a;
    Diem::diemXaNhat(arr);
    Diem::haiDiemXaNhat(arr);
    Diem::diemTungDoMax(arr);
    return 0;
}

double Diem::tinhKhoangCach(Diem a) {
    return sqrt(pow(-a.x, 2) + pow(-a.y, 2));
}

double Diem::tinhKhoangCach(Diem a, Diem b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

void Diem::diemXaNhat(vector<Diem> vt) {
    vector<Diem>::iterator it;
    Diem k = vt[0]; double max = -99;
    for (it = vt.begin(); it != vt.end(); it++) {
        double d = tinhKhoangCach(*it);
        if (d > max) max = d, k = *it;
    }
    cout << k << endl;
}

void Diem::haiDiemXaNhat(vector<Diem> vt) {
    double kc = 0; Diem a = vt[0], b = vt[1];
    for (int i = 0; i < vt.size(); i++) {
        for (int j = i + 1; j < vt.size(); j++) {
            double d = tinhKhoangCach(vt[i], vt[j]);
            if (d > kc) kc = d, a = vt[i], b = vt[j];
        }
    }
    cout << a << " " << b << endl;
}

void Diem::diemTungDoMax(vector<Diem> vt) {
    vector<Diem>::iterator it;
    Diem tungMax = vt[0];
    for (it = vt.begin()+1; it != vt.end(); it++) {
        if (tungMax.y <= it->y) {
            if (tungMax.y == it->y) {
                if (tungMax.x < it->x) tungMax = *it;
            } else tungMax = *it;
        }
    }
    cout << tungMax;
}

istream& operator >> (istream& in, Diem &a) {
    in >> a.x >> a.y;
}

ostream& operator << (ostream& out, Diem a) {
    out << "(" << a.x << "," << a.y << ")";
}