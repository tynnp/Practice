#include <iostream>
#include <vector>
#include <iomanip>
#define endl '\n'
using namespace std;

class Nguoi {
private:
    string hoTen;
    int namSinh;
    string queQuan;
public:
    Nguoi() {}
    ~Nguoi() {}

    void nhap() {
        getline(cin, hoTen);
        cin >> namSinh; cin.ignore();
        getline(cin, queQuan);
        return;
    }

    void xuat() {
        cout << "Ho Ten: " << hoTen << endl;
        cout << "Nam Sinh: " << namSinh << endl;
        cout << "Que quan: " << queQuan << endl;
    }

    string getHoTen() {
        return this->hoTen;
    }

    int getNamSinh() {
        return this->namSinh;
    }

    string getQueQuan() {
        return this->queQuan;
    }

    void setHoTen(string hoTen) {
        this->hoTen = hoTen;
        return;
    }

    void setNamSinh(int namSinh) {
        this->namSinh = namSinh;
        return;
    }

    void setQueQuan(string queQuan) {
        this->queQuan = queQuan;
        return;
    }
};

class SinhVien : public Nguoi {
private:
    string khoa;
    vector<double> diemCacMon;
public:
    ~SinhVien() {}

    SinhVien() {}

    void nhap() {
        Nguoi::nhap();
        getline(cin, khoa);
        double diem;
        while (cin >> diem) 
            diemCacMon.push_back(diem);
    }

    double diemTrungBinh() {
        double res = 0;
        for (double x : diemCacMon) res += x;
        return res / diemCacMon.size();
    }

    void xuat() {
        Nguoi::xuat();
        cout << "Khoa: " << khoa << endl;

        cout << "Diem cac mon: ";
        for (double x : diemCacMon)    
            cout << x << " ";

        cout << endl << fixed << setprecision(2);
        cout << "Diem trung binh: " << diemTrungBinh();
    }

    void setKhoa(string khoa) {
        this->khoa = khoa;
        return;
    }

    void setDiemCacMon(vector<double> diem) {
        diemCacMon = diem;
        return;
    } 

    string getKhoa() {
        return khoa;
    }

    vector<double> getDiemCacMon() {
        return diemCacMon;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    SinhVien sv; 
    sv.nhap();
    sv.xuat();
    return 0;
}