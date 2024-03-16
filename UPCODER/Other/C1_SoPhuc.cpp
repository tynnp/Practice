#include <iostream>
using namespace std;

class SoPhuc {
private:
    int thuc, ao;
public:
    void setThuc(int thuc) {
        this->thuc = thuc;
    }

    int getThuc() {
        return thuc;
    }

    void setAo(int ao) {
        this->ao = ao;
    }

    int getAo() {
        return ao;
    }

    SoPhuc(int k = 1) {
        thuc = ao = k;
    }

    SoPhuc(int thuc, int ao) {
        this->thuc = thuc;
        this->ao = ao;
    }

    friend istream &operator >> (istream &in, SoPhuc &s) {
        in >> s.thuc >> s.ao;
        return in;
    }

    friend ostream &operator << (ostream &out, SoPhuc s) {
        out << s.thuc << "+" << s.ao << "i";
        return out;
    }

    SoPhuc operator + (SoPhuc other) {
        SoPhuc res;
        res.thuc = thuc + other.thuc;
        res.ao = ao + other.ao;
        return res;
    }

    SoPhuc operator - (SoPhuc other) {
        SoPhuc res;
        res.thuc = thuc - other.thuc;
        res.ao = ao - other.ao;
        return res;
    }
};

int main() {
    SoPhuc a, b;
    cin >> a >> b;
    cout << a << endl;
    cout << b << endl;
    cout << a + b << endl;
    cout << a - b << endl;
    return 0;
}