#include <iostream>
#include <cmath>
using namespace std;

struct DonThuc {
    int heSo;
    int soMu;

    DonThuc daoHam() {
        DonThuc res;
        res.heSo = this->heSo * this->soMu;
        res.soMu = this->soMu - 1;
        return res;
    }
    
    friend ostream& operator << (ostream &out, DonThuc donThuc) {
        if (donThuc.heSo != 0) {
            if (donThuc.soMu != 0) {
                if (abs(donThuc.heSo) == 1) out << "x";
                else out << abs(donThuc.heSo) << "x";
                if (donThuc.soMu > 1) out << "^" << donThuc.soMu;
            } else out << abs(donThuc.heSo);
        }

        return out;
    }
};

struct DaThuc {
    int bac;
    DonThuc giaTri[100];

    friend istream& operator >> (istream &in, DaThuc &daThuc) {
        in >> daThuc.bac;
        int size = daThuc.bac;

        for (int i = size; i >= 0; i--) {
            in >> daThuc.giaTri[i].heSo;
            daThuc.giaTri[i].soMu = i;
        }

        return in;
    }

    friend ostream& operator << (ostream &out, DaThuc daThuc) {
        int size = daThuc.bac;
        bool check = false;

        for (int i = size; i >= 0; i--) {
            int heSo = daThuc.giaTri[i].heSo;

            if (check && heSo > 0) cout << "+";
            if (heSo < 0) cout << "-";
            cout << daThuc.giaTri[i];

            if (heSo != 0) check = true;
        }

        return out;
    }

    DaThuc daoHamCapMot() {
        DaThuc res;
        res.bac = this->bac-1;
        for (int i = res.bac; i >= 0; i--)  
            res.giaTri[i] = this->giaTri[i+1].daoHam();
        return res;
    }

    DaThuc daoHamCapHai() {
        DaThuc res1, res2;
        res1 = this->daoHamCapMot();
        res2 = res1.daoHamCapMot();
        return res2;
    }

    int check() {
        int res = 0;
        for (int i = this->bac; i >= 0; i--)    
            res += this->giaTri[i].heSo;
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    DaThuc a; cin >> a;
    cout << a << endl;
    DaThuc b = a.daoHamCapMot();
    DaThuc c = a.daoHamCapHai();

    if (b.check() == 0) cout << 0 << endl;
    else cout << b << endl;

    if (c.check() == 0) cout << 0 << endl;
    else cout << c << endl;

    return 0;
}