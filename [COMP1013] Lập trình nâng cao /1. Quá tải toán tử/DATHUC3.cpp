#include <iostream>
#include <cmath>
using namespace std;

struct BacHai {
    int a, b, c;

    friend istream& operator >> (istream &in, BacHai &bacHai) {
        in >> bacHai.a >> bacHai.b >> bacHai.c;
        return in;
    }

    friend ostream& operator << (ostream &out, BacHai bacHai) {
        out << bacHai.a << "x^2";

        if (bacHai.b < 0) out << "-";
        else out << "+";
        out << abs(bacHai.b) << "x";

        if (bacHai.c < 0) out << "-";
        else out << "+";
        out << abs(bacHai.c);
    }

    int tinhGiaTri(int x) {
        return this->a*x*x + this->b*x + this->c;
    }

    BacHai operator + (BacHai bacHai) {
        BacHai res;
        res.a = this->a + bacHai.a;
        res.b = this->b + bacHai.b;
        res.c = this->c + bacHai.c;
        return res;
    }

    bool operator == (BacHai bacHai) {
        return this->a == bacHai.a && this->b == bacHai.b && this->c == bacHai.c;
    }
};

struct BacNhat {
    int a, b;

    friend istream& operator >> (istream &in, BacNhat &bacNhat) {
        in >> bacNhat.a >> bacNhat.b;
        return in;
    }

    friend ostream& operator << (ostream &out, BacNhat bacNhat) {
        out << bacNhat.a << "x";

        if (bacNhat.b < 0) out << "-";
        else out << "+";
        out << abs(bacNhat.b);

        return out;
    }

    BacHai operator * (BacNhat bacNhat) {
        BacHai res;
        res.a = this->a * bacNhat.a;
        res.b = this->a * bacNhat.b + this->b*bacNhat.a;
        res.c = this->b * bacNhat.b;
        return res;
    }

    int tinhGiaTri(int x) {
        return this->a*x + this->b;
    }
};

int main() {
    BacHai F1, F2;
    BacNhat F3, F4;
    cin >> F1 >> F2 >> F3 >> F4;
    int x; cin >> x;

    cout << F1 << endl;
    cout << F1.tinhGiaTri(x) << endl;

    cout << F2 << endl;
    cout << F2.tinhGiaTri(x) << endl;

    BacHai F5 = F1 + F2;
    cout << F5 << endl;
    cout << F5.tinhGiaTri(x) << endl;

    BacHai F6 = F3 * F4;
    cout << "(" << F3 << ")*(" << F4 << ")=";
    cout << F6 << endl;
    cout << F6.tinhGiaTri(x) << endl;

    if (F1 == F2 && F2 == F6) cout << "TRUE3";
    else if (F2 == F6) cout << "TRUE2";
    else if (F1 == F6) cout << "TRUE1";
    else cout << "FALSE";

    return 0;
}