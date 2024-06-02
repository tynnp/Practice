#include <iostream>
using namespace std;

struct KhachHang {
    string maKhachHang;
    string tenKhachHang;
    long long tienDangCo;

    friend istream &operator >> (istream &in, KhachHang &kh) {
        string str;
        int start = 0, end = 0;
        getline(in, str);

        for (end; str[end] != '-'; end++);
        kh.maKhachHang = str.substr(start, end - start - 1);

        start = end + 2;
        for (end++; str[end] != '-'; end++);
        kh.tenKhachHang = str.substr(start, end - start - 1);

        start = end + 2;
        kh.tienDangCo = stoll(str.substr(start)); 
    }

    friend ostream &operator << (ostream &out, KhachHang kh) {
        out << kh.maKhachHang << " - ";
        out << kh.tenKhachHang << " - ";
        out << kh.tienDangCo;
    }
};

int main() {
    int n, cnt = 0;
    cin >> n;
    cin.ignore();
    KhachHang arr[n], res;
    for (KhachHang &x : arr) cin >> x;
    
    res = arr[0];
    cnt = (arr[0].tienDangCo >= 0);

    for (int i = 1; i < n; i++) {
        cnt += (arr[i].tienDangCo >= 0);
        if (arr[i].tienDangCo > res.tienDangCo)
            res = arr[i];
    }

    cout << cnt << endl << res;
    return 0;
}