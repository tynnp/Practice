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

    bool operator > (int n) {
        return m[data] > n;
    }

    int operator + (SoLaMa other) {
        return m[data] + other.m[other.data];
    }

    int operator + (int n) {
        return m[data] + n;
    }
};

template<typename T>
struct Array {
    int size;
    T values[100];

    int tongDay() {
        int res = values[0] + 0;
        for (int i = 1; i < size; i++)
            res = values[i] + res;
        return res;
    }

    int soLonNhat() {
        int res = values[0] + 0;
        for (int i = 0; i < size; i++)
            if (values[i] > res) res = values[i] + 0;
        return res;
    }

    void run() {
        size = 0;
        while (cin >> values[size]) size++;
        cout << soLonNhat() << endl;
        cout << tongDay() << endl;
    }
};

template<typename T>
void check() {
    Array<T> a;
    a.run();
}

int main() {
    char c;
    cin >> c;
    
    switch (c) {
        case 'N': check<int>(); break;
        case 'L': check<SoLaMa>(); break;
    }

    return 0;
}