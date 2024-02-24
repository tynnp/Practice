#include <iostream>
using namespace std;

struct Thongtin {
    string sdt;
    int den, di;
};

void XuatTT(Thongtin ttin) {
    cout << "{" << ttin.sdt << "," << ttin.den << "," << ttin.di << "}";
    cout << endl;
}

int main() {
    int n; 
    string so_can_tim;
    cin >> n >> so_can_tim;

    Thongtin arr[n]; 
    for (int i = 0; i < n; i++)
        cin >> arr[i].sdt >> arr[i].den >> arr[i].di;

   
    for (int i = 0; i < n; i++)
        if (arr[i].sdt == so_can_tim)
            XuatTT(arr[i]);

    int vta = -1, max = -10e6;
    for (int i = 0; i < n; i++)
        if (arr[i].den > max) 
            max = arr[i].den, vta = i;
    XuatTT(arr[vta]);

    int vtb = -1, min = 10e6;
    for (int i = 0; i < n; i++)
        if (arr[i].den < min) 
            min = arr[i].den, vtb = i;

    XuatTT(arr[vtb]);
    return 0;
}