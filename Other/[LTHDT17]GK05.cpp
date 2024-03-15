#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

class Tinh {
private:
    string maTinh;
    string tenTinh;
    long long danSo;
    double dienTich;
public:
    Tinh() {}

    Tinh(string maTinh, string tenTinh, long long danSo, double dienTich) {
        this->maTinh = maTinh;
        this->tenTinh = tenTinh;
        this->danSo = danSo;
        this->dienTich = dienTich;
    }

    Tinh(const Tinh &other) {
        maTinh = other.maTinh;
        tenTinh = other.tenTinh;
        danSo = other.danSo;
        dienTich = other.dienTich;
    }

    friend istream &operator >> (istream &in, Tinh &t) {
        string str, tmp;
        vector<string> vt;
        getline(in, str);

        stringstream ss(str);
        while (ss >> tmp) vt.push_back(tmp);

        t.dienTich = stod(vt.back()); vt.pop_back();
        t.danSo = stoll(vt.back()); vt.pop_back();
        t.maTinh = vt.front();

        t.tenTinh = "";
        for (int i = 1; i < vt.size(); i++)
            t.tenTinh += " " + vt[i];

        return in;
    }

    friend ostream &operator << (ostream &out, Tinh t) {
        out << "(" << t.maTinh << ")" << t.tenTinh;
        return out;
    }

    bool operator > (Tinh other) {
        return danSo > other.danSo;
    }

    double operator + (Tinh other) {
        return dienTich + other.dienTich;
    }
};

int main() {
    Tinh a, b;
    cin >> a >> b;
    cout << a << endl;
    cout << b << endl;
    cout << (a > b ? "true" : "false") << endl;
    cout << fixed << setprecision(0) << a + b;
    return 0;
}