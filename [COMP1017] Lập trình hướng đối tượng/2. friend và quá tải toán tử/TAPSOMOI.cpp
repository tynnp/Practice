#include <iostream>
#define endl '\n'
using namespace std;

class TapSoMoi {
private:
    int x, y, z, t;
public:
    TapSoMoi() {
        this->x = 0; 
        this->y = 0; 
        this->z = 0; 
        this->t = 0;
    }

    TapSoMoi(int a, int b, int c, int d) {
        this->x = a;
        this->y = b;
        this->z = c;
        this->t = d;
    }

    friend istream& operator >> (istream &in, TapSoMoi &tsm) {
        in >> tsm.x >> tsm.y >> tsm.z >> tsm.t;
        return in;
    }

    friend ostream& operator << (ostream &out, TapSoMoi tsm) {
        out << "[TapSoMoi] " << tsm.x << ";" << tsm.y << ";" << tsm.z << ";" << tsm.t;
        return out;
    }

    TapSoMoi operator + (TapSoMoi other) {
        TapSoMoi res;
        res.x = this->x + other.x;
        res.y = this->y + other.y;
        res.z = this->z + other.z;
        res.t = this->t + other.t;
        return res;
    }

    bool operator < (TapSoMoi other) {
        int n = this->x + this->y + this->z + this->t;
        int m = other.x + other.y + other.z + other.t;
        return n < m;
    }

    TapSoMoi& operator = (const TapSoMoi &other) {
        this->x = other.x;
        this->y = other.y;
        this->z = other.z;
        this->t = other.t;
        return *this;
    }

    TapSoMoi& operator++() {
        ++this->x;
        ++this->t;
        return *this;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TapSoMoi TAP1, TAP2;
    cin >> TAP1 >> TAP2;
    cout << TAP1 << endl << TAP2 << endl;
    cout << (TAP1 < TAP2 ? "true\n" : "false\n");
    cout << TAP1 + TAP2 << endl;
    cout << ++TAP1;
    return 0;
}