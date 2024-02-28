#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Nguoi {
protected: 
    string hoTen;
    string gioiTinh;
    int namSinh;
public:
    Nguoi(){} ~Nguoi(){} 
    Nguoi(string, string, int);
    void setHoTen(string); string getHoTen();
    void setGioiTinh(string); string getGioiTinh();
    void setNamSinh(int); int getNamSinh();
};

class HanhKhach : public Nguoi {
private:
    string viTri;
public: 
    HanhKhach(){} ~HanhKhach(){}
    HanhKhach(string, string, int, string);
    void setViTri(string); string getViTri();
    friend istream& operator >> (istream&, HanhKhach&); 
    void xuatHanhKhach();
};

class ChuyenBay {
private:
    string tenChuyenBay;
    string maChuyenBay;
    string noiDi;
    string noiDen;
    string thoiGian;
    vector<string> viTriGhe;
    vector<HanhKhach> dsHanhKhach;
public:
    ChuyenBay(){} ~ChuyenBay(){}
    int getTongHanhKhach();
    ChuyenBay(string, string, string, string, string, vector<string>, vector<HanhKhach>);
    void setTenChuyenBay(string); string getTenChuyenBay();
    void setMaChuyenBay(string); string getMaChuyenBay();
    void setNoiDi(string); string getNoiDi();
    void setNoiDen(string); string getNoiDen();
    void setThoiGian(string); string getThoiGian();
    void setViTriGhe(vector<string>); vector<string> getViTriGhe();
    void setDSHanhKhach(vector<HanhKhach>); vector<HanhKhach> getDSHanhKhach();
    void nhapChuyenBay(); void xuatChuyenBay();
    static vector<HanhKhach> sapXepHanhKhach(ChuyenBay);
    static vector<string> danhSachGheTrong(ChuyenBay);
};

//------------------------------------------------------------------------------------------------

int main() {
    ChuyenBay CB1; 
    CB1.nhapChuyenBay();
    CB1.xuatChuyenBay();
    string vtCantim; cin >> vtCantim; 

    vector<HanhKhach> sapXep = ChuyenBay::sapXepHanhKhach(CB1);
    if (sapXep.size() != 0) {
        for (HanhKhach x : sapXep) x.xuatHanhKhach();
    } else cout << 0 << endl;

    vector<string> dsGheTrong = ChuyenBay::danhSachGheTrong(CB1);
    if (dsGheTrong.size() != 0) {
        for (auto x : dsGheTrong) 
            cout << x << " "; cout << endl;
    } else cout << 0 << endl;

    cout << vtCantim << endl; bool check = false;
    vector<HanhKhach> THK(CB1.getDSHanhKhach());
    for (HanhKhach x : THK) {
        if (x.getViTri() == vtCantim) { 
            x.xuatHanhKhach(); check = true;
        }
    }
    if (!check) cout << 0 << endl;
    return 0;
}

//------------------------------------------------------------------------------------------------

Nguoi::Nguoi(string hoTen, string gioiTinh, int namSinh) {
    this->hoTen = hoTen;
    this->gioiTinh = gioiTinh;
    this->namSinh = namSinh;
}

void Nguoi::setHoTen(string hoTen) {
    this->hoTen = hoTen;
}

void Nguoi::setGioiTinh(string setGioiTinh) {
    this->gioiTinh = gioiTinh;
}

void Nguoi::setNamSinh(int namSinh) {
    this->namSinh = namSinh;
}

string Nguoi::getHoTen() {
    return hoTen;
}

string Nguoi::getGioiTinh() {
    return gioiTinh;
}

int Nguoi::getNamSinh() {
    return namSinh;
}

//------------------------------------------------------------------------------------------------

HanhKhach::HanhKhach(string hoTen, string gioiTinh, int namSinh, string viTri) : Nguoi(hoTen, gioiTinh, namSinh) {
    this->viTri;
}

void HanhKhach::setViTri(string viTri) {
    this->viTri = viTri;
}

string HanhKhach::getViTri() {
    return viTri;
}

istream& operator >> (istream& in, HanhKhach &x) {
    string tentmp; getline(cin, tentmp);
    x.hoTen = tentmp; if (x.hoTen == "-1") return in;
    in >> x.gioiTinh >> x.namSinh >> x.viTri;
    cin.ignore(); return in;
}

void HanhKhach::xuatHanhKhach() {
    cout << "Ho Ten: " << hoTen << endl;
    cout << "Gioi Tinh: " << gioiTinh << endl;
    cout << "Nam Sinh: " << namSinh << endl;
    cout << "Vi tri: " << viTri << endl;
}

// ------------------------------------------------------------------------------------------------

ChuyenBay::ChuyenBay(string tenChuyenBay, string maChuyenBay, string noiDi, string noiDen, 
string thoiGian, vector<string> viTriGhe, vector<HanhKhach> dsHanhKhach) {
    this->tenChuyenBay = tenChuyenBay;
    this->maChuyenBay = maChuyenBay;
    this->noiDi = noiDi;
    this->noiDen = noiDen;
    this->thoiGian = thoiGian;
    this->viTriGhe = viTriGhe;
    this->dsHanhKhach = dsHanhKhach;
}

void ChuyenBay::setTenChuyenBay(string tenChuyenBay) {
    this->tenChuyenBay = tenChuyenBay;
}

void ChuyenBay::setMaChuyenBay(string maChuyenBay) {
    this->maChuyenBay = maChuyenBay;
}

void ChuyenBay::setNoiDi(string noiDi) {
    this->noiDi = noiDi;
}

void ChuyenBay::setNoiDen(string noiDen) {
    this->noiDen = noiDen;
}

void ChuyenBay::setThoiGian(string thoiGian) {
    this->thoiGian = thoiGian;
}

void ChuyenBay::setViTriGhe(vector<string> viTriGhe) {
    this->viTriGhe = viTriGhe;
}

void ChuyenBay::setDSHanhKhach(vector<HanhKhach> dsHanhKhach) {
    this->dsHanhKhach = dsHanhKhach;
}

int ChuyenBay::getTongHanhKhach() {
    return dsHanhKhach.size();
}

string ChuyenBay::getTenChuyenBay() {
    return tenChuyenBay;
}

string ChuyenBay::getMaChuyenBay() {
    return maChuyenBay;
}

string ChuyenBay::getNoiDi() {
    return noiDi;
}

string ChuyenBay::getNoiDen() {
    return noiDen;
}

string ChuyenBay::getThoiGian() {
    return thoiGian;
}

vector<string> ChuyenBay::getViTriGhe() {
    return viTriGhe;
}

vector<HanhKhach> ChuyenBay::getDSHanhKhach() {
    return dsHanhKhach;
}

void ChuyenBay::nhapChuyenBay() {
    getline(cin, tenChuyenBay); 
    getline(cin, maChuyenBay);
    getline(cin, noiDi);
    getline(cin, noiDen);
    getline(cin, thoiGian);
    HanhKhach tmp; 
    while (cin >> tmp) {
        if (tmp.getHoTen() == "-1") break;
        dsHanhKhach.push_back(tmp);
        viTriGhe.push_back(tmp.getViTri());
    }
}

void ChuyenBay::xuatChuyenBay() {
    cout << "Ten Chuyen Bay: " << getTenChuyenBay() << endl;
    cout << "Ma Chuyen Bay: " << getMaChuyenBay() << endl;
    cout << "Ngay Bay: " << getThoiGian() << endl;
    cout << "Noi Di: " << getNoiDi() << endl;
    cout << "Noi Den: " << getNoiDen() << endl;
}

vector<HanhKhach> ChuyenBay::sapXepHanhKhach(ChuyenBay CB) {
    vector<HanhKhach> HK(CB.getDSHanhKhach());
    for (int i = 1; i < HK.size(); i++) {
        int j = i;
        while (j > 0 && HK[j-1].getViTri() >= HK[j].getViTri())
            swap(HK[j-1], HK[j]), j--;
    }
    return HK;
}

vector<string> ChuyenBay::danhSachGheTrong(ChuyenBay CB) {
    vector<string> result = {"A1", "A2", "A3", "B1", "B2", "B3", "C1", "C2", "C3"};
    vector<string> HK(CB.getViTriGhe());
    vector<string>::iterator it;
    for (it = result.begin(); it != result.end(); it++) {
        vector<string>::iterator it2 = find(HK.begin(), HK.end(), *it);
        if (it2 != HK.end()) result.erase(it--);
    } 
    return result;
}