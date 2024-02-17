#include <iostream>
#include <cmath>
using namespace std;

struct KG2C {
    int x, y;

    friend istream& operator >> (istream &in, KG2C &toaDo) {
        in >> toaDo.x >> toaDo.y;
        return in;
    }

    friend ostream& operator << (ostream &out, KG2C toaDo) {
        out << "(" << toaDo.x << ", " << toaDo.y << ")";
        return out;
    }

    double operator - (KG2C other) {
        return sqrt(pow(other.x - this->x, 2) + pow(other.y - this->y, 2));
    }

    bool operator < (KG2C other) {
        if (this->x < other.x) return true;
        if (this->x == other.x && this-> y < other.y) return true;
        return false;
    }
};

struct KG3C {
    int x, y, z;

    friend istream& operator >> (istream &in, KG3C &toaDo) {
        in >> toaDo.x >> toaDo.y >> toaDo.z;
        return in;
    }

    friend ostream& operator << (ostream &out, KG3C toaDo) {
        out << "(" << toaDo.x << ", " << toaDo.y << ", " << toaDo.z << ")";
        return out;
    }

    double operator - (KG3C other) {
        return sqrt(pow(other.x - this->x, 2) + pow(other.y - this->y, 2) + pow(other.z - this->z, 2));
    }

    bool operator < (KG3C other) {
        if (this->x < other.x) return true;
        if (this->x == other.x && this->y < other.y) return true;
        if (this->x == other.x && this->y == other.y && this->z < other.z) return true;
        return false;
    }
};

template <typename T>
struct Array {
    int size = 0;
    T values[100];

    friend istream& operator >> (istream &in, Array &array) {
        T n; in >> n;
        array.values[array.size++] = n;
        return in;
    } 

    friend ostream& operator << (ostream &out, Array array) {
        for (int i = 0; i < array.size; i++) 
            out << array.values[i] << " ";
        return out;
    }

    double khoangCachLonNhat() {
        double res = 0;
        for (int i = 0; i < this->size; i++)
            for (int j = i + 1; j < this->size; j++)
                if (res < this->values[i] - this->values[j])
                    res = this->values[i] - this->values[j];
        return res;
    }

    void sapXepTangDan() {
        for (int i = 1; i < this->size; i++) {
            int j = i;
            while (j > 0 && this->values[j] < this->values[j-1]) {
                swap(this->values[j], this->values[j-1]);
                j--;
            }
        }
        return;
    }

    void sapXepGiamDan() {
        for (int i = 1; i < this->size; i++) {
            int j = i;
            while (j > 0 && this->values[j-1] < this->values[j]) {
                swap(this->values[j-1], this->values[j]);
                j--;
            }
        }
        return;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str; 
    Array<KG2C> arr2C;
    Array<KG3C> arr3C;

    while (cin >> str) {
        if (str == "Oxy") cin >> arr2C;
        else if (str == "Oxyz") cin >> arr3C;
    }

    arr2C.sapXepTangDan(); cout << arr2C << endl;
    arr3C.sapXepGiamDan(); cout << arr3C << endl;

    cout << roundf(arr2C.khoangCachLonNhat()*1000)/1000 << endl;
    cout << roundf(arr3C.khoangCachLonNhat()*1000)/1000 << endl;

    return 0;
}