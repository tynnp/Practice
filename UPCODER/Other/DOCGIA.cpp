#include <iostream>
#include <fstream>
using namespace std;

class DocGia {
private:
    string maSo;
    string hoTen;
    string gioiTinh;
    int namSinh;
    int soSachMuon;
public:
    DocGia() {}

    DocGia (string str) {
        int start = 0, end = 0;
        
        for (end; str[end] != ','; end++);
        maSo = str.substr(start, end - start);

        start = end + 2;
        for (end++; str[end] != ','; end++);
        hoTen = str.substr(start, end - start);

        start = end + 2;
        for (end++; str[end] != ','; end++);
        gioiTinh = str.substr(start, end - start);

        start = end + 2;
        for (end++; str[end] != ','; end++);
        namSinh = stoi(str.substr(start, end - start));

        soSachMuon = stoi(str.substr(end + 1));
    }

    string getGioiTinh() {
        return gioiTinh;
    }

    int getTuoi() {
        return 2017 - namSinh;
    }

    int tienMuon() {
        if (2017 - namSinh <= 14) return 2000*soSachMuon;
        else return 5000*soSachMuon;
    }
};

int main() {
    ifstream ifile;
    ofstream ofile;
    ifile.open("input.txt");
    ofile.open("output.txt");

    int n = 0, res = 0;
    int lonNam = 0, lonNu = 0, nhoNam = 0, nhoNu = 0;
    DocGia arr[100];

    string tmp;
    while (getline(ifile, tmp)) {
        arr[n] = DocGia(tmp);
        n++;
    }

    for (int i = 0; i < n; i++) {
        res += arr[i].tienMuon();
        if (arr[i].getTuoi() <= 14) {
            if (arr[i].getGioiTinh() == "Nam") nhoNam++;
            else nhoNu++;
        } else {
            if (arr[i].getGioiTinh() == "Nam") lonNam++;
            else lonNu++;
        }
    }

    ofile << n << endl;
    ofile << res << endl;
    ofile << lonNam + lonNu << " (" << lonNam << " Nam, " << lonNu << " Nu)\n";
    ofile << nhoNam + nhoNu << " (" << nhoNam << " Nam, " << nhoNu << " Nu)\n";
    
    ifile.close();
    ofile.close();
    return 0;
}