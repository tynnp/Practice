#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

struct SMG {
    string maSo;
    string soDienThoai;
    string nhaMang;
};

struct QuanLiSMG {
    int size;
    SMG arr[100];

    void nhap() {
        cin >> size;
        for (int i = 0; i < size; i++)
            cin >> arr[i].maSo >> arr[i].soDienThoai >> arr[i].nhaMang;
        return;
    }

    void xuat() {
        for (int i = 0; i < size; i++) {
            cout << arr[i].maSo << ":";
            cout << arr[i].soDienThoai << ":";
            cout << arr[i].nhaMang << endl;
        }
        return;
    }

    void timKiem(string sdt) {
        for (int i = 0; i < size; i++) {
            string soDauList = arr[i].soDienThoai.substr(0, 3);
            string soDauUser = sdt.substr(0, 3);
            if (soDauList == soDauUser) {
                cout << arr[i].maSo << ":";
                cout << arr[i].soDienThoai << ":";
                cout << arr[i].nhaMang << endl;
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    QuanLiSMG list;
    list.nhap();
    string sdt; cin >> sdt;
    list.timKiem(sdt);
    return 0;
}