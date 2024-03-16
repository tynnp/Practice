#include <iostream>
using namespace std;

struct SoDao {
    int number;

    friend istream& operator >> (istream &in, SoDao &sd) {
        in >> sd.number;
        return in;
    }

    friend ostream& operator << (ostream &out, SoDao sd) {
        out << "[SoDao] " << sd.number;
        return out;
    }

    int soDao() {
        int tmp = number;
        int res = 0;
        while (tmp > 0) 
            res = res*10 + tmp%10,
            tmp /= 10;
        return res;
    }

    bool operator > (SoDao sd) {
        return soDao() > sd.soDao();
    }

    int operator + (int x) {
        return soDao() + x;
    }
};

template<typename T>
struct Array {
    int size;
    T values[1000];

    friend istream& operator >> (istream &in, Array &arr) {
        T n; 
        in >> n;
        arr.values[arr.size++] = n;
        return in;
    }

    int tongSo() {
        int res = 0;
        for (int i = 0; i < size; i++)
            res = values[i] + res;
        return res;
    }

    T soLonNhat() {
        T res = values[0];
        for (int i = 1; i < size; i++) 
            if (values[i] > res)
                res = values[i];
        return res;
    }

    friend ostream& operator << (ostream &out, Array arr) {
        if (arr.size == 0) 
            out << "khong co\nkhong co\n";
        else {
            out << arr.tongSo() << endl;
            out << arr.soLonNhat() << endl;
        }
        return out;
    }
};

int main() {
    char c; 
    Array<int> arrInt;
    Array<SoDao> arrSoDao;

    while (cin >> c) {
        if (c == 'T') cin >> arrInt;
        else if (c == 'D') cin >> arrSoDao;
    }

    cout << arrInt;
    cout << arrSoDao;

    return 0;
}