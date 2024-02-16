#include <iostream>
using namespace std;

struct BacNhat {
    int a;
    int b;
    int x;

    friend istream& operator >> (istream& in, BacNhat &other) {
        in >> other.a >> other.b;
        return in;
    }

    friend ostream& operator << (ostream& out, BacNhat other) {
        out << other.a << "x+" << other.b;
        return out;
    }

    int giaTri(int x) {
        return this->a*x + this->b;
    }

    BacNhat operator + (BacNhat other) {
        BacNhat res;
        res.a = this->a + other.a;
        res.b = this->b + other.b;
        return res;
    }

    bool operator == (BacNhat other) {
        return this->a + this->b == other.a + other.b;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    BacNhat f1, f2;
    int x;
    cin >> f1 >> f2 >> x;

    cout << f1 << endl;
    cout << f2 << endl;
    cout << f1 << "+" << f2 << "=" << f1 + f2 << endl;
    cout << f1.giaTri(x) << endl;
    cout << f2.giaTri(x) << endl;
    
    if (f1 == f2) cout << "TRUE";
    else cout << "FALSE";

    return 0;
}