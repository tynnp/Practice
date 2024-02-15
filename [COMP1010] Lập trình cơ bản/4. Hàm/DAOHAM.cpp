#include <iostream>
#include <cmath>
#define endl '\n'
using namespace std;

struct DonThuc {
    double a;
    int n;
};

struct DaThuc {
    int size;
    DonThuc arr[100];

    void nhapDaThuc() {
        cin >> size;
        for (int i = 0; i < size; i++)
            cin >> arr[i].a;
        for (int i = 0; i < size; i++)
            cin >> arr[i].n;
        return;
    }

    void xuatDaThuc() {
        bool check = false;
        for (int i = 0; i < size; i++) {
            if (arr[i].a != 0) {
                if (i == 0 && arr[i].a < 0) cout << "-"; 

                if (check && arr[i].a < 0) cout << " - ";
                else if (check && arr[i].a > 0) cout << " + ";

                if (abs(arr[i].a) != 1 || (abs(arr[i].a) == 1 && arr[i].n == 0)) {
                    cout << abs(arr[i].a);
                    check = true;
                } 

                if (arr[i].n != 0) {
                    cout << "x";
                    if (arr[i].n > 1) cout << "^" << arr[i].n;
                }
            } 
        }
        return;
    }

    double giaTri(int x) {
        double res = 0;
        for (int i = 0; i < size; i++)  
            res += arr[i].a * pow(x, arr[i].n);
        return res;
    }

    void xuatDaoHam() {
        DaThuc res;
        res.size = this->size;
        for (int i = 0; i < this->size; i++) {
            if (this->arr[i].n > 0)
                res.arr[i].a = this->arr[i].a * this->arr[i].n,
                res.arr[i].n = this->arr[i].n - 1;
            else 
                res.arr[i].a = 0,
                res.arr[i].n = 0;
        }
        res.xuatDaThuc();
        return;
    }
};

int main() {
    DaThuc daThuc;
    daThuc.nhapDaThuc();
    daThuc.xuatDaThuc(); cout << endl;
    double x; cin >> x;
    cout << daThuc.giaTri(x) << endl;
    daThuc.xuatDaoHam();
    return 0;
}