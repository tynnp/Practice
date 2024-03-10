
// Chua xong

#include <iostream>
using namespace std;

class Nguoi {
private:
    string hoTen;
    string gioiTinh;
    int tuoi;
    string quocTich;
    int chieuCao;
    int canNang;
public:
    Nguoi() {}
    ~Nguoi() {}

    Nguoi(string hoTen, string gioiTinh, int tuoi, string quocTich, int chieuCao, int canNang) {
        this->hoTen = hoTen;
        this->gioiTinh = gioiTinh;
        this->tuoi = tuoi;
        this->quocTich = quocTich;
        this->chieuCao = chieuCao;
        this->canNang = canNang;
    }

    Nguoi(const Nguoi &other) {
        hoTen = other.hoTen;
        gioiTinh = other.gioiTinh;
        tuoi = other.tuoi;
        quocTich = other.quocTich;
        chieuCao = other.chieuCao;
        canNang = other.canNang;
    }

    void setHoTen(string hoTen) {
        this->hoTen = hoTen;
    }  

    string getHoTen() {
        return hoTen;
    }

    void setGioiTinh(string gioiTinh) {
        this->gioiTinh = gioiTinh;
    }

    string getGioiTinh() {
        return gioiTinh;
    }

    void setTuoi(int tuoi) {
        this->tuoi = tuoi;
    }

    int getTuoi() {
        return tuoi;
    }

    void setQuocTich(string quocTich) {
        this->quocTich = quocTich;
    }

    string getQuocTich() {
        return quocTich;
    }

    void setChieuCao(int chieuCao) {
        this->chieuCao = chieuCao;
    }

    int getChieuCao() {
        return chieuCao;
    }

    void setCanNang(int canNang) {
        this->canNang = canNang;
    }

    int getCanNang() {
        return canNang;
    }

    friend istream &operator >> (istream &in, Nguoi &n) {
        in.ignore();
        getline(in, n.hoTen);
        in >> n.gioiTinh >> n.tuoi;

        in.ignore();
        getline(in, n.quocTich);
        in >> n.chieuCao >> n.canNang;
        
        return in;
    }

    
};