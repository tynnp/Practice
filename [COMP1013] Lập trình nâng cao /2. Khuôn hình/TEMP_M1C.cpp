#include <iostream>
using namespace std;

template <typename T>
struct M1C {
    int size = 0;
    T values[100];

    void nhap() {
        T n; 
        while (cin >> n)
            this->values[this->size++] = n;
        return;
    }

    int tong() {
        T res = 0;
        for (int i = 0; i < this->size; i++)
            res = res + this->values[i];
        return res;
    }

    void xuat() {
        cout << this->tong();
        return;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    M1C<int> arr;
    arr.nhap();
    arr.xuat();
    return 0;
}