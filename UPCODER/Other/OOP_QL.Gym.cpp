#include <iostream>
using namespace std;

class Nguoi {
protected:
    string tenKhachHang;
    string maKhachHang;
    string soDienThoai;
public:
    Nguoi() {}
    ~Nguoi() {}

    Nguoi(string tenKhachHang, string maKhachHang, string soDienThoai) {
        this->tenKhachHang = tenKhachHang;
        this->maKhachHang = maKhachHang;
        this->soDienThoai = soDienThoai;
    }

    Nguoi(const Nguoi &other) {
        tenKhachHang = other.tenKhachHang;
        maKhachHang = other.maKhachHang;
        soDienThoai = other.soDienThoai;
    }

    void setTenKhachHang(string tenKhachHang) {
        this->tenKhachHang = tenKhachHang;
        return;
    }

    void setMaKhachHang(string maKhachHang) {
        this->maKhachHang = maKhachHang;
        return;
    }

    void setSoDienThoai(string soDienThoai) {
        this->soDienThoai = soDienThoai;
        return;
    }

    string getTenKhachHang() {
        return tenKhachHang;
    }

    string getMaKhachHang() {
        return maKhachHang;
    }

    string getSoDienThoai() {
        return soDienThoai;
    }
};

class KhachHang : public Nguoi {
private:
    string loaiKhachHang;
    string goiDangKy;
    int thoiGianGoi;
    long long chiPhiGoi;
    string ngayDangKy;
public:
    KhachHang() {}
    ~KhachHang() {}

    KhachHang(string tenKhachHang, string maKhachHang, string soDienThoai, string loaiKhachHang, string goiDangKy, 
    int thoiGianGoi, long long chiPhiGoi, string ngayDangKy) : Nguoi(tenKhachHang, maKhachHang, soDienThoai) {
            this->loaiKhachHang = loaiKhachHang;
            this->goiDangKy = goiDangKy;
            this->thoiGianGoi = thoiGianGoi;
            this->chiPhiGoi = chiPhiGoi;
            this->ngayDangKy =ngayDangKy;
    }

    KhachHang(const KhachHang &other) : Nguoi(other) {
        loaiKhachHang = other.loaiKhachHang;
        goiDangKy = other.goiDangKy;
        thoiGianGoi = other.thoiGianGoi;
        chiPhiGoi = other.chiPhiGoi;
        ngayDangKy = other.ngayDangKy;
    }

    void setLoaiKhachHang(string loaiKhachHang) {
        this->loaiKhachHang = loaiKhachHang;
        return;
    }

    void setGoiDangKy(string goiDangKy) {
        this->goiDangKy = goiDangKy;
        return;
    }

    void setThoiGianGoi(int thoiGianGoi) {
        this->thoiGianGoi = thoiGianGoi;
        return;
    }

    void setChiPhiGoi(long long chiPhiGoi) {
        this->chiPhiGoi = chiPhiGoi;
        return;
    }

    void setNgayDangKy(string ngayDangKy) {
        this->ngayDangKy = ngayDangKy;
        return;
    }

    string getLoaiKhachHang() {
        return loaiKhachHang;
    }

    string getGoiDangKy() {
        return goiDangKy;
    }

    int getThoiGianGoi() {
        return thoiGianGoi;
    }

    long long getChiPhiGoi() {
        return chiPhiGoi;
    }

    string getNgayDangKy() {
        return ngayDangKy;
    }

    int thanhTien() {
        if (loaiKhachHang == "VIP") return chiPhiGoi - chiPhiGoi*0.15;
        else return chiPhiGoi;
    }

    friend istream &operator >> (istream &in, KhachHang &kh) {
        int n;

        in >> n;
        if (n == 1) kh.loaiKhachHang = "VIP";
        else if (n == 2) kh.loaiKhachHang = "NOR";
        in.ignore();

        getline(in, kh.tenKhachHang);
        in >> kh.maKhachHang >> kh.soDienThoai >> kh.ngayDangKy;

        in >> n;
        if (n == 1) kh.goiDangKy = "Gym";
        else if (n == 2) kh.goiDangKy = "Yoga";
        in.ignore();

        in >> n;
        if (n == 1) kh.thoiGianGoi = 1;
        else if (n == 2) kh.thoiGianGoi = 6;
        else if (n == 3) kh.thoiGianGoi = 12;

        if (kh.thoiGianGoi == 1) kh.chiPhiGoi = 350000;
        else if (kh.thoiGianGoi == 6) kh.chiPhiGoi = 2100000;
        else if (kh.thoiGianGoi == 12) kh.chiPhiGoi = 3000000;

        return in;
    }

    friend ostream &operator << (ostream &out, KhachHang &kh) {
        out << "Loai khach hang: " << kh.loaiKhachHang << endl;
        out << "Ten khach hang: " << kh.tenKhachHang << endl;
        out << "Ma khach hang: " << kh.maKhachHang << endl;
        out << "So dien thoai: " << kh.soDienThoai << endl;
        out << "Ngay dang ký: " << kh.ngayDangKy << endl;
        out << "Goi tap: " << kh.goiDangKy << endl;
        out << "So thoi gian dang ky tap: ";
        if (kh.thoiGianGoi < 12) out << kh.thoiGianGoi << " thang\n";
        else out << "1 nam\n";
        out << "Thanh tien: " << kh.thanhTien() << endl;
    } 
};

int main() {
    int size;
    cin >> size;

    KhachHang arr[size];
    for (KhachHang &x : arr) cin >> x;

    cout << "So luong khach hang: " << size << endl;
    for (int i = 0; i < size; i++) {
        cout << "Khach hang thu: " << i+1 << endl;
        cout << arr[i] << endl;
    }

    return 0;
}