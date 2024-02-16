#include <iostream>
using namespace std;

struct SoDao {
    int number;

    friend istream& operator >> (istream &in, SoDao &sd) {
        in >> sd.number;
        return in;
    }

    friend ostream& operator << (ostream &out, SoDao sd) {
        out << "[SoDao] " << sd.number;
        return out;
    }

    int soDao() {
        int tmp = this->number;
        int res = 0;
        while (tmp > 0) 
            res = res*10 + tmp%10,
            tmp /= 10;
        return res;
    }

    bool operator > (SoDao sd) {
        return this->soDao() > sd.soDao();
    }

    int operator + (int x) {
        return this->soDao() + x;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    SoDao a, b;
    cin >> a >> b;

    cout << a << endl;
    cout << b << endl;

    cout << (a > b ? "YES" : "NO") << endl;
    
    int res = a + 0;
    cout << b + res;

    return 0;
}