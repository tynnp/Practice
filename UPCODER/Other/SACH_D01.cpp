#include <iostream>
using namespace std;

struct Sach {
    string maSach;
    string tenSach;
    int soTo;

    friend istream &operator >> (istream &in, Sach &s) {
        in >> s.maSach >> s.tenSach >> s.soTo;
        return in;
    }

    friend ostream &operator << (ostream &out, Sach s) {
        out << s.maSach << endl;
        out << s.tenSach << endl;
        out << s.soTo << endl;
        return out;
    }
};

int main() {
    string maCanTim;
    int n, index = -1;
    cin >> maCanTim >> n;

    Sach arr[n];
    for (Sach &x : arr) cin >> x;

    for (int i = 0; i < n; i++) {
        if (maCanTim == arr[i].maSach) 
            index = i;
    }

    cout << index; 
    return 0;
}