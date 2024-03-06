#include <iostream>
using namespace std;

class LoDat {
private:
    char loaiLoDat;
    string tenLoDat;
    string viTriLoDat;
    double soLieu[2];
public:
    friend istream &operator >> (istream &in, LoDat &ld) {
        in >> ld.loaiLoDat >> ld.tenLoDat >> ld.viTriLoDat;
        if (ld.loaiLoDat == 'R') in >> ld.soLieu[0] >> ld.soLieu[1];
        else if (ld.loaiLoDat == 'C' || ld.loaiLoDat == 'S') in >> ld.soLieu[0];
    }

    double chuVi() {
        if (loaiLoDat == 'R')   
            return (soLieu[0] + soLieu[1])*2;
        else if (loaiLoDat == 'C')
            return 3.14159*2*soLieu[0];
        else if (loaiLoDat == 'S')
            return soLieu[0]*4;
    }

    double dienTich() {
        if (loaiLoDat == 'R')   
            return soLieu[0] * soLieu[1];
        else if (loaiLoDat == 'C')
            return 3.14159*soLieu[0]*soLieu[0];
        else if (loaiLoDat == 'S')
            return soLieu[0]*soLieu[0];
    }

    friend ostream &operator << (ostream &out, LoDat ld) {
        if (ld.loaiLoDat != 'R' && ld.loaiLoDat != 'C' && ld.loaiLoDat != 'S') {
            cout << "Loai hinh khong hop le";
            return out;
        } else {
            cout << "Ten: " << ld.tenLoDat << endl;
            cout << "Vi tri: " << ld.viTriLoDat << endl;
            cout << "Chu vi: " << ld.chuVi() << endl;
            cout << "Dien tich: " << ld.dienTich() << endl;
        }
        return out;
    }
};

int main() {
    int n;
    cin >> n;
    
    LoDat arr[n];
    for (LoDat &x : arr) cin >> x;
    for (LoDat x : arr) cout << x;

    return 0;
}