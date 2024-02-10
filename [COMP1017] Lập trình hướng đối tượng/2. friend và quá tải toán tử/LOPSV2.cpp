#include <iostream>
#include <iomanip>
using namespace std;

class Diem {
private:
    int size;
    double* arr;
public:
    Diem() {}

    Diem(int size): size(size) {
        this->arr = new double[this->size];
    }

    Diem(const Diem &other) {
        this->size = other.size;
        this->arr = new double[this->size];
        for (int i = 0; i < this->size; i++) 
            this->arr[i] = other.arr[i];
    }

    ~Diem() {
        delete[] this->arr;
    }

    void setSize(int size) {
        this->size = size;
        return;
    }

    int getSize() {
        return this->size;
    }

    void setArr(double* arr) {
        this->arr = arr;
        return;
    }

    double* getArr() {
        return this->arr;
    }

    friend istream& operator >> (istream &in, Diem &diem) {
        diem.size = 0;
        diem.arr = new double[100];
        while (in >> diem.arr[diem.size]) diem.size++;
        return in;
    }

    friend ostream& operator << (ostream &out, Diem diem) {
        for (int i = 0; i < diem.size; i++)
            cout << diem.arr[i] << " ";
        return out;
    }

    double operator [] (int index) {
        return this->arr[index];
    }

    void operator = (Diem other) {
        this->size = other.size;
        this->arr = new double[other.size];
        for (int i = 0; i < other.size; i++)
            this->arr[i] = other.arr[i];
        return;
    }

    double diemTrungBinh() {
        double res = 0;
        for(int i = 0; i < this->size; i++)
            res += this->arr[i];
        return res / this->size;
    }
};

class SinhVien {
private:
    string hoVaTen;
    string maSinhVien;
    Diem diem;
public:
    SinhVien() {}

    SinhVien(string hoVaTen, string maSinhVien, Diem diem):
        hoVaTen(hoVaTen), maSinhVien(maSinhVien), diem(diem) {}

    SinhVien(const SinhVien &sinhVien) {
        this->hoVaTen = sinhVien.hoVaTen;
        this->maSinhVien = sinhVien.maSinhVien;
        this->diem = sinhVien.diem;
    }

    ~SinhVien() {}

    void setHoVaTen(string hoVaTen) {
        this->hoVaTen = hoVaTen;
        return;
    }

    string getHoVaTen() {
        return this->hoVaTen;
    }

    void setMaSinhVien(string maSinhVien) {
        this->maSinhVien = maSinhVien;
        return;
    }

    string getMaSinhVien() {
        return this->maSinhVien;
    }

    void setDiem(Diem diem) {
        this->diem = diem;
        return;
    }

    Diem getDiem() {
        return this->diem;
    }

    friend istream& operator >> (istream &in, SinhVien &sv) {
        getline(in, sv.hoVaTen);
        getline(in, sv.maSinhVien);
        in >> sv.diem;
        return in;
    }

    friend ostream& operator << (ostream &out, SinhVien sv) {
        out << "Ho Ten: " << sv.hoVaTen << endl;
        out << "Ma Sinh Vien: " << sv.maSinhVien << endl;
        out << fixed << setprecision(1);
        out << "DTB: " << sv.diem.diemTrungBinh();
        return out;
    }
};

int main() {
    SinhVien sv = SinhVien();
    cin >> sv;
    cout << sv;
    return 0;
}