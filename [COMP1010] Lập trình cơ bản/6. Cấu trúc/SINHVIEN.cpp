#include <iostream>
#define endl '\n'
using namespace std;

struct SinhVien {
    string HoTen;
    int NamSinh;
    double DTB;
};

void xuatDiemCao(SinhVien list[], int size) {
    SinhVien max = list[0];
    for (int i = 1; i < size; i++) 
        if (max.DTB < list[i].DTB)
            max = list[i];

    cout << "Diem cao nhat lop:\n";
    int cnt = 0;
    for (int i = 0; i < size; i++) {
        if (list[i].DTB == max.DTB) {
            cout << "#" << ++cnt << endl;
            cout << list[i].HoTen << " ";
            cout << list[i].NamSinh << " ";
            cout << list[i].DTB << "\n";
        }
    }
    return;
}

void xuatDiemThap(SinhVien list[], int size) {
    SinhVien min = list[0];
    for (int i = 1; i < size; i++) 
        if (min.DTB > list[i].DTB)
            min = list[i];

    cout << "Diem thap nhat lop:\n";
    int cnt = 0;
    for (int i = 0; i < size; i++) {
        if (list[i].DTB == min.DTB) {
            cout << "#" << ++cnt << endl;
            cout << list[i].HoTen << " ";
            cout << list[i].NamSinh << " ";
            cout << list[i].DTB << "\n";
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    SinhVien list[100];
    int size = 0;
    while (cin >> list[size].HoTen >> list[size].NamSinh >> list[size].DTB) size++;
    xuatDiemCao(list, size);
    xuatDiemThap(list, size);
    return 0;
}