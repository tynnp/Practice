#include <iostream>
#include <cmath>
using namespace std;

const double EPSILON = 1e-9; 

struct Diem {
    double x, y;

    friend istream &operator >> (istream &in, Diem &diem) {
        in >> diem.x >> diem.y;
        return in;
    }

    friend ostream &operator << (ostream &out, Diem diem) {
        out << "(" << diem.x << "," << diem.y << ")";
        return out;
    }

    double doDai(Diem other) {
        return sqrt(pow(other.x - x, 2) + pow(other.y - y, 2));
    }
}; 

bool kiemTraTamGiac(double AB, double BC, double CA) {
    return AB + BC > CA && AB + CA > BC && BC + CA > AB;
}

bool tamGiacVuong(double AB, double BC, double CA) {
    return abs(AB*AB + BC*BC - CA*CA) < EPSILON || abs(BC*BC + CA*CA - AB*AB) < EPSILON || abs(AB*AB + CA*CA - BC*BC) < EPSILON;
}

char gocVuong(double AB, double BC, double CA) {
    if (abs(AB*AB + BC*BC - CA*CA) < EPSILON) return 'B';
    else if (abs(BC*BC + CA*CA - AB*AB) < EPSILON) return 'C';
    else if (abs(AB*AB + CA*CA - BC*BC) < EPSILON) return 'A';
}

int main() {
    Diem A, B, C;
    double AB, BC, CA;
    cin >> A >> B >> C;

    AB = A.doDai(B);
    BC = B.doDai(C);
    CA = C.doDai(A);

    cout << A << "," << B << "," << C << endl;
    if (kiemTraTamGiac(AB, BC, CA)) { 
        cout << "CO\n";
        if (tamGiacVuong(AB, BC, CA)) cout << gocVuong(AB, BC, CA);
    } else cout << "KHONG";

    return 0;
}
