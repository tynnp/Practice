#include <iostream>
#include <algorithm>
using namespace std;

struct HanhDong {
    string ten;
    int diemTocDo;

    friend istream &operator >> (istream &in, HanhDong &a) {
        in >> a.ten >> a.diemTocDo;
        return in;
    }

    friend ostream &operator << (ostream &out, HanhDong a) {
        out << a.ten << endl;
        return out;
    }
};

int main() {
    int n;
    cin >> n;

    HanhDong arr[n];
    for (HanhDong &x : arr) cin >> x;

    sort(arr, arr + n, [](HanhDong a, HanhDong b) {
        return a.diemTocDo > b.diemTocDo;
    });

    for (HanhDong x : arr) cout << x;
    return 0;
}