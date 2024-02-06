#include <iostream>
#include <cmath>
#include <fstream>
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

    friend istream& operator >> (istream &in, Date &date) {
        in >> date.ngay >> date.thang >> date.nam;
        
        if (date.kiemTraNamNhuan()) date.ngayCuaThang[2] = 29;
        else date.ngayCuaThang[2] = 28;
        
        date.setSoNgay();
        return in;
    }

    friend ostream& operator << (ostream &out, Date date) {
        if (date.ngay < 10) out << 0;
        out << date.ngay << "/";

        if (date.thang < 10) out << 0;
        out << date.thang << "/";

        if (date.nam < 1000) out << 0;
        if (date.nam < 100) out << 0;
        if (date.nam < 10) out << 0;
        out << date.nam;

        return out;
    }

    int demNgay() {
        int res = 0;
        for (int i = 1; i < this->thang; i++)
            res += this->ngayCuaThang[i];
        return res + this->ngay;
    }

    string thuTrongTuan() {
        int ngay = this->ngay;
        int thang = this->thang;
        int nam = this->nam;

        if (thang < 3) thang += 12, nam -= 1;
        int n = (ngay + 2*thang + (3*(thang+1))/5 + nam + (nam/4)) % 7;

        if (n == 0) return "Sunday";
        else if (n == 1) return "Monday";
        else if (n == 2) return "Tuesday";
        else if (n == 3) return "Wednesday";
        else if (n == 4) return "Thursday";
        else if (n == 5) return "Friday";
        else if (n == 6) return "Saturday";
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

    bool operator == (Date other) {
        return this->ngay == other.ngay && 
        this->thang == other.thang && 
        this->nam == other.nam;
    }

    bool kiemTraTrungThu(Date other) {
        return this->thuTrongTuan() == other.thuTrongTuan();
    }

    bool operator < (Date other) {
        if (this->nam < other.nam) return true;
        else if (this->nam == other.nam) {
            if (this->thang < other.thang) return true;
            else if (this->thang == other.thang) 
                if (this->ngay < other.ngay) return true;
        }
        return false;
    }

    int operator - (Date other) {
        Date max, min;
        if (*this < other) max = other, min = *this;
        else max = *this, min = other;

        int res = max.demNgay();
        while (--max.nam > min.nam) {
            max.setSoNgay();
            res += max.ngayCuaThang[0];
        }

        if (this->nam == other.nam) return res - min.demNgay();
        else return res + (min.ngayCuaThang[0] - min.demNgay());
    }
};

struct DateArray {
    int size;
    Date *values;

    friend istream& operator >> (istream &in, DateArray &arr) {
        in >> arr.size;
        arr.values = new Date[arr.size];
        for (int i = 0; i < arr.size; i++)
            in >> arr.values[i];
        return in;
    }

    friend ostream& operator << (ostream &out, DateArray arr) {
        for (int i = 0; i < arr.size; i++)
            out << arr.values[i] << " ";
        return out;
    }

    bool operator == (DateArray other) {
        if (this->size != other.size) return false;
        for (int i = 0; i < this->size; i++)
            if (this->values[i].thuTrongTuan() != other.values[i].thuTrongTuan()) return false;
        return true;
    } 

    bool operator < (DateArray other) {
        if (this->size > other.size) return false;
        for (int i = 0; i < this->size; i++)
            if (other.values[i] < this->values[i]) return false;
        return true;
    }

    DateArray operator + (DateArray other) {
        DateArray res;
        res.size = this->size + other.size;
        res.values = new Date[res.size];

        for (int i = 0; i < this->size; i++)
            res.values[i] = this->values[i];

        int index = this->size;
        for (int i = 0; i < other.size; i++)
            res.values[index++] = other.values[i];

        return res;
    }

    int* soNgay(DateArray other) {
        int *res = new int[this->size];
        for (int i = 0; i < this->size; i++)
            res[i] = this->values[i] - other.values[i];
        return res;
    }

    int tangGiam() {
        int tang = 0;
        int giam = 0;

        for (int i = 1; i < this->size; i++)
            tang += (this->values[i-1] < this->values[i]),
            giam += (this->values[i] < this->values[i-1]);

        if (tang > 0 && giam > 0) return 0;
        else if (tang > 0) return 1;
        else if (giam > 0) return -1;
    }

    void xapSepTangDan() {
        for (int i = 1; i < this->size; i++) {
            int j = i;
            while (j > 0 && this->values[j] < this->values[j-1]) {
                swap(this->values[j], this->values[j-1]);
                j--;
            }
        }
        return;
    }

    void xapSepGiamDan() {
        for (int i = 1; i < this->size; i++) {
            int j = i;
            while (j > 0 && this->values[j-1] < this->values[j]) {
                swap(this->values[j-1], this->values[j]);
                j--;
            }
        }
        return;
    }

    int demNamNhuan() {
        int cnt = 0;
        for (int i = 0; i < this->size; i++)
            if (this->values[i].kiemTraNamNhuan()) cnt++;
        return cnt;
    }
};

int main() {
    ifstream ifile; ifile.open("DATE.inp");
    ofstream ofile; ofile.open("DATE.out");

    DateArray a, b; ifile >> a >> b;
    string h; ifile >> h;

    ofile << a.demNamNhuan() << endl;
    for (int i = 0; i < a.size; i++)
            if (a.values[i].kiemTraNamNhuan()) 
                ofile << a.values[i] << " " << a.values[i].thuTrongTuan() << " " <<
                a.values[i].demNgay() << " " << a.values[i].ngayKeTiep() << endl;

    ofile << b.demNamNhuan() << endl;
    for (int i = 0; i < b.size; i++)
            if (b.values[i].kiemTraNamNhuan()) 
                ofile << b.values[i] << " " << b.values[i].thuTrongTuan() << " " <<
                b.values[i].demNgay() << " " << b.values[i].ngayKeTiep() << endl;

    ofile << (a == b ? "TRUE" : "FALSE") << endl;

    if (a.demNamNhuan() == b.demNamNhuan()) ofile << "1 = 2" << endl;
    else if (a.demNamNhuan() > b.demNamNhuan()) ofile << "1 > 2" << endl;
    else ofile << "1 < 2" << endl;

    if (a.tangGiam() == 0) ofile << "KHONG CO THU TU" << endl;
    else if (a.tangGiam() == 1) ofile << "TANG" << endl;
    else if (a.tangGiam() == -1) ofile << "GIAM" << endl;

    if (b.tangGiam() == 0) ofile << "KHONG CO THU TU" << endl;
    else if (b.tangGiam() == 1) ofile << "TANG" << endl;
    else if (b.tangGiam() == -1) ofile << "GIAM" << endl;

    int *mangNgay = a.soNgay(b);
    for (int i = 0; i < a.size; i++)     
        ofile << mangNgay[i] << " ";
    ofile << endl;

    DateArray c = a + b;
    ofile << c.size << endl;
    if (h == "TANG") c.xapSepTangDan();
    else if (h == "GIAM") c.xapSepGiamDan();

    for (int i = 0; i < c.size; i++)
        ofile << c.values[i] << endl;

    ifile.close();
    ofile.close();
}