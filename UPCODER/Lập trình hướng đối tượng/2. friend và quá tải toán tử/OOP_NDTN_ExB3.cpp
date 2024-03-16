#include <iostream>
using namespace std;

class ARRINT2 {
public:
    int len;
    int* arr;

    ARRINT2(int n) {
        this->len = n;
        this->arr = new int[n];
    }

    friend istream& operator >> (istream &in, ARRINT2 &arrInt) {
        for (int i = arrInt.len-1; i >= 0; i--) 
            in >> arrInt.arr[i];
        return in;
    }

    friend ostream& operator << (ostream &out, ARRINT2 arrInt) {
        out << arrInt.len << ": ";
        for (int i = 0; i < arrInt.len; i++)    
            out << arrInt.arr[i];
    }

    ARRINT2 operator - (ARRINT2 other) {
        ARRINT2 res(max(this->len, other.len));

        for (int i = 0; i < res.len; i++) {
            res.arr[i] = this->arr[i] - other.arr[i];
            if (res.arr[i] < 0) res.arr[i] = -res.arr[i];
        }

        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    ARRINT2 arrInt1(n), arrInt2(m);
    cin >> arrInt1 >> arrInt2;
    cout << arrInt1 - arrInt2;

    return 0;
}