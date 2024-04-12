#include <iostream>
#include <vector>
using namespace std;

vector<int> PhanTichThuaSoNguyenTo(int so) {
    vector<int> thuaSo(so + 1, 0);
    for (int i = 2; i <= so; ++i) {
        int soHienTai = i;
        for (int j = 2; j <= soHienTai; ++j) {
            while (soHienTai % j == 0) {
                thuaSo[j]++;
                soHienTai /= j;
            }
        }
    }
    return thuaSo;
}

int DemSoUocCuaGiaiThua(int n) {
    vector<int> cacThuaSo = PhanTichThuaSoNguyenTo(n);
    int soUoc = 1;
    for (int i = 2; i <= n; ++i) 
        if (cacThuaSo[i] > 0) 
            soUoc *= (cacThuaSo[i] + 1);
    return soUoc;
}

int main() {
    int n;
    cin >> n;
    cout << DemSoUocCuaGiaiThua(n);
    return 0;
}