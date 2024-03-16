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
        int res = 0, tmp = number;
        while (tmp > 0) 
            res += tmp % 10,
            tmp /= 10;
        return res;
    }

    bool operator > (SoMoi other) {
        return tongChuSo() > other.tongChuSo();
    }

    SoMoi operator + (SoMoi other) {
        SoMoi res;
        res.number = tongChuSo() + other.tongChuSo();
        return res;
    }

    int operator + (int n) {
        return n + tongChuSo();
    }

    bool operator == (SoMoi other) {
        return number == other.number;
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
        for (int i = 0; i < size; i++)
            res = values[i] + res;
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

template<typename T>
void check(char c) {
    Array<T> arr;
    cin >> arr;
    cout << arr;
    if (c == 'M') cout << "[SoMoi]";
    cout << arr.tongDaySo();
    return;

}

int main() {
    char c; 
    cin >> c;

    switch (c) {
        case 'N': check<int>('N'); break;
        case 'M': check<SoMoi>('M'); break;
    }

    return 0;
}