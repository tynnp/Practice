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

    double getDienTich() {
        return dienTich;
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

class Array {
private:
    int size;
    Tinh values[100];
public:
    Tinh &operator [] (int index) {
        return values[index];
    }

    friend istream &operator >> (istream &in, Array &arr) {
        in >> arr.size;
        in.ignore();
        for (int i = 0; i < arr.size; i++)
            in >> arr[i];
        return in;
    }

    Tinh danSoLonNhat() {
        Tinh res = values[0];
        for (int i = 1; i < size; i++)
            if (values[i] > res) res = values[i];
        return res;
    }

    double tongDienTich() {
        double res = 0;
        for (int i = 0; i < size; i++)
            res += values[i].getDienTich();
        return res;
    }

    friend ostream &operator << (ostream &out, Array arr) {
        out << arr.size << endl;
        out << arr.danSoLonNhat() << endl;
        out << fixed << setprecision(0) << arr.tongDienTich();
        return out;
    }
};

int main() {
    Array a;
    cin >> a;
    cout << a;
    return 0;
}