#include <iostream>
#include <map>
using namespace std;

struct SoLaMa {
    string data;
    map<string, int> m = {{"I", 1} , {"II", 2}, {"III", 3}, {"IV", 4}, 
    {"V", 5}, {"VI", 6}, {"VII", 7}, {"VIII", 8}, {"IX", 9}, {"X", 10}};

    friend istream &operator >> (istream &in, SoLaMa &s) {
        in >> s.data;
        return in;
    }

    friend ostream &operator << (ostream &out, SoLaMa s) {
        out << s.m[s.data];
        return out;
    }

    bool operator < (SoLaMa other) {
        return m[data] < other.m[other.data];
    }

    int operator + (SoLaMa other) {
        return m[data] + other.m[other.data];
    }

    int operator + (int n) {
        return m[data] + n;
    }
};

int main() {
    SoLaMa a, b;
    cin >> a >> b;
    cout << a << endl;
    cout << b << endl;
    cout << a + b << endl;
    if (a < b) cout << "true";
    else cout << "false";
    return 0;
}