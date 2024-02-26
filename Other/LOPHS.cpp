#include <iostream>
#include <vector>
using namespace std;

class HocSinh {
private:
    string name;
    double van;
    double toan;
public:
    void nhap(); 
    void xuat();
    void setName(string); 
    void setVan(double); 
    void setToan(double);
    string getName(); 
    double getVan(); 
    double getToan();
    double diemTrungBinh(); 
    string xepLoai();
    static HocSinh caoNhat(vector<HocSinh>);
};
 
int main() {
    int n; 
    vector<HocSinh> vt(n);
    cin >> n; 
    cin.ignore();
    for (HocSinh &x : vt) x.nhap();
    HocSinh::caoNhat(vt).xuat();
    return 0;
}

void HocSinh::nhap() {
    getline(cin, name);
    cin >> toan >> van; 
    cin.ignore();
}

void HocSinh::xuat() {
    cout << name << endl;
    cout << xepLoai();
}

double HocSinh::diemTrungBinh() {
    return (van + toan)/2.0;
}

string HocSinh::xepLoai() {
    double diem = diemTrungBinh();
    if (diem >= 8) return "Gioi";
    else if (diem >= 7) return "Kha";
    else if (diem >= 5) return "Trung Binh";
    else return "Yeu";
}

HocSinh HocSinh::caoNhat(vector<HocSinh> vt) {  
    HocSinh res = vt[0];
    for (HocSinh x : vt) 
        if (x.diemTrungBinh() > res.diemTrungBinh())
            res = x;
    return res;
}