#include <iostream>
#include <cmath>
using namespace std;

struct Date {
    int ngay, thang, nam;
    int ngayCuaThang[13] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    bool kiemTraNamNhuan() {
        return this->nam % 400 == 0 || 
        (this->nam % 4 == 0 && this->nam % 100 != 0);
    }

    void setSoNgay() {
        if (this->kiemTraNamNhuan()) this->ngayCuaThang[0] = 366;
        else this->ngayCuaThang[0] = 365;
        return;
    }

    bool kiemTraHopLe() {
        if (nam < 1900) return false;
        if (thang < 1 || thang > 12) return false;
        if (ngay < 1 || ngay > ngayCuaThang[thang]) return false;
        return true;
    }

    friend istream& operator >> (istream &in, Date &date) {
        in >> date.ngay >> date.thang >> date.nam;
        
        if (date.kiemTraNamNhuan()) date.ngayCuaThang[2] = 29;
        else date.ngayCuaThang[2] = 28;
        
        date.setSoNgay();
        return in;
    }

    friend ostream& operator << (ostream &out, Date date) {
        out << date.ngay << "-";
        out << date.thang << "-";
        out << date.nam;
        return out;
    }

    Date ngayKeTiep() {
        Date res;
        res.ngay = this->ngay + 1;
        res.thang = this->thang;
        res.nam = this->nam;

        if (res.ngay > this->ngayCuaThang[res.thang])
            res.ngay = 1, res.thang += 1;

        if (res.thang > 12) 
            res.thang = 1, res.nam += 1;

        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Date a;
    cin >> a;

    if (a.kiemTraHopLe()) 
        cout << "YES\n" << a.ngayKeTiep();
    else cout << "NO";

    return 0;
}