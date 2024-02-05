#include <iostream>
#include <cmath>
using namespace std;

struct DaThuc {
    int bac;
    int *heSo;

    friend istream& operator >> (istream &in, DaThuc &daThuc) {
        in >> daThuc.bac;
        daThuc.bac += 1;
        daThuc.heSo = new int[daThuc.bac];
        for (int i = daThuc.bac-1; i >= 0; i--)
            in >> daThuc.heSo[i];
        return in;
    }

    friend ostream& operator << (ostream &out, DaThuc daThuc) {
        bool check = false; // Kiểm tra xem trước đó có đơn thức nào hay chưa
        for (int i = daThuc.bac-1; i >= 0; i--) {
            int giaTri = daThuc.heSo[i];

            if (giaTri != 0) {
                if (check && giaTri > 0) out << "+";
                if (giaTri == -1) out << "-";
                if (abs(giaTri) == 1 && i == 0) out << abs(giaTri);
                if (abs(giaTri) != 1) out << giaTri;
                if (i != 1 && i != 0) out << "x^" << i;
                if (i == 1) out << "x";
            }  

            if (daThuc.heSo[i] != 0) check = true;
        }
        return out;
    }
};

DaThuc daoHamCapMot(DaThuc other) {
    DaThuc res;
    res.bac = other.bac-1;
    res.heSo = new int[res.bac];
    for (int i = res.bac-1; i >= 0; i--)
        res.heSo[i] = other.heSo[i+1]*(i+1);
    return res;
}

DaThuc daoHamCapHai(DaThuc other) {
    DaThuc res1 = daoHamCapMot(other);
    DaThuc res2 = daoHamCapMot(res1);
    return res2;
}

int main() {
    DaThuc a; cin >> a;
    cout << a << endl;
    cout << daoHamCapMot(a) << endl;
    cout << daoHamCapHai(a) << endl;
    return 0;
}