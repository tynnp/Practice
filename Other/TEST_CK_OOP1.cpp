#include <iostream>
#include <iomanip>
using namespace std;

class Thu {
private:
    string maSo;
    string loai;
    bool gioiTinh;
    float canNang;
    string ngayNhapChuong;
public:
    Thu() {}

    Thu(string maSo, string loai, bool gioiTinh, float canNang, string ngayNhapChuong) : 
        maSo(maSo), loai(loai), gioiTinh(gioiTinh), canNang(canNang), ngayNhapChuong(ngayNhapChuong) {}

    Thu(const Thu &other) {
        maSo = other.maSo;
        loai = other.loai;
        gioiTinh = other.gioiTinh;
        canNang = other.canNang;
        ngayNhapChuong = other.ngayNhapChuong;
    }

    void setMaSo(string maSo) {
        this->maSo = maSo;
        return;
    }

    void setLoai(string loai) {
        this->loai = loai;
        return;
    }

    void setGioiTinh(bool gioiTinh) {
        this->gioiTinh = gioiTinh;
        return;
    }

    void setCanNang(float canNang) {
        this->canNang = canNang;
        return;
    }

    void setNgayNhapChuong(string ngayNhapChuong) {
        this->ngayNhapChuong = ngayNhapChuong;
        return;
    }

    string getMaSo() {
        return maSo;
    }

    string getLoai() {
        return loai;
    }

    bool getGioiTinh() {
        return gioiTinh;
    }

    float getCanNang() {
        return canNang;
    }

    string getNgayNhapChuong() {
        return ngayNhapChuong;
    }

    float thucAnCan() {
        float res = 0;
        if (gioiTinh) res = canNang*0.1;
        else res = canNang*0.05;
        return res;
    }

    friend istream &operator >> (istream &in, Thu &thu) {
        string thongTin;
        getline(in, thongTin);

        int start = 0, end = 0;
        for (end; thongTin[end] != '_'; end++);
        thu.maSo = thongTin.substr(start, end - start); 

        start = end+1;
        for (end++; thongTin[end] != '_'; end++);
        thu.loai = thongTin.substr(start, end - start);

        start = end+1;
        for (end++; thongTin[end] != '_'; end++);
        thu.gioiTinh = stoi(thongTin.substr(start, end - start));

        start = end+1;
        for (end++; thongTin[end] != '_'; end++);
        thu.canNang = stod(thongTin.substr(start, end - start));

        thu.ngayNhapChuong = thongTin.substr(end+1);
        return in;
    }

    friend ostream &operator << (ostream &out, Thu thu) {
        out << thu.maSo << " | " << thu.loai << " | ";
        if (thu.gioiTinh) out << "Duc | ";
        else out << "Cai | ";
        out << fixed << setprecision(2);
        out << thu.canNang << " | " << thu.ngayNhapChuong;
        return out;
    }
};

void anNhieuNhat(Thu list[], int n) {
    double khoiLuongThuAn = 0;
    Thu res;

    for (int i = 0; i < n; i++) 
        if (list[i].thucAnCan() > khoiLuongThuAn) 
            khoiLuongThuAn = list[i].thucAnCan(), res = list[i];
        
    cout << fixed << setprecision(2) << khoiLuongThuAn << endl << res;
    return;
}

int main() {
    int n;
    cin >> n;
    Thu list[n];

    cin.ignore();
    for (Thu &x : list) cin >> x;
    for (Thu x : list) cout << x << endl;
    anNhieuNhat(list, n);

    return 0;
}