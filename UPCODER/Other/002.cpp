#include <iostream>
using namespace std;

struct HoSo {
    string ten;
    double diemTrungBinh;

    void Nhap() {
        cin >> ten >> diemTrungBinh;
        return;
    }

    void Xuat() {
        cout << ten << " " << diemTrungBinh << endl;
        return;
    }
};

int main() {
    int n = 0;
    char c;
    HoSo arr[1000];

    do {
        arr[n].Nhap();
        cin >> c;
        n++;
    } while (c != 'K');

    for (int i = 0; i < n; i++)
        if (arr[i].diemTrungBinh < 5.0)
            arr[i].Xuat();

    return 0;
}