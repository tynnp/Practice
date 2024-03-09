#include <iostream>
#include <algorithm>
using namespace std;

struct Tinh {
    string maTinh;
    string tenTinh;
    long long danSo;
    double dienTich;

    friend istream &operator >> (istream &in, Tinh &t) {
        string str;
        getline(in, str);

        size_t pos1 = str.find('_');
        size_t pos2 = str.find('_', pos1 + 1);
        size_t pos3 = str.find('_', pos2 + 1);

        t.maTinh = str.substr(0, pos1);
        t.tenTinh = str.substr(pos1 + 1, pos2 - pos1 - 1);
        t.danSo = stoll(str.substr(pos2 + 1, pos3 - pos2 - 1));
        t.dienTich = stod(str.substr(pos3 + 1));
    }
};

int main() {
    int n;
    bool check = true;
    cin >> n;
    cin.ignore();

    Tinh arr[n];
    for (Tinh &x : arr) cin >> x;

    for (Tinh x : arr) 
        if (x.danSo > 1000000) {
            cout << x.maTinh << " ";
            check = false;
        }
    if (check) cout << 0;
    cout << endl;

    Tinh max = arr[0];
    for (int i = 0; i < n; i++)
        if (arr[i].dienTich > max.dienTich)
            max = arr[i];
    cout << max.tenTinh << endl;

    sort(arr, arr + n, [](Tinh a, Tinh b) {
        return a.dienTich > b.dienTich;
    });

    for (Tinh x : arr) cout << x.maTinh << " ";
    return 0;
}