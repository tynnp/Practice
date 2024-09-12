#include <iostream>
#include <iomanip>
using namespace std;

class Diem {
private:
    double danhSachDiem[100];
    int soLuong;

public:
    friend istream &operator >> (istream &in, Diem &diem);
    friend ostream &operator << (ostream &out, Diem &diem);
    double &operator [] (int index);
    void operator = (Diem diem);
    double getTrungBinhCong();

    Diem();
    Diem(double danhSachDiem[], int soLuong);
    Diem(const Diem &other);
    ~Diem();

    double* getDanhSachDiem();
    void setDanhSachDiem(double danhSachDiem[]);
    int getSoLuong();
    void setSoLuong(int soLuong);
};

class SinhVien {
private:
    string hoTen;
    string maSinhVien;
    Diem diem;

public:
    friend istream &operator >> (istream &in, SinhVien &sv);
    friend ostream &operator << (ostream &out, SinhVien &sv);
    void operator = (SinhVien sv);
    bool operator < (SinhVien sv);
    double getTrungBinhCong();

    SinhVien();
    SinhVien(string hoTen, string maSinhVien, Diem diem);
    SinhVien(const SinhVien &other);
    ~SinhVien();

    string getHoTen();
    void setHoTen(string hoTen);
    string getMaSinhVien();
    void setMaSinhVien(string maSinhVien);
    Diem getDiem();
    void setDiem(Diem diem);
};

int main() {
    SinhVien sinh_vien_uu_tu;
    cin >> sinh_vien_uu_tu;
    cout << sinh_vien_uu_tu;
    return 0;
}

istream &operator >> (istream &in, Diem &diem) {
    while (in >> diem[diem.soLuong])
        diem.soLuong++;
    return in;
}

ostream &operator << (ostream &out, Diem &diem) {
    out << fixed << setprecision(1) << diem.getTrungBinhCong();
    return out;
}

double &Diem::operator [] (int index) {
    return danhSachDiem[index];
}

void Diem::operator = (Diem diem) {
    soLuong = diem.soLuong;
    for (int i = 0; i < soLuong; i++)
        danhSachDiem[i] = diem.danhSachDiem[i]; 
}

double Diem::getTrungBinhCong() {
    double res = 0;
    for (int i = 0; i < soLuong; i++)
        res += danhSachDiem[i];
    return res / soLuong;
}


Diem::Diem() {
    soLuong = 0;
}

Diem::Diem(double danhSachDiem[], int soLuong) {
    this->soLuong = soLuong;
    for (int i = 0; i < soLuong; i++)
        this->danhSachDiem[i] = danhSachDiem[i];
}

Diem::Diem(const Diem &other) {
    soLuong = other.soLuong;
    for (int i = 0; i < soLuong; i++)
        danhSachDiem[i] = other.danhSachDiem[i];
}

Diem::~Diem() {
    soLuong = 0;
}


double* Diem::getDanhSachDiem() {
    return danhSachDiem;
}

void Diem::setDanhSachDiem(double danhSachDiem[]) {
    for (int i = 0; i < soLuong; i++)
        this->danhSachDiem[i] = danhSachDiem[i];
}

int Diem::getSoLuong() {
    return soLuong;
}

void Diem::setSoLuong(int soLuong) {
    this->soLuong = soLuong;
}


istream &operator >> (istream &in, SinhVien &sv) {
    getline(in, sv.hoTen);
    getline(in, sv.maSinhVien);
    in >> sv.diem;
    in.ignore();
    return in;
}

ostream &operator << (ostream &out, SinhVien &sv) {
    out << "Ho Ten: " << sv.hoTen << endl;
    out << "Ma Sinh Vien: " << sv.maSinhVien << endl;
    out << "DTB: " << sv.diem;
    return out;
}

void SinhVien::operator = (SinhVien sv) {
    hoTen = sv.hoTen;
    maSinhVien = sv.maSinhVien;
    diem = sv.diem;
}

bool SinhVien::operator < (SinhVien sv) {
    return this->getTrungBinhCong() < sv.getTrungBinhCong();
}

double SinhVien::getTrungBinhCong() {
    return diem.getTrungBinhCong();
}


SinhVien::SinhVien() {
    hoTen = maSinhVien = "";
}

SinhVien::SinhVien(string hoTen, string maSinhVien, Diem diem) {
    this->hoTen = hoTen;
    this->maSinhVien = maSinhVien;
    this->diem = diem;
}

SinhVien::SinhVien(const SinhVien &other) {
    hoTen = other.hoTen;
    maSinhVien = other.maSinhVien;
    diem = other.diem;
}

SinhVien::~SinhVien() {
    hoTen = maSinhVien = "";
}


string SinhVien::getHoTen() {
    return hoTen;
}

void SinhVien::setHoTen(string hoTen) {
    this->hoTen = hoTen;
}

string SinhVien::getMaSinhVien() {
    return maSinhVien;
}

void SinhVien::setMaSinhVien(string maSinhVien) {
    this->maSinhVien = maSinhVien;
}

Diem SinhVien::getDiem() {
    return diem;
}

void SinhVien::setDiem(Diem diem) {
    this->diem = diem;
}
