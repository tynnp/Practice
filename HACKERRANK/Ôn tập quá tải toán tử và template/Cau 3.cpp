#include <iostream>
using namespace std;

struct LopHoc {
    int maLop, siSo;
};

istream &operator >> (istream &in, LopHoc &obj) {
    in >> obj.maLop >> obj.siSo;
    return in;
}

ostream &operator << (ostream &out, LopHoc obj) {
    out << "Lop " << obj.maLop << " co " << obj.siSo << " hoc sinh";
    return out;
}

int operator + (LopHoc a, LopHoc b) {
    return a.siSo + b.siSo;
}

bool operator > (LopHoc a, LopHoc b) {
    return a.siSo > b.siSo;
}

int main() {
    LopHoc a, b;
    cin >> a >> b;
    cout << a << endl;
    cout << b << endl;
    cout << a + b << endl;
    cout << (a > b ? "TRUE" : "FALSE");
    return 0;
}