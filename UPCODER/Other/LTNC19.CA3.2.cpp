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

template<typename T>
struct Array {
    int size;
    T values[100];

    friend istream &operator >> (istream &in, Array<T> &arr) {
        arr.size = 0;
        while (in >> arr.values[arr.size]) arr.size++;
        return in;
    }

    T maxElement() {
        T res = values[0];
        for (int i = 1; i < size; i++)  
            if (res < values[i]) res = values[i];
        return res;
    }

    int sumElement() {
        int res = values[0] + 0;
        for (int i = 1; i < size; i++)  
            res = values[i] + res;
        return res;
    }
};

template<typename T>
void check() {
    Array<T> arr;
    cin >> arr;
    cout << arr.maxElement() << endl;
    cout << arr.sumElement();
    return;
}

int main() {
    char c;
    cin >> c;

    switch (c) {
        case 'N': check<int>(); break;
        case 'T': check<Time>(); break;
    }

    return 0;
}