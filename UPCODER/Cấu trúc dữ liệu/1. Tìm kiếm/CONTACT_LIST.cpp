#include <bits/stdc++.h>
using namespace std;

struct DienThoai {
    string soDienThoai;
    int goiDen;
    int goiDi;
} yc2, yc3, yc4;

ostream &operator << (ostream &out, DienThoai obj) {
    out << "{" + obj.soDienThoai + "," << obj.goiDen << "," << obj.goiDi << "}\n"; 
    return out;
}

DienThoai timKiemSo(DienThoai arr[], int n, string soCanTim) {
    for (int i = 0; i < n; i++)
        if (arr[i].soDienThoai == soCanTim)
            return arr[i];
}

DienThoai timKiemGoi(DienThoai arr[], int n, int type = 0) {
    DienThoai resGoiDen = arr[0];
    DienThoai resGoiDi = arr[0];
    
    for (int i = 1; i < n; i++) {
        if (resGoiDen.goiDen < arr[i].goiDen) resGoiDen = arr[i];
        else if (resGoiDi.goiDi > arr[i].goiDi) resGoiDi = arr[i];
    }
    
    return type == 0 ? resGoiDen : resGoiDi;
}

int main() {
    int n;
    string soCanTim;
    cin >> n >> soCanTim;
    
    DienThoai arr[n];
    for (auto &x : arr) 
        cin >> x.soDienThoai >> x.goiDen >> x.goiDi;
        
    yc2 = timKiemSo(arr, n, soCanTim);
    yc3 = timKiemGoi(arr, n, 0);
    yc4 = timKiemGoi(arr, n, 1);
    
    cout << yc2 << yc3 << yc4;
    return 0;
}