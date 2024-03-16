#include <iostream>
using namespace std;

struct Ngay {
    int ngay;
    int thang;
    int nam;
    int soLuong = 0;

    friend istream &operator >> (istream &in, Ngay &n) {
        in >> n.ngay >> n.thang >> n.nam;
        return in;
    }

    friend ostream &operator << (ostream &out, Ngay n) {
        if (n.ngay < 10) out << 0;
        out << n.ngay << "/";

        if (n.thang < 10) out << 0;
        out << n.thang << "/";

        out << n.nam;
        return out;
    } 

    bool operator == (Ngay other) {
        return ngay == other.ngay && thang == other.thang && nam == other.nam;
    }
};

struct ThoiGian {
    string gio;
    string phut;

    friend istream &operator >> (istream &in, ThoiGian &tg) {
        in >> tg.gio >> tg.phut;
        return in;
    }

    friend ostream &operator << (ostream &out, ThoiGian tg) {
        out << tg.gio << ":" << tg.phut;
        return out;
    }
};

struct ChuyenBay {
    string maChuyenBay;
    Ngay ngayBay;
    ThoiGian gioBay;
    string noiDen;

    friend istream &operator >> (istream &in, ChuyenBay &cb) {
        in >> cb.maChuyenBay >> cb.ngayBay >> cb.gioBay;
        in.ignore();
        getline(in, cb.noiDen);
    }

    friend ostream &operator << (ostream &out, ChuyenBay cb) {
        out << cb.maChuyenBay << endl;
        out << cb.ngayBay << endl;
        out << cb.gioBay << endl;
        out << cb.noiDen;
    }
};

int main() {
    int n;
    string maCanTim;
    cin >> n;

    ChuyenBay arr[n];
    for (ChuyenBay &x : arr) cin >> x;
    cin >> maCanTim; 

    for (ChuyenBay x : arr) cout << x << endl;

    for (int i = 0; i < n; i++) 
        for (int j = i+1; j < n; j++)
            if (arr[i].ngayBay == arr[j].ngayBay)
                arr[i].ngayBay.soLuong++;
    
    Ngay ngayNhieuNhat = arr[0].ngayBay;
    for (ChuyenBay x : arr) 
        if (x.ngayBay.soLuong > ngayNhieuNhat.soLuong)
            ngayNhieuNhat = x.ngayBay;
    cout << ngayNhieuNhat << endl;

    for (ChuyenBay x : arr)
        if (x.maChuyenBay == maCanTim)
            cout << x;

    return 0;
}