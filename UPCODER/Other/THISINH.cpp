#include <iostream>
#include <algorithm>
using namespace std;

struct ThiSinh {
    string maThiSinh;
    string hoTen;
    double diemToan;
    double diemLy;
    double diemHoa;

    friend istream &operator >> (istream &in, ThiSinh &ts) {
        in >> ts.maThiSinh;
        in.ignore();
        getline(in, ts.hoTen);
        in >> ts.diemToan >> ts.diemLy >> ts.diemHoa;
        return in;
    }

    friend ostream &operator << (ostream &out, ThiSinh ts) {
        out << ts.maThiSinh << "-" << ts.hoTen << "-";
        out << ts.diemToan << "-" << ts.diemLy << "-" << ts.diemHoa;
        return out;
    }

    double tongDiem() {
        return diemToan + diemLy + diemHoa;
    }

    bool kiemTraDau() {
        return tongDiem() > 15 && (diemToan != 0 && diemHoa != 0 && diemLy != 0);
    }
};

int main() {
    int n;
    bool check = false;
    bool checkTS = true;
    cin >> n;

    ThiSinh arr[n];
    for (ThiSinh &x : arr) cin >> x;

    for (ThiSinh x : arr) cout << x << endl;

    for (ThiSinh x : arr) {
        if (x.kiemTraDau()) {
            if (check) cout << "-";
            cout << x.hoTen;
            checkTS = false;
            check = true;
        }
    }

    if (checkTS) cout << -1;
    cout << endl;

    sort(arr, arr + n, [](ThiSinh a, ThiSinh b) {
        return a.tongDiem() > b.tongDiem();
    });

    check = false;
    for (ThiSinh x : arr) {
        if (check) cout << "-";
        cout << x.hoTen;
        check = true;
    }

    return 0;
}