#include <iostream>
#include <iomanip>
using namespace std;

struct BoSua {
    string maBo;
    string tenBo;
    string ngaySinh;
    string gioiTinh;
    double canNang;

    friend istream &operator >> (istream &in, BoSua &boSua) {
        string str, date;
        int start = 0, end = 0;
        getline(in, str);

        for (end; str[end] != ' '; end++);
        boSua.maBo = str.substr(start, end - start);

        start = end + 1;
        for (end++; str[end] != ' '; end++);
        boSua.tenBo = str.substr(start, end - start);

        start = end + 1;
        for (end++; str[end] != ' '; end++);
        date = str.substr(start, end - start);
        for (int i = 0; i < date.length(); i++) {
            if (i > 0 && i < 5 && i % 2 == 0) boSua.ngaySinh += '/';
            boSua.ngaySinh += date[i];
        }


        start = end + 1;
        for (end++; str[end] != ' '; end++);
        boSua.gioiTinh = str.substr(start, end - start);

        boSua.canNang = stod(str.substr(end + 1));
        return in;
    }

    friend ostream &operator << (ostream &out, BoSua boSua) {
        if (boSua.canNang <= 20) return out;
        out << "[BoSua] = \"Mã Bò: " << boSua.maBo << "\",\"Tên Bò: " << boSua.tenBo << "\",\"";
        out << "Ngày Sinh: " << boSua.ngaySinh << "\",\"Giới tính: " << boSua.gioiTinh << "\",\"";
        out << "Cân nặng: " << fixed << setprecision(1) << boSua.canNang << "kg\"\n";
        return out;
    }
};

int main() {
    int test;
    cin >> test;
    cin.ignore();

    while (test--) {
        BoSua a;
        cin >> a;
        cout << a;
    }

    return 0;
}