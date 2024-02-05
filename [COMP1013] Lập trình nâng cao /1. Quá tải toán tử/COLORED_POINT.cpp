#include <iostream>
using namespace std;

struct COLORED_POINT {
    int x;
    int y;
    string maMau;

    friend istream& operator >> (istream &in, COLORED_POINT &cp) {
        in >> cp.x >> cp.y >> cp.maMau;
        return in;
    }

    friend ostream& operator << (ostream &out, COLORED_POINT cp) {
        out << "(" << cp.x << "," << cp.y << ",#" << cp.maMau << ")";
        return out;
    }

    bool kiemTra5DC3A8() {
        if (this->maMau == "5DC3A8") return true;
        else return false;
    }

    void doiMaMau() {
        if (this->x > this->y) this->maMau = "1F00F3";
        return;
    }
};

int main() {
    int size; cin >> size;
    COLORED_POINT *arr = new COLORED_POINT[size];
    for (int i = 0; i < size; i++) cin >> arr[i];

    for (int i = 0; i < size - 1; i++) 
        cout << *(arr + i); 
    cout << *(arr + size-1) << endl;

    int cnt = 0;
    for (int i = 0; i < size; i++) {
        if ((*(arr + i)).kiemTra5DC3A8()) cnt++;
        (*(arr + i)).doiMaMau();
    }

    cout << cnt << endl;
    for (int i = 0; i < size - 1; i++) 
        cout << *(arr + i); 
    cout << *(arr + size-1);

    delete[] arr;
    return 0;
}
