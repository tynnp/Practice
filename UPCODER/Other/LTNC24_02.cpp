#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct ToaDo {
    int x, y;
};

istream &operator >> (istream &in, ToaDo &obj) {
    in >> obj.x >> obj.y;
    return in;
}

ostream &operator << (ostream &out, ToaDo obj) {
    out << "(" << obj.x << ", " << obj.y << ")";
    return out;
}

bool operator == (ToaDo a, ToaDo b) {
    return a.x == b.x && a.y == b.y;
}

ToaDo operator + (ToaDo a, ToaDo b) {
    ToaDo res;
    res.x = a.x + b.x;
    res.y = a.y + b.y;
    return res;
}

double operator - (ToaDo a, ToaDo b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

int main() {
    int size = 0;
    ToaDo canTim, arr[100];

    cin >> canTim;
    while (cin >> arr[size]) size++;

    int trungNhau(0);
    for (int i = 0; i < size; i++)
        if (canTim == arr[i]) trungNhau++;

    ToaDo tong = arr[0];
    for (int i = 1; i < size; i++)
        tong = tong + arr[i];

    double khoangCach(0);
    ToaDo a, b;
    for (int i = 0; i < size; i++)
        for (int j = i+1; j < size; j++)
            if (khoangCach < arr[i] - arr[j]) {
                khoangCach = arr[i] - arr[j];
                a = arr[i], b = arr[j];
            }
    
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    cout << trungNhau << endl;
    cout << tong << endl;
    cout << a << " " << b << endl;
    cout << fixed << setprecision(2) << khoangCach;
    return 0;
}