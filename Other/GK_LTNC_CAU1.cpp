#include <iostream>
#include <iomanip>
using namespace std;

struct SinhVien {
    char* hoTen;
    int namSinh;
    float diem[3];
};

void nhapDanhSach(SinhVien list[], int n) {
    for (int i = 0; i < n; i++) {
        list[i].hoTen = new char[50];
        cin.getline(list[i].hoTen, 50);
        cin >> list[i].namSinh;
        cin >> list[i].diem[0] >> list[i].diem[1] >> list[i].diem[2];
        cin.ignore();
    }
    return;
}

double tongDiem(float list[]) {
    double res = 0;
    for (int i = 0; i < 3; i++)
        res += list[i];
    return res;
}

void sapXepGiam(SinhVien list[], int n) {
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && tongDiem(list[j-1].diem) < tongDiem(list[j].diem))
            swap(list[j-1], list[j]), j--;
    }
    return;
}

void inDanhSach(SinhVien list[], int n) {
    for (int i = 0; i < n; i++) {
        cout << i + 1 << " - ";
        cout << list[i].hoTen << " - ";
        cout << list[i].namSinh << " - ";
        cout << fixed << setprecision(2);
        cout << tongDiem(list[i].diem)/3;
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    
    SinhVien list[n];
    nhapDanhSach(list, n);
    sapXepGiam(list, n);
    inDanhSach(list, n);

    for (int i = 0; i < n; ++i) 
        delete[] list[i].hoTen;

    return 0;
}