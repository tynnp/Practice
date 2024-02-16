#include <iostream>
using namespace std;

struct Diem {
    int x;
    int y;

    friend istream& operator >> (istream& in, Diem& diem) {
        in >> diem.x >> diem.y;
        return in;
    }

    friend ostream& operator << (ostream& out, Diem diem) {
        out << "(" << diem.x << "," << diem.y << ")";
        return out;
    }

    bool operator == (Diem diem) {
        return (this->x == diem.x && this->y == diem.y);
    }

    bool operator < (Diem diem) {
        if (this->x < diem.x) return true;
        if ((this->x == diem.x) && (this->y < diem.y)) return true;
        return false;
    }

    Diem operator + (Diem diem) {
        Diem res;
        res.x = this->x + diem.x;
        res.y = this->y + diem.y;
        return res;
    }
};

struct MangDiem {
    int size;
    Diem *values;

    friend istream& operator >> (istream& in, MangDiem& arr) {
        arr.values = new Diem[100];
        arr.size = 0;
        while (cin >> arr.values[arr.size]) arr.size++;
        return in;
    } 

    friend ostream& operator << (ostream& out, MangDiem arr) {
        for (int i = 0; i < arr.size; i++)
            out << arr.values[i];
        return out;
    }

    MangDiem operator + (MangDiem arr) {
        int length = max(this->size, arr.size);
        MangDiem mangDiem;
        mangDiem.size = length;
        mangDiem.values = new Diem[length];
        for (int i = 0; i < length; i++) 
            mangDiem.values[i] = this->values[i] + arr.values[i];
        return mangDiem;
    }

    Diem diemLonNhat() {
        Diem res = this->values[0];
        for (int i = 1; i < this->size; i++)
            if (res < this->values[i]) res = this->values[i];
        return res;
    }

    Diem tongDiem() {
        Diem res = this->values[0];
        for (int i = 1; i < this->size; i++)
            res = res + this->values[i];
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    MangDiem arr; cin >> arr;
    cout << arr.diemLonNhat() << endl;
    cout << arr.tongDiem() << endl;
    return 0;
}