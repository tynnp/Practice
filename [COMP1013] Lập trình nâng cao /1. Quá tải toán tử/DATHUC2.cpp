#include <iostream>
using namespace std;

struct BacNhat {
    int a, b;

    void nhap() {
        cin >> this->a >> this->b;
        return;
    }

    void xuat() {
        cout << this->a << "x";
        if (this->b > 0) cout << "+";
        cout << this->b;
        return;
    }

    int giaTri(int x) {
        return this->a*x + this->b;
    }

    BacNhat congBacNhat(BacNhat other) {
        BacNhat res;
        res.a = this->a + other.a;
        res.b = this->b + other.b;
        return res;
    }

    bool soSanh(BacNhat other) {
        return (this->a + this->b) == (other.a + other.b);
    }
};

int main() {
    BacNhat a, b;
    int x;

    a.nhap();
    b.nhap();
    cin >> x;

    a.xuat(); cout << endl;
    b.xuat(); cout << endl;

    BacNhat c = a.congBacNhat(b);
    a.xuat(); cout << "+";
    b.xuat(); cout << "=";
    c.xuat(); cout << endl;

    cout << a.giaTri(x) << endl;
    cout << b.giaTri(x) << endl;

    cout << (a.soSanh(b) ? "TRUE" : "FALSE");
    return 0;
}