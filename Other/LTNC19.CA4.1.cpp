#include <iostream>
using namespace std;

struct Time {
    int gio, phut, giay;

    friend istream &operator >> (istream &in, Time &t) {
        in >> t.gio >> t.phut >> t.giay;
        return in;
    }

    friend ostream &operator << (ostream &out, Time t) {
        out << t.gio << ":" << t.phut << ":" << t.giay;
        return out;
    } 

    int timestamp() {
        return gio*3600 + phut*60 + giay;
    }

    bool operator < (Time other) {
        return timestamp() < other.timestamp();
    }

    Time operator + (Time other) {
        Time res;
        res.gio = gio + other.gio;
        res.phut = phut + other.phut;
        res.giay = giay + other.giay;
        return res;
    }

    int operator + (int n) {
        return timestamp() + n;
    }
};

int main() {
    Time a, b;
    cin >> a >> b;
    cout << a << endl;
    cout << b << endl;
    cout << a.timestamp() << endl;
    cout << b.timestamp() << endl;
    cout << (a < b ? "true" : "false");
    return 0;
}