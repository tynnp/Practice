#include <iostream>
using namespace std;

struct SoMoi {
    int number;

    friend istream& operator >> (istream &in, SoMoi &soMoi) {
        in >> soMoi.number;
        return in;
    }

    friend ostream& operator << (ostream &out, SoMoi soMoi) {
        out << "[SoMoi] " << soMoi.number;
        return out;
    }

    int tongChuSo() {
        int res = 0, tmp = this->number;
        while (tmp > 0) 
            res += tmp % 10,
            tmp /= 10;
        return res;
    }

    bool operator > (SoMoi soMoi) {
        return this->tongChuSo() > soMoi.tongChuSo();
    }

    SoMoi operator + (SoMoi soMoi) {
        SoMoi res;
        res.number = this->tongChuSo() + soMoi.tongChuSo();
        return res;
    }
};

int main() {
    SoMoi a, b; 
    cin >> a >> b;
    cout << a << endl;
    cout << b << endl;
    cout << (a > b ? "true" : "false") << endl;
    cout << a + b;
    return 0;
}