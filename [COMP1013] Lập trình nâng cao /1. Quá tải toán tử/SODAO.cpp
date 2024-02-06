#include <iostream>
using namespace std;

struct SoDao {
    string number;

    int soChan() {
        int res = 0;
        for (int i = 0; i < this->number.length(); i += 2)
            res = res*10 + (this->number[i] - 48);
        return res;
    }

    int soLe() {
        int res = 0;
        for (int i = 1; i < this->number.length(); i += 2)
            res = res*10 + (this->number[i] - 48);
        return res;
    }

    friend istream& operator >> (istream &in, SoDao &soDao) {
        in >> soDao.number;
        return in;
    }

    friend ostream& operator << (ostream &out, SoDao soDao) {
        out << soDao.soChan();
        return out;
    }

    bool operator < (SoDao other) {
        return this->soChan() < other.soChan();
    }
};

int tongThanhPhan(SoDao soDao, int key = 0) {
    int resChan = 0;
    int resLe = 0;
    
    for (int i = 0; i < soDao.number.length(); i++) {
        if (i % 2 == 0) resChan += (soDao.number[i] - 48);
        else resLe += (soDao.number[i] - 48);
    }

    if (key == 0) return resChan;
    else return resLe;
}

int main() {
    SoDao a, b; 
    int key; 

    cin >> a >> b;
    cin >> key;
    
    cout << a << endl;
    cout << b << endl;
    cout << (a < b ? "true" : "false") << endl;
    cout << tongThanhPhan(a, key) << endl;
    cout << tongThanhPhan(b, key) << endl;
    return 0;
}