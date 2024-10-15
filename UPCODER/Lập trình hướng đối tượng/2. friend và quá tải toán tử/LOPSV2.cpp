#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

// Lớp Điểm
class Diem {
private:
    double danhSachDiem[100];   // danh sách điểm
    int size;                   // số lượng phần tử của danh sách điểm

public:
    Diem();                                 // khởi tạo mặc định
    Diem(double danhSachDiem[], int size);  // khởi tạo với tham số
    Diem(const Diem &other);                // sao chép
    ~Diem();                                // hàm hủy

    double* getDanhSachDiem();                              // lấy danh sách điểm
    void setDanhSachDiem(double danhSachDiem[], int size);  // gán danh sách điểm
    int getSize();                                          // lấy số lượng phần tử
    void setSize(int size);                                 // gán số lượng phần tử

    friend istream &operator >> (istream &in, Diem &diem);          // toán tử >>
    friend ostream &operator << (ostream &out, const Diem &diem);   // toán tử <<
    double &operator [] (int index);                                // toán tử []
    Diem &operator = (const Diem &other);                           // toán tử =
    double trungBinhCong() const;                                   // lấy điểm trung bình
};

// Lớp sinh viên
class SinhVien {
private:
    string hoTen;       // họ tên
    string maSinhVien;  // mã sinh viên
    Diem diemSinhVien;  // danh sách điểm

public:
    SinhVien();                                                     // khởi tạo mặc định
    SinhVien(string hoTen, string maSinhVien, Diem diemSinhVien);   // khởi tạo có tham số
    SinhVien(const SinhVien &other);                                // sao chép
    ~SinhVien();                                                    // hủy

    string getHoTen();                          // lấy họ tên
    void setHoTen(string hoTen);                // gán họ tên
    string getMaSinhVien();                     // lấy mã sinh viên
    void setMaSinhVien(string maSinhVien);      // gán mã sinh viên
    Diem getDiemSinhVien();                     // lấy danh sách điểm
    void setDiemSinhVien(Diem diemSinhVien);    // gán danh sách điểm

    friend istream &operator >> (istream &in, SinhVien &sinhVien);          // toán tử >>
    friend ostream &operator << (ostream &out, const SinhVien &sinhVien);   // toán tử <<
    SinhVien &operator = (const SinhVien &other);                           // toán tử =
    bool operator < (const SinhVien &other);                                // toán tử <
    double diemTrungBinhCong() const;                                       // lấy điểm trung bình của sinh viên
};

int main() {
    SinhVien sv;
    cin >> sv;
    cout << sv;
    return 0;
}

// Định nghĩa lớp Điểm ---------------------------------------------------------------------------------------------------------------

Diem::Diem() {
    size = 0;
}

Diem::Diem(double danhSachDiem[], int size) {
    this->size = size;
    for (int i = 0; i < size; i++)
        this->danhSachDiem[i] = danhSachDiem[i];
}

Diem::Diem(const Diem &other) {
    size = other.size;
    for (int i = 0; i < size; i++)
        danhSachDiem[i] = other.danhSachDiem[i];
}

Diem::~Diem() {
    // không cần định nghĩa
}

double* Diem::getDanhSachDiem() {
    return danhSachDiem;
}

void Diem::setDanhSachDiem(double danhSachDiem[], int size) {
    this->size = size;
    for (int i = 0; i < size; i++)
        this->danhSachDiem[i] = danhSachDiem[i];
}

int Diem::getSize() {
    return size;
}

void Diem::setSize(int size) {
    this->size = size;
}

istream &operator >> (istream &in, Diem &diem) {
    string strLine;
    double diemTungMon;

    // xử lý các số trên 1 dòng
    getline(in, strLine);
    stringstream ssLine(strLine);

    while (ssLine >> diemTungMon) 
        diem[diem.size++] = diemTungMon;
    
    return in;
}

ostream &operator << (ostream &out, const Diem &diem) {
    out << diem.trungBinhCong();
    return out;
}

double &Diem::operator [] (int index) {
    return danhSachDiem[index];
}

Diem &Diem::operator = (const Diem &other) {
    if (this == &other)
        return *this;

    size = other.size;
    for (int i = 0; i < size; i++)
        danhSachDiem[i] = other.danhSachDiem[i];

    return *this;
}

double Diem::trungBinhCong() const {
    double res = 0;
    for (int i = 0; i < size; i++)
        res += danhSachDiem[i];
    return size > 0 ? res / size : 0;
}

// Định nghĩa lớp Sinh viên ---------------------------------------------------------------------------------------------------------------

SinhVien::SinhVien() {
    hoTen = maSinhVien = "";
}

SinhVien::SinhVien(string hoTen, string maSinhVien, Diem diemSinhVien) {
    this->hoTen = hoTen;
    this->maSinhVien = maSinhVien;
    this->diemSinhVien = diemSinhVien;
}

SinhVien::SinhVien(const SinhVien &other) {
    hoTen = other.hoTen;
    maSinhVien = other.maSinhVien;
    diemSinhVien = other.diemSinhVien;
}

SinhVien::~SinhVien() {
    // không cần định nghĩa
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

Diem SinhVien::getDiemSinhVien() {
    return diemSinhVien;
}

void SinhVien::setDiemSinhVien(Diem diemSinhVien) {
    this->diemSinhVien = diemSinhVien;
}

istream &operator >> (istream &in, SinhVien &sinhVien) {
    getline(in, sinhVien.hoTen);
    getline(in, sinhVien.maSinhVien);
    in >> sinhVien.diemSinhVien;
    return in;
}

ostream &operator << (ostream &out, const SinhVien &sinhVien) {
    out << fixed << setprecision(1);
    out << "Ho Ten: " << sinhVien.hoTen << endl;
    out << "Ma Sinh Vien: " << sinhVien.maSinhVien << endl;
    out << "DTB: " << sinhVien.diemTrungBinhCong() << endl;
    return out;
}

SinhVien &SinhVien::operator = (const SinhVien &other) {
    if (this == &other)
        return *this;

    hoTen = other.hoTen;
    maSinhVien = other.maSinhVien;
    diemSinhVien = other.diemSinhVien;
    return *this;
}

bool SinhVien::operator < (const SinhVien &other) {
    return this->diemTrungBinhCong() < other.diemTrungBinhCong();
}

double SinhVien::diemTrungBinhCong() const {
    return diemSinhVien.trungBinhCong();
}