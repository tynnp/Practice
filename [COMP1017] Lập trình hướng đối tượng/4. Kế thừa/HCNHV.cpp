#include <iostream>
#define endl '\n'
using namespace std;

class HinhChuNhat {
private:
    int dai, rong;
public:
    int tinhChuVi() {
        return (dai + rong) * 2;
    }  

    int tinhDienTich() {
        return dai * rong;
    }

    friend istream& operator >> (istream &in, HinhChuNhat &hcn) {
        in >> hcn.dai >> hcn.rong;
        return in;
    }
};

class HinhVuong : public HinhChuNhat {
private:
    int canh;
public: 
    int tinhChuVi() {
        return canh * 4;
    }  

    int tinhDienTich() {
        return canh * canh;
    }

    friend istream& operator >> (istream &in, HinhVuong &hv) {
        in >> hv.canh;
        return in;
    } 
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string hinh; cin >> hinh;
    HinhChuNhat hcn[100];
    HinhVuong hv[100];
    int n = 0, max = -10e6;

    if (hinh == "HCN") {
        while (cin >> hcn[n]) n++;
        for (int i = 0; i < n; i++)
            if (max < hcn[i].tinhChuVi())
                max = hcn[i].tinhChuVi();

    } else if (hinh == "HV") {
        while (cin >> hv[n]) n++;
        for (int i = 0; i < n; i++)
            if (max < hv[i].tinhChuVi())
                max = hv[i].tinhChuVi();
    }

    cout << max;
    return 0;
}
