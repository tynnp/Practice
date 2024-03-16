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
        out << s.maSach << "-";
        out << s.tenSach << "-";
        out << s.soTo;
        return out;
    }
};

void sapXepTangDan(Sach arr[], int n) {
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && arr[j-1].soTo > arr[j].soTo) 
            swap(arr[j-1], arr[j]), j--;
    }
    return;
}

int main() {
    int n;
    cin >> n;

    Sach arr[n];
    for (Sach &x : arr) cin >> x;

    sapXepTangDan(arr, n);
    for (Sach x : arr) cout << x << endl;
    
    return 0;
}