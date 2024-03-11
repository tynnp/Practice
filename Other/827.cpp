#include <iostream>
using namespace std;

struct Phong {
    string maPhong;
    string tenPhong;
    double donGia;
    int tinhTrangPhong;

    friend istream &operator >> (istream &in, Phong &p) {
        in >> p.maPhong >> p.donGia >> p.tinhTrangPhong;
        return in;
    }


};

int main() {

}