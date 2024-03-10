#include <iostream>
#include <algorithm>
using namespace std;

struct HocSinh {
    string ten;
    double diem[2];

    double diemTrungBinh() {
        return (double) (diem[0] + diem[1])/2;
    }

    friend istream &operator >> (istream &in, HocSinh &hs) {
        in >> hs.ten >> hs.diem[0] >> hs.diem[1];
        return in;
    }

    friend ostream& operator << (ostream &out, HocSinh hs) {
        out << hs.ten << " " << hs.diemTrungBinh();
        return out;
    }
};  

int main() {
    int n;
    cin >> n;

    HocSinh arr[n];
    for (HocSinh &x : arr) cin >> x;

    sort(arr, arr + n, [] (HocSinh a, HocSinh b) {
        return a.diemTrungBinh() > b.diemTrungBinh();
    });

    for (int i = 0; i < n; i++) 
        cout << i+1 << " " << arr[i] << endl;
    
    return 0;
}