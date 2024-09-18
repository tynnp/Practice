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

// #include <iostream>
// using namespace std;

// class Sim {
// private:
//     string _strSoDienThoai;
//     int _iGoiDen;
//     int _iGoiDi;

// public:
//     Sim();
//     Sim(string soDienThoai, int goiDen, int goiDi);
//     Sim(const Sim &sim);
//     ~Sim();

//     string getSoDienThoai();
//     void setSoDienThoai(string soDienThoai);
//     int getGoiDen();
//     void setGoiDen(int goiDen);
//     int getGoiDi();
//     void setGoiDi(int goiDi);

//     friend istream &operator >> (istream &in, Sim &sim);
//     friend ostream &operator << (ostream &out, const Sim &sim);
// };

// Sim timKiem(Sim danhSach[], int soLuong, string soDienThoai);
// Sim cuocGoiDenNhieuNhat(Sim danhSach[], int soLuong);
// Sim cuocGoiDiItNhat(Sim danhSach[], int soLuong);

// int main() {
//     int soLuong;
//     string soDienThoai;
//     cin >> soLuong >> soDienThoai;

//     Sim danhSach[100];
//     for (int i = 0; i < soLuong; i++)
//         cin >> danhSach[i];

//     cout << timKiem(danhSach, soLuong, soDienThoai) << endl;
//     cout << cuocGoiDenNhieuNhat(danhSach, soLuong) << endl;
//     cout << cuocGoiDiItNhat(danhSach, soLuong);
//     return 0;
// }

// Sim::Sim() {}

// Sim::Sim(string soDienThoai, int goiDen, int goiDi) {
//     _strSoDienThoai = soDienThoai;
//     _iGoiDen = goiDen;
//     _iGoiDi = goiDi;
// }

// Sim::Sim(const Sim &sim) {
//     _strSoDienThoai = sim._strSoDienThoai;
//     _iGoiDen = sim._iGoiDen;
//     _iGoiDi = sim._iGoiDi;
// }

// Sim::~Sim() {}


// string Sim::getSoDienThoai() {
//     return _strSoDienThoai;
// }

// void Sim::setSoDienThoai(string soDienThoai) {
//     _strSoDienThoai = soDienThoai;
// }

// int Sim::getGoiDen() {
//     return _iGoiDen;
// }

// void Sim::setGoiDen(int goiDen) {
//     _iGoiDen = goiDen;
// }   

// int Sim::getGoiDi() {
//     return _iGoiDi;
// }

// void Sim::setGoiDi(int goiDi) {
//     _iGoiDi = goiDi;
// }

// istream &operator >> (istream &in, Sim &sim) {
//     in >> sim._strSoDienThoai >> sim._iGoiDen >> sim._iGoiDi;
//     return in;
// }

// ostream &operator << (ostream &out, const Sim &sim) {
//     out << '{' << sim._strSoDienThoai << ',' << sim._iGoiDen << ',' << sim._iGoiDi << '}';
//     return out;
// }

// Sim timKiem(Sim danhSach[], int soLuong, string soDienThoai) {
//     for (int i = 0; i < soLuong; i++)
//         if (danhSach[i].getSoDienThoai() == soDienThoai)
//             return danhSach[i];
// }

// Sim cuocGoiDenNhieuNhat(Sim danhSach[], int soLuong) {
//     Sim ketQua = danhSach[0];
//     for (int i = 1; i < soLuong; i++)
//         if (ketQua.getGoiDen() < danhSach[i].getGoiDen())
//             ketQua = danhSach[i];
//     return ketQua;
// }

// Sim cuocGoiDiItNhat(Sim danhSach[], int soLuong) {
//     Sim ketQua = danhSach[0];
//     for (int i = 1; i < soLuong; i++)
//         if (ketQua.getGoiDi() > danhSach[i].getGoiDi())
//             ketQua = danhSach[i];
//     return ketQua;
// }
