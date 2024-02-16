#include <iostream>
#include <cmath>
using namespace std;

struct Diem {
    int x;
    int y;

    friend istream& operator >> (istream& in, Diem& other)  {
        in >> other.x >> other.y;
        return in;
    }

    friend ostream& operator << (ostream& out, Diem other) {
        out << "(" << other.x << "," << other.y << ")";
    }

    double khoangCach(Diem other) {
        return sqrt(pow(other.x - this->x, 2) + pow(other.y - this->y, 2));
    }

    bool operator == (Diem other) {
        return this->x == other.x && this->y == other.y;
    }
};

struct TamGiac {
    Diem a;
    Diem b;
    Diem c;

    friend istream& operator >> (istream& in, TamGiac& other) {
        in >> other.a >> other.b >> other.c;
        return in;
    }

    friend ostream& operator << (ostream& out, TamGiac other) {
        out << other.a << other.b << other.c;
        return out;
    }

    double chuViTamGiac() {
        return a.khoangCach(b) + b.khoangCach(c) + c.khoangCach(a);
    }

    double operator + (TamGiac other) {
        return this->chuViTamGiac() + other.chuViTamGiac();
    }

    bool operator < (TamGiac other) {
        return this->chuViTamGiac() < other.chuViTamGiac();
    }

    bool operator == (TamGiac other) {
        if ((this->a == other.a || this->a == other.b || this->a == other.c) &&
            (this->b == other.b || this->b == other.c || this->b == other.a) &&
            (this->c == other.c || this->c == other.a || this->c == other.b)) return true;
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TamGiac a, b; 
    cin >> a >> b;
    
    cout << a << endl;
    cout << b << endl;

    if (a < b) cout << "TRUE" << endl;
    else cout << "FALSE" << endl;

    if (a == b) cout << "TRUE" << endl;
    else cout << "FALSE" << endl;

    return 0;
}