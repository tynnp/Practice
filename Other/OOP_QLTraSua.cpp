#include <iostream>
#include <vector>
using namespace std;

class TraSua {
protected:
    string name;
    int gia;
    int soLuong;
    string thanhPhan;
    string hanSuDung;
public:
    TraSua(){} 
    TraSua(string, int, int, string, string);
    int giaTien();
    void setName(string);
};

class TraSuaTranChau : public TraSua {
public:
    static void tinhTong(vector<TraSuaTranChau>); void xuatDuLieu();
    friend istream& operator >> (istream&, TraSuaTranChau&);
};

class TraSuaSocola : public TraSua {
public:
    static void tinhTong(vector<TraSuaSocola>); void xuatDuLieu(); 
    friend istream& operator >> (istream&, TraSuaSocola&);
};

class TraSuaDau : public TraSua {
public:
    static void tinhTong(vector<TraSuaDau>); void xuatDuLieu(); 
    friend istream& operator >> (istream&, TraSuaDau&);
};

//------------------------------------------------------------------------------------------

int main() {
    string str; 
    vector<TraSuaTranChau> tstc;
    vector<TraSuaSocola> tss;
    vector<TraSuaDau> tsd;
    TraSuaTranChau a; 
    TraSuaSocola b;
    TraSuaDau c; 
    while (getline(cin, str)) {
        if (str == "Tra sua tran chau" || 
        str == "Tra sua tran chau ") {
            a.setName(str); cin >> a;
            tstc.push_back(a);
            a.xuatDuLieu();
        }
        else if (str == "Tra sua socola") {
            b.setName(str); cin >> b;
            tss.push_back(b);
            b.xuatDuLieu();
        }
        else if (str == "Tra sua dau") {
            c.setName(str); cin >> c;
            tsd.push_back(c);
            c.xuatDuLieu();
        }
    }
    TraSuaTranChau::tinhTong(tstc);
    TraSuaSocola::tinhTong(tss);
    TraSuaDau::tinhTong(tsd);
    return 0;
}

//------------------------------------------------------------------------------------------

TraSua::TraSua(string name, int gia, int soLuong, string thanhPhan, string hanSuDung) {
    this->name = name;
    this->gia = gia;
    this->soLuong = soLuong;
    this->thanhPhan = thanhPhan;
    this->hanSuDung = hanSuDung;
}

istream& operator >> (istream& in, TraSuaTranChau& tstc) {
    in >> tstc.gia >> tstc.soLuong; in.ignore();
    getline(in, tstc.thanhPhan);
    getline(in, tstc.hanSuDung);
    return in;
}

istream& operator >> (istream& in, TraSuaSocola& tss) {
    in >> tss.gia >> tss.soLuong; in.ignore();
    getline(in, tss.thanhPhan);
    getline(in, tss.hanSuDung);
    return in;
}

istream& operator >> (istream& in, TraSuaDau& tsd) {
    in >> tsd.gia >> tsd.soLuong; in.ignore();
    getline(in, tsd.thanhPhan);
    getline(in, tsd.hanSuDung);
    return in;
}

void TraSua::setName(string str) {
    this->name = str;
} 

void TraSuaTranChau::xuatDuLieu() {
    cout << "Thong tin cua tra sua tran chau:\n";
    cout << "Ten: " << name << endl;
    cout << "Gia: " << gia << endl;
    cout << "So luong: " << soLuong << endl;
    cout << "Thanh phan: " << thanhPhan << endl;
    cout << "Han su dung: " << hanSuDung << endl << endl;
}

void TraSuaSocola::xuatDuLieu() {
    cout << "Thong tin cua tra sua socola:\n";
    cout << "Ten: " << name << endl;
    cout << "Gia: " << gia << endl;
    cout << "So luong: " << soLuong << endl;
    cout << "Thanh phan: " << thanhPhan << endl;
    cout << "Han su dung: " << hanSuDung << endl << endl;
}

void TraSuaDau::xuatDuLieu() {
    cout << "Thong tin cua tra sua dau:\n";
    cout << "Ten: " << name << endl;
    cout << "Gia: " << gia << endl;
    cout << "So luong: " << soLuong << endl;
    cout << "Thanh phan: " << thanhPhan << endl;
    cout << "Han su dung: " << hanSuDung << endl << endl;
}

int TraSua::giaTien() {
    return gia*soLuong;
}

void TraSuaTranChau::tinhTong(vector<TraSuaTranChau> vt) {
    int sum = 0;
    for (TraSuaTranChau x : vt) 
        sum += x.giaTien();
    cout << "Tong tien cua tra sua tran chau: ";
    cout << sum << endl;
}

void TraSuaSocola::tinhTong(vector<TraSuaSocola> vt) {
    int sum = 0;
    for (TraSuaSocola x : vt) 
        sum += x.giaTien();
    cout << "Tong tien cua tra sua socola: ";
    cout << sum << endl;
}

void TraSuaDau::tinhTong(vector<TraSuaDau> vt) {
    int sum = 0;
    for (TraSuaDau x : vt) 
        sum += x.giaTien();
    cout << "Tong tien cua tra sua dau: ";
    cout << sum << endl;
}