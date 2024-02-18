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

template<typename T>
class Array {
public:
    int size = 0;
    T values[1000];

    friend istream& operator >> (istream &in, Array &arr) {
        T n; 
        while (cin >> n) 
            arr.values[arr.size++] = n;
        return in;
    }

    T tongDaySo() {
        T res = this->values[0];
        for (int i = 1; i < this->size; i++)
            res = this->values[i] + res;
        return res;
    }

    friend ostream& operator << (ostream &out, Array arr) {
        T max = arr.values[0];

        for (int i = 1; i < arr.size; i++) 
            if (max < arr.values[i]) 
                max = arr.values[i];

        out << max << endl;
        return out;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    char c; cin >> c;
    Array<int> arrInt;
    Array<TapSoMoi> arrTapSoMoi;

    if (c == 'A') {
        cin >> arrInt;
        cout << arrInt;
        cout << arrInt.tongDaySo();

    } else if (c == 'B') {
        cin >> arrTapSoMoi;
        cout << arrTapSoMoi;
        cout << arrTapSoMoi.tongDaySo();
    }

    return 0;
}