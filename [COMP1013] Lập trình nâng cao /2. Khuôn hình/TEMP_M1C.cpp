#include <iostream>
using namespace std;

template <typename T>
struct M1C {
    int size = 0;
    T values[100];

    void nhap() {
        T n; 
        while (cin >> n)
            values[size++] = n;
        return;
    }

    int tong() {
        T res = 0;
        for (int i = 0; i < size; i++)
            res = res + values[i];
        return res;
    }

    void xuat() {
        cout << tong();
        return;
    }
};

int main() {
    M1C<int> arr;
    arr.nhap();
    arr.xuat();
    return 0;
}