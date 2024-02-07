#include <iostream>
using namespace std;

struct SoMoi {
    int number;

    friend istream& operator >> (istream &in, SoMoi &soMoi) {
        in >> soMoi.number;
        return in;
    }

    friend ostream& operator << (ostream &out, SoMoi soMoi) {
        out << "[SoMoi] " << soMoi.number;
        return out;
    }

    int tongChuSo() {
        int res = 0, tmp = this->number;
        while (tmp > 0) 
            res += tmp % 10,
            tmp /= 10;
        return res;
    }

    bool operator > (SoMoi soMoi) {
        return this->tongChuSo() > soMoi.tongChuSo();
    }

    SoMoi operator + (SoMoi soMoi) {
        SoMoi res;
        res.number = this->tongChuSo() + soMoi.tongChuSo();
        return res;
    }

    int operator + (int n) {
        return n + this->tongChuSo();
    }

    bool operator == (SoMoi soMoi) {
        return this->number == soMoi.number;
    }
};

template<typename T>
struct Array {
    int size = 0;
    T values[1000];

    friend istream& operator >> (istream &in, Array &arr) {
        T n; 
        while (cin >> n) 
            arr.values[arr.size++] = n;
        return in;
    }

    int tongDaySo() {
        int res = 0;
        for (int i = 0; i < this->size; i++)
            res =this->values[i] + res;
        return res;
    }

    friend ostream& operator << (ostream &out, Array arr) {
        T max = arr.values[0];
        int cnt = 1;

        for (int i = 1; i < arr.size; i++) {
            cnt += (max == arr.values[i]);
            if (arr.values[i] > max) 
                max = arr.values[i], cnt = 1;
        }

        out << max << endl;
        out << cnt << endl;
        return out;
    }
};

int main() {
    char c; cin >> c;
    Array<int> arrInt;
    Array<SoMoi> arrSoMoi;

    if (c == 'N') {
        cin >> arrInt;
        cout << arrInt;
        cout << arrInt.tongDaySo();

    } else if (c == 'M') {
        cin >> arrSoMoi;
        cout << arrSoMoi;
        cout << "[SoMoi]" << arrSoMoi.tongDaySo();
    }

    return 0;
}