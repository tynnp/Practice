#include <iostream>
using namespace std;

class Hinh {
public: 
    virtual istream& nhap(istream& in) = 0;
    virtual double dienTich() = 0;
};

class HinhVuong : public Hinh {
private:
    double canh;
public:
    virtual istream& nhap(istream& in) {
        in >> canh;
        return in;
    }

    virtual double dienTich() {
        return canh * 4;
    }
};

class HinhChuNhat : public Hinh {
private:
    double dai, rong;
public: 
    virtual istream& nhap(istream& in) {
        in >> dai >> rong;
        return in;
    }

    virtual double dienTich() {
        return (dai + rong) * 2;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Hinh* arr[100];
    int i = 0; char c;

    while (cin >> c) {
        if (c == 'a') arr[i] = new HinhVuong();
        else if (c == 'b') arr[i] = new HinhChuNhat();
        arr[i]->nhap(cin);
        cout << arr[i]->dienTich() << '\n';
    }

    return 0;
}